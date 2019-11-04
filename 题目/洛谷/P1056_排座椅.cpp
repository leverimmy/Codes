#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <cstdlib>

using namespace std;

int m,n,k,l,d,x,y,p,q,t;
int countlie[1010];
int counthang[1010];
int lie[1010];
int hang[1010];
int maxa;

int main()
{
	scanf("%d %d %d %d %d",&m,&n,&k,&l,&d);
	for(int i=1;i<=d;i++)
	{
		scanf("%d %d %d %d",&x,&y,&p,&q);
		if(p==x && q==y+1)
			countlie[y]++;
		if(p==x && q==y-1)
			countlie[q]++;
		if(q==y && p==x+1)
			counthang[x]++;
		if(q==y && p==x-1)
			counthang[p]++;
	}
	for(int i=1;i<1010;i++)
	{
		int t;
		t=1009;
		maxa=1;
		for(int j=i;j<1010;j++)
		{
			if(counthang[j]>=maxa)
			{
				maxa=counthang[j];
				hang[t--]=j;
			}
		}
		maxa=1;
		t=1009;
		for(int j=i;j<1010;j++)
		{
			if(countlie[j]>=maxa)
			{
				maxa=countlie[j];
				lie[t--]=j;//这里有问题
			}
		}
	}
	for(int i=1009;i>=1;i--)
		if(hang[i]>0 && k>0)
		{
			k--;
			printf("%d ",hang[i]);
		}
	printf("\n");
	for(int i=1009;i>=1;i--)
		if(lie[i]>0 && l>0)
		{
			printf("%d ",lie[i]);
			l--;
		}
	return 0;
}