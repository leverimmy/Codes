#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define il inline

const int oo = 0x3f3f3f3f;
const int N = 2500 + 10;

int c, l, ans;
int spf[N], cover[N];

struct COW {
	int spfmin, spfmax;
	bool operator < (const struct COW &rhs)	const {
		return spfmin > rhs.spfmin;
	}
} cow[N];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	c = read(), l = read();
	for(rgi i = 1; i <= c; ++i)	cow[i].spfmin = read(), cow[i].spfmax = read();
	for(rgi i = 1; i <= l; ++i) spf[i] = read(), cover[i] = read();
	
	std::sort(cow + 1, cow + c + 1);
	
	for(rgi i = 1; i <= c; ++i) {
		int nxt = -1, val = -oo;
		for(rgi j = 1; j <= l; ++j)	if(cover[j] && cow[i].spfmin < spf[j] && spf[j] < cow[i].spfmax)
			if(spf[j] > val)	nxt = j, val = spf[j];
		if(~nxt)	cover[nxt]--, ans++;
	}
	
	printf("%d", ans);
	return 0;
}

