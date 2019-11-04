#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 1e5 + 10 , MAX_M = 5e5 + 10 , INF = 0x3f3f3f3f ;

struct Edge {int x , y , v ;}eg[MAX_M] ;
struct Link {
	int num , val ;
	Link *next ;
}list[MAX_N << 1] ;

Link *head[MAX_N] ;
int n , m , cur , ans , fa[MAX_N] ;

bool cmp(Edge a , Edge b) {return a.v < b.v ;}
int findset(int x) {return fa[x] == -1 ? x : (fa[x] = findset(fa[x])) ;}

inline int read() {
	char c = getchar() ;
	int num = 0 , f = 1 ;

	for (; c < '0' || c > '9' ; c = getchar()) if (c == '-') f = -f ;
	for (; c >= '0' && c <= '9' ; c = getchar()) num = num * 10 - '0' + c ;

	return num * f ;
}

void ins(int x , int y , int v) {
	list[cur].num = y ;
	list[cur].val = v ;
	list[cur].next = head[x] ;
	head[x] = &list[cur++] ;
}

void dfs(int x , int fa , int F) {
	ans += F ;

	for (Link *h = head[x] ; h ; h = h->next) {
		int nx = h->num ;
		if (nx == fa) continue ;

		dfs(nx , x , std::max(F , h->val)) ;
	}
}

int main() {
	freopen("tree.in" , "r" , stdin) ;
	freopen("tree.out" , "w" , stdout) ;

	n = read() ; m = read() ;
	for (int i = 0 ; i < m ; ++i) {
		int a , b , c ; a = read() ; b = read() ; c = read() ;

		eg[i] = (Edge){a , b , c} ;
	}

	///

	std::sort(eg + 0 , eg + m , cmp) ;
	for (int i = 1 ; i <= n ; ++i) fa[i] = -1 ;
	for (int i = 0 ; i < m ; ++i) {
		Edge *p = &eg[i] ;
		int fx = findset(p->x) , fy = findset(p->y) ;
		if (fx == fy) continue ;

		ins(p->x , p->y , p->v) ; ins(p->y , p->x , p->v) ;
		fa[fx] = fy ;
	}

	dfs(1 , 1 , 0) ;
	printf("%d\n" , ans) ;

	fclose(stdin) ; fclose(stdout) ;

	return 0 ;
}