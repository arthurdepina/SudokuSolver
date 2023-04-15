#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool verifica_possibilidade(int **tabuleiro, int n, int x, int y){
    // A função vai verificar se é possível inserir um número n nas coordenadas (x, y) de um tabuleiro de sudoku
    
    return true;
}

int resolve_sudoku(int **tabuleiro){
    int n;
    for(int l = 0; l < 9; l++){
        for(int c = 0; c < 9; c++){
            if (tabuleiro[l][c] == 0){
                for(int n = 1; n <= 9; n++){
                    if(verifica_possibilidade(tabuleiro, n, l, c)){
                        tabuleiro[l][c] = n;
                        if(resolve_sudoku(tabuleiro)){
                            return 1; // Solucionado
                        }
                    tabuleiro[l][c] = 0;
                    }
                }
            return 0; // Sem solução
            }
        }
    }
    return 1; // Resolvido
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
    // resolve_sudoku(tabuleiro);

    for(int i = 0; i < linhas; i++){
        free(tabuleiro[i]);
    }

    free(tabuleiro);
    return 0;
}