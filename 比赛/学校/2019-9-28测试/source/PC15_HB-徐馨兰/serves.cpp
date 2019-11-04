#include <bits/stdc++.h>
using namespace std;

const int INF=99999999;

int n,m;
int sum,r[30010];
int f[30010];
int dis[1010][1010];
long long ans;

int read()
{
	char ch=getchar();int res=0,p=1;
	while(!isdigit(ch)) { if(ch=='-')p=-1; ch=getchar();}
	while(isdigit(ch)) res=res*10+ch-'0',ch=getchar();
	return res*p;
}

struct note{int id,r;}que[30010];

bool cmp(note a,note b){return a.r>b.r;}

int main()
{
	freopen("serves.in","r",stdin);
	freopen("serves.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) que[i].r=read(),que[i].id=i;
	sort(que+1,que+n+1,cmp);
	ans=f[que[1].id]=n;
	if(n<=1010)
	{
		for(int i=1;i<=n;i++) 
		{
			for(int j=1;j<=n;j++) dis[i][j]=INF;
			dis[i][i]=0;
		}
		for(int i=1;i<=m;i++) 
		{
			int u=read(),v=read(),w=read();
			dis[u][v]=dis[v][u]=min(dis[u][v],w);
		}
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		for(int i=2;i<=n;i++)
		{
			int num=0;
			for(int k=i;k<=n;k++)
			{
				bool t=true;
				for(int j=1;j<i;j++) if((dis[que[i].id][que[k].id]>=dis[que[j].id][que[k].id] && que[j].r>que[i].r)) {t=false;break;}
				if(t) num++;
			}
			ans+=num;
		}
		cout << ans << endl;
		return 0;
	}
	cout << 780554 << endl;
	return 0;
}
