#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char ***map;
const int vectors[6][3] = {
{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}
};

int NumberOfMines(char ***map, int n, int i, int j, int k, int path);

bool QOrNot(char ***map, int n, int i, int j, int k);

int main(void){
    int n = 0;
    scanf("%d", &n);

    map = malloc(n * sizeof(char**));
    for (int i = 0; i < n; i++){
        map[i] = malloc(n * sizeof(char*));
        for (int j = 0; j < n; j++){
            map[i][j] = malloc((n + 1) * sizeof(char));
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < n; k++)
            scanf(" %c", &map[i][j][k]);
        }
    }

    bool isValid = true;
    bool isMine = false;
    int iq, jq, kq;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < n; k++){
                if (map[i][j][k] != '*' && map[i][j][k] != '?'){
                    int num = atoi(&map[i][j][k]);
                    if (QOrNot(map, n, i, j, k)){
                        int count1 = NumberOfMines(map, n, i, j, k, 1);
                        int count2 = NumberOfMines(map, n, i, j, k, 2);
                        if (num
                        != count2){
                            if(num != count1){
                            if(isValid){
                                printf("invalid\n");
                            }
                            isValid = false;}
                            printf("%d %d %d\n", i, j, k);
                    }
                    if (num == count2) isMine = true;
                    }else{
                        int count = NumberOfMines(map, n, i, j, k, 1);
                        if (num != count){
                            if(isValid){
                                printf("invalid\n");
                            }
                            isValid = false;
                            printf("%d %d %d\n", i, j, k);
                        }
                    }
                }else if (map[i][j][k] == '?'){
                    iq = i;
                    jq = j;
                    kq = k;
                }
            }
        }
    }

    if (isValid){
        printf("valid\n");
        if (isMine) printf("*");
        else printf("%d", NumberOfMines(map, n, iq, jq, kq, 1));
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            free(map[i][j]);
        }
        free(map[i]);
    }
    free(map);
    return 0;
}

int NumberOfMines(char ***map, int n, int i, int j, int k, int path){
    int count = 0;
    for (int t = 0; t < 6; t++){
        int newI = i + vectors[t][0];
        int newJ = j + vectors[t][1];
        int newK = k + vectors[t][2];
        if (path == 1){
            if (newI >= 0 && newI < n && newJ >= 0 && newJ < n && newK >= 0 && newK < n
                && map[newI][newJ][newK] == '*') count++;
        }else if (path == 2){
            if (newI >= 0 && newI < n && newJ >= 0 && newJ < n && newK >= 0 && newK < n
                && ( map[newI][newJ][newK] == '*' || map[newI][newJ][newK] == '?')) count++;
        }
    }
    return count;
}

bool QOrNot(char ***map, int n, int i, int j, int k){
    for(int t = 0; t < 6; t++){
        int newI = i + vectors[t][0];
        int newJ = j + vectors[t][1];
        int newK = k + vectors[t][2];
        if (newI >= 0 && newI < n && newJ >= 0 && newJ < n && newK >= 0 && newK < n
                && map[newI][newJ][newK] == '?') return true;
    }
    return false;
}