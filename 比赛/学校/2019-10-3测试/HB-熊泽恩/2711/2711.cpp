#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <cmath> 
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 1000 + 10;

int len, cnt[10], digit[N];
string num;

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
//	freopen("2711.in", "r", stdin);
//	freopen("2711.out", "w", stdout);
	cin >> num; len = num.length();
	for(rgi i = 0; i < len; ++i) cnt[num[i] - '0']++;
	for(rgi i = 0; i < len; ++i) digit[i + 1] = num[i] - '0';
	sort(digit + 1, digit + len + 1, greater <int> ());
	do {
		int cur[N];
		for(rgi i = len; i >= 1; --i) cur[i] = digit[len - i + 1];
		int tmp = 0, ans = 0;
		for(rgi i = 1; i <= len; ++i) {
			if(i % 3 == 0) {
				tmp += cur[i] * 100;
				if((i / 3) & 1)	ans += tmp;
				else	ans -= tmp;
				tmp = 0;
			}
			if(i % 3 == 1)	tmp += cur[i];
			if(i % 3 == 2)	tmp += cur[i] * 10;
		}
		if(len % 3 != 0) {
			if((int)ceil((double)len / 3) & 1)	ans += tmp;
			else	ans -= tmp;
		}
		if(abs(ans) % 11 == 0) {
			for(rgi i = 1; i <= len; ++i) printf("%d", digit[i]);
			break;
		}
	} while(prev_permutation(digit + 1, digit + len + 1));
	return 0;
}

