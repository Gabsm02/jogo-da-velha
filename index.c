#include <stdio.h>

#define TAMANHO 3

// Função para exibir o tabuleiro
void exibirTabuleiro(char tabuleiro[TAMANHO][TAMANHO]) {
    printf("\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if (j < TAMANHO - 1) printf("|");
        }
        printf("\n");
        if (i < TAMANHO - 1) printf("---|---|---\n");
    }
    printf("\n");
}

// Função para verificar se há um vencedor
int verificarVencedor(char tabuleiro[TAMANHO][TAMANHO], char jogador) {
    // Verifica linhas e colunas
    for (int i = 0; i < TAMANHO; i++) {
        if ((tabuleiro[i][0] == jogador && tabuleiro[i][1] == jogador && tabuleiro[i][2] == jogador) ||
            (tabuleiro[0][i] == jogador && tabuleiro[1][i] == jogador && tabuleiro[2][i] == jogador)) {
            return 1;
        }
    }
    // Verifica diagonais
    if ((tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador) ||
        (tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador)) {
        return 1;
    }
    return 0;
}

// Função para verificar se o tabuleiro está cheio
int tabuleiroCheio(char tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            if (tabuleiro[i][j] != 'X' && tabuleiro[i][j] != 'O') {
                return 0;
            }
        }
    }
    return 1;
}

// Função principal para o jogo
int main() {
    char tabuleiro[TAMANHO][TAMANHO] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
    int movimento, linha, coluna;
    char jogador = 'X';
    int vencedor = 0;

    while (!vencedor && !tabuleiroCheio(tabuleiro)) {
        exibirTabuleiro(tabuleiro);
        printf("Jogador %c, escolha um número (1-9): ", jogador);
        scanf("%d", &movimento);

        // Calcula a linha e coluna a partir do movimento
        linha = (movimento - 1) / TAMANHO;
        coluna = (movimento - 1) % TAMANHO;

        // Verifica se a posição está disponível
        if (movimento < 1 || movimento > 9 || tabuleiro[linha][coluna] == 'X' || tabuleiro[linha][coluna] == 'O') {
            printf("Movimento inválido! Tente novamente.\n");
            continue;
        }

        // Realiza o movimento
        tabuleiro[linha][coluna] = jogador;

        // Verifica se há um vencedor
        vencedor = verificarVencedor(tabuleiro, jogador);
        if (vencedor) {
            exibirTabuleiro(tabuleiro);
            printf("Jogador %c venceu!\n", jogador);
        } else if (tabuleiroCheio(tabuleiro)) {
            exibirTabuleiro(tabuleiro);
            printf("Empate!\n");
        } else {
            // Alterna para o próximo jogador
            jogador = (jogador == 'X') ? 'O' : 'X';
        }
    }

    return 0;
}
