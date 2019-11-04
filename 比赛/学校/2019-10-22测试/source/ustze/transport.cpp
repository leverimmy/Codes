#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
const int N=505;
int n,k;
int x[N],y[N];
int f[N][N];
inline int calc(int i,int j){
	return abs(x[i]-x[j])+abs(y[i]-y[j]);
}
int main(){
	freopen("transport.in","r",stdin);
	freopen("transport.out","w",stdout);
	n=read(),k=read();
	memset(f,0x3f,sizeof(f));
	for(int i=0;i<=k;i++) f[1][i]=0;
	for(int i=1;i<=n;i++){
		x[i]=read(),y[i]=read();
		for(int j=0;j<=min(k,i-2);j++){
			for(int l=0;l<=j;l++)
				f[i][j]=min(f[i][j],f[i-l-1][j-l]+calc(i-l-1,i));
		}
	}
	printf("%d",f[n][min(k,n-2)]);
	return 0;
} 
/*
5 2 
0 0
8 3 
1 1 
10 -5 
2 2

*/ 
