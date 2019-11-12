#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int n,m;
char s[N][N];
int f[N][N],c[N];
int ans=0;
int main(){
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(s[i][j]=='1')
				f[j][i]=f[j-1][i]+1;
	for(int i=1;i<=m;i++){
		memset(c,0,sizeof(c));
		for(int j=1;j<=n;j++) c[f[i][j]]++;
		int cnt=0;
		for(int j=0;j<=n;j++) {
			while(c[j]) {
				cnt++;f[i][cnt]=j;c[j]--;
			}
		}
		for(int j=n;j>=1;j--) ans=max(ans,(n-j+1)*f[i][j]);
	}
	printf("%d",ans);
	return 0;
}
