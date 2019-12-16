#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define il inline

const int N = 500 + 10;

int n, m, idx, ans;
int first[N], siz[N], stk[N];

struct node {
	int lc, rc, up, dn, row, col;
} t[N * N];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Build(int R, int C) {
	for(rgi i = 0; i <= C; ++i) {
		t[i].lc = i - 1;
		t[i].rc = i + 1;
		t[i].up = t[i].dn = i;
	} t[0].lc = C, t[C].rc = 0, idx = C + 1;
	memset(first, -1, sizeof(first));
	memset(siz, 0, sizeof(siz));
}

void Insert(int R, int C) {
	siz[C]++;
	t[idx].row = R, t[idx].col = C;
	
	t[idx].up = C;
	t[idx].dn = t[C].dn;
	t[t[C].dn].up = idx;
	t[C].dn = idx;
	
	if(first[R] == -1) first[R] = t[idx].lc = t[idx].rc = idx;
	else {
		t[idx].rc = first[R];
		t[idx].lc = t[first[R]].lc;
		t[t[first[R]].lc].rc = idx;
		t[first[R]].lc = idx;
	}
	idx++;
}

void Remove(int C) {
	t[t[C].rc].lc = t[C].lc;
	t[t[C].lc].rc = t[C].rc;
	
	for(rgi i = t[C].dn; i != C; i = t[i].dn)
		for(rgi j = t[i].rc; j != i; j = t[j].rc) {
			t[t[j].dn].up = t[j].up;
			t[t[j].up].dn = t[j].dn;
			siz[t[j].col]--;
		}
}

void Recover(int C) {
	for(rgi i = t[C].up; i != C; i = t[i].up)
		for(rgi j = t[i].lc; j != i; j = t[j].lc) {
			t[t[j].dn].up = j;
			t[t[j].up].dn = j;
			siz[t[j].col]++;
		}
	
	t[t[C].rc].lc = C;
	t[t[C].lc].rc = C;
}

bool Dance(int dep) {
	if(!t[0].rc) {
		ans = dep;
		return 1;
	}
	int C = t[0].rc;
	for(rgi i = C; i; i = t[i].rc) if(siz[i] < siz[C]) C = i;
	
	Remove(C);
	for(rgi i = t[C].dn; i != C; i = t[i].dn) {
		stk[dep] = t[i].row;
		for(rgi j = t[i].rc; j != i; j = t[j].rc) Remove(t[j].col);
		if(Dance(dep + 1)) return 1;
		for(rgi j = t[i].lc; j != i; j = t[j].lc) Recover(t[j].col);
	}
	Recover(C);
	
	return 0;
}

int main() {
	n = read(), m = read();
	Build(n, m);
	for(rgi i = 1; i <= n; ++i) for(rgi j = 1; j <= m; ++j) {
		int x = read();
		if(x) Insert(i, j);
	} Dance(1);
	if(ans)
		for(rgi i = 1; i < ans; ++i) printf("%d ", stk[i]);
	else
		puts("No Solution!");
	return 0;
}
