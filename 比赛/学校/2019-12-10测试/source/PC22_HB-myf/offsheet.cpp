#include <bits/stdc++.h>
using namespace std;

const int N = 405;
int w[N][N];
int la[N], lb[N];
bool va[N], vb[N];
int match[N];
int n, delta, upd[N];

struct poi
{
	int x, y;
}a[N];

bool dfs(int x) {
	va[x] = 1;
	for (int y = 1; y <= n; y++)
		if (!vb[y])
			if (la[x] + lb[y] - w[x][y] == 0) {
				vb[y] = 1;
				if (!match[y] || dfs(match[y])) {
					match[y] = x;
					return true;
				}
			}
			else upd[y] = min(upd[y], la[x] + lb[y] - w[x][y]);
	return false;
}

int KM() {
	for (int i = 1; i <= n; i++) {
		la[i] = -(1 << 30);
		lb[i] = 0;
		for (int j = 1; j <= n; j++)
			la[i] = max(la[i], w[i][j]);
	}
	for (int i = 1; i <= n; i++)
		while (true) {
			memset(va, 0, sizeof(va));
			memset(vb, 0, sizeof(vb));
			delta = 1 << 30;
			for (int j = 1; j <= n; j++) upd[j] = 1 << 30; 
			if (dfs(i)) break;
			for (int j = 1; j <= n; j++)
				if (!vb[j]) delta = min(delta, upd[j]);
			for (int j = 1; j <= n; j++) {
				if (va[j]) la[j] -= delta;
				if (vb[j]) lb[j] += delta;
			}
		}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans += w[match[i]][i];
	return ans;
}

inline int get_dis(int p,int q) {
	return abs(a[p].x-a[q].x)+abs(a[p].y-a[q].y);
}

int main() {
	freopen("offsheet.in", "r", stdin);
	freopen("offsheet.out", "w", stdout);
	
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &a[i].x, &a[i].y);
	for (int i = n + 1; i <= (n<<1); i++)
	{
		scanf("%d %d", &a[i].x, &a[i].y);
		for (int j = 1; j <= n; j++)
			w[j][i-n] = get_dis(j,i);
	}
	
	cout<<KM()<<endl;
	return 0;
}
