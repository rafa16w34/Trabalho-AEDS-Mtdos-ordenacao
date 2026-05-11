package sorts

func Combsort(vet []int, n int) {

	gap := n
	troca := 1

	for gap != 1 || troca != 0 {

		gap = int(float64(gap) / 1.3)

		if gap < 1 {

			gap = 1
		}

		troca = 0

		for i := 0; i+gap < n; i++ {

			if vet[i] > vet[i+gap] {

				vet[i], vet[i+gap] = vet[i+gap], vet[i]
				troca++
			}

		}

	}
}
