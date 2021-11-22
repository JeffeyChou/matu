// 输入正整数n（1-10）,求1-n的阶乘之和，最后必须输出回车。遇到异常情况（如不是1-10中数），输出"error"；否则不要随意输出。
// 例如，输入4，输出33；
// 输入7，输出5913回车。
#include<stdio.h>
int main()
{
    int n,i,sum,a=1;
    scanf("%d",&n);
    if (n<=10 && n>=1)
    {
        for(i=1,sum=0;i<=n;i++)
        {a*=i;sum+=a;}
        printf("%d\n",sum);
    }
    else
        printf("error");
    return 0;
}