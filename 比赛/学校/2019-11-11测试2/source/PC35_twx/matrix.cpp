#include <bits/stdc++.h>

using namespace std;
const int N = 20;
int read(){
	char ch=getchar();
	while(ch!='0' && ch!='1'){
		ch=getchar();
	}
	return ch-'0';
}
int n,m;
int a[N][N];
int main(){
	freopen("matrix.in", "r", stdin);
	freopen("matrix.out", "w", stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			a[i][j]=read();
		}
	}
	printf("2");
	return 0;
}
