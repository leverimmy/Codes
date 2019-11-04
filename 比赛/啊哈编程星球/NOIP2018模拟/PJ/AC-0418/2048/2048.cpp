#include <cstdio>

using namespace std;

int op,map[5][5];
char cmd[100010];

int main()
{
	freopen("2048.in","r",stdin);
	freopen("2048.out","w",stdout);
	for(int i=1;i<=4;i++)
		for(int j=1;j<=4;j++)
			scanf("%d",&map[i][j]);
	scanf("%d",&op);
	scanf("%s",cmd);
	for(int i=0;i<op;i++)
	{
		if(cmd[i]=='w')
		{
			for(int j=1;j<=4;j++)
				for(int k=1;k<=3;k++)
					if(map[j][k]==map[j][k+1])
					{
						map[j][k]*=2;
						for(int t=k+1;t<=4;t++)
							map[j][t]=map[j][t+1];
					}
			
		}
		else if(cmd[i]=='a')
		{
			for(int k=1;k<=4;k++)
				for(int j=1;j<=3;j++)
					if(map[j][k]==map[j+1][k])
					{
						map[j][k]*=2;
						for(int t=j+1;t<=4;t++)
							map[t][k]=map[t+1][k];
					}
		}
		else if(cmd[i]=='s')
		{
			for(int j=1;j<=4;j++)
				for(int k=4;k>=2;k++)
					if(map[j][k]==map[j][k-1])
					{
						map[j][k]*=2;
						for(int t=k-1;t>=1;k--)
							map[j][t]=map[j][t-1];
					}
		}
		else if(cmd[i]=='d')
		{
			for(int k=4;k>=1;k--)
				for(int j=4;j>=2;j--)
				if(map[j][k]=map[j-1][k])
				{
					map[j][k]*=2;
					for(int t=j-1;t>=1;t--)
						map[t][k]=map[t-1][k];
				}
		}
	}
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=4;j++)
			printf("%d ",map[i][j]);
		printf("\n");
	}
	return 0;
}