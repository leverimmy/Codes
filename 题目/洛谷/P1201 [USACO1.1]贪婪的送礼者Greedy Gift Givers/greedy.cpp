#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 10 + 10;

int n;
std::string name[N];
std::map <std::string, int> mp;

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	n = read();
	for(rgi i = 1; i <= n; ++i)	std::cin >> name[i];
	for(rgi i = 1; i <= n; ++i) {
		std::string str;
		std::cin >> str;
		int tot = read(), m = read();
		if(!m)	continue;
		mp[str] -= tot / m * m;
		
		for(rgi j = 1; j <= m; ++j) {
			std::string rec;
			std::cin >> rec;
			mp[rec] += tot / m;
		}
	}
	for(rgi i = 1; i <= n; ++i)	std::cout << name[i] << " " << mp[name[i]] << std::endl;
	return 0;
}

