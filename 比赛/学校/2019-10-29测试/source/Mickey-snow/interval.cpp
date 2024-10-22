#include<bits/stdc++.h>

const int MAXN = 200050;
const int MAXM = MAXN<<1;

struct Seg{
    int fr,to,ID;
    Seg(){}
    Seg(const int& ifr,const int& ito,const int& iID) : fr(ifr),to(ito),ID(iID) {}

    bool operator () (const Seg& a,const Seg& comp) const { return a.to < comp.to; }
}seg[MAXN];

std::vector<int> valarr,arr;
std::map<int,int> val,org;
int D[MAXM],ans[MAXM];

std::stack<int> stk;

signed main(void)
{
    freopen("interval.in","r",stdin);
    freopen("interval.out","w",stdout);
    
    memset(ans,-1,sizeof(ans));
    
    int totNums,fr,to;

    scanf("%d", &totNums);
    for(int i=0;i<totNums;i++){
        scanf("%d%d", &fr,&to);
        if(fr > to) std::swap(fr,to);
        valarr.push_back(fr); valarr.push_back(to);
        seg[i] = Seg(fr,to,i+1);
    }

    std::sort(seg,seg+totNums,Seg());
    std::sort(valarr.begin(),valarr.end());
    valarr.erase(std::unique(valarr.begin(),valarr.end()), valarr.end());
    for(int i=0;i<valarr.size();i++){ val[valarr[i]] = i+1; org[i+1] = valarr[i]; }
    for(int i=0;i<totNums;i++){ seg[i].fr = val[seg[i].fr]; seg[i].to = val[seg[i].to]; }
    
    int nowAt=0;
    for(int i=1;nowAt < totNums;i++){
        D[i] = D[i-1]; ans[i] = ans[i-1];
        for(; i==seg[nowAt].to && nowAt<totNums; nowAt++){
            if(D[seg[nowAt].fr-1]+1>D[i]){
                D[i] = D[seg[nowAt].fr-1] + 1;
                ans[i] = nowAt;
            } else if(D[seg[nowAt].fr-1]+1==D[i]&&D[seg[nowAt].fr-1]==0&&seg[ans[i]].ID>seg[nowAt].ID) ans[i] = nowAt;
            else if(D[seg[nowAt].fr-1]+1==D[i]&&seg[ans[i]].ID>seg[nowAt].ID&&D[seg[nowAt].fr-1]>0&&seg[ans[seg[ans[i]].fr-1]].to<seg[nowAt].fr)
                ans[i] = nowAt;
        }
    }

    printf("%d\n", D[seg[totNums-1].to]);
    nowAt = ans[seg[totNums-1].to];
    while(nowAt >= 0){
        arr.push_back(seg[nowAt].ID);
        if(seg[nowAt].fr-1 < 0) break;
        //assert(D[seg[nowAt].fr-1]+1 == D[seg[nowAt].to]);
        //assert(seg[ans[seg[nowAt].fr-1]].to < seg[nowAt].fr);
        nowAt = ans[seg[nowAt].fr-1];
    }
    std::sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size();i++) printf("%d ", arr[i]);
    putchar('\n');
    
    return 0;
}
