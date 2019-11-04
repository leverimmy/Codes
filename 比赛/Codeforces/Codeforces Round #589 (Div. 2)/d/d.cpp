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

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	n = read(), m = read();
	for(rgi i = 1; i <= m; ++i) {
		int u = read(), v = read();
		Add_Edge(u, v);
		Add_Edge(v, u);
	}
	for(rgi i = 1; i <= n; ++i) {
		for(rgi j = first[i]; ~j; j = e[j]._next) {
			int v = e[j].to;
			
		}
	} 
	return 0;
}

