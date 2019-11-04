#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int m,n,T;
char map[60][1010];

void get()
{
	getchar();
	for(int i=1;i<=m;++i)
	{
		for(int j=1;j<=n;++j)
			scanf("%c",&map[i][j]);
		getchar();
	}
}

int _max(int a,int b,int c,int d)
{
	int s,t;
	s=a>=b?a:b;
	t=c>=d?c:d;
	return s>=t?s:t;
}

int main()
{
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		int ans=0;
		scanf("%d %d",&m,&n);
		get();
		for(int i=1;i<=n;++i)
		{
			int a,c,g,t;
			a=c=g=t=0;
			for(int j=1;j<=m;++j)
			{
				if(map[j][i]=='A')
					a++;
				else if(map[j][i]=='C')
					c++;
				else if(map[j][i]=='G')
					g++;
				else if(map[j][i]=='T')
					t++;
			}
			if(a==_max(a,c,g,t))
			{
				printf("A");
				ans=ans+c+g+t;
			}
			else if(c==_max(a,c,g,t))
			{
				printf("C");
				ans=ans+a+g+t;
			}
			else if(g==_max(a,c,g,t))
			{
				printf("G");
				ans=ans+a+c+t;
			}
			else if(t==_max(a,c,g,t))
			{
				printf("T");
				ans=ans+a+c+g;
			}
		}
		printf("\n");
		printf("%d\n",ans);
	}
	return 0;
}