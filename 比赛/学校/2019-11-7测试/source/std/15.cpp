#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000010;
int n;

struct node
{
	int x,pos;
}e[maxn];

bool cmp(node a,node b)
{
	return a.x > b.x;
}

int main()
{
	freopen("15.in","r",stdin);
	freopen("15.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d",&e[i].x);
		e[i].pos = i - 1;
	}
	sort(e + 1,e + 1 + n,cmp);
	printf("%d %d\n",e[1].x,e[1].pos);
	
	return 0;
}
