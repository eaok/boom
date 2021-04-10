#include<stdio.h>

void swap(int * array, int i, int j)
{
    int tmp = 0;

    tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}

void group_print(int * subs, int s)
{
    int i = 0;

    for(i = 0; i < s; i++)
    {
        printf("%d", subs[i]);
    }
    printf(" ");
}

void perm(int array[], int n, int m, int s, void (*group)(int array[], int s))
{     
    int i = 0;

    if(s == m)
    {
        (*group)(array, s);
    }
    else
    {
        for(i = s; i < n; i++)
        {
             swap(array, s, i);
             perm(array, n, m, s + 1, group);
             swap(array, s, i);
        }
    }
}

void arrangement(int *array, int n, int m)
{
    int s = 0;

    perm(array, n, m, s, group_print);
}

int main(void)
{
    int n = 4;
    int m = 0;
    int array[4] = {1, 2, 3, 5};

//    for(m = 1; m <= n; m++)
//    {
        arrangement(array, n, n);
        printf("\n");
//    }

    return 0;
}
