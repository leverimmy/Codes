#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const ll oo = 0x3f3f3f3f3f3f3f3fLL;
const int N = 1e5 + 10;

ll n, k;
ll a[N], sum[N];

struct Seg_Node {
	int lc, rc;
	int dat, pre, suf, sum;
} t[N << 2];

std::vector <ll> vec;

/*template <typename ASS> class heap {
	private:
		static const int MAX_SIZE = 2e5;
		int siz;	ASS _h[MAX_SIZE + 10];
	public:
		void push(ASS val) {
			_h[++siz] = val;
			int cur = siz;
			while(cur > 1) {
				if(_h[cur] > _h[cur >> 1])
					std::swap(_h[cur], _h[cur >> 1]);
				else
					break;
				cur >>= 1;
			}
		}
		void pop() {
			std::swap(_h[1], _h[siz--]);
			int cur = 1;
			while(cur << 1 <= siz) {
				int lc = cur << 1, rc = cur << 1 | 1, nxt;
				if(rc <= siz) {
					if(_h[lc] > _h[rc])
						nxt = lc;
					else
						nxt = rc;
				}
				else
					nxt = lc;
				if(_h[nxt] > _h[cur])
					std::swap(_h[nxt], _h[cur]);
				else
					break;
				nxt = cur;
			}
		}
		ASS top() {return _h[1];}
		int size() {return siz;}
		bool empty() {return !siz;}
		void clear() {siz = 0;}
		heap() {clear();}
};*/

il ll read() {
	rgl x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Push(int p) {
	t[p].dat = std::max(std::max(t[p << 1].dat, t[p << 1 | 1].dat), t[p << 1].suf + t[p << 1 | 1].pre);
	t[p].pre = std::max(t[p << 1].pre, t[p << 1].sum + t[p << 1 | 1].pre);
	t[p].suf = std::max(t[p << 1 | 1].suf, t[p << 1].suf + t[p << 1 | 1].sum);
	t[p].sum = t[p << 1].sum + t[p << 1 | 1].sum;
}

void Build(int p, int l, int r) {
	t[p].lc = l, t[p].rc = r;
	if(l == r) {
		t[p].dat = t[p].pre = t[p].suf = t[p].sum = a[l];
		return;
	}
	int mid = l + r >> 1;
	Build(p << 1, l, mid);
	Build(p << 1 | 1, mid + 1, r);
	Push(p);
}

int main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	n = read(), k = read();
	for(rgl i = 1; i <= n; ++i)	{
		a[i] = read();
		sum[i] = sum[i - 1] + a[i];
	}
	if(k == 1) {
		Build(1, 1, n);
		printf("%lld", t[1].dat);
	}
	else {
		for(rgl i = 0; i <= n - 1; ++i)	for(rgl j = i + 1; j <= n; ++j)
			vec.push_back(sum[j] - sum[i]);
		std::sort(vec.begin(), vec.end(), std::greater <ll> ());
		printf("%lld", vec[k - 1]);
	}
	return 0;
}
/*
10 1
-81 90 -76 66 -47 59 37 -60 97 60

*/
