#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
int a[105],p[105];
int f[105][105];
int main(){
	freopen("zuma.in","r",stdin);
	freopen("zuma.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%d",&a[cnt=1]);
	for(int i=2;i<=n;i++){
		int x;scanf("%d",&x);
		if(x!=a[cnt]) a[++cnt]=x;
		p[cnt]++;
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=cnt;i++) f[i][i]=max(0,m-p[i]);
	for(int i=1;i<cnt;i++)
		for(int j=1;j+i<=cnt;j++){
			int l=j+i;
			if(a[j]==a[l]) {
				f[j][l]=f[j+1][l-1]+max(0,m-p[j]-p[l]);
			}
			for(int k=j;k<l;k++) f[j][l]=min(f[j][l],f[j][k]+f[k+1][l]);
		} 
	printf("%d",f[1][cnt]);
	return 0;
}
