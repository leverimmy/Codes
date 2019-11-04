#include <cstdio>

using namespace std;

int r,c,cnt=1,kase=1;
char map[15][15];
int num[15][15];

int check_start(int i,int j)
{
	if(i-1<1 || j-1<1 || map[i-1][j]=='*' || map[i][j]=='*')
		if(map[i][j]!='*')
			return 1;
	return 0;
}

void print()
{
	for(int i=1;i<=r;i++)
	{
		for(int j=1;j<=c;j++)
			printf("%c",map[i][j]);
		printf("\n");
	}
	for(int i=1;i<=r;i++)
	{
		for(int j=1;j<=c;j++)
			printf("%3d",num[i][j]);
		printf("\n");
	}
}

void print_down(int i,int j)
{
    printf("%3d.",num[i][j]);
    for(int s=i;s<=r;s++)
    {
        if(map[s][j]=='*')
            break;
        else
            printf("%c",map[s][j]);
    }
}

void solve_down()
{	
	printf("\nDown\n");
	for(int i=1;i<=r;i++)
	    for(int j=1;j<=c;j++)
	        if(check_start(i,j) && (map[i-1][j]=='*'||i==1))
			{
				print_down(i,j);
				printf("\n");
			}
	//printf("\n");
}

void solve_across()
{	
	printf("Across");
	for(int i=1;i<=r;i++)
	{
		int head=1;
		for(int j=1;j<=c;j++)
		{
			if(head&&map[i][j]!='*')
			{
				printf("\n%3d.%c",num[i][j],map[i][j]);
				head=0;
			}
			else if(map[i][j]!='*')
				printf("%c",map[i][j]);
			else if(map[i][j]=='*')
			{
				if(j==c)
				{
					if(i==r)
						continue;
					else
					{
						i=i+1;j=0;
						head=1;
					}
				}
				else
				{
					head=1; 
					continue;
				}
			}
		}
	}
}

int main()
{
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	while(1)
	{
		cnt=1;
		scanf("%d",&r);
		if(r==0)
			break;
		scanf(" %d\n",&c);
		for(int i=1;i<=r;i++)
		{
			for(int j=1;j<=c;j++)
				scanf("%c",&map[i][j]);
			getchar();
		}
		for(int i=1;i<=r;i++)
			for(int j=1;j<=c;j++)
				if(i-1<1 || j-1<1 || map[i-1][j]=='*' || map[i][j-1]=='*')
					if(map[i][j]!='*')
						num[i][j]=cnt++;
		//print();
		if(kase==1)
			printf("puzzle #%d:\n",kase++);
		else
			printf("\npuzzle #%d:\n",kase++);
		solve_across();
		solve_down();
	}
	return 0;
}