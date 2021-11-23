// 编写程序，输入整数n，动态分配保存n个整数的存储器，然后输入n个整数保存到存储器中。最后，将这n个整数从小到大输出。
// 例如：
// 输入如下：
// 10回车
// 10 9 8 7 6 5 4 3 2 1回车
// 则输出
// 1,2,3,4,5,6,7,8,9,10
#include<stdio.h>
#include<stdlib.h>
void change(int a[], int n)
{
    int j,k,temp;
    for (int j = 0; j < n; j++)
    {
        for (int k = 0; k < n-j-1; k++)
        {
            if (a[k] > a[k+1])
            {
                temp = a[k+1];
                a[k+1]=a[k];
                a[k]=temp;
            }
        }
    }
}
int main()
{
    int n,*p,temp;
    scanf("%d",&n);
    p =(int * ) malloc(n * sizeof(int));
    if (p == NULL) return -1 ;
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&p[i]);
    }
    change(p,n);
    for (int l = 0; l < n; l++)
    {
        printf("%d",p[l]);
        if (l != n-1)
        {
            printf(",");
        }
    }
    return 0;
}
