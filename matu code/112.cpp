// 编写程序，输入一个字符串，分别统计输出该字符串中的字母个数和数字个数。

// 输入输出格式要求：
// 	输入格式：string回车
// 例如：
// 输入：the day the month the year 123回车
// 输出：letters:21,digits:3
// 输入：aaabacad回车
// 输出：letters:8,digits:0
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    char s[60];
    int letter=0,digits=0,i=0;
    while ((s[i] =getchar()) != '\n')
    {
        if ((s[i] >= 'A') && (s[i] <= 'z'))
        {
            letter++;
        }
        if ((s[i] >= '0') && (s[i] <= '9'))
        {
            digits++;
        }
        i++;
    }
    printf("letters:%d,digits:%d",letter,digits);
    return 0;
}
