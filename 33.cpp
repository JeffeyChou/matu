// 实现字符串的拷贝。

// void my_strcpy(char * destination,char * source);
// 将source指向的字符串拷贝到destination指向的位置。

// 注意：使用空格字符来表示字符串的结束。
// 例如source指向位置，依次保存了字符'a'，字符'b'，字符空格' '，字符'c'，则source指向的字符串为"ab"。


// 遇到异常情况，输出"error"；否则不要随意输出，会视为错误
#include<stdio.h>
void my_strcpy(char * destination,char * source){
    if(destination == NULL||source ==NULL){
        printf("error");
        return;
    }
    char *p1 = destination, *p2 = source;
    while((*p1++ = *p2++) != ' ');
}

