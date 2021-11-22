// 题目3：输入n(n<100)个有序正数，请用折半查找算法，查找x在其中的位置。
// 例如,
// 输入:
// 5
// 1,2,3,4,5
// 2
// 输出:
// 2
// 测试集合中，x数一定在正数数组中。即不用处理错误逻辑。
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int m,score[100];
    int n,low=0,high,mid;
    scanf("%d",&n);
    high=n;
	for(int i=0;i<n;i++)
	{
		scanf("%d,",&score[i]);
	}
	scanf("%d",&m);
    mid=(high+low)/2;
	while(low<=high)
	{
	    if(m==score[mid])
	    {
			printf("%d",mid+1);
			break;
		}
	    if(score[mid] > m)
	        high = mid-1;
	    else if(score[mid] < m)
	        low = mid+1;
        mid = (low+high)/2;
	}

system("pause");
return 0; 
}
