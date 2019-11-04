#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int kase=1;
char test;
char map[10][10];
char cmd[10010];

void _swap(int a,int b,int c,int d)
{
	int s=map[a][b];
	int t=map[c][d];
	map[a][b]=t;
	map[c][d]=s;
}

void print()
{
	for(int i=1;i<=5;i++)
	{
		for(int j=1;j<=5;j++)
			printf("%c",map[i][j]);
		printf("\n");
	}
}

int main()
{	
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	while(1)
	{
		memset(cmd,'\0',sizeof(cmd));
		if(kase>1)	getchar();
		test=getchar();
		if(test=='Z')
			return 0;
		if(kase!=1)	printf("\n");
		map[1][1]=test;
		for(int i=1;i<=5;i++)
		{
			for(int j=1;j<=5;j++)
			{
				if(i==1 && j==1)
					continue;
				map[i][j]=getchar();
			}
			getchar();
		}
		//print();
		int x,y;
		for(int i=1;i<=5;i++)
			for(int j=1;j<=5;j++)
				if(map[i][j]==' ')
				{
					x=i;y=j;
				}
		int len=0;
		while(1)
		{
			char ch;
			cin>>ch;
			if(ch=='0')
				break;
			cmd[len++]=ch;
		}
		int flag=1;
		for(int i=0;i<len;i++)
		{
			if(cmd[i]=='A')
			{
				if(x-1<1)
				{
					flag=0;
					break;
				}
				_swap(x,y,x-1,y);
				x=x-1;
			}
			else if(cmd[i]=='B')
			{
				if(x+1>5)
				{
					flag=0;
					break;
				}
				_swap(x,y,x+1,y);
				x=x+1;
			}
			else if(cmd[i]=='L')
			{
				if(y-1<1)
				{
					flag=0;
					break;
				}
				_swap(x,y,x,y-1);
				y=y-1;
			}
			else if(cmd[i]=='R')
			{
				if(y+1>5)
				{
					flag=0;
					break;
				}
				_swap(x,y,x,y+1);
				y=y+1;
			}
			else
			{
				flag=0;
				break;
			}
		}
		printf("Puzzle #%d:\n",kase++);
		if(!flag)
			cout<<"This puzzle has no final configuration."<<endl;
		else
            for(int i=1;i<=5;i++)
            {
                for(int j=1;j<=5;j++)
                {
                    if(j==1)
                        cout<<map[i][j];
                    else
                        cout<<" "<<map[i][j];
                }
                cout<<endl;
            }
    }
    return 0;
}