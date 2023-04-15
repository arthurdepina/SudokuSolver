#include <stdio.h>
#include <stdlib.h>

void mostrar_tabuleiro(int **m, int linhas, int colunas){
    int i, j, k;
    for (i = 0; i < linhas; i++){
        for (j = 0; j < colunas; j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

int alocando_sudoku(int **tabuleiro, int linhas, int colunas){
    FILE *tab;
    tab = fopen("01 Sudoku.txt", "r");
    if (tab == NULL){
        printf("Erro na abertura do arquivo");
        return 1;
    }
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            fscanf(tab, "%d", &tabuleiro[i][j]);
        }
    }
    fclose(tab);
    return 0;
}

int resolve_sudoku(int **tabuleiro, int linhas, int colunas){
    return 0;
}


int main(){
    int linhas, colunas;
    linhas = 9;
    colunas = 9;
    int **tabuleiro = malloc(linhas * sizeof(int *));
    for(int i = 0; i < linhas; i++){
        tabuleiro[i] = malloc(colunas * sizeof(int));
    }
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            tabuleiro[i][j] = 0;
        }
    }

    alocando_sudoku(tabuleiro, linhas, colunas);

    printf("\nTabuleiro Inicial:\n\n");
    mostrar_tabuleiro(tabuleiro, linhas, colunas);
    
    printf("\nTabuleiro Resolvido:\n\n");
    // resolve_sudoku(tabuleiro, linhas, colunas);

    for(int i = 0; i < linhas; i++){
        free(tabuleiro[i]);
    }

    free(tabuleiro);
    return 0;
}