#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
const int N = 500000 + 10;
int n, m;
long long ans;
int fa[N];
struct edge
{
	int u, v, vl;
}e[N];

inline int get_father(int x)
{
	if(fa[x] == x) return x;
	fa[x] = get_father(fa[x]);
	return fa[x];
}

bool cmp(edge e, edge f)
{
	return e.vl < f.vl;
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

void init()
{
	n = read(); m = read();
	for(int i = 1; i <= m; ++ i)
		e[i].u = read(), e[i].v = read(), e[i].vl = read();
}
void wrk()
{
	sort(e + 1, e + m + 1, cmp);
	for(int i = 1; i <= n; ++ i)
		fa[i] = i;
	for(int i = 1; i <= m; ++ i)
	{
		fa[e[i].u] = get_father(e[i].u);
		fa[e[i].v] = get_father(e[i].v);
		
		if(fa[e[i].u] == fa[e[i].v]) continue;
		fa[e[i].v] = e[i].u;
		ans += e[i].vl;
	}
	printf("%lld", ans);
}
int main()
{
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	init();
	wrk();
	
	return 0;
}
