#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cctype>
#define rgi register int
#define il inline

using namespace std;

const int N = 1e5 + 10;

long long n, l, r, k;
long long a[N];
bool flag = 0;

int main() {
	scanf("%lld %lld", &n, &k);
	for(rgi i = 1; i <= n; ++i)	scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	l = 1, r = n;
	while(l < r) {
//		if(k <= 0) {
//			flag = 1;
//			printf("%lld", a[r] - a[l]);
//			break;
//		}
		if(l <= n - r + 1) {
			if(k <= l * (a[l + 1] - a[l])) {
				printf("%lld", a[r] - a[l] - k / l);
				flag = 1;
				break;
			}
			else
				k -= l * (a[l + 1] - a[l]), l++;
		}
		else {
			if(k <= (n - r + 1) * (a[r] - a[r - 1])) {
				printf("%lld", a[r] - k / (n - r + 1) - a[l]);
				flag = 1;
				break;
			}
			else
				k -= (n - r + 1) * (a[r] - a[r - 1]), r--;
		}
	}
	if(!flag)	puts("0");
	return 0;
}

