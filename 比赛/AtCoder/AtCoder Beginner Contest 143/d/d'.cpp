#include <bits/stdc++.h>
#define rgi register int
#define ll long long
#define il inline

using namespace std;

const int N = 2000 + 10;

int n, ans;
int l[N];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	n = read();
	for(rgi i = 1; i <= n; ++i) l[i] = read();
	for(rgi i = 1; i <= n; ++i)
		for(rgi j = i + 1; j <= n; ++j)
			for(rgi k = j + 1; k <= n; ++k)
				if(l[i] + l[j] > l[k] && l[j] + l[k] > l[i] && l[k] + l[i] > l[j])
					ans++;
	printf("%d", ans);
	return 0;
}
