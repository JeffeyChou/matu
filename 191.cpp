// 输入3个整数，用指针指向最大整数并输出
// 输入:
// 1 2 3
// 输出:
// 3
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
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
    n=3;
    p =(int * ) malloc(n * sizeof(int));
    if (p == NULL) return -1 ;
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&p[i]);
    }
    change(p,n);
        printf("%d",p[n-1]);
    return 0;
}
