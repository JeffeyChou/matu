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
struct Person
    {
        int no;
        int age;
        int height;
    };
void sort(Person * array,int n)
{
    if (array == NULL )
    {
        printf("error");
        return ;
    }
    int temp = 0 ,changed;
    for (int i = 0; i < n; i++)
    {
        changed=0;
        for (int j = 1; j <=n-i ; j++)
        {
            if ((array)->no > (array+1)->no)
            {
                temp = (array+1)->no;
                (array+1)->no = (array)->no;
                (array)->no = temp;
                changed = 1;
            }
            
            if ((array)->no = (array+1)->no)
            {   
                if ((array)->age > (array+1)->age)
                {
                    temp = (array+1)->age;
                    (array+1)->age = (array)->age;
                    (array)->age = temp;
                    changed = 1;
                }
                if ((array)->age = (array+1)->age)
                {
                    if ((array)->height > (array+1)->height)
                    {
                        temp = (array+1)->height;
                        (array+1)->height = (array)->height;
                        (array)->height = temp;
                        changed = 1;
                    }
                }
            }
        }
        array++;
        if (changed == 0)
        {
            break;
        }

    }
}
    

