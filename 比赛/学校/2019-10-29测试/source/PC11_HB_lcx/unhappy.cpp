#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read() {
	int x = 0, f = 1;
	char c = getchar();
	while(!isdigit(c)) {
		if(c == '-') {
			f = -1;
		}
		c = getchar();
	}
	while(isdigit(c)) {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f;
}
int cnt, root;
struct treap {
	int lc, rc, cnt, siz, val, pri;
} tree[5000001];
inline void upt(const int &k) {
	tree[k].siz = tree[tree[k].lc].siz + tree[tree[k].rc].siz + tree[k].cnt;
}
inline void zig(int &k) {
	int y = tree[k].lc;
	tree[k].lc = tree[y].rc;
	tree[y].rc = k;
	tree[y].siz = tree[k].siz;
	upt(k);
	k = y;
}
inline void zag(int &k) {
	int y = tree[k].rc;
	tree[k].rc = tree[y].lc;
	tree[y].lc = k;
	tree[y].siz = tree[k].siz;
	upt(k);
	k = y;
}
inline void Insert(int &k, const int &key) {
	if(!k) {
		k = ++cnt;
		tree[k].val = key;
		tree[k].pri = rand();
		tree[k].cnt = tree[k].siz = 1;
		tree[k].lc = tree[k].rc = 0;
		return;
	} else {
		tree[k].siz++;
	}
	if(tree[k].val == key) {
		tree[k].cnt++;
	} else if(key < tree[k].val) {
		Insert(tree[k].lc, key);
		if(tree[tree[k].lc].pri < tree[k].pri) {
			zig(k);
		}
	} else {
		Insert(tree[k].rc, key);
		if(tree[tree[k].rc].pri < tree[k].pri) {
			zag(k);
		}
	}
}
inline void Delete(int &k, const int &key) {
	if(tree[k].val == key) {
		if(tree[k].cnt > 1) {
			tree[k].cnt--;
			tree[k].siz--;
		} else if(!tree[k].lc || !tree[k].rc) {
			k = tree[k].lc + tree[k].rc;
		} else if(tree[tree[k].lc].pri < tree[tree[k].rc].pri) {
			zig(k);
			Delete(k, key);
		} else {
			zag(k);
			Delete(k, key);
		}
		return;
	}
	tree[k].siz--;
	if(key < tree[k].val) {
		Delete(tree[k].lc, key);
	} else {
		Delete(tree[k].rc, key);
	}
	return;
}
inline int QueryKth(int k) {
	int x = root;
	while(x) {
		if(tree[tree[x].lc].siz < k && tree[tree[x].lc].siz + tree[x].cnt >= k) {
			return tree[x].val;
		}
		if(tree[tree[x].lc].siz >= k) {
			x = tree[x].lc;
		} else {
			k -= tree[tree[x].lc].siz + tree[x].cnt;
			x = tree[x].rc;
		}
	}
	return 0;
}
inline int QueryQian(const int &key) {
	int x = root, res = -0x7ffffff;
	while(x) {
		if(tree[x].val < key) {
			res = tree[x].val;
			x = tree[x].rc;
		} else {
			x = tree[x].lc;
		}
	}
	return res;
}
signed main() {
	freopen("unhappy.in", "r", stdin);
	freopen("unhappy.out", "w", stdout);
	int n = read(), m = read();
	int gzz = 0, num = 0, sum = 0;
	while(n--) {
		char x;
		cin >> x;
		if(x == 'I') {
			int k = read();
			if(k < m) {
				continue;
			}
			Insert(root, k - gzz);
			sum++;
		}
		if(x == 'A') {
			int k = read();
			gzz += k;
		}
		if(x == 'S') {
			int k = read();
			gzz -= k;
			Insert(root, m - gzz);
			int qqq = QueryQian(m - gzz);
			while(qqq != -0x7ffffff) {
				Delete(root, qqq);
				qqq = QueryQian(m - gzz);
				num++;
				sum--;
			}
			Delete(root, m - gzz);
		}
		if(x == 'F') {
			int k = read();
			if(k > sum) {
				printf("-1\n");
			} else {
				printf("%lld\n", QueryKth(sum - k + 1) + gzz);
			}
		}
	}
	printf("%lld\n", num);
	return 0;
}
