#include <bits/stdc++.h>
#define ll long long
#define rgi register int 

using namespace std;

const int mod = 1e9 + 7;
const int N = 1005;
const int M = 205;
const int K = 205;

int n, m, k;
ll f[2][M][K][2];
char A[N], B[N];

int main() {
	scanf("%d %d %d", &n, &m, &k);
	scanf("%s", A + 1), scanf("%s", B + 1);
	f[1][0][0][0] = f[0][0][0][0] = 1;
	for(rgi i = 1; i <= n; ++i)
		for(rgi j = 1; j <= m; ++j)
			for(rgi p = 1; p <= k; ++p) {
				if(A[i] == B[j]) {
					f[i & 1][j][p][0] = (f[i & 1 ^ 1][j][p][0] + f[i & 1 ^ 1][j][p][1]) % mod;
					f[i & 1][j][p][1] = (f[i & 1 ^ 1][j - 1][p][1] + f[i & 1 ^ 1][j - 1][p - 1][0] + f[i & 1 ^ 1][j - 1][p - 1][1]) % mod;
				}
				else {
					f[i & 1][j][p][0] = (f[i & 1 ^ 1][j][p][0] + f[i & 1 ^ 1][j][p][1]) % mod;
					f[i & 1][j][p][1] = 0;
				}
			}
	printf("%lld", (f[n & 1][m][k][0] + f[n & 1][m][k][1]) % mod);
	return 0;
}
