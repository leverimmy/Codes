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
const int N = 5e5 + 10;

int n, T;
int p[N], d[N], siz[N];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int Find(int x) {
	if(x == p[x])	return x;
	int rt = Find(p[x]);
	d[x] += d[p[x]];
	p[x] = Find(p[x]);
	return p[x] = rt;
}

void Union(int a, int b) {
	int pa = Find(a), pb = Find(b);
	if(pa != pb) {
		p[pa] = pb;
		d[pa] = siz[pb];
		siz[pb] += siz[pa];
	}
}

bool Check(int a, int b) {
	return Find(a) == Find(b);
}

int main() {
	T = read();
	for(rgi i = 1; i <= T; ++i)	{
		p[i] = i;
		siz[i] = 1;
	}
	for(rgi i = 1; i <= T; ++i) {
		char cmd[5]; scanf("%s", cmd);
		int x = read(), y = read();
		if(cmd[0] == 'M')	Union(x, y);
		else if(cmd[0] == 'C') {
			if(!Check(x, y))	puts("-1");
			else	printf("%d\n", abs(d[x] - d[y]) - 1);
		}
	}
	return 0;
}

