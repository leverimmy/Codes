#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 1e5 + 10;
const int M = 1e5 + 10;

int n, q, cnt, root, ans;
int first[N], lg2[N] = {-1}, dep[N], siz[N];
int f[N][20];

std::vector <int> ch[N];

struct edge {
	int to, _next;
} e[M << 1];

struct node {
	int siz, dep, has;
	std::vector <int> ch;
} t[N];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Add_Edge(int u, int v) {
	e[cnt].to = v;
	e[cnt]._next = first[u];
	first[u] = cnt++;
}

void Build(int x, int p) {
	t[x].siz = 1;
	t[x].dep = t[p].dep + 1;
	t[p].ch.push_back(x);
	f[x][0] = p;
	
	for(rgi i = 1; i <= lg2[t[x].dep]; ++i)
		f[x][i] = f[f[x][i - 1]][i - 1];
	for(rgi i = first[x], y = e[i].to; ~i; i = e[i]._next, y = e[i].to)
		if(y != p) {
			Build(y, x);
			t[x].siz += t[y].siz;
		}
	std::sort(t[x].ch.begin(), t[x].ch.end());
}

void Insert(int x, int val) {
	if(t[x].siz - t[x].has == val && !ans) ans = x;
	if(t[x].ch.size() == 0) {
		t[x].has++;
		return;
	}
#define VEC std::vector<int>::iterator
	for(VEC it = t[x].ch.begin(); it != t[x].ch.end(); ++it) {
		if(t[*it].siz >= val) {
			Insert(*it, val);
			t[*it].has = val;
			break;
		}
		else {
			Insert(*it, t[*it].siz);
			val -= t[*it].siz;
			t[*it].has = t[*it].siz;
		}
	}
}

void Delete(int x) {
	int y = x;
	for(rgi i = lg2[t[x].dep]; i >= 0; --i)
		if(t[f[y][i]].has == t[f[y][i]].siz && f[y][i] != 0)
			y = f[y][i];
	for(rgi i = y; i; i = f[i][0])
		t[i].has--;
	ans = t[x].dep - t[y].dep;
}

int main() {
//	freopen("game.in", "r", stdin);
//	freopen("game.out", "w", stdout);
	n = read(), q = read();
	memset(first, -1, sizeof(first));
	for(rgi i = 1; i <= n; ++i) lg2[i] = lg2[i >> 1] + 1;
	for(rgi i = 1; i <= n; ++i) {
		int x = read();
		if(!x) root = i;
		else Add_Edge(x, i), Add_Edge(i, x);
	}
	Build(root, t[0].dep = 0);
	for(rgi i = 1; i <= q; ++i, ans = 0) {
		int opt = read(), k = read();
		if(opt == 1) {
			Insert(root, k);
			t[root].has += k;
		}
		else
			Delete(k);
		printf("%d\n", ans);
	}
	return 0;
}
/*
8 4
0
1
2
2
3
3
4
6
1 8
2 5
2 7
2 8

*/
