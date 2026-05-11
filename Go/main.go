package main

import (
	"fmt"
	"os"
	"path/filepath"
	"runtime"
	"shellsort/sorts"
	"strconv"
	"strings"
	"time"
)

func totalAlloc() uint64 {
	var m runtime.MemStats
	runtime.ReadMemStats(&m)
	return m.TotalAlloc
}

func readInput(path string) ([]int, error) {
	dados, err := os.ReadFile(path)
	if err != nil {
		return nil, err
	}
	campos := strings.Fields(string(dados))
	vet := make([]int, len(campos))
	for i, v := range campos {
		num, err := strconv.Atoi(v)
		if err != nil {
			return nil, fmt.Errorf("valor inválido '%s' em %s: %w", v, path, err)
		}
		vet[i] = num
	}
	return vet, nil
}

func writeOutput(path string, vet []int) error {
	f, err := os.Create(path)
	if err != nil {
		return err
	}
	defer f.Close()
	for _, v := range vet {
		fmt.Fprintln(f, v)
	}
	return nil
}

func main() {
	inputDir := "INPUT"
	outputDir := "OUTPUT"

	if err := os.MkdirAll(outputDir, 0755); err != nil {
		panic(err)
	}

	bench, err := os.Create(filepath.Join(outputDir, "benchmark.dat"))
	if err != nil {
		panic(err)
	}
	defer bench.Close()

	// Nota: Shell Sort e Comb Sort são algoritmos in-place.
	// A memória registrada é o tamanho do vetor de trabalho (n * 8 bytes para []int64).
	// Alocações internas durante a ordenação são capturadas via TotalAlloc delta.
	header := fmt.Sprintf("%-40s | %-10s | %-18s | %-18s | %-18s | %-18s\n",
		"Input", "N", "Shell Tempo (s)", "Shell Mem (KB)", "Comb Tempo (s)", "Comb Mem (KB)")
	sep := strings.Repeat("-", 135) + "\n"
	nota := "# Memoria = vetor de trabalho (in-place) + alocacoes internas medidas por TotalAlloc\n\n"
	fmt.Fprint(bench, nota)
	fmt.Fprint(bench, header)
	fmt.Fprint(bench, sep)
	fmt.Print(header)
	fmt.Print(sep)

	entries, err := os.ReadDir(inputDir)
	if err != nil {
		panic(err)
	}

	for _, entry := range entries {
		if entry.IsDir() || !strings.HasSuffix(entry.Name(), ".dat") {
			continue
		}

		inputPath := filepath.Join(inputDir, entry.Name())
		baseName := strings.TrimSuffix(entry.Name(), ".dat")

		vet, err := readInput(inputPath)
		if err != nil {
			fmt.Fprintf(os.Stderr, "Erro ao ler %s: %v\n", inputPath, err)
			continue
		}
		n := len(vet)
		// Tamanho do vetor em KB (memória principal do algoritmo, in-place)
		vetKB := int64(n * 8 / 1024)

		// Shell Sort
		vetShell := make([]int, n)
		copy(vetShell, vet)
		runtime.GC()
		antesShell := totalAlloc()
		t0 := time.Now()
		sorts.Shellsort(vetShell, n)
		tempoShell := time.Since(t0)
		extraShellKB := int64(totalAlloc()-antesShell) / 1024
		memShellKB := vetKB + extraShellKB

		// Comb Sort
		vetComb := make([]int, n)
		copy(vetComb, vet)
		runtime.GC()
		antesComb := totalAlloc()
		t0 = time.Now()
		sorts.Combsort(vetComb, n)
		tempoComb := time.Since(t0)
		extraCombKB := int64(totalAlloc()-antesComb) / 1024
		memCombKB := vetKB + extraCombKB

		shellOut := filepath.Join(outputDir, "shell_"+baseName+".dat")
		combOut := filepath.Join(outputDir, "comb_"+baseName+".dat")
		writeOutput(shellOut, vetShell)
		writeOutput(combOut, vetComb)

		line := fmt.Sprintf("%-40s | %-10d | %-18.6f | %-18d | %-18.6f | %-18d\n",
			entry.Name(), n,
			tempoShell.Seconds(), memShellKB,
			tempoComb.Seconds(), memCombKB,
		)
		fmt.Fprint(bench, line)
		fmt.Print(line)
	}

	fmt.Println("\nPronto! Outputs em OUTPUT/  |  Benchmark em OUTPUT/benchmark.dat")
}
