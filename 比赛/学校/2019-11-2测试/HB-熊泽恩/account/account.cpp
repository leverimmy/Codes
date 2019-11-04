#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int oo = 0x3f3f3f3f;
const int N = 1e5 + 10;

int n, __A__, __B__, cnt, ans;
int a[N], res[N], tmp[N];
ll X;

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int randint(int L, int R) {
	const long long A = __A__, B = __B__;
	X = (X * X + A * X + B) % 99824353LL;
	return X % (R - L + 1) + L;
}

int Qsort(int A[],int L,int R) {
	if(L >= R)	return 1;
	int l = L;
	int r = R;
	int index = randint(L, R);
	int key = A[index];
	std::swap(A[l], A[index]);
	while(l<r) {
		while(l < r && A[r] >= key)--r;	A[l] = A[r];
		while(l < r && A[l] <= key)++l;	A[r] = A[l];
	}
	A[l] = key;
	return std::max(Qsort(A, L, l - 1),	Qsort(A, l + 1, R)) + 1;
}

int main() {
//	freopen("account.in", "r", stdin);
//	freopen("account.out", "w", stdout);
	n = read(), __A__ = read(), __B__ = read();
	for(rgi i = 1; i <= n; ++i)	a[i] = i;
	do {
		X = 1;
//		memcpy(tmp, a, n + 1 << 2);
		for(rgi i = 1; i <= n; ++i)	tmp[i] = a[i];
		cnt = Qsort(tmp, 1, n);
		if(cnt >= ans) {
			ans = cnt;
//			memcpy(res, a, n + 1 << 2);
			for(rgi i = 1; i <= n; ++i)	res[i] = a[i];
		}
	} while(std::next_permutation(a + 1, a + n + 1));
	
	for(rgi i = 1; i <= n; ++i)	printf("%d ", res[i]);
	return 0;
}

