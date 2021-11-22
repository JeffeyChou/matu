// 编写一个程序，找出1~N中的所有素数,其中1<N,N为整数。

// 输入输出格式要求：
// 	1.要求每个数后面都要输出逗号，
// 	  请不要输出其他字符

//  2.遇到异常情况，输出error
// 例如：
// 输入：5
// 输出：2,3,5,
// 输入：a
// 输出：error
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int resol(int n)
{
    for (int l=2;l<=n/2;++l)
    if (n%l == 0)
    {
        return 0;
    }
    return 1;
}
int main()
{
    int n,k=1;
    int ret = scanf("%d",&n);
    if (ret == 0 || n<=1)
    {
        printf("error");
    }
    else
    {
        for(int i= 2;i<=n;i++)
        {
            if (resol(i))
            {
                printf("%d,",i);
            }
        }
    }
}