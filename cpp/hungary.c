#include<stdio.h>
#include<stdbool.h>
#include<string.h>

#define N 4
#define M 4

bool line[N + 1][M + 1] = {false};
bool used[N] = {false};
int girl[M] = {0};

void init_line(void) {
    line[1][1] = true;
    line[1][2] = true;
    line[2][2] = true;
    line[2][3] = true;
    line[3][1] = true;
    line[3][2] = true;
    line[4][3] = true;
}

bool find(int x) {
    int i = 0;

    /*扫描每个妹子*/
    for (i = 1; i <= M; i++) {
        /*如果x和i有暧昧并且还没有标记过*/
        if (line[x][i] == true && used[i] == false) {
            used[i] = true;

            /*妹子i还未匹配，或者i在匹配中，但是还可以与其它人匹配*/
            if (girl[i] == 0 || find(girl[i])) {
                girl[i] = x;

                return true;
            }
        }
    }

    return false;
}

int main(void) {
    int i = 0;
    int match_number = 0;

    init_line();

    for (i = 1; i <= N; i++) {
        /*清空上一次查找的标记*/
        memset(used, 0, sizeof(used));

        if (find(i)) {
            match_number += 1;
        }
    }

    printf("match_number=%d\n", match_number);
    for (i = 1; i <= N; i++) {
        printf("%d====%d\n", girl[i], i);
    }

    return 0;
}
