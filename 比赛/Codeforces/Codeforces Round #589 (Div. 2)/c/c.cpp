#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#define int long long
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;

int x, n, cur;

vector <int> vec;

int gcd(int a, int b) {
	return !b ? a : gcd(b, a % b); 
}

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

signed main() {
	x = read(), n = read(); cur = gcd(x, n);
	for(rgi i = 2; i <= cur / i; ++i)
		if(cur % i == 0) {
			vec.push_back(i);
			while(cur % i == 0) {
				cur /= i;
				cnt[i]++;
			}
		} if(cur != 1) vec.push_back(cur); cnt[cur]++;
	//get factors
	for(rgi i = 0; i < vec.size(); ++i) {
		
	}
	return 0;
}

