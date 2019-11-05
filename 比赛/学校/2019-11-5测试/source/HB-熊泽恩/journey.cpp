#include <bits/stdc++.h>
#define int long long
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 2e5 + 10;
const int M = 2e5 + 10;

int X, n, m, p, maxt, pos, sum, flag;
int a[N], b[N], _next[N];
int num[N], U[N], V[N], T[N];

struct EDGE {
	int num, u, v, t;
	bool operator < (const struct EDGE &rhs) const {
		return num < rhs.num;
	}
} E[M];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Get_Next(int str[], int len)
{
	int j, k;
	_next[0] = -1, j = 0, k = -1;
	while(j < len)
	{
		if(k == -1 || str[j] == str[k])
		{
			j++, k++;
			_next[j] = k;
		}
		else
			k = _next[k];
	}
}

void KMP(int T[], int S[], int lent, int lens)//ÓÃsÆ¥Åät
{
	int i = 0, j = 0;
	while(i < lent && j < lens)
	{
		if(j == -1 || T[i] == S[j])
			i++, j++;
		else
			j = _next[j];
		if(j == lens)
		{
			pos = i - j + 1;
			flag = 1;
//			printf("%d\n", i - j + 1);
//			j = _next[j];
			return;
		}
	}
}

signed main() {
	freopen("journey.in", "r", stdin);
	freopen("journey.out", "w", stdout);
	X = read();
	while(X--) {
		n = read(), m = read(), sum = pos = flag = 0;
		for(rgi i = 0; i < m; ++i) {
			E[i].num = read();
			E[i].u = read();
			E[i].v = read();
			E[i].t = read();
		}
		p = read();
		for(rgi i = 0; i < p; ++i)	a[i] = read();
		maxt = read();
		
		std::sort(E, E + m);
		
		for(rgi i = 0; i < m; ++i)	b[i] = E[i].u;	b[m] = E[m - 1].v;
		
		Get_Next(a, p);
		KMP(b, a, m + 1, p);
		
//		printf("%d\n", pos);
		
		if(!flag) {
			puts("NO");
			continue;
		}

		pos += p - 2;
		
		for(rgi i = 0; i < pos; ++i)	sum += E[i].t;
		
		if(sum <= maxt)
			printf("YES %lld\n", sum);
		else
			puts("NO");
	}
	
	return 0;
}
/*
3
5 4
1 1 2 1
4 4 5 1
3 3 4 1
2 2 3 1
5
1 2 3 4 5
4
5 4
2 4 2 3
3 2 1 6
4 1 5 2
1 3 4 5
4
1 2 3 4
20
5 4
4 2 4 2
2 3 5 1
3 5 2 2
1 1 3 1
3
5 2 4
5

*/
