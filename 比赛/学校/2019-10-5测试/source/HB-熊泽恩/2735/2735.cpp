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
const int N = 8e6 + 10;

int n, m;
int a[N], root[N];

class trie {
	private:
		static const int MAX_SIZE = 8e6;
		int idx, ch[MAX_SIZE + 10][2], cnt[MAX_SIZE + 10], latest[MAX_SIZE + 10];
	public:
		void build(int x) {
			root[x] = ++idx;
		}
		void insert(int digit, int same, int x, int id) {
			if(digit < 0) {
				latest[x] = id;
				return;
			}
			int cur = a[id] >> digit & 1;
			if(same)
				ch[x][!cur] = ch[same][!cur];
			ch[x][cur] = ++idx;
			insert(digit - 1, ch[same][cur], ch[x][cur], id);
			latest[x] = max(latest[ch[x][0]], latest[ch[x][1]]);
		}
		int query(int digit, int x, int val, int limit) {
			if(digit < 0)	return a[latest[x]] ^ val;
			int cur = val >> digit & 1;
			if(latest[ch[x][!cur]] >= limit)
				return query(digit - 1, ch[x][!cur], val, limit);
			else
				return query(digit - 1, ch[x][cur], val, limit);
		}
		trie() {
			build(0);
			latest[0] = -1;
			insert(30, 0, root[0], 0);
		}
} t;

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	freopen("2735.in", "r", stdin);
	freopen("2735.out", "w", stdout); 
	n = read(), m = read();
	t.build(0);
	for(rgi i = 1; i <= n; ++i) {
		a[i] = read();
		t.build(i);
		t.insert(30, root[i - 1], root[i], i);
	}
	for(rgi i = 1; i <= m; ++i) {
		int x = read(), l = read() + 1, r = read() + 1; 
		printf("%d\n", t.query(30, root[r], x, l));
	}
	return 0;
}

