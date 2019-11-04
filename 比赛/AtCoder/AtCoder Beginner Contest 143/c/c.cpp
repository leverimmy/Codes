#include <bits/stdc++.h>
#define rgi register int
#define ll long long
#define il inline

using namespace std;

int n, len, ans;
string str;

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	n = read();
	cin >> str; len = str.length(); ans = len;
	for(rgi i = 0; i < len - 1; ++i) {
		if(str[i + 1] == str[i])
			ans--;
	}
	printf("%d", ans);
	return 0;
}

