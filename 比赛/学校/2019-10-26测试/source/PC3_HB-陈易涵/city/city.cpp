#include <bits/stdc++.h>

using namespace std;

#define maxn 305

int n, m;
int a[maxn];
int b[maxn];
int c[maxn];
int ans = 0;
int res[maxn][maxn];
int maxsum;

void dfs(int cur, int b[]){
	if(cur>n){
		int tot = 0;
		for(int i = 1; i <= n; i++){
			for(int j = i+1; j <= n; j++){
				c[++tot] = b[i]+b[j];
			}
		}
		sort(c+1, c+1+n);
		int flag = 1;
		for(int i = 1; i <= m; i++){
			if(c[i]!=a[i]){
				flag = 0;
				break;
			}
		}
		if(flag==0) return;
		ans++;
		for(int i = 1; i <= n; i++){
			res[ans][i] = b[i];
		}
		return;
	}
	
	for(int i = 1; i <= maxsum-(n-1); i++){
		b[cur] = i;
		dfs(cur+1, b);
	}
}

int main()
{
	freopen("city.in", "r", stdin);
	freopen("city.out", "w", stdout);
	
	cin>>n;
	m = n*(n-1)/2;
	for(int i = 1; i <= m; i++){
		scanf("%d", &a[i]);
	}
	
	sort(a+1, a+1+m);
	maxsum = a[m];
	
//	if(n<=5){
		dfs(1, b);
		cout<<ans<<endl;
		for(int i = ans; i>=1; i--){
			for(int j = 1; j <= n; j++){
				cout<<res[i][j]<<' ';
			}
			cout<<endl;
		}
		return 0;
//	}
	
	return 0;
}
/*
4
3 5 4 7 6 5

4
11 17 21 12 20 15
*/
