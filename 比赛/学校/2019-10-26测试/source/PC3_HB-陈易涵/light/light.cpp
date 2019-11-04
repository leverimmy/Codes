#include <bits/stdc++.h>

using namespace std;

#define maxn 100005

int n, m, p, v;
int a[maxn];

int main()
{
	freopen("light.in", "r", stdin);
	freopen("light.out", "w", stdout);
	cin>>n>>m;
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
//	if(n<=1000&&m<=1000){
		for(int i = 1; i <= m; i++){
			int l, r;
			int ans = 0;
			scanf("%d%d%d%d",&l, &r, &p, &v);
			for(int i = l; i <= r; i++){
				if(a[i]%p==v){
					ans++;
				}
			}
			printf("%d\n", ans);
		}
		return 0;
//	}

	return 0;	
}
/*
5 2
1 5 2 3 7
1 3 2 1
2 5 3 0
*/
