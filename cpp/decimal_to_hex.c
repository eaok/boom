#include <stdio.h>
#include <string.h>

//#define print(format,...) fprintf(stderr,format,##__VA_ARGS__)
//#define print1(format,args...) fprintf(stderr,format,##args)

/*
   功能：     该函数采用移位实现10进制数转换成16进制数
   函数名：   to10_16
*/

void to10_16(int n)
{
    int a=n,n1,i;
    char ch[9];

    memset(ch,0,sizeof(ch));  //数组初始化

    /*通过移位实现数值转换*/
    for(i = 1;i <= 8;i++)
    {
        n1 = n-((n>>(4*i))<<(4*i));
        n = (n>>(4*i))<<(4*i);
        n1 = n1>>(4*(i-1));

        if(0 == n1)
            break;

        if(n1 < 10)
            ch[8-i] = n1+'0';
        else
            ch[8-i] = n1-10+'A';
    }

    ch[8] = '\0';

    //让p指向第一个非0的字符元素
    char *p = ch;
    while(0 == *p)p++;
    printf("%d(10) is 0x%s(16)\n",a,p);  //打印
} 

int main(void)
{
    int a,n,n1,i;
    char ch[9];

    memset(ch,0,sizeof(ch));

    scanf("%d",&a);
    to10_16(a);
    return 0;
}
