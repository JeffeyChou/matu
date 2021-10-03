// 输入2个整数（空格区分），输出最大公约数和最小公倍数（，逗号区分）
// 例如输入5空格10，输出应为5,10
#include<stdlib.h>
#include<stdio.h>
int main()
{
    int a,b,min,mode,max,multi,sum;
    scanf("%d%d",&a,&b);
    max=a>b?a:b;
    min=a>b?b:a;
    mode=max%min;
    while (mode!=0)
    {
        max=min>mode?min:mode;
        min=min>mode?mode:min;
        mode=max%min;
    }
    multi=a*b;
    sum = multi/min;
    printf("%d,%d",min,sum);
    system("pause");
    return 0;
}
