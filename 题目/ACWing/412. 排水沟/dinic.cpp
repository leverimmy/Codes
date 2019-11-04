#include <iostream>
#include <cstring>

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 200 + 10;
const int M = 200 + 10;

int n, m, s, t, cnt, max_flow, flow;
int first[N], dep[N];

struct edge
{
    int to, _next, cap;
} e[M << 1];

struct QUEUE
{
    static const int MAX_SIZE = 2e5;
    int _head, _tail, que[MAX_SIZE + 10];
    void clear(){_head = _tail = 0;}
    void push(int val){que[++_tail] = val;}
    void pop(){(_head + 1 == _tail) ? (_head = _tail = 0) : (_head++);}
    int front(){return que[_head + 1];}
    int back(){return que[_tail];}
    int size(){return _tail - _head;}
    bool empty(){return _head == _tail;}
    QUEUE(){clear();}
};

void Add_Edge(int u, int v, int w)
{
    e[cnt].to = v;
    e[cnt].cap = w;
    e[cnt]._next = first[u];
    first[u] = cnt++;
}

bool bfs(int S, int T)
{
    memset(dep, 0, sizeof(dep));
    struct QUEUE q;
    dep[S] = 1, q.push(S);
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        for(int i = first[x]; ~i; i = e[i]._next)
        {
            int y = e[i].to;
            if(e[i].cap && !dep[y])
            {
                dep[y] = dep[x] + 1;
                q.push(y);
                if(y == T)
                    return 1;
            }
        }
    }
    return 0;
}

int Dinic(int x, int FLOW)
{
	if(x == t)
		return FLOW;
    int rest = FLOW;
    for(int i = first[x]; ~i; i = e[i]._next)
    {
        int y = e[i].to;
        if(e[i].cap && dep[y] == dep[x] + 1)
        {
            int cur_flow = Dinic(y, min(rest, e[i].cap));
            if(!cur_flow)
                dep[y] = 0;
            e[i].cap -= cur_flow;
            e[i ^ 1].cap += cur_flow;
            rest -= cur_flow;
        }
    }
    return FLOW - rest;
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> m; s = 1, t = m;
    memset(first, -1, sizeof(first));
    for(int i = 1; i <= n; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        Add_Edge(u, v, w);
        Add_Edge(v, u, 0);
    }
    while(bfs(s, t))
        while(flow = Dinic(s, oo))
            max_flow += flow;
    printf("%d", max_flow);
    return 0;
}
