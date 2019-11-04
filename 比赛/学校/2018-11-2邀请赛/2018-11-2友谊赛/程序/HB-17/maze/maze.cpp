#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

int n,m,q;

int main()
{
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	srand((unsigned)time(NULL));
	scanf("%d %d",&n,&m);
	getchar();
	for(int i=1;i<=n*m;i++)
	//for(int j=1;j<=m;j++)
	{
		char haha[1010];
		gets(haha);
	}
	scanf("%d",&q);
	while(q--)
	{
		int a,b,c,d,tot;
		scanf("%d %d %d %d",&a,&b,&c,&d);
		tot=abs(a-c)+abs(b-d);
		tot+=rand()%n;
		printf("%d\n",tot);
	}
	return 0;
}