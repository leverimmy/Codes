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
const int N = 1e6 + 10;

int n, m;

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

class trie {
	private:
		static const int MAX_SIZE = 1e6;
		int idx, ch[MAX_SIZE + 10][26];
		long long val[MAX_SIZE + 10];
	public:
		void insert(char str[], int w) {
			int p = 0, len = strlen(str);
			for(rgi i = 0; i < len; ++i) {
				int &nxt = ch[p][str[i] - 'a'];
				if(!nxt)	nxt = ++idx;
				p = nxt;
			}
			val[p] = w;
		}
		int query(char str[]) {
			int p = 0, len = strlen(str);
			for(rgi i = 0; i < len; ++i) {
				int &nxt = ch[p][str[i] - 'a'];
				if(!nxt)	return -1;
				p = nxt;
			}
			return val[p];
		}
		void clear() {
			idx = 0;
			memset(ch, 0, sizeof(ch));
			memset(val, -1, sizeof(val));
		}
		trie() {
			clear();
		}
} t;

int main() {
	freopen("liverpool.in", "r", stdin);
	freopen("liverpool.out", "w", stdout);
	n = read();
	for(rgi i = 1; i <= n; ++i) {
		char str[N]; scanf("%s", str);
		int weight; weight = read();
		t.insert(str, weight);
	}
	m = read();
	for(rgi i = 1; i <= m; ++i) {
		int k = read();	long long ans = 0;
		for(rgi j = 1; j <= k; ++j) {
			char str[N]; scanf("%s", str);
			if(t.query(str) == -1) {
				ans = -1;
				break;
			}
			else
				ans += t.query(str);
		}
		printf("%lld\n", ans);
	}
	return 0;
}

