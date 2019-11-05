#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const char c[] = {'Q', 'W', 'E', 'R', 'q', 'w', 'e', 'r'};

int main() {
	srand(time(0));
	freopen("tea.in", "w", stdout);
	puts("2000");
	for(rgi i = 1; i <= 2000; ++i) {
		for(rgi j = 1; j <= 20000; ++j)
			putchar(c[rand() % 8]);
		puts("");
	}
	return 0;
}

