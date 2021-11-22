// 编写程序，计算
// 	e^x=1+x+(x^2)/(2!)+(x^3)/(3!)+(x^4)/(4!)+...+(x^n)/n!

// 说明：e^x表示e的x次方，2!表示2的阶乘

// 输入输出格式要求：
// 	输入格式：x n回车
// 	e^x, x, n均用double类型存储。
// 	要求输出小数点后6位。
// 	只输出运算结果，请不要输出其他字符，遇到异常情况（如n为负数），输出error
// 例如：
// 输入：3 10回车
// 输出：20.079665
// 输入：5.24 11回车
// 输出：187.210665
// 输入：5 -10
// 输出：error
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    double x,k=1,f=1,e,n;
    double a=1;
    scanf("%lf %lf",&x,&n);//double输入的话需要以lf来表示
    if(n < 0 || x<0)
        printf("error");
    else
    {
        for(int i = 1;i <= n;i++)
        {
        a *= x;
        k *= i;
        e = a/k;
        f += e;
        }

    printf("%.6lf",f);//保留小数点后6位
    }
    system("pause");
}