// main函数写成下面形式：
// struct node
// {
// int data;
// struct node *next;
// };
// int main(int data[],int n)；
// 然后以数组data里面的数据生成带头结点的单链表，头指针header作为main函数的返回值,需要将头指针转换为int返回。
// 定义头指针：struct node * header;那么main函数返回时需要return (int)header;
// header指针指向的单链表数据和data里面数据顺序一致。
// 比如data存放的数据是1 2 3,则n=3，且单链表header所指的数据结点的数据依次为1,2,3。
// 如果出现错误，则输出"error"，并返回NULL。
// 头结点定义如下：
// struct node
// {
// int data;
// struct node *next;
// };
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
struct node
{
    int data;
    struct node *next;
};
int mail1(int data[],int n);
void printlist(struct node *header);
void freelist(struct node *header);
int main()
{
    int n, *a;
    struct node *header;
    srand(unsigned(time(NULL)));
    scanf("%d",&n);
    a = (int*)malloc(n * sizeof(int));
    if (!a) return 0;
    for(int i = 0; i<n; ++i)
    {
        a[i]= rand() % 100;
    }
    header = (struct node *)mail1(a,n);
    printlist(header);
    freelist(header);
    return 0;
};
