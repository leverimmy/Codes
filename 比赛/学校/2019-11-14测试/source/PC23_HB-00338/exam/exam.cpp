#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 5e6 + 10;
const int M = 5e6 + 10;

int n, cnt, VERT, EDGE, first_max, second_max, ans;
int first[N], vis[N], rev[N];

std::vector <int> vec;

struct IN {
	int a, b;
} t[N];

struct edge {
	int to, _next;
} e[M << 1];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Add_Edge(int u, int v) {
	e[cnt].to = v;
	e[cnt]._next = first[u];
	first[u] = cnt++;
}

void dfs(int x) {
	
	vis[x] = 1; VERT++;
	
	if(x > n) {
		if(first_max < x - n) {
			second_max = first_max;
			first_max = x - n;
		}
		else
			second_max = std::max(second_max, x - n);
	}
	
	for(rgi i = first[x]; ~i; i = e[i]._next) {
		int y = e[i].to;	EDGE++;
		if(vis[y])	continue;
		dfs(y);
	}
}

int main() {
	freopen("exam.in", "r", stdin);
	freopen("exam.out", "w", stdout);
	n = read();
	memset(first, -1, sizeof(first));
	for(rgi i = 1; i <= n; ++i) {
		t[i].a = read(), vec.push_back(t[i].a);
		t[i].b = read(), vec.push_back(t[i].b);
	}
	//Input
	
	std::sort(vec.begin(), vec.end());
	for(rgi i = 1; i <= n; ++i) {
		
		int A = std::lower_bound(vec.begin(), vec.end(), t[i].a) - vec.begin() + 1;
		int B = std::lower_bound(vec.begin(), vec.end(), t[i].b) - vec.begin() + 1;
		
		rev[A] = t[i].a;
		rev[B] = t[i].b;
		
		Add_Edge(i, A + n), Add_Edge(A + n, i);
		Add_Edge(i, B + n), Add_Edge(B + n, i);
	}
	
//	printf("tot = %d", tot);
	
	for(rgi i = 1; i <= n; ++i) if(!vis[i]) {
		
		first_max = second_max = VERT = EDGE = 0;
		
		dfs(i);
		
		if(EDGE > VERT * 2) {
//			printf("EDGE : %d VERT : %d", EDGE, VERT);	
			puts("-1");
			return 0;
		}
		else if(EDGE == VERT * 2)
			ans = std::max(ans, first_max);
		else
			ans = std::max(ans, second_max);
	}
	
	printf("%d", rev[ans]);
	return 0;
}
/*
2
1 5
1 7

*/
