#include<cstdio>
#include<queue>
#include<utility>

typedef std::pair<int, int> pr;
const int N = 100100; 

std::queue<pr> li[N];
int in[N], qu[N], an[N];
int main() {

    freopen("array.in", "r", stdin);
    freopen("array.out", "w", stdout);

    int n;
    scanf("%d", &n);
    for (register int i = 1; i <= n; ++i) {
        scanf("%d", in + i);
    }
    int m, a;
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%d %d", &a, &qu[i]);
        li[a].push(std::make_pair(0, i));
    }

    pr now;
    for (register int i = 1; i <= n; ++i) {
        while (!li[i].empty()) {
            now = li[i].front(); li[i].pop();
            if (i + qu[now.second] + in[i] > n) an[now.second] = now.first + 1;
            else now.first++, li[i + qu[now.second] + in[i]].push(now);
        }
    }

    for (register int i = 1; i <= n; ++i) {
        printf("%d\n", an[i]);
    }

    return 0;
}