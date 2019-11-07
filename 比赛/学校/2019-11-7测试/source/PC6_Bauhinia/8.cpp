#include <bits/stdc++.h>
#define rgi register int
#define fin(s) freopen(s,"r",stdin)
#define fout(s) freopen(s,"w",stdout)
using namespace std;
int a,b,m;
char cnm1,cnm2;
bool calc(int x,int y)
{
	if(a*x+b*y<=m)
		return 1;
	else
		return 0;
}
signed main()
{
	fin("8.in"),fout("8.out");
	scanf("%d%c%d%c%d",&a,&cnm1,&b,&cnm2,&m);
	for(rgi i=1;i<=m;++i)
		for(rgi j=i;j<=m;++j)
			if(calc(i,j))
				printf("%d,%d\n",i,j);
	return 0;
}

