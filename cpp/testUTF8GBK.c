#include<stdio.h>
#include<string.h>

int main() {
    char str[10] = {
        0
    };

    strcpy(str, "��");
    printf("str=%s\n", str);

    return 0;
}
