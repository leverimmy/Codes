#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;
const int SIZE = 1e5 + 10;
const int N = 2e5 + 10;

int n, k;
int vis[N], a[N];

vector <int> primes;
vector <int> fact[SIZE];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void solve(int x) {
	
	for(rgi i = 1; i <= n; ++i) {
		
	}
	
}

int main() {
	n = read(), k = read();
	
	for(rgi i = 2; i <= 100000; ++i) {
		if(!vis[i])	primes.push_back(i);
		for(rgi j = 2; j <= 100000 / i; ++j)
			vis[i * j] = 1; 
	}
	
	for(rgi i = 1; i <= n; ++i)	a[i] = read();
	
	for(rgi i = 1; i <= n; ++i) {
		
		solve(a[i]);
		
	}
	
	return 0;
}

