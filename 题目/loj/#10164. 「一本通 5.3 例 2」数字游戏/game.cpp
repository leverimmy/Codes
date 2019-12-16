#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int DIGIT = 50;

int a, b, digit[DIGIT], f[DIGIT][DIGIT];

int F(int i, int j, int flag) {
	if(i == -1) return 1;
	if(!flag && ~f[i][j]) return f[i][j];
	int res(0), d = flag ? digit[i] : 9;
	for(rgi k = j; k <= d; ++k) res += F(i - 1, k, flag && k == d);
	if(!flag) f[i][j] = res;
	return res;
}

int Query(int x) {
	int tot(0);
	while(x) {digit[tot++] = x % 10; x /= 10;}
	memset(f, -1, sizeof(f));
	return F(tot - 1, 0, 1);
}

int main() {
	while(scanf("%d %d", &a, &b) != EOF) {
 		printf("%d\n", Query(b) - Query(a - 1));
	}
	return 0;
}
/*
1 9
1 19
1 20

*/
