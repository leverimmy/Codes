#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 1e5 + 10;

char str[N];
int len, a[N];

struct Seg_Node {
	int lc, rc;
	int dat, sum, pre, suf;
} t[N << 2];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

il void write(int x){
    if(x < 0) putchar('-'), x = -x;
    if(x > 9) write(x / 10);
    putchar(x - x / 10 * 10 + 48);
}

il void Push(int p) {
	t[p].pre = std::max(t[p << 1].pre, t[p << 1].sum + t[p << 1 | 1].pre);
	t[p].suf = std::max(t[p << 1 | 1].suf, t[p << 1 | 1].sum + t[p << 1].suf);
	t[p].sum = t[p << 1].sum + t[p << 1 | 1].sum;
	t[p].dat = std::max(t[p << 1].suf + t[p << 1 | 1].pre, std::max(t[p << 1].dat, t[p << 1 | 1].dat));
}

void Build(int p, int l, int r) {
	t[p].lc = l, t[p].rc = r;
	if(l == r) {
		t[p].dat = t[p].sum = t[p].pre = t[p].suf = a[l];
		return;
	}
	int mid = l + r >> 1;
	Build(p << 1, l, mid);
	Build(p << 1 | 1, mid + 1, r);
	Push(p);
}

int main() {
	scanf("%s", str + 1);	len = strlen(str + 1);
	for(rgi i = 1; i <= len; ++i) a[i] = (str[i] == '0') ? 1 : -1;
	Build(1, 1, len);
	write(t[1].dat);
	
	return 0;
}

