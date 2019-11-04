#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

long long n,m,t,q,len;
long long d,r;
char s[100010];

void get()
{
	for(int i=0;i<=len;i++)
	{
		if(s[i]=='U')
			d--;
		else if(s[i]=='D')
			d++;
		else if(s[i]=='L')
			r--;
		else if(s[i]=='R')
			r++;
	}
	d=t*d;r=t*r;
	return;
}

int main()
{
	scanf("%lld %lld %lld",&n,&m,&t);
	scanf("%s",s);
	scanf("%lld",&q);
	len=strlen(s);
	get();
	while(q--)
	{
		long long startx,starty;
		scanf("%lld %lld",&startx,&starty);
		long long endx,endy;
		endx=((startx+d)%n+n-1)%n+1;
		endy=((starty+r)%m+m-1)%m+1;
		printf("%lld %lld\n",endx,endy);
	}
	return 0;
}