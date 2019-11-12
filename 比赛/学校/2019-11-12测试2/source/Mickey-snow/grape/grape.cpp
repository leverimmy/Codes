#include<bits/stdc++.h>

const int MAXT = 200050;
const int MAXN = 200050;
const int MAXM = 400000;

struct Edge{
    int fr,to,tfr,tto;
    Edge(){}
    Edge(const int& ifr,const int& ito,const int& itfr,const int& itto) : fr(ifr),to(ito),tfr(itfr),tto(itto) {}
}edge[MAXM],t1[MAXM],t2[MAXM];

bool ans[MAXT];

//sdu
int up[MAXN<<1],siz[MAXN<<1];
std::pair<int,int> hist[MAXM]; int top;
int FindTop(const int& nowAt){ return up[nowAt]==nowAt ? nowAt : FindTop(up[nowAt]); }
bool Unity(int a,int b){
    a = FindTop(a); b = FindTop(b);
    if(a == b) return false;
    if(siz[a] > siz[b]) std::swap(a,b);
    hist[top++] = std::make_pair(a,up[a]); up[a] = b;
    return true;
}
void FlashBack(const int& time){
    for(;top>time;--top) up[hist[top-1].first] = hist[top-1].second;
}

void Solve(const int timefr,const int timeto,const int qfr,const int qto){
    int mid = timefr+timeto>>1;
    bool flag = true;

    for(int i=qfr;i<=qto;i++)
        if(edge[i].tfr<=timefr && edge[i].tto>=timeto){
            if(FindTop(edge[i].fr) == FindTop(edge[i].to)){
                for(int t=timefr;t<=timeto;++t) ans[t] = false;
                return;
            }
            Unity(edge[i].fr, edge[i].to+MAXN); Unity(edge[i].fr+MAXN, edge[i].to);
        } else flag = false;

    if(flag){
        for(int i=timefr;i<=timeto;++i) ans[i] = true;
        return;
    }

    int ttop = top;
    int fsiz=0,lsiz=0;
    for(int i=qfr;i<=qto;i++)
        if(edge[i].tfr<=mid && !(edge[i].tfr<=timefr&&edge[i].tto>=timeto)) t1[fsiz++] = edge[i];
        else t2[lsiz++] = edge[i];
    for(int i=0;i<fsiz;i++) edge[i+qfr] = t1[i];
    for(int i=0;i<lsiz;i++) edge[i+qfr+fsiz] = t2[i];
    Solve(timefr,mid,qfr,qfr+fsiz-1);

    FlashBack(ttop);
    fsiz = lsiz = 0;
    for(int i=qfr;i<=qto;i++)
        if(edge[i].tto>mid && !(edge[i].tfr<=timefr&&edge[i].tto>=timeto)) t1[fsiz++] = edge[i];
        else t2[lsiz++] = edge[i];
    for(int i=0;i<fsiz;i++) edge[i+qfr] = t1[i];
    for(int i=0;i<lsiz;i++) edge[i+qfr+fsiz] = t2[i];
    Solve(mid+1,timeto,qfr,qfr+fsiz-1);
}

signed main(void)
{
    freopen("grape.in","r",stdin);
    freopen("grape.out","w",stdout);
    
    int totVertex,totEdge,totTime;
    int fr,to,tfr,tto;

    scanf("%d%d%d", &totVertex,&totEdge,&totTime);
    for(int i=0;i<MAXN;++i) up[i]=i, up[i+MAXN]=i+MAXN;
    for(int i=0;i<totEdge;++i){
        scanf("%d%d%d%d", &fr,&to,&tfr,&tto);
        edge[i] = Edge(fr,to,tfr+1,tto);
    }

    Solve(1,totTime,0,totEdge-1);

    for(int i=1;i<=totTime;++i)
        if(ans[i]) puts("Yes");
        else puts("No");
    
    return 0;
}
