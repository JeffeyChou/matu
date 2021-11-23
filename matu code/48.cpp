// 描述
// 将输入的10个整数，按从小到大的顺序输出（使用,作为间隔）。
// 注意：1、逗号为英文输入法中逗号；2、任意多余输出视为错误。例如
// 输入
// 10 9 8 7 6 5 4 3 2 1
// 输出
// 1,2,3,4,5,6,7,8,9,10
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int num[10],max,min,high,low;
    for (int i = 0; i < 10; i++)
    {
        scanf("%d",&num[i]);
    }
    for (int n = 9; n > 0; n--)
    {
        for (int nn = 0; nn < n+1; nn++)
        {
        if (num[nn]>num[nn+1])
        {
            high=num[nn];
            low=num[nn+1];
            num[nn+1]=high;
            num[nn]=low;
        }
        }
    }
    for (int m = 0; m < 9; m++)
    {
        printf("%d",num[m]);
        printf(",");
    }
    printf("%d",num[9]);
    return 0;
}