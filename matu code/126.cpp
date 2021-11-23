// 求n!(n由键盘输入)，当结果将要超出表示范围时退出（以32位机器为例），显示溢出前的n以及n!结果。
// 输入输出示例：
// 输入:
// 5
// 输出:
// 5!=120
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,d=1;
    scanf("%d",&n);
    if(n<0)
    printf("error");
    else if(n>=13)
    printf("12!=479001600");
    else
    {
        for(int i=1;i<=n;++i)
        {
            d*=i;
        }
    printf("%d!=%d",n,d);
    }    
    system("pause");
    return 0;
}