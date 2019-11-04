#include<iostream>
#include<cstring>
#define inf 0x7fffffff/3
#define MAXn 5002
#define MAXm 10002
using namespace std;
int n,m,cnt,a[MAXn][MAXn],f[MAXn],pre[MAXn][MAXn];
int find(int k) {
	if(f[k]==k) return k;
	else return f[k]=find(f[k]);
}
void join(int p,int q) {
	int p1=find(p),p2=find(q);
	if(p1!=p2) f[p2]=p1;
}
bool judge(int p,int q) {
	int p1=find(p),p2=find(q);
	if(p1==p2) return 1;
	else return 0;
}
int main() {
	freopen("bomb.in","r",stdin);
	freopen("bomb.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			a[i][j]=inf;
	for(int i=1; i<=m; i++) {
		int u,v,w;
		cin>>u>>v>>w;
		a[u][v]=w;
		a[v][u]=w;
	}
	for(int k=1; k<=n; k++)
		for(int i=1; i<=n; i++)
			for(int j=1; j<=i; j++)
				if(a[i][k]!=inf&&a[k][j]!=inf&&a[i][j]>a[i][k]+a[k][j]) {
					a[i][j]=a[i][k]+a[j][k];
					a[j][i]=a[i][j];
					pre[i][j]=k;
				}
//	for(int i=1; i<=n; i++) {
//		for(int j=1; j<=n; j++)
//			if(a[i][j]==inf) cout<<"OO"<<"\t";
//			else cout<<a[i][j]<<"\t";
//		cout<<endl;
//	}
//	cout<<endl<<pre[1][n]<<endl<<endl;
//	for(int i=1; i<=n; i++) {
//		for(int j=1; j<=n; j++)
//			cout<<pre[i][j]<<"\t";
//		cout<<endl;
//	}
	if(a[1][n]==inf) cout<<"Mission Failed";
	else             cout<<a[1][n];
//	for(i=1;i<=n-2;i++){
//		cin>>x;
//		if(x) {
//		    while(cin>>y){
//			     if(judge(x,y)==0) join(x,y);
//		    }
//	    }
//	}
	return 0;
}
