#include <bits/stdc++.h>
#define rgi register int
#define ll long long
#define il inline

using namespace std;

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {

	return 0;
}

