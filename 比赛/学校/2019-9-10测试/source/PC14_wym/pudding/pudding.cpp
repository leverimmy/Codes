#include<bits/stdc++.h>
using namespace std;
long long num,n,m,t1,t2,t3,x,prev=-1;
struct pudding
{
	long long col,nxt;
}pd[100010];
inline void update(int bas,int tgt)
{
	if(bas==tgt)
		return;
	int now=1;
	while(pd[now].nxt!=0)
	{
		if(pd[now].col==bas)
		{
			pd[now].col=tgt;
			if(pd[pd[now].nxt].col==tgt)
			{
				pd[now].nxt=pd[pd[now].nxt].nxt;
				num--;
			}
		}
		now=pd[now].nxt;
	}
	if(pd[now].col==bas)
		pd[now].col=tgt;
	now=1;
	while(now)
	{
		while(pd[now].col==pd[pd[now].nxt].col)
		{
			pd[now].nxt=pd[pd[now].nxt].nxt;
			num--;
		}
		now=pd[now].nxt;
	}
}
int main()
{
	freopen("pudding.in","r",stdin);
	freopen("pudding.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		if(x!=prev)
		{
			pd[++num].col=x;
			pd[num-1].nxt=num;
			prev=x;
		}
	}
	pd[num].nxt=0;
	int now=1;
	for(int i=1;i<=m;i++)
	{
		cin>>t1;
		switch(t1)
		{
			case 2:
			{
				cout<<num<<endl;
				break;
			}
			case 1:
			{
				cin>>t2>>t3;
				update(t2,t3);
				break;
			}
		}
	}
}
