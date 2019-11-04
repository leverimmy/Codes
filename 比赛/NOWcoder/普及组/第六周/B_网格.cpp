#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int n,m,q;
char map[210][210];
char s[1010];

int main()
{
	scanf("%d %d %d",&n,&m,&q);
	getchar();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			map[i][j]=getchar();
		getchar();
	}
	while(q--)
	{
		int a,b,t=0;
		scanf("%d %d",&a,&b);
		while(a<=n && b<=m)
		{
			s[t++]=map[a++][b++];
		}
		sort(s,s+t);
		printf("%s\n",s);
		memset(s,0,sizeof(s));
	}
	return 0;
}