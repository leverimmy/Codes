#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105][105];
int main(){
	freopen("16.in","r",stdin);
	freopen("16.out","w",stdout);
	cin>>n>>m;
	a[1][1]=n;
	for(int i=2;i<=m;i++) a[i][1]=++n;
	for(int i=2;i<=m;i++) a[m][i]=++n;
	for(int i=m-1;i>=1;i--) a[i][m]=++n;
	for(int i=m-1;i>1;i--) a[1][i]=++n;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++) 
			if(a[i][j]) printf("%d ",a[i][j]);
			else printf("   ");
		puts("");
	}
	return 0;
}
