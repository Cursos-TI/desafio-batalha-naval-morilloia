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
    int indexVertical, indexHorizontal, i;
    // Display do navio vertical
    indexVertical = 2; // Coluna fixa
    printf("Navio Vertical (Coluna %d):\n", indexVertical);
    for (i = 2; i < 5; i++){
        if (tabuleiro[i][indexVertical] != 0) { // Valida se a posição já está ocupada
            printf("A posição (%d, %d) já foi ocupada\n",i, indexVertical);
            return 1; // Sai do programa com código de erro
        } else if (i > 10 || i < 0) { // Valida se a posição está dentro dos limites do tabuleiro
                printf("A posição (%d, %d) está fora dos limites do tabuleiro\n",i, indexVertical);
                return 1; // Sai do programa com código de erro
            } else{
        tabuleiro[i][indexVertical] = 3; // Marca o navio no tabuleiro
        printf("Parte do navio na posicao: (%d, %d)\n", i, indexVertical); //Printa as posições do navio
        }
    }

    // Display do navio horizontal
    indexHorizontal = 8;
    printf("Navio Horizontal (Linha %d):\n", indexHorizontal);
    for( i = 5; i < 8; i++){
        if (tabuleiro[indexHorizontal][i] != 0) 
        {
            printf("A posição (%d, %d) já foi ocupada\n",indexHorizontal, i); // Valida se a posição já está ocupada
            return 1; // Sai do programa com código de erro
        } else if (i > 10 || i < 0) { // Valida se a posição está dentro dos limites do tabuleiro
                printf("A posição (%d, %d) está fora dos limites do tabuleiro\n",indexHorizontal, i);
                return 1; // Sai do programa com código de erro
            } else {
            tabuleiro[indexHorizontal][i] = 3; // Marca o navio no tabuleiro
            printf("Parte do navio na posicao: (%d, %d)\n", indexHorizontal, i);
        }
    }
    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.
    // Display dos navios diagonais
    printf("Navio Diagonal 1:\n");
    for (int i = 9, j = 2 ; i > 6; i--, j++){ // Faz a iteração decrescente para i e crescente para j, trocando a direção da diagonal
        if (tabuleiro[i][j] != 0) { // Valida se a posição já está ocupada
            printf("A posição (%d, %d) já foi ocupada\n",i, j);
            return 1; // Sai do programa com código de erro
            } else if (i > 10 || i < 0) { // Valida se a posição está dentro dos limites do tabuleiro
                printf("A posição (%d, %d) está fora dos limites do tabuleiro\n",i, j);
                return 1; // Sai do programa com código de erro
            } else {
                tabuleiro[i][j] = 3; // Marca o navio no tabuleiro
                printf("Parte do navio na posicao: (%d, %d)\n", i, j);
            }
        }
    printf("Navio Diagonal 2:\n");
    for (i = 4; i < 7; i++){ // Faz a iteração crescente para i e j, mantendo a direção da diagonal
        if (tabuleiro[i][i] != 0) { // Valida se a posição já está ocupada
            printf("A posição (%d, %d) já foi ocupada\n",i, i);
            return 1; // Sai do programa com código de erro
            } else if (i > 10 || i < 0) { // Valida se a posição está dentro dos limites do tabuleiro
                printf("A posição (%d, %d) está fora dos limites do tabuleiro\n",i, i);
                return 1; // Sai do programa com código de erro
            } else { 
                tabuleiro[i][i] = 3; // Marca o navio no tabuleiro
                printf("Parte do navio na posicao: (%d, %d)\n", i, i);
            }
        }
    printf("\n"); 
    // Display do tabuleiro após posicionar os navios
    printf("Tabuleiro naval:\n");

     for (i = 0; i < LINHAS; i++) // Loop para linhas
    {   
        for (int j = 0; j < COLUNAS; j++) // Loop para colunas
        {
            printf("%d ", tabuleiro[i][j]); 
        }
        printf("\n");
    }    
    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
