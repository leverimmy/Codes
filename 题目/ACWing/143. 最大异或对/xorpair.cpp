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

int n, ans = -oo;
int a[N];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

class trie {
	private:
		static const int MAX_SIZE = 2e5;
		int idx, ch[MAX_SIZE + 10][2], cnt[MAX_SIZE + 10];
	public:
		void insert(int x) {
			int p = 0;
			for(rgi i = 30; ~i; --i) {
				int &nxt = ch[p][x >> i & 1];
				if(!nxt) nxt = ++idx;
				p = nxt;
			}
		}
		int query(int x) {
			int p = 0, res = 0;
			for(rgi i = 30; ~i; --i) {
				
				int nxt = x >> i & 1;
				
				if(ch[p][!nxt]) {
					res += 1 << i;
					p = ch[p][!nxt];
				}
				else
					p = ch[p][nxt];
			}
			return res;
		}
} t;

int main() {
	n = read();
	for(rgi i = 1; i <= n; ++i) {
		a[i] = read();
		t.insert(a[i]);
	}
	for(rgi i = 1; i <= n; ++i)
		ans = max(ans, t.query(a[i]));
	printf("%d", ans);
	return 0;
}

