#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;
struct operate
{
	int x,b,s;
}t[200001];

vector<pair<int,int> >v,v2;
void out()
{
	int pre=v.size()==1?0:v[v.size()-2].first;
	printf("%lld %lld\n",pre+1,v.back().second);
}
signed main()
{
	freopen("dance.in","r",stdin);
	freopen("dance.out","w",stdout);
	int tmp,m;
	scanf("%lld%lld",&tmp,&m);
	t[1].x=1,t[1].b=tmp;
	for(int i=2;i<=m+1;i++)
	{
		scanf("%lld",&t[i].x);
		if(t[i].x==1||t[i].x==2)
			scanf("%lld",&t[i].b);
		else
			scanf("%lld%lld",&t[i].b,&t[i].s);
	}
	m++;
	for(int p=1;p<=m;p++)
	{
		if(t[p].x==1)
		{
			int pre=v.size()==0?0:v.back().first;
			v.clear();
			v.push_back(make_pair(pre+t[p].b,0));
		}
		else if(t[p].x==2)
		{
			if(v.size()&&v.back().second==0)
				v.back().first+=t[p].b;
			else
			{
				int pre=v.size()==0?0:v.back().first;
				v.push_back(make_pair(pre+t[p].b,0));
			}
		}
		else
		{
			for(int i=0;i<v.size();i++)
				v[i].second+=((i==0?0:v[i-1].first))*t[p].s+t[p].b;
			int pre=inf;
			for(int i=0;i<v.size();i++)
			{
				if(v[i].second>=pre)
				{
					v2.back().first=v[i].first;
					continue;
				}
				v2.push_back(v[i]);
				pre=v[i].second;
			}
			swap(v,v2);
			v2.clear();
		}
		if(p!=1)out();
	/*	printf("------------*\n");
		for(int i=0;i<v.size();i++)
		{
			printf("%d %d\n",v[i].first,v[i].second);
		}
		printf("------------*\n\n");*/
	}
	return 0;
}
/*
*/