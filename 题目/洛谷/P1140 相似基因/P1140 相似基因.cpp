#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 100 + 10;
const int e[5][5] = {
	{5, -1, -2, -1, -3},
	{-1, 5, -3, -2, -4},
	{-2, -3, 5, -2, -2},
	{-1, -2, -2, 5, -1},
	{-3, -4, -2, -1, 5}
};

int len1, len2, a[N], b[N], f[N][N];
std::string A, B;

int main() {
	std::cin >> len1 >> A;
	std::cin >> len2 >> B;
	
	for(rgi i = 1; i <= len1; ++i)	for(rgi j = 1; j <= len2; ++j)
		f[i][j] = -0x7fffffff;
	for(rgi i = 1; i <= len1; ++i) {
		if(A[i - 1] == 'A')	a[i] = 0;
		if(A[i - 1] == 'C')	a[i] = 1;
		if(A[i - 1] == 'G')	a[i] = 2;
		if(A[i - 1] == 'T')	a[i] = 3;	
	}
	for(rgi i = 1; i <= len2; ++i) {
		if(B[i - 1] == 'A')	b[i] = 0;
		if(B[i - 1] == 'C')	b[i] = 1;
		if(B[i - 1] == 'G')	b[i] = 2;
		if(B[i - 1] == 'T')	b[i] = 3;	
	}
	
	for(rgi i = 1; i <= len1; ++i)	f[i][0] = f[i - 1][0] + e[a[i]][4];
	for(rgi i = 1; i <= len2; ++i)	f[0][i] = f[0][i - 1] + e[4][b[i]];
	
	for(rgi i = 1; i <= len1; ++i)	for(rgi j = 1; j <= len2; ++j) {
		f[i][j] = std::max(f[i][j], f[i - 1][j] + e[a[i]][4]);
		f[i][j] = std::max(f[i][j], f[i][j - 1] + e[4][b[j]]);
		f[i][j] = std::max(f[i][j], f[i - 1][j - 1] + e[a[i]][b[j]]);
	}
	
	printf("%d", f[len1][len2]);
	return 0;
}

