#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <cstdlib>
using namespace std;
const int limN = 5005;

char mat[limN];
int cntSiz[limN][limN];

int main() {
//	freopen("matrix.in","r",stdin);     freopen("matrix.out","w",stdout);
    int R, C ;

    scanf("%d%d", &R, &C);
    for(int i=0; i<R; i++) {
        scanf("%s", mat);
        for(int j=0, crg=0; j<C; j++) {
            if(mat[j] == '1')
                crg ++;
            else
                crg = 0;
            cntSiz[j][crg] ++;
        }
    }

    int ans = 0;
    for(int j=0; j<C; j++) {
        for(int i=j+1, c=0; i; i--) {
            c += cntSiz[j][i];
            ans = max(ans, c * i);
        }
    }

    printf("%d\n", ans);
}
