#include <bits/stdc++.h>
#define rgi register int
#define rgl register long long
#define il inline
#define ll long long

using namespace std;

const int oo = 0x3f3f3f3f;

string str, X, Y;
int len;

il int read() {
    rgi x = 0, f = 0, ch;
    while(!isdigit(ch = getchar())) f |= ch == '-';
    while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

int main() {
	cin >> str;	len = str.length();
	reverse(str.begin(), str.end());
	for(rgi i = 1; i < len; ++i) if(str[i] == 'Z' && str[i - 1] != 'Z') {
		puts("-1");
		return 0;
	}
	for(rgi i = len - 1; ~i; --i) {
		if(str[i] == 'X')	X.push_back('9'), Y.push_back('8');
		if(str[i] == 'Y')	X.push_back('8'), Y.push_back('9');
		if(str[i] == 'Z')	X.push_back('5'), Y.push_back('5');
	}
	cout << X << endl << Y;
	return 0;
}
