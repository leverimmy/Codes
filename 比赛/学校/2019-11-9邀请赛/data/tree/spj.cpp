#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MAX_T = 5 + 5 , MAX_N = 1e5 + 10 , MAX_NUM = 1e7 + 10 , lgN = 25 + 5 , INF = 1e7 ;

///

bool vis[MAX_NUM] ;
int tot , pri[MAX_NUM] , fir[MAX_NUM] ;
int T , rt , n[MAX_T] , num[MAX_T][MAX_N] ;

void initpri() {
	int N = 1e7 ;
	for (int i = 2 ; i <= N ; ++i) {
		if (!vis[i]) pri[tot++] = i , fir[i] = i ;

		for (int j = 0 ; j < tot ; ++j) {
			int tmp = pri[j] * i ;
			if (tmp > N) break ;

			vis[tmp] = 1 ; fir[tmp] = pri[j] ;
			if (!(i % pri[j])) break ;
		}
	}
}

///

struct Node {
	Node *ch[2] ;

	void init() {ch[0] = ch[1] = NULL ;}
}tre[MAX_N * lgN] ;
struct Link {
	int num ;
	Link *next ;
}list[MAX_N << 1] ;

bool ans ;
Node *root[MAX_N] ;
Link *head[MAX_N] ;
int cur , tcnt , cnt[MAX_N] , fa[MAX_N] , P[MAX_N][MAX_T] , in[MAX_N] ;

int findset(int x) {return fa[x] == -1 ? x : (fa[x] = findset(fa[x])) ;}

bool add(Node *&rt , int x , int y , int f) {
	if (f < x || y < f) return 1 ;

	if (x == y) {
		if (!rt) (rt = &tre[tcnt++])->init() ;
		else return 0 ;
		return 1 ;
	}
	if (!rt) (rt = &tre[tcnt++])->init() ;

	int mid = (x + y) >> 1 ;
	return add(rt->ch[0] , x , mid , f) && add(rt->ch[1] , mid + 1 , y , f) ;
}

void merge(Node *&rt , Node *ort) {
	if (!rt) rt = ort ;
	else if (ort) merge(rt->ch[0] , ort->ch[0]) , merge(rt->ch[1] , ort->ch[1]) ;
}

bool cap(int x , int l , int r) {
	return l <= x && x <= r ;
}

void dfs(int x , int fa , int L , int R) {
	int L1 = L , R1 = x - 1 , L2 = x + 1 , R2 = R ;

	for (Link *h = head[x] ; h && ans ; h = h->next) {
		int nx = h->num ;
		if (nx == fa) continue ;

		if (cap(nx , L1 , R1)) dfs(nx , x , L1 , R1) ;
		else if (cap(nx , L2 , R2)) dfs(nx , x , L2 , R2) ;
		else ans = 0 ;

		if (ans) merge(root[x] , root[nx]) ;
	}

	for (int i = 0 ; i < cnt[x] ; ++i) ans &= add(root[x] , 1 , INF , P[x][i]) ;
}

void ins(int x , int y) {
	list[cur].num = y ;
	list[cur].next = head[x] ;
	head[x] = &list[cur++] ;
}

void init(int CASE) {
	cur = tcnt = 0 ;
	memset(in , 0 , sizeof(in)) ;
	memset(fa , -1 , sizeof(fa)) ;
	memset(root , 0 , sizeof(root)) ;
	memset(head , 0 , sizeof(head)) ;
}

int main(int argc , char* argv[]) {
	FILE* fin = fopen(argv[1] , "r") ;
	FILE* fout = fopen(argv[2] , "r") ;
	FILE* fscore = fopen(argv[5] , "w") ;
	FILE* freport = fopen(argv[6] , "w") ;

	// ------ input ------ //

	fscanf(fin , "%d" , &T) ;
	initpri() ;

	for (int i = 0 ; i < T ; ++i) {
		fscanf(fin , "%d" , &n[i]) ;
		for (int j = 1 ; j <= n[i] ; ++j) fscanf(fin , "%d" , &num[i][j]) ;
	}

	// ------ input ------ //

	// ------ output ------ //

	ans = 1 ;
	for (int CASE = 0 ; CASE < T && ans ; ++CASE) {
		int N = n[CASE] ;
		init(CASE) ;

		// ------ divide ------ //

		for (int i = 1 ; i <= N ; ++i) {
			int a = num[CASE][i] ; cnt[i] = 0 ;

			for (; a > 1 ;) {
				int t = fir[a] ;
				for (; !(a % t) ; a /= t) ;
				P[i][cnt[i]++] = t ;
			}
		}

		// ------ divide ------ //

		// ------ check ------ //

		rt = -1 ;
		for (int i = 1 ; i <= N && ans ; ++i) {
			int a ; fscanf(fout , "%d" , &a) ; ++in[a] ;
			if (!a) {
				if (rt == -1) rt = i ;
				else ans = 0 ;
				continue ;
			}

			ins(i , a) ; ins(a , i) ;

			int fx = findset(a) , fy = findset(i) ;
			if (fx == fy) ans = 0 ;
			else fa[fx] = fy ;
		}
		if (rt == -1) ans = 0 ;

		for (int i = 1 ; i <= N && ans ; ++i) ans &= (in[i] <= 2) ;
		if (ans) dfs(rt , rt , 1 , N) ;

		// ------ check ------ //
	}

	// ------ output ------ //

	if (ans) {
		fprintf(fscore , "%d" , 10) ;
		fprintf(freport , "Accepted") ;
	}
	else {
		fprintf(fscore , "%d" , 0) ;
		fprintf(freport , "Wrong Answer") ;
	}

	return 0 ;
}