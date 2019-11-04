#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cctype>
#define rgi register int
#define il inline

using namespace std;

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	int a, b;
	while(a = read(), b = read()) {
		cout << a + b << endl;
	}
	return 0;
}

