// 编写学生管理系统，其中学生的信息有姓名（汉语拼音，最多20个字符），性别（男/女，用1表示男，2表示女）、
// 生日（19850101（年月日））、身高（以m为单位），还需要处理C语言、微积分两门课的成绩，请编写程序实现功能：
// 输入学生的人数和每个学生的信息；输出每门课程的总平均成绩、最高分和最低分，以及获得最高分的学生的信息。
// 需要注意的是某门课程最高分的学生可能不只一人。

// 输入输出格式要求：
// 	身高输出时保留两位小数，请按照例子中进行输出，请勿输出其他字符
// 例如：
// 输入：3 zhangsan 1 19910101 1.85 85 90 lisi 1 19920202 1.56 89 88 wangwu 2 19910303 1.6 89 90回车
// 输出：
// C_average:87回车
// C_max:89回车
// lisi 1 19920202 1.56 89 88回车
// wangwu 2 19910303 1.60 89 90回车
// C_min:85回车
// Calculus_average:89回车
// Calculus_max:90回车
// zhangsan 1 19910101 1.85 85 90回车
// wangwu 2 19910303 1.60 89 90回车
// Calculus_min:88回车
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <conio.h>
int main()
{
    int c_av=0,c_max=0,c_min=100,cal_av=0,cal_max=0,cal_min=100,num,ccc_all=0,cal_all=0;
    struct info
    {
        char name[30];
        int gender;
        char birthday[10];
        double height;
        int ccc;
        int cal;
    }stu[1000];
    scanf("%d",&num);
    for (int i = 0; i < num; i++)
    {
        scanf("%s%d%s%lf%d%d",stu[i].name,&stu[i].gender,stu[i].birthday,&stu[i].height,&stu[i].ccc,&stu[i].cal);
        ccc_all+=stu[i].ccc;
        cal_all+=stu[i].cal;
        if (c_max <= stu[i].ccc )
        {
            c_max=stu[i].ccc;
        }
        if (c_min >= stu[i].ccc)
        {
             c_min=stu[i].ccc;
        }
        if (cal_min >= stu[i].cal)
        {
             cal_min=stu[i].cal;
        }
        if (cal_max <= stu[i].cal)
        {
             cal_max=stu[i].cal;
        }
    }
    c_av=ccc_all/num;
    cal_av=cal_all/num;
    printf("C_average:%d\n",c_av);
    printf("C_max:%d\n",c_max);
    for (int j = 0; j < num; j++)
    {
        if (stu[j].ccc == c_max)
        {
            printf("%s %d %s %.2lf %d %d\n",stu[j].name,stu[j].gender,stu[j].birthday,stu[j].height,stu[j].ccc,stu[j].cal);
        }
    }
    printf("C_min:%d\n",c_min);
    printf("Calculus_average:%d\n",cal_av);
    printf("Calculus_max:%d\n",cal_max);
    for (int k = 0; k < num; k++)
    {
        if (stu[k].cal == cal_max)
        {
            printf("%s %d %s %.2lf %d %d\n",stu[k].name,stu[k].gender,stu[k].birthday,stu[k].height,stu[k].ccc,stu[k].cal);
        }
    }
    printf("Calculus_min:%d\n",cal_min);
    return 0;
}
