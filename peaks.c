#include <stdio.h>

#define MAXN 100
#define MAXM 100

int N, M;
int grid[MAXN][MAXM];
int num_peak = 0;
typedef struct{
        int row;
        int col;
    }Peak;

Peak peaks[MAXN * MAXM];

int is_peak(int x, int y) {
    //checo cada um dos 8 vizinhos
    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            if(i == 0 && j == 0){
                continue;
            }
            if(x + i >= 0 && x + i < N && y + j >= 0 && y + j < M){
                if(grid[x][y] <= grid[x+i][y+j]){
                    return 0;
                }
                
            }
        
        }
    }
    //vou receber um x,y de grid e preciso fazer para cada um dos lados se ele e menor ou nao que o numero x,y
    //toda vez que retornar 0 eu conto peak += 1;
    //retorno o x e y se for 0, pois ele sera um pico.
    return 1;
}

int main() {
    //le as dimensoes
    if (scanf("%d %d", &N, &M) != 2) {
        return 1;
    }

    //verifica onde tem picos
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            scanf("%d", &grid[i][j]);
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (is_peak(i, j)) {
                peaks[num_peak].row = i;
                peaks[num_peak].col = j;
                num_peak++;
            }
        }
    }
    
    //printa cada par de linha e coluna em relacao a onde esta o pico
    printf("%d\n", num_peak);
    for(int i = 0; i < num_peak; i++){
            printf("%d %d\n",peaks[i].row, peaks[i].col);
    }
    return 0;
}
