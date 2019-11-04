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
const int N = 500 + 10;

int n, ans = -oo;
int a[N][N];
vector <int> vec[N];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
//	freopen("testdata (3).in", "r", stdin);
	n = read();
	for(rgi i = 1; i <= n - 1; ++i)	for(rgi j = i + 1; j <= n; ++j)
		a[i][j] = a[j][i] = read();
//	for(rgi i = 1; i <= n; ++i) {
//		for(rgi j = 1; j <= n; ++j)
//			printf("%d ", a[i][j]);
//		puts("");
//	}
	for(rgi i = 1; i <= n; ++i) {
		sort(a[i] + 1, a[i] + n + 1);
		ans = max(ans, a[i][n - 1]);
	}
	/*for(rgi i = 1; i <= n - 1; ++i)
		for(rgi j = 1; j <= n - 1; ++j)
			vec[i].push_back(a[i][j]);
	for(rgi i = 1; i <= n - 1; ++i) {
		sort(vec[i].begin(), vec[i].end());
		ans = max(vec[i][n - 3], ans);
	}*/
	
	/*for(rgi i = 1; i <= n - 1; ++i) {
		for(rgi j = 0; j < n - 1; ++j)
			cout << vec[i][j] << " ";
		cout << endl;
	}*/
	printf("1\n%d", ans);
	return 0;
}

