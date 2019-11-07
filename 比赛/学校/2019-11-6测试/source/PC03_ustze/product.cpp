#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; 
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
const int N=205;
int n;
int t[N],d[N];
ll st[N],sd[N];
ll f[N][N];
ll dfs(int l,int r){
	if(l>r) return 0;
	if(l==r) return f[l][r]=t[l]*d[l];
	if(f[l][r]) return f[l][r];
	ll res=1e15;
	for(int k=l;k<=r;k++) {
		ll t1=dfs(l,k-1),t2=dfs(k+1,r);
		res=min(res,t1+t2+(sd[r]-sd[k])*(st[k-1]-st[l-1])+d[k]*(st[r]-st[l-1]));
	}
	return f[l][r]=res;
}
int main(){
	freopen("product.in","r",stdin);
	freopen("product.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) t[i]=read(),d[i]=read(),st[i]=st[i-1]+t[i],sd[i]=sd[i-1]+d[i];
	printf("%lld",dfs(1,n));
    return 0;
}
/*
t1*d1 t2*d2 (t2+t3)*d3
t1*d1 + (t1+t2)*d2
*/
