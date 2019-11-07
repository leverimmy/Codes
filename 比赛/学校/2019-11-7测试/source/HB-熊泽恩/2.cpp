#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define il inline

const int N = 10 + 10;

int n, len;
std::string str[N];

int main() {
	freopen("2.in", "r", stdin);
	freopen("2.out", "w", stdout);
	std::cin >> n;
	for(rgi i = 1; i <= n; ++i)	std::cin >> str[i];
	len = str[1].length();
	for(rgi i = 0; i < len; ++i) {
		int A = 0, C = 0, G = 0, T = 0;
		for(rgi j = 1; j <= n; ++j) {
			if(str[j][i] == 'A')	A++;
			if(str[j][i] == 'C')	C++;
			if(str[j][i] == 'G')	G++;
			if(str[j][i] == 'T')	T++;
		}
		if(A >= C && A >= G && A >= T) {
			putchar('A');
			continue;
		}
		if(C >= A && C >= G && C >= T) {
			putchar('C');
			continue;
		}
		if(G >= A && G >= C && G >= T) {
			putchar('G');
			continue;
		}
		if(T >= A && T >= C && T >= G) {
			putchar('T');
			continue;
		}
	}
	return 0;
}

