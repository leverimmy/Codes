#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 1e5 + 10 ;

struct QUERY {int p , k , idx , ans ;}qry[MAX_N] ;

int n , m , bk , a[MAX_N] , f[MAX_N] ;

bool cmp1(QUERY a , QUERY b) {return a.k < b.k ;}
bool cmp2(QUERY a , QUERY b) {return a.idx < b.idx ;}

inline int read() {
	char c = getchar() ;
	int num = 0 , f = 1 ;

	for (; c < '0' || c > '9' ; c = getchar()) if (c == '-') f = -f ;
	for (; c >= '0' && c <= '9' ; c = getchar()) num = num * 10 - '0' + c ;

	return num * f ;
}

void dp(int k) {
	for (int i = n ; i ; --i) {
		int np = i + a[i] + k ;
		if (np > n) f[i] = 1 ;
		else f[i] = f[np] + 1 ;
	}
}

int getans(int p , int k) {
	int ans ;
	for (ans = 0 ; p <= n ; p = p + a[p] + k , ++ans) ;
	return ans ;
}

int main() {
	freopen("array.in" , "r" , stdin) ;
	freopen("array.out" , "w" , stdout) ;

	n = read() ;
	for (int i = 1 ; i <= n ; ++i) a[i] = read() ;
	m = read() ;
	for (int i = 0 ; i < m ; ++i) {
		QUERY *p = &qry[i] ;
		p->p = read() ; p->k = read() ; p->idx = i ;
	}

	///

	bk = (int)sqrt(n) ;
	std::sort(qry + 0 , qry + m , cmp1) ;

	int last = -1 ;
	for (int i = 0 ; i < m ; ++i) {
		QUERY *p = &qry[i] ;

		if (p->k <= bk) {
			if (p->k != last) {last = p->k ; dp(p->k) ;}
			p->ans = f[p->p] ;
		}
		else p->ans = getans(p->p , p->k) ;
	}

	std::sort(qry + 0 , qry + m , cmp2) ;
	for (int i = 0 ; i < m ; ++i) printf("%d\n" , qry[i].ans) ;

	fclose(stdin) ; fclose(stdout) ;

	return 0 ;
}