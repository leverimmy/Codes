
#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
const int N = 100000 + 10;
int n, m, f[N], a[N];
int sum[N], num, ans[N];
struct qu
{
	int id, k, p;
}q[100];

bool cmp(qu e,qu f)
{
	return e.k < f.k;
}
inline int read()
{
	int s = 0;
	char ch = getchar();
	while(! (ch >= '0' && ch <= '9')) ch = getchar();
	while(ch >= '0' && ch <= '9')
		s = (s << 1) + (s << 3) + ch -'0', ch = getchar();
	return s;
}
int baoli(int k, int nw)
{
	if(f[nw] != 0) return f[nw];
	if(nw > n) return 0;
	f[nw] = baoli(k, k + a[nw]) + 1;
	return f[nw];
}
int main()
{
	freopen("array.in", "r", stdin);
	freopen("array.out", "w", stdout);

	n = read();
	for(int i = 1;i <= n; ++ i)
		a[i] = read() + i;
	m = read();
	for(int i = 1; i <= m; ++ i)
		q[i].id = i, q[i].p = read(), q[i].k = read(), ++ sum[q[i].k];
	sort(q + 1, q + m + 1, cmp);
	for(int i = 1; i <= m; ++ i)
	{
		if(sum[q[i].k] != sum[q[i - 1].k])
			memset(f,0,sizeof(f));
		ans[q[i].id] = baoli(q[i].k, q[i].p);
	}
	for(int i = 1; i <= m; ++ i)
		printf("%d\n", ans[i]);
	return 0;
}
