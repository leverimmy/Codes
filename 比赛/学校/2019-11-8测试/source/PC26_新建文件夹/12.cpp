#include <bits/stdc++.h>
using namespace std;
const int MAXN=100055;
char a[MAXN],b[MAXN];
int c[MAXN];
int main()
{
	freopen("12.in","w",stdin);
	freopen("12.out","r",stdout);
	while(scanf("%s",a)!=EOF)
	{
		scanf("%s",b);
		int len1=strlen(a);
		int len2=strlen(b);
		int now=0;
		int last=0;
		for(int i=len1;i>=1;i--)
		{
			now++;
			int u=0,v=0;
			if(len1-now>=0)
				u=a[len1-now]-'0';
			if(len2-now>=0)
				v=b[len2-now]-'0';
			u-=last;
			if(u<v)
			{
				u+=10;
				last=1;
			}
			else
			{
				last=0;
			}
			c[i]=u-v;
		}
		if(last)
		{
			printf("1");
		}
		for(int i=1;i<=len1;i++)
		{
			printf("%d",c[i]);
		}
	}
	return 0;
}

