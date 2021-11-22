// 对结构体数组进行排序。

// 题目描述：
// struct Person{
// 　　int no;
// 　　int age;
// 　　int height;
// }
// 实现sort方法对结构体数组进行排序。
// void sort(Person * array,int n);

// 根据no从小到大排序；如果no相同则根据age排序；如果age相同，则根据height排序。

// 注意：
// 遇到异常情况，输出"error"；否则不要随意输出，会视为错误。
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct Person
    {
        int no;
        int age;
        int height;
    };
void sort(Person * array,int n)
{
    int i,j;
    Person t;
    if (array != NULL && n >0)
    {
            for(i=0;i<n-1;++i)
        {
            for(j=0;j<n-i-1;++j)
            {
                if(array[j].no>array[j+1].no)
                {
                    t=array[j];
                    array[j]=array[j+1];
                    array[j+1]=t;
                }
                else if(array[j].no==array[j+1].no&&array[j].age>array[j+1].age)
                {
                    t=array[j];
                    array[j]=array[j+1];
                    array[j+1]=t;
                }
                else if(array[j].no==array[j+1].no&&array[j].age==array[j+1].age&&array[j].height>array[j+1].height)
                {
                    t=array[j];
                    array[j]=array[j+1];
                    array[j+1]=t;
                }
            }
        }
    }
    else
    {
        printf("error");
    }
}

    

