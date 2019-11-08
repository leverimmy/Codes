#include <bits/stdc++.h>
#define rgi register int
using namespace std;
const int maxn=1e5+5;
int n,m,nxt[maxn];
char a[maxn],b[maxn];
inline void gtnxt()
{
	nxt[0]=-1;
	for(rgi i=1,j=-1;i<=m;++i)
	{
		while(j>=0&&b[i]!=b[j+1])
			j=nxt[j];
		if(b[i]!=b[j+1])
			++j;
		nxt[i]=j;
	}
}
inline bool kmp()
{
	for(rgi i=0,j=-1;i<=n;++i)
	{
		while(j>0&&(j==m||a[i]!=b[j+1]))
			j=nxt[j];
		if(a[i]==b[j+1])
			++j;
		if(j==m)
			return 1;
	}
	return 0;
}
signed main()
{
	freopen("2.in","r",stdin);
	freopen("2.out","w",stdout);
	while(scanf("%s",a)!=EOF)
	{
		memset(nxt,0,sizeof(nxt));
		scanf("%s",b);
		n=strlen(a)-1,m=strlen(b)-1;
		gtnxt();
		bool p=kmp();
		if(p)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}

