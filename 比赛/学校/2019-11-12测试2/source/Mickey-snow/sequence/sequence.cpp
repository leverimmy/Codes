#include<bits/stdc++.h>
#define nullptr NULL

const int MAXN = 100050;
const int MAXM = 1000000;
long long val[MAXN],sum[MAXN];

//Segment Tree
long long range = (long long)MAXN*MAXM;
struct Node{
    int cnt;
    Node *lft,*rgt;
    Node(){ lft = rgt = nullptr; cnt = 0; }
    Node(const int& icnt) : cnt(icnt){ lft = rgt = nullptr; cnt = 0; }

    Node& Update(void){
        cnt = 0;
        if(lft != nullptr) cnt += lft->cnt;
        if(rgt != nullptr) cnt += rgt->cnt;
        return *this;
    }
};
std::vector<Node*>ver;

Node* Chroot(const long long& ins,Node* temp){
    int fr=-range,to=range,mid;
    Node *nowAt = new Node(); Node *root = nowAt;
    while(fr <= to){
        if(temp != nullptr) nowAt->cnt = temp->cnt;
        nowAt->cnt++;
        if(fr >= to) break;
        
        mid = fr+to>>1;
        if(ins > mid){
            nowAt->lft = temp==nullptr ? nullptr : temp->lft;
            nowAt->rgt = new Node(); nowAt = nowAt->rgt;
            if(temp != nullptr) temp = temp->rgt;
            fr = mid+1;
        } else {
            nowAt->rgt = temp==nullptr ? nullptr : temp->rgt;
            nowAt->lft = new Node(); nowAt = nowAt->lft;
            if(temp != nullptr) temp = temp->lft;
            to = mid;
        }
    } return root;
}

int Count(const long long& top, Node* nowAt, const int fr=-range,const int to=range){
    if(nowAt==nullptr || nowAt->cnt<=0 || fr>top) return 0;

    if(to <= top) return nowAt->cnt;
    else return Count(top,nowAt->lft,fr,fr+to>>1) + Count(top,nowAt->rgt,1+(fr+to>>1),to);
}


int totNums;

long long Solve(const long long& sumval){
    long long cnt = 0;
    for(int i=0;i<totNums;i++)
        cnt += Count(sum[i]-sumval,ver[i]);
    return cnt;
}

signed main(void)
{
    freopen("sequence.in","r",stdin);
    freopen("sequence.out","w",stdout);
    
    long long kth;

    scanf("%d%lld", &totNums,&kth);
    for(int i=0;i<totNums;i++) scanf("%lld", val+i);

    *sum = *val; ver.push_back(Chroot(0,nullptr));
    for(int i=1;i<totNums;i++){
        sum[i] = sum[i-1]+val[i];
        ver.push_back(Chroot(sum[i-1],ver.back()));
    }

    long long fr = -range*totNums,to=range*totNums,mid;
    while(fr < to){
        mid = fr+to+1>>1;
        if(Solve(mid) >= kth) fr = mid;
        else to = mid-1;
    }

    printf("%lld\n", fr);
    
    return 0;
}
