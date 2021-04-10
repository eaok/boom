#include<stdio.h>

int main(void)
{
    char *a = "a\0bcdefg";

    printf("%c\n", *a);
    printf("%c\n", *a+1);
    printf("%c\n", *a+2);
    printf("%c\n", *(a));
    printf("%c\n", *(a+1));
    printf("%c\n", *(a+2));

    char *p = "ABCDEFGH";

    while(*p){
        printf("%s", p);
        p += 2;
    }
    printf("\n");

    return 0;
}
