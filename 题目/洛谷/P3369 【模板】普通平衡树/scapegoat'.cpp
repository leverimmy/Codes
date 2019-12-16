#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const double alpha = 0.86;

int n;

struct Node {
	Node *l, *r;
	int tot, siz, val;
	bool del;
	bool bad() {
		return (l -> tot >= tot * alpha) ||
			   (r -> tot >= tot * alpha); // 1
	}
	void push() {
		tot = l -> tot + r -> tot + 1;
		siz = l -> siz + r -> siz + !del;
	}
} *null, *root, **BadTag;

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Dfs(Node *p, std::vector <Node *> &keys) {
	if(p == null) return;
	Dfs(p -> l, keys);
	if(!p -> del) keys.push_back(p);
	Dfs(p -> r, keys);
	if(p -> del) delete p;
}

Node *Build(std::vector <Node *> &keys, int l, int r) {
	if(l >= r) return null;
	int mid = l + r >> 1;
	Node *p = keys[mid];
	p -> l = Build(keys, l, mid);
	p -> r = Build(keys, mid + 1, r);
	p -> push();
	return p;
}

void Rebuild(Node *&p) {
	std::vector <Node *> vec;
	Dfs(p, vec);
	p = Build(vec, 0, vec.size());
}

void Ins(Node *&p, int x) {
	if(p == null) {
		p = new Node;
		p -> l = p -> r = null;
		p -> siz = p -> tot = 1;
		p -> val = x;
		p -> del = 0;
	}
	else {
		++p -> siz;
		++p -> tot;
		if(x >= p -> val) Ins(p -> r, x);
		else Ins(p -> l, x);
		if(p -> bad()) BadTag = &p;
		else if(BadTag != &null)
			p -> tot -= (*BadTag) -> tot - (*BadTag) -> siz; // 2
	}
}

void Insert(Node *&p, int x) {
	BadTag = &null;
	Ins(p, x);
	if(BadTag != &null) Rebuild(*BadTag);
}

void Remove(Node *p, int x) {
	if(!p -> del && p -> l -> siz + 1 == x) {
		p -> del = 1;
		--p -> siz;
		return;
	}
	--p -> siz;
	if(x <= p -> l -> siz + !p -> del) Remove(p -> l, x); // 3
	else Remove(p -> r, x - p -> l -> siz - !p -> del);
}

int GetRank(Node *p, int x) {
	int res(1);
	while(p != null) {
		if(p -> val >= x) p = p -> l;
		else {
			res += p -> l -> siz + !p -> del;
			p = p -> r;
		}
	} return res;
}

int kth(Node *p, int x) {
	while(p != null) {
		if(!p -> del && p -> l -> siz + 1 == x)
			return p -> val;
		if(p -> l -> siz >= x) p = p -> l;
		else {
			x -= p -> l -> siz + !p -> del;
			p = p -> r;
		}
	}
}

int main() {
	n = read();
	null = new Node;
	root = null;
	for(rgi i = 1; i <= n; ++i) {
		int opt = read(), x = read();
		switch(opt) {
			case 1: Insert(root, x); break;
			case 2: Remove(root, GetRank(root, x)); break;
			case 3: printf("%d\n", GetRank(root, x)); break;
			case 4: printf("%d\n", kth(root, x)); break;
			case 5: printf("%d\n", kth(root, GetRank(root, x) - 1)); break;
			case 6: printf("%d\n", kth(root, GetRank(root, x + 1))); break;
		}
	}
	return 0;
}
/*
20
1 964673
5 968705
4 1
3 964673
5 965257
1 915269
1 53283
3 964673
3 53283
3 53283
1 162641
5 973984
1 948119
2 915269
2 53283
6 959161
1 531821
1 967521
2 531821
1 343410

*/
