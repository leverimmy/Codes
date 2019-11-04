#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 5e5 + 10;

int n, k; ll ans, sum, med;
ll s[N], val[N], vis[N], tmp[N];

ll solve(int x) {
	int idx = 0; ll res = 0;
	memset(tmp, 0, sizeof(tmp));
	
	while(!vis[x]) {
		vis[x] = 1;
		tmp[++idx] = val[x];
		x += k; if(x > n) x -= n;
	}
	
	for(rgi i = 2; i <= idx; ++i)	s[i] = s[i - 1] + tmp[i - 1] - med;
	
	sort(s + 1, s + idx + 1);
	
	ll ans = 0, cur_med = s[idx + 1 >> 1];
	
	for(rgi i = 1; i <= idx; ++i)	res += abs(s[i] - cur_med);
	
	return res;
}

int main() {
//	freopen("6.in", "r", stdin);
	scanf("%d %d", &n, &k); k++;
	for(rgi i = 1; i <= n; ++i)	scanf("%lld", &val[i]), sum += val[i]; med = sum / n;
	for(rgi i = 1; i <= n; ++i)
		if(!vis[i])	ans += solve(i);
	printf("%lld", ans);
	return 0;
}
/*

*/
