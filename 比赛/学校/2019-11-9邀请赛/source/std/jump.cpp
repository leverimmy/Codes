#include <stdio.h>
#include <stdlib.h>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 5e4 + 10 , MAX_K = 200 + 10 ;

struct Link {
	int num ;
	Link *next ;
}list[MAX_N << 1] ;

ll res ;
Link *head[MAX_N] ;
int n , k , cur , siz[MAX_N] , tmp[MAX_K] , f[MAX_N][MAX_K] , g[MAX_N][MAX_K] ;

inline int mod(int x) {
	if (!k) return 0 ;
	return x >= k ? x - k : x ;
}

inline int read() {
	char c = getchar() ;
	int num = 0 , f = 1 ;

	for (; c < '0' || c > '9' ; c = getchar()) if (c == '-') f = -f ;
	for (; c >= '0' && c <= '9' ; c = getchar()) num = num * 10 - '0' + c ;

	return num * f ;
}

void ins(int x , int y) {
	list[cur].num = y ;
	list[cur].next = head[x] ;
	head[x] = &list[cur++] ;
}

void dp_f(int x , int fa) {
	++f[x][0] ; siz[x] = 1 ;

	for (Link *h = head[x] ; h ; h = h->next) {
		int nx = h->num ;
		if (nx == fa) continue ;

		dp_f(nx , x) ; siz[x] += siz[nx] ;
		for (int i = 0 ; i < k ; ++i) f[x][mod(i + 1)] += f[nx][i] ;
	}
}

void dp_g(int x , int fa) {
	for (int i = 0 ; i < k ; ++i) tmp[i] = 0 ;
	for (Link *h = head[x] ; h ; h = h->next)
		if (h->num != fa) for (int i = 0 ; i < k ; ++i) tmp[i] += f[h->num][i] ;

	for (Link *h = head[x] ; h ; h = h->next) {
		int nx = h->num ;
		if (nx == fa) continue ;

		res += (ll)siz[nx] * (n - siz[nx]) << 1 ;
		for (int i = 0 ; i < k ; ++i) g[nx][mod(i + 2)] += g[x][mod(i + 1)] + tmp[i] - f[nx][i] ;
		++g[nx][mod(1)] ;
	}
	for (Link *h = head[x] ; h ; h = h->next)
		if (h->num != fa) dp_g(h->num , x) ;
}

int main() {
	freopen("jump.in" , "r" , stdin) ;
	freopen("jump.out" , "w" , stdout) ;

	n = read() ; k = read() ;
	for (int i = 1 ; i < n ; ++i) {
		int x , y ; x = read() ; y = read() ;
		ins(x , y) ; ins(y , x) ;
	}

	///

	dp_f(1 , 1) ;
	dp_g(1 , 1) ;
	for (int i = 1 ; i <= n ; ++i)
		for (int j = 1 ; j < k ; ++j) res += (f[i][j] + g[i][j]) * (k - j) ;

	printf("%lld\n" , (res / k) >> 1) ;

	fclose(stdin) ; fclose(stdout) ;

	return 0 ;
}