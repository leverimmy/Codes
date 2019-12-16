#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define il inline

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	if(system("fc run.out run.ans"))
		puts("WA");
	else
		puts("AC"); 
	return 0;
}

