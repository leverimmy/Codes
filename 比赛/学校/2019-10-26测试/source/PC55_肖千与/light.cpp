#pragma GCC optimize("O2")
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,mx;
int a[N];
vector<int> G[N];
vector<int> g[105][105];
inline int read(){
	int s=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s;
} 

int main(){
	freopen("light.in","r",stdin);
	freopen("light.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read(),mx=max(mx,a[i]),G[a[i]].push_back(i);
	for(int i=1;i<=n;i++){
		for(int j=1;j<80;j++)
			g[j][a[i]%j].push_back(i);
	}
	
	for(int i=1;i<=m;i++){
		int l=read(),r=read(),p=read(),v=read();
		if(p>=80) {
			int res=0;
			for(int j=0;j*p+v<=mx;j++) {
				int k=j*p+v;
				res+=upper_bound(G[k].begin(),G[k].end(),r)-lower_bound(G[k].begin(),G[k].end(),l);
			}
			printf("%d\n",res);
		}else {
			int res=upper_bound(g[p][v].begin(),g[p][v].end(),r)-lower_bound(g[p][v].begin(),g[p][v].end(),l);
			printf("%d\n",res);
		}
	}
	return 0;
}
/*
5 2
1 5 2 3 7
1 3 2 1
2 5 3 0
*/
