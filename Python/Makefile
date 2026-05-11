# ============================================================
#  Makefile - Trabalho 2 AEDSI (Python)
#  Compatível com Linux
# ============================================================

PYTHON    := python3
SCRIPT    := metodos_ordena.py

SAIDA_DIRS := dados/Saida/Crescente \
              dados/Saida/Decrescente \
              dados/Saida/Desordenado-Ordenado

# ------------------------------------------------------------
.PHONY: all run clean help

# Alvo padrão
all: run

## Cria as pastas de saída (caso não existam) e executa o script
run: $(SAIDA_DIRS)
	@echo "==> Executando $(SCRIPT) ..."
	$(PYTHON) $(SCRIPT)
	@echo "==> Concluído. Resultados em dados/Saida/"

## Garante que os diretórios de saída existam
$(SAIDA_DIRS):
	mkdir -p $@

## Remove todos os arquivos de saída gerados
clean:
	@echo "==> Removendo arquivos de saída ..."
	rm -rf dados/Saida/Crescente/* \
	       dados/Saida/Decrescente/* \
	       dados/Saida/Desordenado-Ordenado/* \
	       dados/Saida/log_memoria.dat
	@echo "==> Limpeza concluída."

## Exibe esta ajuda
help:
	@echo ""
	@echo "Uso: make [alvo]"
	@echo ""
	@echo "  all (padrão)  Cria pastas e executa o script"
	@echo "  run           Mesmo que 'all'"
	@echo "  clean         Remove os arquivos de saída"
	@echo "  help          Exibe esta mensagem"
	@echo ""