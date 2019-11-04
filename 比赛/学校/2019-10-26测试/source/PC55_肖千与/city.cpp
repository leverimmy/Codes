#pragma GCC optimize("O2")
#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int s=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s;
} 
const int N=100005;
int n,m;
int a[N],b[N],vis[N],stk[N];
int cnt=0,top;
int ans[1005][305];
inline void solve(int x){
	if((a[1]+a[2]+a[x])&1) return;
	b[1]=((a[1]+a[2]-a[x])/2);
	b[2]=a[1]-b[1];
	b[3]=a[2]-b[1];
	if(b[1]<=0||b[2]<=0||b[3]<=0) return;
	while(top) vis[stk[top]]=0,top--;
	vis[1]=vis[2]=vis[x]=1;
	stk[++top]=x;
	for(int i=4,j=3;i<=n;i++){
		while(j<=m&&vis[j]) j++;
		if(vis[j]||j>m) return;
		b[i]=a[j]-b[1];vis[j]=1;stk[++top]=j;
		for(int k=2;k<i;k++){
			if(b[k]>b[i]) return;
			int v=b[k]+b[i];
			int p=lower_bound(a+1,a+m+1,v)-a;
			if(a[p]!=v) return;
			while(p<=m&&vis[p]) p++;
			if(a[p]!=v||vis[p]) return;
			vis[p]=1;stk[++top]=p;
		}
	}
	cnt++;
	for(int i=1;i<=n;i++) ans[cnt][i]=b[i];
}
int main(){
	freopen("city.in","r",stdin);
	freopen("city.out","w",stdout);
	n=read();m=n*(n-1)/2;
	for(int i=1;i<=m;i++) a[i]=read();
	sort(a+1,a+m+1);
	for(int i=3;i<=m;i++) 
		if(i==3||a[i]!=a[i-1]) 
			solve(i);
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++) {
		for(int j=1;j<=n;j++) printf("%d ",ans[i][j]);
		puts("");
	}
	return 0;
}
/*
4
11 17 21 12 20 15
*/
