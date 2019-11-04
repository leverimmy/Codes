#include <stdio.h>
#include <stdlib.h>
int max(int a,int b)
{
	return a>b?a:b;
}//定义max函数
int min(int a,int b)
{
	return a<b?a:b;
}//定义min函数
struct spot
{
	int dis1;
    int dis2;
}r[1000000],t;//用结构体来存储每个点到两套导弹拦截系统的距离，大一点，不会死
void quicksort(int left,int right)
{
	int i,j,mid;
    i=left;j=right;
    mid=r[(left+right)/2].dis1;//注意这里是根据到第一个拦截系统的距离来从小到大排的序
    do
    {
		while(r[i].dis1<mid)//这里也是
			i++;
        while(r[j].dis1>mid)//这里也是
			j--;
        if(i<=j)
        {
			t=r[i];
            r[i]=r[j];
            r[j]=t;
            i++;
            j--;
        }
    }while(i<=j);
    if(left<j)
		quicksort(left,j);
    if(right>i)
		quicksort(i,right);
}//快速排序
int main()
{
	int a,b,c,d,x,y,n,i,r2=0,sum=100000;
    //r2是第二个拦截系统的半径，初值为0，也就是把第二个拦截系统关闭，只有第一个拦截系统
    //sum设大一点
    scanf("%d %d %d %d %d",&a,&b,&c,&d,&n);
    for(i=1;i<=n;i++)
	{
    	scanf("%d %d",&x,&y);
        r[i].dis1=(x-a)*(x-a)+(y-b)*(y-b);//两点间的距离公式，这里为了避免小数，就把根号去掉了，比较他们的平方
        r[i].dis2=(x-c)*(x-c)+(y-d)*(y-d);
    }
    quicksort(1,n);
    sum=r[n].dis1;//假设都由第一个管
    for(i=n;i>1;i--)
    {
		r2=max(r2,r[i].dis2);//逐个增大r2的值，也就是把第二个拦截系统的半径扩大
        sum=min(sum,r[i-1].dis1+r2);//如果sum比以前的要小，就更新
    }
    printf("%d",sum);//输出
	system("pause");
	return 0;
}
