#include <cstdio>

using namespace std;

int n,m,t;
char map[1010][1010];

void print_fell()
{
	printf("Aha fell out of the world\n");
}

void print_ate()
{
	printf("Aha ate himself\n");
}

struct node
{
	int x,y;
}alpha[110];

void print_map()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			printf("%c",map[i][j]);
		printf("\n");
	}
}

int main()
{
	scanf("%d %d %d\n",&n,&m,&t);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%c",&map[i][j]);
			if(map[i][j]!='@'&&map[i][j]!='.')
			{
				alpha[map[i][j]-'A'+1].x=i;
				alpha[map[i][j]-'A'+1].y=j;
			}
		}
		getchar();
	}
	while(t--)
	{
		char op;
		scanf("%c",&op);
		if(op=='W')
		{
			if(alpha[1].y==1)
			{
				print_fell();
				print_map();
				printf("W");
			}
			else if(map[alpha[1].x-1][alpha[1].y]=='@')
			{
				map[alpha[1].x-1][alpha[1].y]='A';
				for(int i=maxn;i>=2;i--)
				{
					alpha[i].x=alpha[i-1].x;
					alpha[i].y=alpha[i-1].y;
					
				}
			}
		}
	}
	return 0;
}