#include<stdio.h>
#include<string.h>

int main()
{
	int arry[2][3] = {0};

	arry[0][0] = 9;
	arry[0][1] = 9;
	arry[0][2] = 9;

	arry[1][0] = 1;
	arry[1][1] = 2;
	arry[1][2] = 3;

    memset(arry[0], 0, 3 * sizeof(int));
    printf("%d %d %d\n%d %d %d\n\n", arry[0][0], arry[0][1], arry[0][2], arry[1][0], arry[1][1], arry[1][2]);

    memcpy(arry[0], arry[1], 3 * sizeof(int));
    arry[1][0] = 1;
    arry[1][1] = 2;
    arry[1][2] = 3;
	printf("%d %d %d\n%d %d %d\n\n", arry[0][0], arry[0][1], arry[0][2], arry[1][0], arry[1][1], arry[1][2]);

    printf("bool=%d\n", memcmp(arry[0], arry[1], 3 * sizeof(int)));
    if (!memcmp(arry[0], arry[1], 3 * sizeof(int)))
    {
        printf("......\n");
    }
}
