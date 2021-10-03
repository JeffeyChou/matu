// 一个数如果恰好等于它的因子之和，就被成为完数。
// 例如6的因子为1,2,3，而6=1+2+3，所以6是一个完数。
// 编程找出1-1000之间的所有完数，并按照从小到大的顺序输出，输出的每个数都必须以回车结尾。
#include<stdio.h>
#include<stdlib.h>
int main()
{
       int i,n,m;
       m=0;
       for(i=1;i<=1000;i++)
        {                                                                                    
             for(n=1;n<i;n++)
            {
                if(i%n==0)
                m=n+m;               
            }
             n=1;
             if(i==m) 
                printf("%d\n",m);
             m=0;
        }
             system("pause");
             return 0;
}