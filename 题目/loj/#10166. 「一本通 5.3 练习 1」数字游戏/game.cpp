#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 200 + 10;
const int DIGIT = 20;

int a, b, mod;
int digit[DIGIT], f[DIGIT][DIGIT][N];

void Init() {
	memset(f, 0, sizeof(f)); f[0][0][0] = 1;
	for(rgi i = 1; i <= 10; ++i) // len
		for(rgi j = 0; j <= 9; ++j) // this digit
			for(rgi k = 0; k < mod; ++k) // last modulo
				for(rgi l = 0; l <= 9; ++l) // last digit
					f[i][j][k] += f[i - 1][l][((k - j) % mod + mod) % mod];
}

int Query(int x) {
	int tot(0), res(0), cur(0);
	while(x) {digit[++tot] = x % 10; x /= 10;}
	for(rgi i = tot; i >= 1; --i) { // len
		for(rgi j = 0; j < digit[i]; ++j) // this digit
			res += f[i][j][((mod -cur) % mod + mod) % mod];
		cur = (cur + digit[i]) % mod;
	} return res + !(cur % mod);
}

int main() {
	while(scanf("%d %d %d", &a, &b, &mod) != EOF) {
		Init();
		printf("%d\n", Query(b) - Query(a - 1));
	}
	return 0;
}

