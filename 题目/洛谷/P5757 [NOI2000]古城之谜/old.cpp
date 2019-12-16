#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

struct trie {
#define MAXSIZE (100000 + 10)
	int idx, ch[MAXSIZE][30];
	void insert(std::string str, std::string type) {
		str += type;
		int len = str.length(), p = 0;
		for(rgi i = 0; i < len; ++i) {
			int &nxt = ch[p][str[i] - 'a'];
			if(!nxt) nxt = ++idx;
			p = nxt;
		}
	}
	int check(std::string str) {
		int len = str.length(), p = 0, res = 1;
		for(rgi i = 0; i < len; ++i) {
			int nxt = ch[p][str[i] - 'a'];
			if(!nxt) return 0;
			p = nxt;
		}
		if(ch[p]['n' - 'a']) res *= 2;
		if(ch[p]['v' - 'a']) res *= 3;
		if(ch[p]['v' - 'a']) res *= 5;
		return res;
	}
	void clear() {idx = 0; memset(ch, 0, sizeof(ch));}
	trie() {clear();}
#undef MAXSIZE
} t;

int main() {
	return 0;
}

