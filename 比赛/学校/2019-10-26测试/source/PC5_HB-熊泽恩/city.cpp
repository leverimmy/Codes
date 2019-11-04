#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define il inline

const int N = 1e5 + 10;

int n, ans;
int a[N], b[N], tmp[N];

std::vector <int> vec[N];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void dfs(int cur, int last) {
	if(cur == n + 1) {
		int tot = 0;
		for(rgi i = 1; i <= n; ++i)	for(rgi j = i + 1; j <= n; ++j)
			b[++tot] = tmp[i] + tmp[j];
		
		std::sort(b + 1, b + n * (n - 1) / 2 + 1);
		
		for(rgi i = 1; i <= n * (n - 1) / 2; ++i)
			if(a[i] != b[i])	return;
		ans++;
		for(rgi i = 1; i <= n; ++i)
			vec[ans].push_back(tmp[i]);
		return;
	}
	for(rgi i = last; i <= 13; ++i)
		tmp[cur] = i, dfs(cur + 1, i);
}

int main() {
	freopen("city.in", "r", stdin);
	freopen("city.out", "w", stdout);
	n = read();
	for(rgi i = 1; i <= n * (n - 1) / 2; ++i)	a[i] = read();
	
	std::sort(a + 1, a + n * (n - 1) / 2 + 1);
	
	dfs(1, 1);
	
	printf("%d\n", ans);
	
	for(rgi i = ans; i >= 1; --i) {
		int siz = vec[i].size();
		for(rgi j = 0; j <= siz - 1; ++j)
			printf("%d ", vec[i][j]);
		putchar('\n');
	}
	
	return 0;
}
/*
4
3 5 4 7 6 5

4
11 17 21 12 20 15

*/
