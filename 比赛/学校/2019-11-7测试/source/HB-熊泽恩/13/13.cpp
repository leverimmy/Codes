#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define il inline

int n, cnt[10010];

std::vector <int> vec;

int main() {
	freopen("13.in", "r", stdin);
	freopen("13.out", "w", stdout);
	std::cin >> n;	int tmp = n;
	for(rgi i = 2; i <= n; ++i) {
		while(n % i == 0) {
			cnt[i]++;
			n /= i;
		}
	}
	std::cout << tmp << "=";
	for(rgi i = 2; i <= tmp; ++i)
		if(cnt[i])	vec.push_back(i);
	for(rgi i = 0; i < vec.size() - 1; ++i) {
		if(cnt[vec[i]] > 1)	std::cout << vec[i] << "^" << cnt[vec[i]] << "*";
		else				std::cout << vec[i] << "*";
	}
	if(cnt[vec.back()] > 1)	std::cout << vec.back() << "^" << cnt[vec.back()];
	else					std::cout << vec.back();
	return 0;
}

