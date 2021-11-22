// 编写程序，输入一个字符串，分别统计输出该字符串中的字母a和d的个数。

// 输入输出格式要求：
// 	输入格式：string回车
// 例如：
// 输入：thedaythemonththeyear123回车
// 输出：a:2,d:1
// 输入：a
// 输出：a:1,d:0
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char strings[50];
    int i=0,maxa = 0,maxd = 0;
    scanf("%s",&strings[i]);
    do
    {
        if (strings[i]=='a' || strings[i]=='A')
        {
            maxa++;
        }
        if (strings[i]=='d' || strings[i]=='D')
        {
            maxd++;
        }
        i++;
    } while (strings[i] !='\0');
    printf("a:%d,d:%d",maxa,maxd);
    return 0 ;
}