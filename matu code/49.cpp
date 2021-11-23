// 输出由*组成的三角形。指定底边长度。第一排输出*，第二排输出***，每行中间需对齐，每行的最后一个*后输出回车。
// 输入边长(1-80中的奇数)，错误边长，输出error。
// 例如，
// 输入1，输出*回车
// 输入2，输出error
// 输入3，输出
//  *
// ***回车
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,j,k,i;
    scanf("%d",&n);
    if(n % 2 == 0 || n > 80 || n < 1)
    {
        printf("error\n");
    }
    else
    {
        for(i=1;2*i<=n+1;++i)
            {
                    for(j=(n+1)/2-i;j>0;j--)
                    {
                        printf(" ");
                    }              
                    for(k=0;k<(2*i)-1;k++)
                    {
                        printf("*");
                    }
                printf("\n");
            }    
    }
    system("pause");
    return 0;
}