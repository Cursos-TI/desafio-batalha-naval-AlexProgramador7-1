#include <stdio.h>

// Tamanho fixo do tabuleiro

#define TAMANHO 10

// Valor que representa a parte de um navio

#define NAVIO 3

int main() {
    // 1. Declaração e inicialização da matriz do tabuleiro (10x10)
    int tabuleiro[TAMANHO][TAMANHO] = {0};

    // 2. Declaração dos navios (vetores de tamanho 3)
    int navio_horizontal[3] = {NAVIO, NAVIO, NAVIO};
    int navio_vertical[3] = {NAVIO, NAVIO, NAVIO};

    // 3. Coordenadas iniciais dos navios
    int linha_horizontal = 2; // linha para o navio horizontal
    int coluna_horizontal = 4; // coluna inicial do navio horizontal

    int linha_vertical = 5; // linha inicial do navio vertical
    int coluna_vertical = 7; // coluna para o navio vertical

    // 4. Validação do navio horizontal (verifica se cabe no tabuleiro)
    if (coluna_horizontal + 3 <= TAMANHO) {
        for (int i = 0; i < 3; i++) {
            // Verifica se já tem navio na posição
            if (tabuleiro[linha_horizontal][coluna_horizontal + i] == 0) {
                tabuleiro[linha_horizontal][coluna_horizontal + i] = navio_horizontal[i];
            } else {
                printf("Erro: sobreposição de navios no navio horizontal.\n");
                return 1;
            }
        }
    } else {
        printf("Erro: navio horizontal ultrapassa os limites do tabuleiro.\n");
        return 1;
    }

    // 5. Validação do navio vertical (verifica se cabe no tabuleiro)
    if (linha_vertical + 3 <= TAMANHO) {
        for (int i = 0; i < 3; i++) {
            // Verifica se já tem navio na posição
            if (tabuleiro[linha_vertical + i][coluna_vertical] == 0) {
                tabuleiro[linha_vertical + i][coluna_vertical] = navio_vertical[i];
            } else {
                printf("Erro: sobreposição de navios no navio vertical.\n");
                return 1;
            }
        }
    } else {
        printf("Erro: navio vertical ultrapassa os limites do tabuleiro.\n");
        return 1;
    }

    // 6. Exibição do tabuleiro
    printf("\n=== TABULEIRO ===\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}