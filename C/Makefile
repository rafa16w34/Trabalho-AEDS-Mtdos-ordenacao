# ============================================================
#  Makefile - Shell Sort e Comb Sort
# ============================================================

CC     = gcc
CFLAGS = -Wall -Wextra -O2
TARGET = programa
SRCS   = main.c shell.c comb.c

# compila tudo de uma vez (sem arquivos .o intermediários)
all:
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

# compila e executa
run: all
	./$(TARGET)

# remove o executável
clean:
	rm -f $(TARGET)

# remove executável e outputs gerados
cleanall: clean
	rm -f OUTPUT/output_*.dat OUTPUT/metricas.dat

.PHONY: all run clean cleanall