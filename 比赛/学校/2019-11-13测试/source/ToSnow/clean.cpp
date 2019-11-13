#include<bits/stdc++.h>

const int MAXN = 500050;

int mk[MAXN];

signed main(void)
{
    freopen("clean.in","r",stdin);
    freopen("clean.out","w",stdout);
    
    int totLen,totOpt,fr,to;

    scanf("%d%d", &totLen,&totOpt);
    while(totOpt--){
        scanf("%d%d", &fr,&to);
        if(fr > to) std::swap(fr,to);
        ++mk[fr]; --mk[to+1];
    }

    int lv=0,cnt=0;
    for(int i=1;i<=totLen;i++){
        lv += mk[i]; assert(lv >= 0);
        if(lv == 0) ++cnt;
    }

    printf("%d\n", cnt);
    
    return 0;
}
