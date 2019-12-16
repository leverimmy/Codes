#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n,m;
char p[100001];

int main()
{
	freopen("lcp.in","r",stdin);
	freopen("lcp.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	scanf("%s",p);
	
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		a--;
		b--;
		if(a<0)a=0;
		if(b<0)b=0;
		if(a==b)
		{
			printf("1\n");
			continue;
		}
		printf("%d\n",(strcmp(p+a,p+b)<0?0:1));
	}	
	
	return 0;
}
