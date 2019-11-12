#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

struct INT {
	static const int MAX_DIGIT = 30;
	int len;	ll d[MAX_DIGIT + 10];
#define BASE 100000000
#define DIGIT 8
	struct INT operator + (const struct INT &rhs) const {
		struct INT res;
		res.len = std::max(rhs.len, len);
		
		for(rgi i = 1; i <= res.len; ++i)	res.d[i] = d[i] + rhs.d[i];
		for(rgi i = 1; i <= res.len; ++i) {
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
	void in() {
		char tmp[MAX_DIGIT + 10];	scanf("%s", tmp + 1);
		len = strlen(tmp + 1);
		for(rgi i = len, j = 1; i >= 1; --i) {
			d[j] = d[j] * 10 + tmp[i] - '0';
			if((len - i + 1) % DIGIT == 0)	j++;
		}
		while(!d[len] && len > 1)	len--;
	}
	void out() {for(rgi i = len; i >= 1; --i)	printf("%8lld", d[i]);}
	void clear() {memset(d, 0, sizeof(d));}
	INT() {clear();}
} A, B;

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	A.in();
	B.in();
	A.out();	putchar('\n');
	B.out();	putchar('\n');
	(A + B).out();	putchar('\n');
	(A * B).out();	putchar('\n');
	return 0;
}

