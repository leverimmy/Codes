#include<bits/stdc++.h>
#define nullptr NULL

const int MAXN = 1001;
const int MAXK = 100010;
const int MAXM = 100010;

std::vector<int> arr[MAXN];

//SegmentTree
struct Node{
    int fr,to;
    int cov; std::vector<int> del;
    Node *lft,*rgt;
    Node(){ lft = rgt = nullptr; cov = 0; }
    Node(const int& ifr,const int& ito) : fr(ifr),to(ito){ lft = rgt = nullptr; cov = 0; }

    Node& Push_Down(void){
        if(cov > 0){
            if(lft != nullptr) lft->cov = cov;
            if(rgt != nullptr) rgt->cov = cov;
            if(to > fr) cov = 0;
        } return *this;
    }
}*list0[MAXN],*list1[MAXN];
Node* Build(const int& siz){
    Node *a,*b,*t;
    std::queue<Node*> que,add;
    for(int i=0;i<siz;i++){
        t = new Node(i,i); que.push(t);
    }
    for(;que.size()>=2;std::swap(que,add)){
        while(que.size()>=2){
            a = que.front(); que.pop(); b = que.front(); que.pop();
            t = new Node(a->fr,b->to); t->lft = a; t->rgt = b;
            add.push(t);
        } if(!que.empty()){ add.push(que.front()); que.pop(); }
    } return que.front();
}
void Attcov(const int& col,const int& fr,const int& to,Node* nowAt){
    if(nowAt==nullptr || to<nowAt->fr || nowAt->to<fr) return;

    nowAt->Push_Down();
    if(fr<=nowAt->fr && nowAt->to<=to) nowAt->cov = col;
    else { Attcov(col,fr,to,nowAt->lft); Attcov(col,fr,to,nowAt->rgt); }
}
void Attdel(const int& col,const int& fr,const int& to,Node* nowAt){
    if(nowAt==nullptr || to<nowAt->fr || nowAt->to<fr) return;

    nowAt->Push_Down();
    if(fr<=nowAt->fr && nowAt->to<=to) nowAt->del.push_back(col);
    else { Attdel(col,fr,to,nowAt->lft); Attdel(col,fr,to,nowAt->rgt); }
}

void Query(const int& targ, std::stack<int>& S, Node* nowAt){
    if(nowAt==nullptr || nowAt->to<targ || targ<nowAt->fr) return;

    if(nowAt->cov > 0) S.push(nowAt->cov);
    else {
        nowAt->Push_Down();
        Query(targ,S,nowAt->lft); Query(targ,S,nowAt->rgt);
    }
}
void Query(const int& targ, int *S,Node* nowAt){
    if(nowAt==nullptr || nowAt->to<targ || targ<nowAt->fr) return;

    for(int i=0;i<nowAt->del.size();i++) --S[nowAt->del[i]];
    Query(targ,S,nowAt->lft); Query(targ,S,nowAt->rgt);
}

struct Opert{
    int ver,col,frx,fry,tox,toy; int jump;
    Opert(){ jump = -3; }
    Opert(const int& iver,const int& icol, const int& ifrx,const int& ifry,const int& itox,const int& itoy) : ver(iver),col(icol),frx(ifrx),fry(ifry),tox(itox),toy(itoy) { jump = -3; }
}opt[MAXM];
int targPos[MAXM];

std::stack<int> val0,val1;
int del0[MAXK],del1[MAXK];

signed main(void)
{
    freopen("chessboard.in","r",stdin);
    freopen("chessboard.out","w",stdout);
    
    int siz,totColor,totOrder;
    char opttype[15]; int frx,fry,tox,toy,col;

    scanf("%d%d%d", &siz,&totColor,&totOrder);

    int nowVer = 0;
    for(int i=0;i<totOrder;i++){
        scanf("%s", opttype);
        switch(*opttype){
        case 'P':
            scanf("%d%d%d%d%d", &col,&fry,&frx,&toy,&tox);
            opt[i] = Opert(nowVer,col,frx,fry,tox,toy);
            opt[i].jump = -1;
            break;
        case 'S':
            targPos[++nowVer] = i;
            break;
        case 'L':
            scanf("%d", &col);
            opt[i].jump = col;
            break;
        }
    }

    for(int i=totOrder-1;i>=0;i--){
        if(opt[i].jump >= 0){
            i = targPos[opt[i].jump]-1;
        }
        if(opt[i].jump == -1) opt[i].jump = -2;
    }

    for(int i=0;i<siz;i++){ list0[i] = Build(siz+1);list1[i] = Build(siz+1); }
    for(int i=0;i<totOrder;i++)
        if(opt[i].jump == -2){
            const Opert& it = opt[i];
            if(it.frx+it.fry & 1){
                Attcov(it.col,it.fry,it.toy,list1[it.frx]);
                Attdel(it.col,it.fry,it.toy,list1[it.tox+1]);
            } else {
                Attcov(it.col,it.fry,it.toy,list0[it.frx]);
                Attdel(it.col,it.fry,it.toy,list0[it.tox+1]);
            }
        }

    for(int line=0;line<siz;line++){
        { std::stack<int> T1,T2; std::swap(T1,val0); std::swap(T2,val1); }
        memset(del1,0,sizeof(del1)); memset(del0,0,sizeof(del0));

        val0.push(1); val1.push(1);
        for(int i=0;i<siz;i++){
            Query(line,val0,list0[i]); Query(line,val1,list1[i]);
            Query(line,del0,list0[i]); Query(line,del1,list1[i]);

            while(del0[val0.top()] > 0){ del0[val0.top()]--; val0.pop(); }
            while(del1[val1.top()] > 0){ del1[val1.top()]--; val1.pop(); }
            
            if(i+line & 1) printf("%d ", val1.top());
            else printf("%d ", val0.top());
        } putchar('\n');
    }
    
    return 0;
}
