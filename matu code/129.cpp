// 根据历法，凡是1、3、5、7、8、10、12月，每月31天；凡4、6、9、11月，每月30天；2月闰年29天，平年28天。
// 闰年判断方法是：
//   如果年号能被400整除，此年为闰年
//   如果年号能被4整除，而不能被100整除，此年为闰年；
//   否则不是闰年。
//  程序输入年、月，输出该月的天数。如果月份不为1~12之间的数字则转换为正确的月份，如13对应1月，不考虑月份为负数的情况。
//  例如：
//  输入：1992 3
//  输出：days:31

//  输入：2001 14
//  输出：days:28
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int mm,yy,aa=0;
    scanf("%d%d",&yy,&mm);
    while (mm>12)
    {
         mm-=12;
    }
    if (yy%400==0 || (yy%4==0 && yy%100!=0))
    {
        aa=1;
    }
    switch(mm)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            printf("days:%d",31);
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            printf("days:%d",30);
            break;
        case 2:
            {
                switch (aa)
                {
                case 0:
                    printf("days:%d",28);
                    break;
                default:
                    printf("days:%d",29);
                    break;
                }
            }
            break;
    }
    system("pause");
    return 0;
}