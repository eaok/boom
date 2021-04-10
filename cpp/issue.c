/*********************************************************************
  有两个数组a,b,大小都为n，数组元素的值任意，无序；通过交换a,b中的元素，
  使数组a元素的和与数组b的元素的和之间的差最小。
 *********************************************************************/

#include<stdio.h>


int find_mindiff(int *a, int *b, int n)
{
    int i = 0;
    int j = 0;
    int diff = 0;
    int single_diff = 0;
    int temp = 0;

    for(i = 0; i < n; i++)
    {
        diff += (a[i] - b[i]);
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            single_diff = a[i] - b[j];
            temp = single_diff - diff;

            if(temp * single_diff < 0)
            {
                a[i] = a[i] + b[j];
                b[j] = a[i] - b[j];
                a[i] = a[i] - b[j];
                diff -= 2 * single_diff;
            }
        }
    }

    return diff;
}

int main(void)
{
    int i = 0;;
    int n = 0;
    int mindiff = 0;
    int a[5] = {25, 3, 7, 21, 8};
    int b[5] = {11, 2, 88, 24, 5};

    n = 5;
    for(i = 0; i < n; i++)
    {
        printf("%d\t%d", a[i], b[i]);
        printf("\n");
    }

    mindiff = find_mindiff(a, b, n);

    printf("The mindiff = %d\n", mindiff);
    for(i = 0; i < n; i++)
    {
        printf("%d\t%d", a[i], b[i]);
        printf("\n");
    }

    return 0;
}
