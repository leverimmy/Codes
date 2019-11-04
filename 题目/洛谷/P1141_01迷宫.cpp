#include <cstdio>
#include <queue>
#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

int n,m,cnt;
int map[1010][1010];
int vis[1010][1010];

inline int read()
{
	int num = 0, w = 1; char c = 0;
	while (c != '-' && !isdigit(c)) c = getchar();
	if (c == '-') w = -1, c = getchar();
	while (isdigit(c)) num = num * 10 + c - '0', c = getchar();
	return num * w;
}
	
inline void write(int x)
{
	if (x < 0) putchar('-'), x = -x;
	if (x / 10) write(x / 10);
	putchar(x % 10 + '0');
}

void getmap()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
		{
			char ch=getchar();
            if(!isdigit(ch))
				ch=getchar();
			map[i][j]=ch-'0';
		}
}

struct node
{
    int x;
    int y;
};

queue <struct node> q;

void bfs(int x,int y)
{
    while(q.empty()==0)
    {
        int tx=q.front().x;
        int ty=q.front().y;
        int flag=map[tx][ty];
        if(tx-1>0 && map[tx-1][ty]==!flag && vis[tx-1][ty]==0)
        {
            struct node t_1;
            t_1.x=tx-1;
            t_1.y=ty;
			vis[t_1.x][t_1.y]=1;
            q.push(t_1);
            cnt++;
        }
        if(tx+1<=n && map[tx+1][ty]==!flag && vis[tx+1][ty]==0)
        {
            struct node t_2;
            t_2.x=tx+1;
            t_2.y=ty;
			vis[t_2.x][t_2.y]=1;
            q.push(t_2);
            cnt++;
        }
        if(ty+1<=n && map[tx][ty+1]==!flag && vis[tx][ty+1]==0)
        {
            struct node t_3;
            t_3.x=tx;
            t_3.y=ty+1;
			vis[t_3.x][t_3.y]=1;
            q.push(t_3);
            cnt++;
        }
        if(ty-1>0 && map[tx][ty-1]==!flag && vis[tx][ty-1]==0)
        {
            struct node t_4;
            t_4.x=tx;
            t_4.y=ty-1;
			vis[t_4.x][t_4.y]=1;
            q.push(t_4);
            cnt++;
        }
        q.pop();
    }
}

int main()
{
    n=read(),m=read();
	getmap();
    while(m--)
    {
		memset(vis,0,sizeof(vis));
        struct node t;
        t.x=read(),t.y=read();
        cnt=1;
        q.push(t);
		vis[t.x][t.y]=1;
        bfs(t.x,t.y);
		write(cnt);
		printf("\n");
    }
    return 0;
}