#include<cstdio>
#define maxn 1005
#define re register
using namespace std;

inline int read(){
	int s=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=(s<<3)+(s<<1)+ch-'0';
		ch=getchar();
	}
	return s*f;
}

int n,m;

int a[maxn][maxn],dp[maxn][maxn],way[maxn][maxn];

int min(int x,int y){
	return x>y?y:x;
}

int main()
{
	freopen("lemouse.in","r",stdin);
	freopen("lemouse.out","w",stdout);
	n=read();
	m=read();
	for(re int i=1;i<=n;++i){
		for(re int j=1;j<=m;++j){
			a[i][j]=read();
		}
	}
/*	for(re int i=1;i<=n;++i){
		for(re int j=1;j<=m;++j){
			dp[i][j]=a[i+1][j]+a[i-1][j]+a[i][j+1]+a[i][j-1];
		}
	}*/
	//dp[1][1]=a[1][1]+a[1][2]+a[2][1];
	for(re int i=1;i<=n;++i){
		dp[i][1]=dp[i-1][1]+a[i][2]+a[i+1][1];
		way[i][1]=2;
	}
	for(re int j=1;j<=m;++j){
		dp[1][j]=dp[1][j-1]+a[2][j]+a[1][j+1];
		way[1][j]=1;
	}
	for(re int i=2;i<=n;++i){
		for(re int j=2;j<=m;++j){
			if(way[i-1][j]==1&&way[i][j-1]==1){
				int x=dp[i-1][j]+a[i][j-1]+a[i][j+1]+a[i-1][j];
				int y=dp[i][j-1]+a[i+1][j]+a[i][j+1];
				if(x>y){
					dp[i][j]=y;
					way[i][j]=2;
				}
				else {
					dp[i][j]=x;
					way[i][j]=1;
				}
				//dp[i][j]=min(dp[i-1][j]+a[i][j-1]+a[i][j+1]+a[i-1][j],dp[i][j-1]+a[i+1][j]+a[i][j+1]);
			}
			if(way[i-1][j]==2&&way[i][j-1]==2){
				int x=dp[i-1][j]+a[i+1][j]+a[i][j+1];
				int y=dp[i][j-1]+a[i-1][j]+a[i+1][j]+a[i][j+1];
				if(x>y){
					dp[i][j]=y;
					way[i][j]=2;
				}
				else {
					dp[i][j]=x;
					way[i][j]=1;				
				}
			}
			if(way[i-1][j]==1&&way[i][j-1]==2){
				int x=dp[i-1][j]+a[i][j-1]+a[i][j+1]+a[i+1][j];
				int y=dp[i][j-1]+a[i+1][j]+a[i-1][j]+a[i][j+1];
				if(x>y){
					dp[i][j]=y;
					way[i][j]=2;
				}
				else {
					dp[i][j]=x;
					way[i][j]=1;
				}
			}
			if(way[i-1][j]==2&&way[i][j-1]==1){
				int x=dp[i-1][j]+a[i][j+1]+a[i+1][j];
				int y=dp[i][j-1]+a[i+1][j]+a[i][j+1];
				if(x>y){
					dp[i][j]=y;
					way[i][j]=2;
				}
				else {
					dp[i][j]=x;
					way[i][j]=1;
				}
			}
		}
	}
	/*for(re int i=1;i<=n;++i){
		for(re int j=1;j<=m;++j){
			printf("%d ",dp[i][j]);
		}
		printf("\n");
	}*/
	printf("%d\n",dp[n][m]);
	return 0;
}
/*
3 9
0 0 1 0 0 0 0 0 1
1 1 1 1 1 1 0 1 0
1 0 0 1 0 0 1 0 0
*/
// 9
