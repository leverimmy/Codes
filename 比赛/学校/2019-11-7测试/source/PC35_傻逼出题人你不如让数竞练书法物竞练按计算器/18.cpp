#include<bits/stdc++.h>
using namespace std;
const int N=3005;
int n,m;
int fa[N];
inline int findf(int x){
	return x==fa[x]?x:fa[x]=findf(fa[x]);
}
int main(){
	freopen("18.in","r",stdin);
	freopen("18.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) {
		int x,y;cin>>x>>y;
		int fx=findf(x),fy=findf(y);
		if(fx==fy) continue;
		fa[fx]=fy;
	}
	int ans=0;
	for(int i=1;i<=n;i++) if(findf(i)==i) ans++;
	cout<<ans;  
	return 0;
}
