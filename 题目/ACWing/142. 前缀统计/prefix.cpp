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

int n, m;

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

class trie {
	private:
		static const int MAX_SIZE = 2e5;
		int idx, ch[MAX_SIZE + 10][26], cnt[MAX_SIZE + 10];
		char val[MAX_SIZE + 10];
	public:
		void insert(string in) {
			int len = in.length(), p = 0;
			for(rgi i = 0; i < len; ++i) {
				int &nxt = ch[p][in[i] - 'a'];
				if(!nxt) nxt = ++idx;
				p = nxt;
			}
			cnt[p]++;
		}
		int query(string in) {
			int len = in.length(), p = 0, res = 0;
			for(rgi i = 0; i < len; ++i) {
				int &nxt = ch[p][in[i] - 'a'];
				if(!nxt)	break;
				p = nxt;
				res += cnt[p];
			}
			return res;
		}
} t;

int main() {
	n = read(), m = read();
	for(rgi i = 1; i <= n; ++i) {
		string str; cin >> str;
		t.insert(str);
	}
	for(rgi i = 1; i <= m; ++i) {
		string str; cin >> str;
		printf("%d\n", t.query(str));
	}
	return 0;
}

