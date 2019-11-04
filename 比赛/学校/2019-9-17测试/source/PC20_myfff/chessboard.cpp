#include <cstdio>
#include <cctype>
#include <cstring>
#define il inline
#define rgi register int
#define sp putchar(' ')
#define el putchar('\n')
using namespace std;
il int ri()
{
	register int o1=0;
	register bool o2=0;
	register char o3;
	while(!isdigit(o3=getchar()))
		o2|=o3=='-';
	while(isdigit(o3))
		o1=(o1<<1)+(o1<<3)+(o3^48),o3=getchar();
	return o2?-o1:o1;
}
il void wi(int o1)
{
	if(o1<0)
		putchar('-'),o1=-o1;
	rgi o2=o1/10;
	if(o2)
		wi(o2);
	putchar((o1-(o2<<1)-(o2<<3))^48);
}
bool a[105][105],book[105];
int n,match[105],ans;
il bool dfs(int x)
{
	for(rgi i=1;i<=n;++i)
		if(!book[i]&&a[x][i])
		{
			book[i]=1;
			if(!match[i]||dfs(match[i]))
			{
				match[i]=x;
				return 1;
			}
		}
	return 0;
}
signed main()
{
	freopen("chessboard.in","r",stdin);
	freopen("chessboard.out","w",stdout);
	n=ri();
	for(rgi i=1;i<=n;++i)
		for(rgi j=1;j<=n;++j)
		{
			char c=getchar();
			while(c!='.'&&c!='#')
				c=getchar();
			if(c=='.')
				a[i][j]=1;
		}
	for(rgi i=1;i<=n;++i)
	{
		memset(book,0,sizeof(book));
		if(dfs(i))
			++ans;
	}
	wi(ans);
	return 0;
}

