// 输出100~200之间不能被3整除也不能被7整除的数。
// 输出要求：
// 连续输出满足要求的数字，数字之间不能有任何符号。
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,k=99;
    for(i=0;i<100;i++)
    {
        k++;
        if(k%3!=0 && k%7!=0)
        printf("%d",k);
    }
    return 0;
}