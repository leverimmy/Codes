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

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	int l = read(), r = read(), ans = oo;
	int vis[100000 + 10];
	for(rgi i = l; i <= r; ++i) {
		int x = i, cur = 1;
		memset(vis, 0, sizeof(vis));
		while(x) {
			vis[x % 10]++;
			x /= 10;
		}
		for(rgi i = 0; i <= 9; ++i) {
			if(vis[i] >= 2) {
				cur = 0;
				break;
			}
		}
		if(cur) {
			ans = i;
			break;
		}
	}
	if(ans != oo) printf("%d", ans);
	else puts("-1");
	return 0;
}

