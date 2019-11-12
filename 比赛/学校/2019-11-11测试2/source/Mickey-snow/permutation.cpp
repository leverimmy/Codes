#include<bits/stdc++.h>

const int MAXN = 100050;

int val[MAXN],cnt[MAXN],nxt[MAXN];

signed main(void)
{
    freopen("permutation.in","r",stdin);
    freopen("permutation.out","w",stdout);
    
    int totNums;

    scanf("%d", &totNums);
    for(int i=0;i<totNums;i++){
        scanf("%d", val+i); ++cnt[val[i]];
    }

    for(int i=2;i<=totNums;i++)
        if(cnt[i]>cnt[i-1]){ puts("-1"); return 0; }

    printf("%d\n", cnt[1]);
    for(int i=0;i<totNums;i++)
        printf("%d ", ++nxt[val[i]]);
    putchar('\n');
    
    return 0;
}
