// 编写程序，输入两个字符串，比较他们是否相等。
// 输入输出格式要求：
// 	输入格式：string1回车string2回车
// 	string1和string2最长为256，可能包含空格
	
// 例如：
// 输入：string1回车string2回车
// 输出：unequal
// 输入：string1回车string1回车
// 输出：equal
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    char s1[257],s2[257];
    char *p=s1,*q=s2;
    int n=0;
    
    while (*p != '\n' && *q != '\n')
    {
        if (*p == *q)
        {
            p++;
            q++;
        }
        else
        {
            n=1;
            break;
        }
        ;
    }
    if (n =='1')
    {
        printf("unqual\n");
    }
    else
    {
        printf("equal\n");
    }
    return 0;
}

