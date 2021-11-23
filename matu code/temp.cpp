
// 写函数/程序实现击鼓传花:小明今年生日邀请了一群朋友,总共n个人(5<=n<=20人)一起玩击鼓传花的游戏
//随机数ⅹ秒(2<=ⅹ<=5),这个人需要随机喝y杯啤酒(1<=y<=3),每1瓶啤酒可以倒3杯,每瓶啤酒5元钱,玩了z(10<=z<=30)次
// 之后结账。如果给这些人按照1到n标号,哪些人喝过啤酒?按照编号递增顺序输出喝过啤酒的人的编号及他喝的总的啤酒杯数。最后输出小明需要付款多少
//作答end
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
struct info
{
    int num;
    int sum;
}pp[20];
int main()
{
    int n=0,x=0,y=0,z=0,sum=0,temp=0,tt=0;
    scanf("%d %d %d %d",&n,&x,&y,&z);
    if ((x>=2 && x<=5) && (y>=1 && y<=3) && (z>=10 && z<=30))
    {
        pp[0].num=0;
        pp[0].sum=0;
        temp = x;
        for (int i = 1; i < n; i++)
        {
            pp[i].num=i;
            pp[i].sum=0;
        }
        for (int j = 1; j <=z ; j++)
        {
            for (int i = 1; i <= n; i++)
            {
               if ( pp[i].num=temp)
               {
                   pp[i].sum+=y;
                   tt+=y;
               }
            }
            temp +=x;
            temp=temp%n;
        }
        for (int l = 1; l <= n; l++)
        {
            printf("code=%d,drinking time=%d/n",pp[l].num,pp[l].sum);
        }
        int price = 0;
        int t = tt%3;
        if (t=0)
        {
            price=tt*5/3;
        }
        else
        {
            price = (tt-t)/3*5+5;
        }
        printf("price=%d",price);
        return 0;
    }
    else
    {
        printf("error/n");
        return 0;
    }


}

