//
//他想买的物品一共有n个，编号从1号到n号。现在有m个商店，同一个物品在不同商店的价格不同。
//standout inpput
//第一行数有两个，n,m。
//接下来m行，每一行有个n个整数，第i行中第j个数，表示第i个商店中j号物品的价格，缺货为-1.
//standard output
//一个整数，表示bensnahuan最少需要的钱。
//
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int **a;
    a = (int**)malloc(sizeof(int*)*m);
    for (int i = 0; i < n; i++)
    {
        a[i] = (int*)malloc(sizeof(int)*n);
    }
    for (int j = 0; j < m; j++)
    {
        for (int k = 0; k<n;k++)
        {
            scanf("%d",&a[j][k]);
        }
    }
    int price = 0 ;
        for (int k = 0; k < m;k++)
    {
        int min =100;
        for (int j = 0; j<n;j++)
        {
            if (a[j][k] >0 && a[j][k] < min)
            {
                min = a[j][k];
            }
        }
        price += min ;
    }
    printf("%d",price);
    return 0;
}
