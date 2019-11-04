#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string> 
#define INF 0x3f3f3f3f
#define NO 505
#define MO 250005
#define p pair<int, int>
#define mp(x, y) make_pair(x, y)
typedef long long ll;
//by Oliver
using namespace std;
ll read()
{
    char ch = ' ', last;
    ll ans = 0;
    while (ch < '0' || ch > '9')
        last = ch, ch = getchar();
    while (ch >= '0' && ch <= '9')
        ans = ans * 10 + int(ch - '0'), ch = getchar();
    if (last == '-')
        return -ans;
    return ans;
}
//head

int n, m, cnt, cnt1, edg, head[NO * 1000], ans;
bool book[NO * 1000];
struct tr
{
    p x, y;
	int cost;
}f[MO];
struct node
{
	int next, to;
}edge[MO];
p father[NO][NO], s, e;
//variable

bool cmp(tr i, tr j)
{
    return i.cost > j.cost;
}
p getfather(p o)
{
    if (o == father[o.first][o.second])
        return o;
    else
        return father[o.first][o.second] = getfather(father[o.first][o.second]);
}
void addt(p from, p to, int cost)
{
	f[++cnt].x = from;
	f[cnt].y = to;
	f[cnt].cost = cost;
}

void add(int from, int to)
{
	edge[++cnt1].next = head[from];
	edge[cnt1].to = to;
	head[from] = cnt1;
}
void init()
{
	freopen("maze.in", "r", stdin);
	freopen("maze.out", "w", stdout);
	n = read(), m = read();
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			char a;
			int k;
			cin>>a, k = read();
			if(a != 'X')
				addt(mp(i, j), mp(i + 1, j), k);
			cin>>a, k = read();
			if(a != 'X')
				addt(mp(i, j), mp(i, j + 1), k);
		}
    for (int i = 1; i <= n; i++)
    	for(int j = 1; j <= m; j++)
        	father[i][j] = mp(i, j);
}
void Kruskal()
{
	cout<<cnt<<endl;
    sort(f + 1, f + cnt + 1, cmp);
    for (int i = 1; i <= cnt; i++)
        if (getfather(f[i].x) != getfather(f[i].y))
        {
            p a = getfather(f[i].x), b = getfather(f[i].y);
            father[a.first][a.second] = b;
            //printf("ther is a path from %d to %d\n", f[i].x.first * 1000 + f[i].x.second, f[i].y.first * 1000 + f[i].y.second);
            add(f[i].x.first * 1000 + f[i].x.second, f[i].y.first * 1000 + f[i].y.second);
            add(f[i].y.first * 1000 + f[i].y.second, f[i].x.first * 1000 + f[i].x.second);
            edg++;
            if(edg == n * m)
                return;
        }
}
int dfs(p now, int step)
{
	//printf("now at (%d, %d), step = %d\n", now.first, now.second, step);
	if(now == e)
		ans = step;
	else
		for(int i = head[now.first * 1000 + now.second]; i; i = edge[i].next)
			if(!book[edge[i].to])
				book[edge[i].to] = true, dfs(mp(edge[i].to / 1000, edge[i].to % 1000), step + 1), book[edge[i].to] = false;
}
//functions

int main()
{
    init();
    Kruskal();
    int T = read();
    while(T--)
    {
    	memset(book, false, sizeof(book));
    	ans = -1;
    	s.first = read(), s.second = read(), e.first = read(), e.second = read();
    	book[s.first * 1000 + s.second] = true;
    	dfs(s, 0);
    	cout<<ans<<endl;
	}
    return 0;
}
//main
