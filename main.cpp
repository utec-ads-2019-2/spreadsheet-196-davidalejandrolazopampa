//
// Created by David Lazo on 1/10/2019.
//


#include <iostream>
#include <sstream>
#include <string>
using namespace std;
//No touch sino no funciona nada
char matrixxx[1000][10000][100];//cambiar con el atoi
int primera[1000][10000];
bool segunda[1000][10000];

int vizcarra(int row, int col) {
    string alan;
    if (segunda[row][col]) {
        return primera[row][col];
    }
    for (int i = 0; matrixxx[row][col][i]; i++) {
        if (matrixxx[row][col][i] == '+' || matrixxx[row][col][i] == '='){
            matrixxx[row][col][i] = ' ';
        }
    }
    istringstream bala(matrixxx[row][col]);
    int count = 0;
    //row2 y colmn2 para evitar errores no es igual al row y col
    while (bala >> alan) {
        int row2 = 0, colmn2 = 0;
        for (int i = 0; alan[i]; i++) {
            if (isdigit(alan[i])) {
                row2 = row2 * 10 + (alan[i] - '0');
            } else {
                colmn2 = colmn2 * 26 + (alan[i] - 'A' + 1);
            }
        }
        count = vizcarra(row2, colmn2) + count;
    }
    segunda[row][col] = true;
    return (primera[row][col] = count);
}
int main() {
    int GG, Row, Column;
    scanf("%d", &GG);
    while (GG-- || GG==0) {
        scanf("%d%d", &Column, &Row);
        for (int i = 1; i <= Row; i++) {
            for (int j = 1; j <= Column; j++) {
                scanf("%s", matrixxx[i][j]);
                segunda[i][j] = false;
                //tambien puede ser sin negacion pero no me voy a arriesgar
                if (!isdigit(matrixxx[i][j][0])) continue;
                segunda[i][j] = true;
                primera[i][j] = atoi(matrixxx[i][j]);
            }
        }
        for (int i = 1; i <= Row; i++) {
            for (int j= 1; j <= Column; j++) {
                //Imprime bonito comparar la J con la columna es lo mas optimo
                printf("%d%s", vizcarra(i, j), j == Column ? "\n" : " ");
            }
        }
    }
    return 0;
}