#pragma GCC optimize (2)
#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

static const int MAX_DIGIT = 4;

const int N = 4e6 + 10;

ll n, tmp;

struct INT {
	int len;	ll d[MAX_DIGIT];
#define BASE 1000000000
#define DIGIT 9
	struct INT operator + (const struct INT &rhs) const {
		struct INT res;
		res.len = std::max(rhs.len, len);
		
		for(rgi i = 1; i <= res.len; ++i)	res.d[i] = d[i] + rhs.d[i];
		for(rgi i = 1; i <= res.len; ++i) if(res.d[i] >= 10) {
			res.d[i + 1] += res.d[i] / BASE;
			res.d[i] %= BASE;
		}
		if(res.d[res.len + 1])	res.len++;
		while(!res.d[res.len] && res.len > 1)	res.len--;
		return res;
	}
	struct INT operator * (const struct INT &rhs) const {
		struct INT res;
		res.len = rhs.len + len;
		
		for(rgi i = 1; i <= len; ++i)
			for(rgi j = 1; j <= rhs.len; ++j) {
				res.d[i + j - 1] += d[i] * rhs.d[j];
				res.d[i + j] += res.d[i + j - 1] / BASE;
				res.d[i + j - 1] %= BASE;
			}
		
		/*for(rgi i = 1; i <= len; ++i)	for(rgi j = 1; j <= rhs.len; ++j)
			res.d[i + j - 1] += d[i] * rhs.d[j];
		for(rgi i = 1; i <= res.len; ++i) if(res.d[i] >= 10) {
			res.d[i + 1] += res.d[i] / BASE;
			res.d[i] %= BASE;
		}*/
		
		if(res.d[res.len])	res.len++;
		while(!res.d[res.len] && res.len > 1)	res.len--;
		return res;
	}
	bool operator < (const struct INT &rhs) const {
		if(len != rhs.len)	return len < rhs.len;
		else {
			for(rgi i = len; i >= 1; --i) {
				if(d[i] < rhs.d[i])	return 1;
				else if(d[i] > rhs.d[i])	return 0;
				else	continue;
			}
			return 0;
		}
	}
	void in(ll x) {
		d[1] = x % BASE, len = 1;
		if(x > 1000000000)
			d[2] = x / BASE, len = 2;
	}
	void out() {
		while(!d[len] && len > 1)	len--;
		for(rgi i = len; i >= 1; --i)	printf("%9lld", d[i]);
	}
	void clear() {memset(d, 0, sizeof(d));}
	INT() {clear();}
} ans, CUR;

template <typename T> class heap {
	private:
		static const int MAX_SIZE = 4e6;
		int siz;
		T _h[MAX_SIZE + 10];
	public:
		void push(T val) {
			_h[++siz] = val;
			int cur = siz;
			while(cur > 1) {
				if(_h[cur] < _h[cur >> 1])
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
					if(_h[lc] < _h[rc])
						nxt = lc;
					else
						nxt = rc;
				}
				else
					nxt = lc;
				if(_h[nxt] < _h[cur])
					std::swap(_h[nxt], _h[cur]);
				else
					break;
				cur = nxt;
			}
		}
		T top() {return _h[1];}
		int size() {return siz;}
		void clear() {siz = 0;}
		bool empty() {return !siz;}
		heap() {clear();}
};

il ll read() {
	rgl x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

heap <struct INT> h;

int main() {
	freopen("stone.in", "r", stdin);
	freopen("stone.out", "w", stdout);
	
	n = read();
	for(rgi i = 1; i <= n; ++i)	{
		tmp = read();
		CUR.in(tmp);
		h.push(CUR);
	}
	while(h.size() >= 2) {
		struct INT A = h.top();	h.pop();
		struct INT B = h.top();	h.pop();
		h.push(A + B);
		ans = A * B + ans;
	}
	ans.out();
	return 0;
}

