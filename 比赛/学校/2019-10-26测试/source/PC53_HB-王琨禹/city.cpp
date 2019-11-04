#include <bits/stdc++.h>
using namespace std;
const int MAXN=500000;
int a[MAXN];
int sum;
int num[MAXN];
int N;
int book[MAXN];
int cnt;
int ans[100][100];
int now[MAXN];
int _count;
int main()
{
	freopen("city.in","r",stdin);
	freopen("city.out","w",stdout);
	scanf("%d",&N);
	for(int i=1;i<=N*(N-1)/2;i++)
	{
		scanf("%d",a+i);
		sum+=a[i];
		book[a[i]]++;
	}
	sum/=(N-1);
	if(N==3)
	{
		for(int i=1;i<=20;i++)
		{
			for(int j=i;j<=20;j++)
			{
				for(int k=j;k<=20;k++)
				{
						memset(now,0,sizeof(now));
					now[i+j]++;
					now[i+k]++;
					now[j+k]++;
					if(now[i+j]==book[i+j]&&now[i+k]==book[i+k]&&now[j+k]==book[j+k])
					{
						_count++;
						ans[_count][1]=k;
						ans[_count][2]=j;
						ans[_count][3]=i;
					}
				}
			}
		}
	}
	if(N==4)
	{
		
		for(int i=1;i<=20;i++)
		{
			for(int j=i;j<=20;j++)
			{
				for(int k=j;k<=20;k++)
				{
					for(int p=k;p<=20;p++)
					{
						memset(now,0,sizeof(now));
						now[i+j]++;
						now[i+k]++;
						now[i+p]++;
						now[j+k]++;
						now[j+p]++;
						now[k+p]++;
						if(now[i+j]==book[i+j]&&now[i+k]==book[i+k]&&now[i+p]==book[i+p]&&now[j+k]==book[j+k]&&now[j+p]==book[j+p]&&now[k+p]==book[k+p])
						{
							_count++;
							ans[_count][1]=p;
							ans[_count][2]=k;
							ans[_count][3]=j;
							ans[_count][4]=i;
						}
					}
				}
			}
		}
	}
	if(N==5)
	{
		
		for(int i=1;i<=20;i++)
		{
			for(int j=i;j<=20;j++)
			{
				for(int k=j;k<=20;k++)
				{
					for(int p=k;p<=20;p++)
					{
						for(int w=p;w<=20;w++)
						{
						memset(now,0,sizeof(now));
						now[i+j]++;
						now[i+k]++;
						now[j+k]++;
						now[i+p]++;
						now[j+p]++;
						now[k+p]++;
						now[i+w]++;
						now[j+w]++;
						now[k+w]++;
						now[p+w]++;
							if(now[i+j]==book[i+j]&&now[i+k]==book[i+k]&&now[i+p]==book[i+p]&&now[i+w]==book[i+w]&&now[j+k]==book[j+k]&&now[j+p]==book[j+p]&&now[j+w]==book[j+w]&&now[k+p]==book[k+p]&&now[k+w]==book[k+w]&&now[p+w]==book[p+w])
							{
								_count++;
								ans[_count][2]=p;
								ans[_count][3]=k;
								ans[_count][4]=j;
								ans[_count][5]=i;
								ans[_count][1]=w;
							}
						}
					}
				}
			}
		}
	}
	
	printf("%d\n",_count);
	for(int i=_count;i>=1;i--)
	{
		for(int j=N;j>=1;j--)
		{
			printf("%d ",ans[i][j]);
		}
		putchar('\n');
	}
	return 0;
}
