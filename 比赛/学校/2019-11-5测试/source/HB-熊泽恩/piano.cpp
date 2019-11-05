#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

int n, m, p;

struct BIG_INTEGER {
	
	static const int MAX_DIGIT = 5e4 + 10;
	int len, a[MAX_DIGIT];
	BIG_INTEGER operator + (const struct BIG_INTEGER &rhs) const {
		BIG_INTEGER res;
		res.len = std::max(len, rhs.len);
		for(rgi i = 1; i <= rhs.len; ++i)	res.a[i] = a[i] + rhs.a[i];
		for(rgi i = 1; i <= res.len - 1; ++i) {
			res.a[i + 1] += res.a[i] / 10;
			res.a[i] %= 10;
		}
		while(res.a[res.len] >= 10)	{
			res.a[res.len + 1] += res.a[len] / 10;
			res.a[res.len] %= 10;
			res.len++;
		}
		return res;
	}
	void in() {
		std::string str;	std::cin >> str;
		len = str.length();
		for(rgi i = 1; i <= len; ++i)	a[i] = str[len - i] - '0';
	}
	void out() {for(rgi i = len; i >= 1; --i)	printf("%d", a[i]);}
	BIG_INTEGER() {a[len = 1] = 0;}
};

struct Trie {
	
	static const int MAX_SIZE = 2e5 + 10;
	int idx, ch[MAX_SIZE][26], cnt[MAX_SIZE];
	
	void insert(std::string in) {
		int len = in.length(), p = 0;
		for(rgi i = 0; i < len; ++i) {
			int &nxt = ch[p][in[i] - 'a'];
			if(!nxt) nxt = ++idx;
			p = nxt;
		}
		cnt[p]++;
	}
	
	
	
	Trie () {idx = 0, memset(ch, 0, sizeof(ch));}
	
} t;

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
//	freopen("piano.in", "r", stdin);
//	freopen("piano.out", "w", stdout);
	n = read(), m = read(), p = read();
	std::cin >> dict;
	
	for(rgi i = 1; i <= p; ++i) {
		std::cin >> ch[i];
		t.insert(ch[i]);
	}
	
	
	
	return 0;
}

