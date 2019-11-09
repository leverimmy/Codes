#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	int a; std::cin >> a;
	int ans = 0;
	for(rgi i = 1; i <= a; ++i)
		if(i != a - i && i <= a - i)
			ans++;
	std::cout << ans;
	return 0;
}

