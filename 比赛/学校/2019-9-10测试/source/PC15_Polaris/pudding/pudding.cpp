#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<map>
#include<stack>
#include<cctype>
using namespace std;
const int inf=0x3f3f3f3f;
const int Maxn=2020000;
int col[Maxn],n,m,ccc;
vector <int> pos[Maxn];
inline int read()
{
	int x=0,f=1;char s=getchar();
	while (!isdigit(s))
	{
		if (s=='-')
		{
			f=-1;
		}
		s=getchar();
	}
	while (isdigit(s))
	{
		x=(x<<1)+(x<<3)+(s^48);
		s=getchar();
	}
	return x*f;
}
int main()
{
	freopen("pudding.in","r",stdin);
	freopen("pudding.out","w",stdout);
	n=read();
	m=read();
	int pre=-inf,x;
	for (int i=1;i<=n;i++)
	{
		x=read();
		if (x!=pre)
		{
			col[++ccc]=x;
			pos[x].push_back(ccc);
		}
		pre=x;
	}
	for (int i=1;i<=m;i++)
	{
		int move=read();
		if (move==1)
		{
			int a=read(),b=read();
			for (int j=0;j<pos[a].size();j++)
			{
				col[pos[a][j]]=b;
				if (col[pos[a][j]]==col[pos[a][j]-1]&&(j==0||pos[a][j-1]!=pos[a][j]-1))
				{
					ccc--;
				}
				if (col[pos[a][j]]==col[pos[a][j]+1])
				{
					ccc--;
				}
				pos[b].push_back(pos[a][j]-1);
				sort(pos[b].begin(),pos[b].end());
			}
			pos[a].clear();
		}
		else
		{
			printf("%d\n",ccc);
		}
	}
	return 0;
}
