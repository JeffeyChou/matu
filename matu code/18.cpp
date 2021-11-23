/* 输入一个大于3的整数n，判断它是否为素数。（输出yes/no）
例如，输入4，输出no；
输入7，输出yes。
错误输入，则输出error。所有输出没有回车符号。 */
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,k;
    scanf("%d",&n);
    if(n<=3)
        printf("error\n");
    else
    {
        for (k = 2; k<n; k++)
            {
                if (n%k == 0)
                break;
            }
        if(k<n)
            printf("no\n");
        else
            printf("yes\n");
    }
    system("pause");
    return 0;
}