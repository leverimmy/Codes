#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 5000 + 10;
const ll mod =998244353LL;
const ll mul = 127;

int n, s[N], f[N], cnt[N];
char str[N];

void solve(int x) {
	
	ll hash_st = 0LL;
	ll hash_ed = 0LL;
	ll suf = 1LL;
	
	memset(cnt, 0, sizeof(cnt));
	
	for(rgi i = x; i <= n; ++i) {
		hash_st = (hash_st * mul + str[i]) % mod;
		hash_ed = (hash_ed + suf * str[i]) % mod;
		suf *= mul, suf %= mod;
		if(hash_st == hash_ed)
			cnt[i] = cnt[(i - x + 1) / 2 + x - 1] + 1;
		f[cnt[i]]++;
	}
}

int main() {
	scanf("%s", str + 1);
	n = strlen(str + 1);
	
	for(rgi i = 1; i <= n; ++i)	solve(i);
	for(rgi i = n - 1; i >= 1; --i)	f[i] += f[i + 1];
	for(rgi i = 1; i <= n; ++i)	printf("%d ", f[i]);
	
	return 0;
}

