#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
struct _
{
	int t;
	int p;
};
int P[10005][10005],book[100005];
int main()
{
	struct _ a[100005];
	int n,l,sum=0;
	cin >> n >> l;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i].t >> a[i].p;
	}
	for(int i=1;i<=n;i++)
	{
		book[a[i].t]++;
		P[a[i].t][book[a[i].t]]=a[i].p;
	}
	for(int i=1;i<=n;i++)
	{
		if(book[a[i].t]!=0)
		{
			for(int j=1;j<=book[a[i].t];j++)
			{
				sum+=abs(P[a[i].t][(book[a[i].t]+1)/2]-P[a[i].t][j]);
			}
		}
	}
	cout << sum;
	return 0;
}
