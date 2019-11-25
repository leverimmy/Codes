#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 20;

int T, n, a[N];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	T = read(), n = read();
	
	while(T--) {
		for(rgi i = 1; i <= n; ++i)	{
			a[i] = read();
			int kk = read();
		}
		std::sort(a + 1, a + n + 1);
		
		if(n == 1) puts("1");
		if(n == 2) {
			if(a[1] == a[2])	puts("1");
			else	puts("2");
		}
		if(n == 3) {
			if(a[1] == a[2] && a[2] == a[3])	puts("1");
			else if(a[1] == a[2] || a[2] == a[3])	puts("2");
			else puts("3");
		}
		if(n == 4) {
			if(a[1] == a[2] && a[2] == a[3] && a[3] == a[4])	puts("1");
			else if((a[1] == a[2] && a[2] == a[3]) || (a[2] == a[3] && a[3] == a[4]))	puts("1");
			else if(a[1] == a[2] && a[3] == a[4])	puts("2");
			else if(a[1] == a[2] || a[2] == a[3] || a[3] == a[4])	puts("3");
			else	puts("4");
		}
	}
	
	return 0;
}

