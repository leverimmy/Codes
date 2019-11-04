#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

const int maxn=1200;

int a[maxn][maxn];
int f[maxn][maxn][3];
int n,m;

int dx[]={0,1,0,-1,0};
int dy[]={0,0,1,0,-1};

inline int read(){
	int w=1,x=0,ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x*w;
}

int main(){
	freopen("lemouse.in","r",stdin);
	freopen("lemouse.out","w",stdout);
    n=read(); m=read();
    for(register int i=1;i<=n;i++)
        for(register int j=1;j<=m;j++)
            a[i][j]=read();
    memset(f,0x3f3f,sizeof f); f[1][1][1]=f[1][1][2]=a[1][1]+a[2][1]+a[1][2]; 
    for(register int i=1;i<=n;i++){
        for(register int j=1;j<=m;j++){
            if(i==1&&j==1) continue;
            f[i][j][1]=min(f[i-1][j][1]+a[i+1][j]+a[i][j-1]+a[i][j+1],f[i-1][j][2]+a[i+1][j]+a[i][j+1]);
            f[i][j][2]=min(f[i][j-1][2]+a[i][j+1]+a[i-1][j]+a[i+1][j],f[i][j-1][1]+a[i][j+1]+a[i+1][j]);
        }
    }
    printf("%d\n",min(f[n][m][1],f[n][m][2]));
    return 0;
}
