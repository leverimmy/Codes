#include<bits/stdc++.h>
#define int long long
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
string dfs(int step) {
	if(step == 1) {
		return "A";
	}
	char x = (char)('A' + step - 1);
	string y = dfs(step - 1);
	string ans = y + x + y;
	return ans;
}
signed main() {
	freopen("6.in", "r", stdin);
	freopen("6.out", "w", stdout);
	int n = read();
	cout << dfs(n);
	return 0;
} 
