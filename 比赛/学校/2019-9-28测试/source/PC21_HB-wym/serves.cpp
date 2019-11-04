#include<bits/stdc++.h>
using namespace std;
int n,m,r[100010],dis[1010][1010],t1,t2,t3;
long long ans;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
	{
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
	{
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
int main()
{
	freopen("serves.in","r",stdin);
	freopen("serves.out","w",stdout);
	memset(dis,0x3f,sizeof(dis));
	n=read(),m=read();
	for(int i=1;i<=n;i++)
		r[i]=read(),dis[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		cin>>t1>>t2>>t3;
		dis[t1][t2]=min(dis[t1][t2],t3);
		dis[t2][t1]=min(dis[t2][t1],t3);
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			++ans;
			for(int k=1;k<=n;k++)
				if(dis[i][k]<=dis[i][j]&&r[k]>r[j])
				{
					--ans;
					break;
				}
		}
	cout<<ans;
	return 0;
}
