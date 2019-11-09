#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,m;
int s[200],a[200];
int f[200][200];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("pb.in","r",stdin);
	freopen("pb.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++){
			f[i][j]=inf;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int k=j;k<i;k++){
				f[i][j]=min(f[i][j],f[k-1][j-1]+i*(s[i]-s[k-1]));
			}
		}
	}
	printf("%.4lf",(double)f[n][m]/(double)s[n]);
}
