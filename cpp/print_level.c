#include<stdio.h>
#include<stdarg.h>

typedef enum TEST_PRINT_LEVEL
{
    TEST_ONE_PRINT,
    TEST_TWO_PRINT,
    TEST_THREE_PRINT,
    TEST_PRINT_TOTAL
}TEST_PRINT_LEVEL_ENUM;

int TestPrintLevel[TEST_PRINT_TOTAL] = {1, 0, 1};

void Test_Printf(int ucLevel, char *fmt, ...)
{
    va_list args;
    char cBuf[256]; 

    va_start(args, fmt);
    vsprintf(cBuf, fmt, args); 
    va_end(args);

    if (0 != TestPrintLevel[ucLevel])
    {
        printf("%s", cBuf);
    }

    return;
}

int main(void)
{
    int a = 5;

    Test_Printf(TEST_ONE_PRINT, "hello one\n");
    Test_Printf(TEST_TWO_PRINT, "hello two\n");
    Test_Printf(TEST_THREE_PRINT, "hello three\n");

    Test_Printf(TEST_ONE_PRINT, "one\ta = %d\n", a);
    Test_Printf(TEST_TWO_PRINT, "two\ta = %d\n", a);
    Test_Printf(TEST_THREE_PRINT, "three\ta = %d\n", a);

    return 0;
}
