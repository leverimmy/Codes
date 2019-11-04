#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;

const int maxn=10001;
int r[maxn];
int b[maxn];
int dis[1000][1000];
int ans;
int n,m;
bool vis[maxn];

inline int read(){
	int w=1,x=0,ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return w*x;
}

int main(){
	freopen("serves.in","r",stdout);
	freopen("serves.out","w",stdout);
	n=read(),m=read();
	for(register int i=1;i<=n;i++) r[i]=read();
	int x,y,z;
	memset(dis,0x3f3f3f,sizeof(dis));
	for(register int i=1;i<=m;i++){
		x=read(),y=read(),z=read();
		dis[x][y]=z;
		dis[y][x]=z;
	}
	for(register int i=1;i<=n;i++) dis[i][i]=0;
	for(register int k=1;k<=n;k++)
		for(register int i=1;i<=n;i++)
			for(register int j=1;j<=n;j++)
				if(dis[i][j]>dis[i][k]+dis[k][j]) dis[i][j]=dis[i][k]+dis[k][j];
	int cnt=0;
	int sum=0;
	int num=0;
	for(register int i=1;i<=n;i++){
		num=0;
		for(register int j=1;j<=n;j++){
			sum=cnt=0;
			for(register int k=1;k<=n;k++){
				if(dis[i][k]<=dis[i][j]){
					vis[k]=1;
					cnt++;
				}
			}
			for(register int k=1;k<=n;k++){
				if(vis[k]&&r[k]<=r[j]){
					vis[k]=0;
					sum++;
				} 
			}
			if(sum==cnt) num++;
		}
		b[i]=num;
	}			
	for(register int i=1;i<=n;i++) ans+=b[i];
	cout<<ans<<'\n';
	return 0;	
}
