#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>

using namespace std;
const int N = 100000 + 10;
const int M = 30 + 10;
int n, m, t;
int to[N], nxt[N], fnt[N], vl[N], cnt;
int f[N];
inline int read()
{
	int s = 0;
	char ch = getchar();
	while(! (ch >= '0' && ch <= '9')) ch = getchar();
	while(ch >= '0' && ch <= '9')
		s = (s << 1) + (s << 3) + ch -'0', ch = getchar();
	return s;
}
void addline(int u, int v, int val)
{
	to[++ cnt] = v;
	vl[cnt] = val;
	nxt[cnt] = fnt[u];
	fnt[u] = cnt;
}
void init()
{
	n = read(); m = read();
	for(int i = 1; i <= m; ++ i)
	{
		int u = read(), v = read(), val = read();
		addline(u, v, val);
	}
}
void mem()
{
	cnt = 0;
	memset(f, -1, sizeof(f));
	memset(to, 0, sizeof(to));
	memset(nxt, 0, sizeof(nxt));
	memset(fnt, 0, sizeof(fnt));
	memset(vl, 0, sizeof(vl));
}
bool wrk()
{
	f[1] = 0;
	for(int i = 1; i <= n; ++ i)
	{
		for(int j = fnt[i]; j; j = nxt[j])
		{
			int tmp = f[i] ^ vl[j];
			if(f[to[j]] == -1) f[to[j]] = tmp;
			else if(f[to[j]] != tmp) return false;
		}
	}
	return true;
}
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	t = read();
	while(t --)
	{
		mem();
		init();
		if(wrk()) printf("Yes\n");
		else printf("NO\n");
	}
	
	return 0;
}
