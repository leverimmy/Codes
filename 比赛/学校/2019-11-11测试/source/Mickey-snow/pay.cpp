#include<bits/stdc++.h>
#define nullptr NULL

const long long INT64_MAX = 1LL<<62;

class Prq{
private:
    std::priority_queue< long long,std::vector<long long>,std::less<long long> > que,del;
public:
    Prq& Attend(const long long& val){ que.push(val); return *this; }
    Prq& Delete(const long long& val){ del.push(val); return *this; }
    long long Max(void){
        while(!que.empty() && !del.empty() && que.top()==del.top()){
            que.pop(); del.pop();
        } return que.top();
    }
}que;

const int MAXN = 250;
const int MAXM = 50050;

struct Node{
    long long val;    //valueB 
    bool rev;
    Node *ch[2],*fa,*max;
    Node(){ ch[0]=ch[1]=fa=nullptr; max=this; }
    Node(const long long& ival) : val(ival) { ch[0]=ch[1]=fa=nullptr; max=this; }

    Node& Reverse(void){ rev^=1; std::swap(ch[0],ch[1]); return *this; }
    Node& Push_Down(void){
        if(rev){
            if(ch[0] != nullptr) ch[0]->Reverse();
            if(ch[1] != nullptr) ch[1]->Reverse();
            rev = false;
        } return *this;
    }
    Node& Update(void){
        max = this;
        for(int i=0;i<2;i++)
            if(ch[i] != nullptr)
                if(ch[i]->max->val > max->val) max = ch[i]->max;
        return *this;
    }

    bool IsRoot(void) const { return fa==nullptr || fa->ch[0]!=this&&fa->ch[1]!=this; }
    short Comp(const Node* comp) const { return (ch[0]!=comp&&ch[1]!=comp) ? -1 : (ch[0]==comp?0:1); }
}point[MAXN],valPt[MAXM];

void Rotate(Node* targ){
    assert(!targ->IsRoot());
    Node* up = targ->fa;
    const bool pos = up->Comp(targ);
    up->ch[pos] = targ->ch[pos^1];
    if(targ->ch[pos^1] != nullptr) targ->ch[pos^1]->fa = up;
    targ->ch[pos^1] = up;
    if(!up->IsRoot()) up->fa->ch[up->fa->Comp(up)] = targ;
    targ->fa = up->fa; up->fa = targ;
    up->Update(); targ->Update();
} std::stack<Node*> S;
void Spaly(Node* nowAt){
    Node* targ = nowAt; S.push(targ);
    while(!targ->IsRoot()) S.push(targ = targ->fa);
    while(!S.empty()){ S.top()->Push_Down(); S.pop(); }

    for(;!nowAt->IsRoot() && !nowAt->fa->IsRoot(); Rotate(nowAt))
        if(nowAt->fa->Comp(nowAt) == nowAt->fa->fa->Comp(nowAt->fa)) Rotate(nowAt->fa);
        else Rotate(nowAt);
    if(!nowAt->IsRoot()) Rotate(nowAt);
}

void Access(Node* nowAt){
    for(Node* targ=nullptr;nowAt!=nullptr;nowAt=nowAt->fa){
        Spaly(nowAt); nowAt->ch[1] = targ; nowAt->Update(); targ = nowAt;
    }
}
void Make_Root(Node* nowAt){
    Access(nowAt); Spaly(nowAt); nowAt->Reverse();
}
Node* Find_Root(Node* nowAt){
    Access(nowAt); Spaly(nowAt);
    for(nowAt->Push_Down();nowAt->ch[0]!=nullptr;nowAt->Push_Down()) nowAt = nowAt->ch[0];
    return nowAt;
}
void Split(Node* x,Node* y){
    Make_Root(x); Access(y); Spaly(x);
}
void Cut(Node* x,Node* y){
    Make_Root(x); 
    if(Find_Root(y)!=x || y->ch[0]!=x || x->ch[1]!=nullptr) return;
    else x->fa = y->ch[0] = nullptr;
}
void Link(Node* x,Node* y){//Link x->y
    Make_Root(x);
    if(Find_Root(y) != x) x->fa = y;
}

struct Edge{
    int fr,to; long long vala,valb;
    Edge(){}
    Edge(const int& ifr,const int& ito,const long long& ivala,const long long& ivalb) : fr(ifr),to(ito),vala(ivala),valb(ivalb) {}

    bool operator () (const Edge& a,const Edge& comp) const {
        return a.vala==comp.vala ? a.valb<comp.valb : a.vala<comp.vala;
    }
}edge[MAXM];

signed main(void)
{
    freopen("pay.in","r",stdin);
    freopen("pay.out","w",stdout);
    
    int totVertex,totEdges; long long pra,prb;
    int fr,to; long long a,b;

    scanf("%d%d%lld%lld", &totVertex,&totEdges,&pra,&prb);
    for(int i=0;i<totEdges;i++){
        scanf("%d%d%lld%lld", &fr,&to,&a,&b);
        edge[i] = Edge(fr,to,a,b);
    }

    std::sort(edge,edge+totEdges,Edge());
    bool ins; int bkopt,cntEdge=0; long long ans = INT64_MAX;
    for(int i=0;i<totEdges;i++){
        const Edge& it = edge[i];

        //Check
        ins = true;
        Make_Root(point+it.fr);
        if(Find_Root(point+it.to) == point+it.fr){
            bkopt = point[it.to].max - valPt;
            if(point[it.to].max->val > it.valb){
                que.Delete(edge[bkopt].valb); --cntEdge;
                Cut(point+edge[bkopt].fr, valPt+bkopt); Cut(valPt+bkopt, point+edge[bkopt].to);
            } else ins = false;
        }

        //Insert
        valPt[i].val = edge[i].valb;
        if(ins){
            que.Attend(it.valb); ++cntEdge;
            Link(point+edge[i].fr,valPt+i); Link(valPt+i, point+edge[i].to);
        }

        //Query
        if(cntEdge == totVertex-1)
            ans = std::min(ans, it.vala*pra + que.Max()*prb);
    }

    printf("%lld\n", ans);
    
    return 0;
}
