#include <stdio.h>
#define LINHAS 10
#define COLUNAS 10

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    int tabuleiro[LINHAS][COLUNAS] = {
        {0,0,0,0,0,0,0,0,0,0}, 
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
    };
    
    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.
    
    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    int habilidadeCone[3][5] = { // Matriz representando a habilidade em cone
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1}
    };
    int linhaOrigem, colunaOrigem, origemLinhaCone = 0, origemColunaCone = 0; // Ponto de origem da habilidade
    for (linhaOrigem = 0; linhaOrigem < 3; linhaOrigem++) {
        for (colunaOrigem = 0; colunaOrigem < 5; colunaOrigem++) {
            // Condições para evitar sair dos limites do tabuleiro
            int linha = origemLinhaCone + linhaOrigem;
            int coluna = origemColunaCone + colunaOrigem;
            if (linha >= LINHAS || coluna >= COLUNAS) {
                 printf("Advertencia: Posición (%d, %d) fuera de límites\n", linha, coluna);
                continue; // Continua para a próxima iteração se sair dos limites
            }
            // Condições para preencher a matriz do tabuleiro com a habilidade em cone
            if (linhaOrigem == 0 && colunaOrigem == 2) {
                tabuleiro[linha][coluna] = 1; // posição central da primeira linha
            }
            else if (linhaOrigem == 1 && (colunaOrigem >= 1 && colunaOrigem <= 3)) {
                tabuleiro[linha][coluna] = 1;  // três posições centrais da segunda linha
            }
            else if (linhaOrigem == 2) {
                tabuleiro[linha][coluna] = 1;  // Toda a terceira linha
            }
        }
    }
    // Display da habilidade no tabuleiro
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0
    int habilidadeOctaedro[3][5] = { // Matriz representando a habilidade em octaedro
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };
    int origemLinhaOctaedro = 4, origemColunaOctaedro = 4; // Ponto de origem da habilidade
    for (linhaOrigem = 0; linhaOrigem < 3; linhaOrigem++) // Loop para linhas
    {   
        for (colunaOrigem = 0; colunaOrigem < 5; colunaOrigem++) // Loop para colunas
        {   // Condições para evitar sair dos limites do tabuleiro
            int linha = origemLinhaOctaedro + linhaOrigem;
            int coluna = origemColunaOctaedro + colunaOrigem;
            if (linha >= LINHAS || coluna >= COLUNAS) {
                 printf("Advertencia: Posición (%d, %d) fuera de límites\n", linha, coluna);
                continue; // Continua para a próxima iteração se sair dos limites
            }
            // Condições para preencher a matriz do tabuleiro com a habilidade em octaedro
            if ((linhaOrigem == 0 || linhaOrigem == 2) && colunaOrigem == 2) { // Primeira e terceira linha
                tabuleiro[linha][coluna] = 1;
            } else if (linhaOrigem == 1 && (colunaOrigem >= 1 && colunaOrigem <= 3)) { // Segunda linha, colunas 1 a 3
                tabuleiro[linha][coluna] = 1;
            }
        }
    }
    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0
    int habilidadeCruz[3][5] = { // Matriz representando a habilidade em cruz
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0}
    };
    int origemLinhaCruz = 6, origemColunaCruz = 1; // Ponto de origem da habilidade
    for (linhaOrigem = 0; linhaOrigem < 3; linhaOrigem++) // Loop para linhas
    {   
            
        for (colunaOrigem = 0; colunaOrigem < 5; colunaOrigem++) // Loop para colunas
        {   // Condições para evitar sair dos limites do tabuleiro
            int linha = origemLinhaCruz + linhaOrigem;
            int coluna = origemColunaCruz + colunaOrigem;
            if (linha >= LINHAS || coluna >= COLUNAS) {
                 printf("Advertencia: Posición (%d, %d) fuera de límites\n", linha, coluna);
                continue; // Continua para a próxima iteração se sair dos limites
            }
         // Condições para preencher a matriz do tabuleiro com a habilidade em cruz
            if ((linhaOrigem == 0 || linhaOrigem == 2 ) && colunaOrigem == 2) { // Primeira e terceira linha
                tabuleiro[linha][coluna] = 1;
            } else if (linhaOrigem == 1 ) { // Segunda linha, todas as colunas
                tabuleiro[linha][coluna] = 1;
            }
        }
    }

// Display do tabuleiro após posicionar as habilidades
    printf("Tabuleiro naval:\n");

     for (int i = 0; i < LINHAS; i++) // Loop para linhas
    {   
        for (int j = 0; j < COLUNAS; j++) // Loop para colunas
        {
            printf("%d ", tabuleiro[i][j]); 
        }
        printf("\n");
    }    

    return 0;
}
