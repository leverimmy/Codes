#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;
inline int read() {
	int x = 0, f = 1;
	char c = getchar();
	while(!isdigit(c)) {
		if(c == '-') {
			f = -1;
		}
		c = getchar();
	}
	while(isdigit(c)) {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f;
}
string a;
char s[1000001];
signed main() {
	freopen("subscript.in", "w", stdout);
	freopen("subscript.out", "w", stdout);
	int T = read();
	while(T--) {
		cin >> a;
		int lena = a.length();
		for(int i = 0; i < lena; i++) {
			s[i + 1] = a[i];
		}
	}
	return 0;
}
