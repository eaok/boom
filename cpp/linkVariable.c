#include <stdio.h>

#define TEST(b) a##b
#define TESTB(b) "a"#b

int main(void) {
    char* a = "1";
    char* b = "2";
    char* ab = "1234";

    printf("a=%s b=%s ab=%s TESTB(b)=%s\n", a, b, TEST(b), TESTB(b));

    return 0;
}
