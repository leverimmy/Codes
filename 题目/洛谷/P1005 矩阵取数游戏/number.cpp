#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;
const int DIGIT = 1000 + 10;
const int N = 80 + 10;
const int M = 80 + 10;

int n, m;
int w[M];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

struct number
{
	int a[N], len;
	void init(){len = 0, memset(a, 0, sizeof(a));}
	number(){init();}
	
	struct number operator + (const struct number &add) const {
		struct number res;
		res.len = max(add.len, len) + 1;
		for(rgi i = 0; i < res.len; ++i)
			res.a[i] = a[i] + add.a[i];
		for(rgi i = 0; i < res.len; ++i)
			if(res.a[i] >= 10)
			{
				res.a[i + 1] ++;
				res.a[i] -= 10;
			}
		while(res.a[res.len - 1] == 0 && res.len > 1)
			res.len--;
		return res;
	}
	
	struct number operator * (const int &tim) const {
		struct number res;
		res.len = len + 1;
		for(rgi i = 0; i < res.len; ++i)
			res.a[i] = a[i] * tim;
		for(rgi i = 0; i < res.len; ++i)
			if(res.a[i] >= 10)
			{
				res.a[i + 1] += res.a[i] / 10;
				res.a[i] %= 10;
			}
		while(res.a[res.len - 1] == 0 && res.len > 1)
			res.len--;
		return res;
	}

	struct number& operator = (const struct number& it){
		len = it.len;
		for(rgi i = 0; i < len; i++) a[i] = it.a[i];
		return *this;
	}
} two[M], f[M][M], ans;

void In(struct number & x)
{
	char tmp[N]; scanf("%s", tmp);
	x.init(); x.len = strlen(tmp);
	for(rgi i = 0; i < x.len; ++i)
		x.a[i] = tmp[i] - '0';
}

void Out(struct number x)
{
	for(rgi i = x.len - 1; i >= 0; --i)	printf("%d", x.a[i]);
}

void prework()
{
	two[0].a[0] = 1;
	for(rgi i = 1; i <= m; ++i)
	{
		two[i].a[0] = 1;
		two[i] = two[i - 1] * 2;
		Out(two[i]), putchar('\n');
	}
}

struct number max(struct number a, struct number b)
{
	if(a.len > b.len)	return a;
	if(a.len < b.len)	return b;
	if(a.len == b.len)
	{
		for(rgi i = 0; i < a.len; ++i)
		{
			if(a.a[i] > b.a[i])
				return a;
			if(a.a[i] < b.a[i])
				return b;
		}
	}
	return a;
}

int main()
{
	n = read(), m = read();
	prework();
	for(rgi rnd = 1; rnd <= n; ++rnd)
	{
		for(rgi i = 1; i <= m; ++i) w[i] = read();
		for(rgi len = 1; len <= m; ++len)
		{
			for(rgi l = 1; l + len - 1 <= m; ++l)
			{
				int r = l + len - 1;
				f[l][r] = max(f[l + 1][r] + two[m - (r - l)] * w[l], f[l][r + 1] + two[m - (r - l)] * w[r]);
			}
		}
		ans = (ans + f[1][n]);
	}
	Out(ans);
	return 0;
}

