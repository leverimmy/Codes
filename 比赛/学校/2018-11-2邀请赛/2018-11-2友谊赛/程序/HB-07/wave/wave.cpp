#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <cstring>

using namespace std;

const int N=50010;

struct Node
{
	int h,l;
	Node(int H=0,int L=0)
	{
		h=H;
		l=L;
	}
	bool operator<(const Node& b) const
	{
		return h<b.h;
	}
};

set<Node> a;

int n,x[N],y[N];
long long ans;

int main()
{
	freopen("wave.in","r",stdin);
	freopen("wave.out","w",stdout);
	
	int i;
	set<Node>::iterator p;
	Node t;
	
	scanf("%d",&n);
	
	for (i=1;i<=n;++i)
	{
		scanf("%d%d",x+i,y+i);
	}
	
	a.insert(Node(0x7fffffff,0));
	a.insert(Node(0,0x7fffffff));
	
	for (i=n;i>=1;--i)
	{
		t.h=y[i];
		t.l=x[i];
		p=a.lower_bound(t);
		ans=ans+t.l-p->l;
		--p;
		ans=ans+t.h-p->h;
		a.insert(t);
	}
	
	cout<<ans;
	
	return 0;
}
