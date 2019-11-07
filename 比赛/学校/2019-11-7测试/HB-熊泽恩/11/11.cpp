#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define il inline

const double EPS = 1e-6;

double n;

double myabs(double a) {
	return a > 0 ? a : -a;
}

int main() {
	freopen("11.in", "r", stdin);
	freopen("11.out", "w", stdout);
	while(1) {
		std::cin >> n;
		int i = 1;
		double sum = 0;
		if(n <= 0.005)
			break;
		do {
			i++;
			sum += 1.0 / i;
		} while(sum < n);
		std::cout << i - 1 << " card(s)" << std::endl;
	}
	return 0;
}

