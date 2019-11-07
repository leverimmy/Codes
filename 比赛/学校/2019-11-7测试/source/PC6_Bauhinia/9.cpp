#include <bits/stdc++.h>
#define rgi register int
#define fin(s) freopen(s,"r",stdin)
#define fout(s) freopen(s,"w",stdout)
using namespace std;
int m,n,r,cnt,mx;
char tmp1,tmp2;
signed main()
{
	fin("9.in"),fout("9.out");
	scanf("%d%c%d%c%d",&m,&tmp1,&n,&tmp2,&r);
	bool flag=1;
	for(rgi i=m;i>=1;--i)
		if(i%n==r)
		{
			flag=0;
			mx=i;
			break;
		}
	if(flag)
		return 0;
	for(rgi i=1;i<mx;++i)
		if(i%n==r)
		{
			++cnt;
			printf("%d",i);
			if(cnt==10)
			{
				cnt-=10;
				putchar(10);
			}
			else
				putchar(',');
		}
	printf("%d",mx);
	return 0;
}

