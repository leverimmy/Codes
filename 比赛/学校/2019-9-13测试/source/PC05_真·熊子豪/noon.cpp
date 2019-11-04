#include<bits/stdc++.h>
using namespace std;
int n,m;
long double a[1001];
int d[1001];
int main(){
	freopen("noon.in","r",stdin);
	freopen("noon.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<=n;i++){
		d[i]=1;
		a[i]=19260817;
	}
	while(m--){
		int u,v;
		cin>>u>>v;
		a[u]=(long double)v/(long double)u;
		for(int i=u;i<=n;i++){
			for(int j=1;j<i;j++){
				if(a[i]>a[j]&&a[i]!=19260817&&a[j]!=19260817){
					d[i]=max(d[i],d[j]+1);
				}
			}
		}
		cout<<d[n]<<'\n';
	}
	return 0;
}
