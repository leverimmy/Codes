#include<bits/stdc++.h>

const int MAXN = (int)1e5+50;

long long val[MAXN],tsum[MAXN];
int fa[MAXN];

bool Check(const int& fr,const int& mid,const int& to){
    for(int i=fr;i<=to;i++)
        if(i!=mid && 1!=std::__gcd(val[mid],val[i])) return false;
    return true;
}

int Dfs(const int& fr,const int& to){
    if(fr == to) return fr;
    if(fr > to) return MAXN-1;
    
    int ch1,ch2;
    for(int i=fr;i<=to;i++)
        if(Check(fr,i,to)){
            ch1 = Dfs(fr,i-1); ch2 = Dfs(i+1,to);
            if(ch1==-1 || ch2==-1) continue;
            fa[ch1] = fa[ch2] = i;
            return i;
        }
    return -1;
}

signed main(void)
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    
    int totCases,totVertex;

    scanf("%d", &totCases);
    while(totCases--){
        scanf("%d", &totVertex);
        for(int i=0;i<totVertex;i++) scanf("%lld", val+i);

        fa[Dfs(0,totVertex-1)] = -1;

        for(int i=0;i<totVertex;i++) printf("%d ", fa[i]+1); putchar('\n');
    }
    
    return 0;
}
