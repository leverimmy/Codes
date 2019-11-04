#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
int n,m;
int d[510][510];
int head,tail;
struct tt{int x,y;}list[2100000];
bool v[510][510];
int stx,sty,edx,edy;
char st[510][510];
void spfa()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            d[i][j]=999999;
    d[stx][sty]=0;
    memset(v,false,sizeof(v));v[stx][sty]=true;
    head=1;tail=2;list[1].x=stx,list[1].y=sty;
    while(head!=tail)
    {
        int x=list[head].x,y=list[head].y;
        for(int i=0;i<4;i++)
        {
            int tx=x+dx[i],ty=y+dy[i];
            if(tx<1||tx>n||ty<1||ty>m)continue;
            int t=0;
            if(st[tx][ty]!=st[x][y])t=1;
            if(d[tx][ty]>d[x][y]+t)
            {
                d[tx][ty]=d[x][y]+t;
                if(v[tx][ty]==false)
                {
                    v[tx][ty]=true;
                    list[tail].x=tx,list[tail++].y=ty;
                    if(tail==2100000)tail=1;

                }
            }
        }
        head++;
        if(head==2000000+1)head=1;
        v[x][y]=false;
    }
    printf("%d\n",d[edx][edy]);
}
int main()
{        freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)break;

        for(int i=1;i<=n;i++)
            scanf("%s",st[i]+1);

        scanf("%d%d%d%d",&stx,&sty,&edx,&edy);
        stx++;sty++;edx++;edy++;
        spfa();
    }
    return 0;
}
	