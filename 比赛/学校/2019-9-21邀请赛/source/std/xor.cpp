#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MAX_N = 1e5 + 10 ;

struct Link {
    int num , val ;
    Link *next ;
}list[MAX_N << 1] ;

Link *head[MAX_N] ;
bool ans , ap[MAX_N] ;
int T , n , m , cur , a[MAX_N] , s[MAX_N] ;

void dfs(int x) {
    for (Link *h = head[x] ; h ; h = h->next) {
        if (!ans) return ;

        int nx = h->num ;
        if (ap[nx]) {
            if ((s[nx] ^ s[x]) != h->val) ans = 0 ;
            continue ;
        }

        ap[nx] = 1 ; s[nx] = s[x] ^ h->val ;
        dfs(nx) ;
    }
}

void ins(int x , int y , int a) {
    list[cur].num = y ;
    list[cur].val = a ;
    list[cur].next = head[x] ;
    head[x] = &list[cur++] ;
}

void init() {
    cur = 0 ; ans = 1 ;
    memset(ap , 0 , sizeof(ap)) ;
    memset(head , 0 , sizeof(head)) ;
}

inline int read() {
    char c = getchar() ;
    int num = 0 , f = 1 ;

    while (c < '0' || c > '9') {if (c == '-') f = -f ; c = getchar() ;}
    while (c >= '0' && c <= '9') {num = num * 10 + c - '0' ; c = getchar() ;}

    return num * f ;
}

int main() {
    freopen("xor.in" , "r" , stdin) ;
    freopen("xor.out" , "w" , stdout) ;

    T = read() ;
    while (T--) {
        init() ;

        n = read() ; m = read() ;
        for (int i = 0 ; i < m ; ++i) {
            int x , y , a ;
            x = read() ; y = read() ; a = read() ; --x ;
            ins(x , y , a) ; ins(y , x , a) ;
        }

        ap[0] = 1 ; a[0] = 0 ; dfs(0) ;
        for (int i = 1 ; i < n && ans ; ++i)
            if (!ap[i]) {a[i] = 0 ; ap[i] = 1 ; dfs(i) ;}

        if (ans) printf("Yes\n") ;
        else printf("No\n") ;
    }

    fclose(stdin) ; fclose(stdout) ;

    return 0 ;
}