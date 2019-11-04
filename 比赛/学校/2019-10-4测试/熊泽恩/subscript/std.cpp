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
const int N = 1e5 + 10;

int T, top, len, start;
int nxt[N], match[N], stk[N];
string str;

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

bool cmp(int l1, int r1, int l2, int r2) {//比较大小( < ) 
	for(rgi i = l1, j = l2; ; i = nxt[i], j = nxt[j]) {
		if(str[i] != str[j])	return str[i] < str[j];
		if(i == r1 || j == r2)	return i == r1;
	}
}

void solve(int &l, int r) {
	if(isalpha(str[r]))	return;
	int mid = match[r], end = r--;
	int lend = mid - 1, rbegin = mid + 1;
	solve(l, lend);
	solve(rbegin, r);
	if(!cmp(l, lend, rbegin, r)) {
		swap(l, rbegin);
		swap(lend, r);
	}
	nxt[lend] = mid;
	nxt[mid] = rbegin;
	nxt[r] = end;
}

int main() {
	T = read();
	while(T--) {
		memset(nxt, -1, sizeof(nxt));
		memset(match, -1, sizeof(match));
		start = top = 0;
		cin >> str; len = str.length();
		for(rgi i = 0; i < len; ++i)	nxt[i] = i + 1;
		for(rgi i = 0; i < len; ++i) {
			if(str[i] == '[')	stk[++top] = i;
			if(str[i] == ']')	match[i] = stk[top--];
		}
		solve(start, len - 1);
		for(rgi i = start; i < len; i = nxt[i])	printf("%c", str[i]);
		puts("");
	}
	return 0;
}
/*
4
aaa[bbb]
a[b[abbb]]
b[a[azzz]]
x[a][b[a]]

10
d[u]
h[t]
p[d]
j[i]
c[b]
a[e]
d[b]
a[d]
a[b]
a[a]

*/
