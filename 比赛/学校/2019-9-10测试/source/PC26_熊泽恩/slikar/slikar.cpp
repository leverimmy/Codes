#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <queue>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register int

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 50 + 10;
const int M = 50 + 10;
const int STEP = 2500 + 10;

int n, m, cnt, ans = oo;
bool vis[N][M];
int e[N][M];
char E[N][M];

struct node
{
    int x, y, time;
} start, end;

queue <struct node> q;

il int read()
{
    rgi x = 0, f = 0, ch;
    while(!isdigit(ch = getchar())) f |= ch == '-';
    while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

bool is_safe1(int x, int y)
{
    if(x < 1 || y < 1 || x > n || y > m || e[x][y])
        return 0;
    if(E[x][y] == '.')
        return 1;
    return 0;
}

bool is_safe2(int x, int y, int time)
{
    if(x < 1 || y < 1 || x > n || y > m)
        return 0;
    if(vis[x][y])
        return 0;
    if(E[x][y] != '*' && E[x][y] != 'X' && e[x][y] == 0)
        return 1;
    if(e[x][y] <= time)
        return 0;
    if(E[x][y] == '.')
        return 1;
    return 0;
}

void push_in(int x, int y, int time)
{
    struct node tmp;
    tmp.x = x, tmp.y = y, tmp.time = time;
    q.push(tmp);
}

void bfs1()
{
    while(!q.empty())
    {
        struct node cur = q.front();
        q.pop();
        if(e[cur.x][cur.y])
            continue;
        e[cur.x][cur.y] = cur.time;
        if(is_safe1(cur.x, cur.y + 1))
            push_in(cur.x, cur.y + 1, cur.time + 1);
        if(is_safe1(cur.x + 1, cur.y))
            push_in(cur.x + 1, cur.y, cur.time + 1);
        if(is_safe1(cur.x - 1, cur.y))
            push_in(cur.x - 1, cur.y, cur.time + 1);
        if(is_safe1(cur.x, cur.y - 1))
            push_in(cur.x, cur.y - 1, cur.time + 1);
    }
}

void bfs2()
{
    while(!q.empty())
    {
        struct node cur = q.front();
        q.pop();
        if(cur.x == end.x && cur.y == end.y)
        {
            ans = cur.time;
            return;
        }
        if(vis[cur.x][cur.y])
            continue;
        vis[cur.x][cur.y] = 1;
        if(is_safe2(cur.x - 1, cur.y, cur.time + 1))
            push_in(cur.x - 1, cur.y, cur.time + 1);
        if(is_safe2(cur.x + 1, cur.y, cur.time + 1))
            push_in(cur.x + 1, cur.y, cur.time + 1);
        if(is_safe2(cur.x, cur.y - 1, cur.time + 1))
            push_in(cur.x, cur.y - 1, cur.time + 1);
        if(is_safe2(cur.x, cur.y + 1, cur.time + 1))
            push_in(cur.x, cur.y + 1, cur.time + 1);
    }
}

int main()
{
//	freopen("slikar.in", "r", stdin);
//	freopen("slikar.out", "w", stdout);
    n = read(), m = read();
    for(rgi i = 1; i <= n; ++i)
    	scanf("%s", E[i] + 1); 
    for(rgi i = 1; i <= n; ++i)
    {
        for(rgi j = 1; j <= m; ++j)
        {
            if(E[i][j] == 'S')
            {
                start.x = i;
                start.y = j;
                start.time = 0;
            }
            if(E[i][j] == 'D')
            {
                end.x = i;
                end.y = j;
            }
            if(E[i][j] == '*')
            {
                cnt++;
                push_in(i, j, 0);
            }
        }
    }
    if(cnt != 0)
        bfs1();//处理洪水
    q.push(start);
    bfs2();//处理画家
    if(ans == oo)
    	puts("ORZ hzwer!!!");
    else
        printf("%d", ans);
    return 0;
}
