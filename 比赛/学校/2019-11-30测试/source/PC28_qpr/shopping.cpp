#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
char a[12];
int n,cnt,book[1005],ans1,ans2,k;
struct blublu
{
	int c;
	int l;
	int num;
}_[1005],p[1005],q[1005];
bool cmp1(blublu x,blublu y)
{
	if(x.c!=y.c)
	{
		return x.c>y.c;
	}
	else
	{
		return x.l<y.l;
	}
}
bool cmp2(blublu x,blublu y)
{
	if(x.l!=y.l)
	{
		return x.l>y.l;
	}
	else
	{
		return x.c<y.c;
	}
}
int main()
{
	freopen("shopping.in","r",stdin);
	freopen("shopping.out","w",stdout);
	cin>>n>>a;
	for(int i=1;i<=n;i++)
	{
		cin>>_[i].c>>_[i].l;
		_[i].num=i;
	}
	sort(_+1,_+n+1,cmp1);
	for(int i=1;i<=n;i++)
	{
		p[i].num=_[i].num;
		p[i].c=_[i].c;
	}
	sort(_+1,_+n+1,cmp2);
	for(int i=1;i<=n;i++)
	{
		q[i].num=_[i].num;
		q[i].l=_[i].l;
	}
	if(a[0]=='C')
	{
		k=1;
	}
	else
	{
		k=2;
	}
	while(cnt<n)
	{
		cnt++;
		if(k%2==1)
		{
			for(int i=1;i<=n;i++)
			{
				if(book[p[i].num]==0)
				{
					ans1+=p[i].c;
					book[p[i].num]=1;
					break;
				}
			}
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				if(book[q[i].num]==0)
				{
					ans2+=q[i].l;
					book[q[i].num]=1;
					break;
				}
			}
		}
		k++;
	}
	cout<<ans1<<" "<<ans2;
	return 0;
}
/*
7
Lagrange
4 1
3 1
2 1
1 1
1 2
1 3
1 4
*/
