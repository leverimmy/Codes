#include<bits/stdc++.h>
#define nullptr NULL

const int MAXN = 100050;

struct Vector2{
    int y,x;
    Vector2(){}
    Vector2(const int& iy,const int& ix) : y(iy),x(ix) {}
}; typedef Vector2 Point;

int totPoints;

const float Alpha = 0.82;
class Set{
private:
    struct Node{
        int val,dval, max;
        size_t siz;
        Node *lft,*rgt;
        Node(const int& ival,const int& idval) : val(ival),dval(idval) { max = dval; siz = 1; lft = rgt = nullptr; }
        Node& Update(void){
            siz = 1; max = dval;
            if(lft != nullptr){ siz += lft->siz; max = std::max(max, lft->max); }
            if(rgt != nullptr){ siz += rgt->siz; max = std::max(max, rgt->max); }
            return *this;
        }
        bool Balance(void){
            if(lft!=nullptr && siz*Alpha<lft->siz) return false;
            if(rgt!=nullptr && siz*Alpha<rgt->siz) return false;
            return true;
        }
        bool Deadend(void){ return lft==nullptr && rgt==nullptr; }
    }*root;

    //Rebuild
    std::vector<Node*> arr;
    void Dfs(Node* nowAt){
        if(nowAt->lft != nullptr) Dfs(nowAt->lft);
        arr.push_back(nowAt);
        if(nowAt->rgt != nullptr) Dfs(nowAt->rgt);
    }
    Node* Build(const int fr,const int to){
        if(fr > to) return nullptr;
        int mid = fr+to>>1;
        arr[mid]->lft = Build(fr,mid-1); arr[mid]->rgt = Build(mid+1,to);
        arr[mid]->Update(); return arr[mid];
    }
    Node* Rebuild(Node* targ){
        Dfs(targ);
        targ = Build(0,arr.size()-1);
        std::vector<Node*> T; std::swap(arr,T);
        //puts("Rebuilded!");
        return targ;
    }

    void Attend(const int& val,const int& dval, Node* nowAt){
        //assert(nowAt != nullptr);
        if(val == nowAt->val) nowAt->dval = std::max(nowAt->dval, dval);
        else if(val < nowAt->val)
            if(nowAt->lft == nullptr) nowAt->lft = new Node(val,dval);
            else Attend(val,dval,nowAt->lft);
        else
            if(nowAt->rgt == nullptr) nowAt->rgt = new Node(val,dval);
            else Attend(val,dval,nowAt->rgt);

        nowAt->Update();
    }
    void Check(const int& val,Node* nowAt){
        while(!nowAt->Deadend())
            if(val == nowAt->val) return;
            else if(val<nowAt->val)
                if(!nowAt->lft->Balance()){
                    nowAt->lft = Rebuild(nowAt->lft);
                    return;
                } else nowAt = nowAt->lft;
            else{
                if(!nowAt->rgt->Balance()){
                    nowAt->rgt = Rebuild(nowAt->rgt);
                    return;
                } else nowAt = nowAt->rgt;
            }
        
    }

public:
    Set(){ root = nullptr; }

    Set& Attend(const int& val,const int& dval){
        if(root == nullptr) root = new Node(val,dval);
        else Attend(val,dval,root);

        if(!root->Balance()) root = Rebuild(root);
        else Check(val,root);
        
        return *this;
    }
    int CountLower(const int& val){
        Node* nowAt = root; int ans=0;
        while(nowAt != nullptr){
            if(nowAt->val <= val){
                ans = std::max(ans, nowAt->dval);
                if(nowAt->lft != nullptr) ans = std::max(ans, nowAt->lft->max);
                nowAt = nowAt->rgt;
            } else nowAt = nowAt->lft;
        } return ans;
    }
};

//BIT
#define Lowbit(x) ((x)&(-(x)))
Set arr[MAXN];
void Add(Vector2 pos,const int& val){
    for(;pos.y<=totPoints;pos.y+=Lowbit(pos.y)) arr[pos.y].Attend(pos.x,val);
}
int Query(Vector2 pos){
    int ans = 0;
    for(--pos.y,--pos.x;pos.y>0;pos.y-=Lowbit(pos.y))
        ans = std::max(ans, arr[pos.y].CountLower(pos.x));
    return ans;
}

Vector2 pt[MAXN];
std::vector<int> arrx,arry;
std::map<int,int> mapx,mapy;

signed main(void)
{
    freopen("function.in","r",stdin);
    freopen("function.out","w",stdout);
    
    scanf("%d", &totPoints);

    for(int i=0;i<totPoints;++i){
        scanf("%d%d", &pt[i].x,&pt[i].y);
        arrx.push_back(pt[i].x); arry.push_back(pt[i].y);
    }

    //Unique
    std::sort(arrx.begin(), arrx.end());
    std::sort(arry.begin(), arry.end());
    arrx.erase(std::unique(arrx.begin(),arrx.end()), arrx.end());
    arry.erase(std::unique(arry.begin(),arry.end()), arry.end());
    for(int i=0;i<arrx.size();++i) mapx[arrx[i]] = i+1;
    for(int i=0;i<arry.size();++i) mapy[arry[i]] = i+1;

    //Solve
    int ans=0,ts;
    for(int i=0;i<totPoints;++i){
        pt[i] = Vector2(mapy[pt[i].y], mapx[pt[i].x]);
        ans = std::max(ans, (ts=(Query(pt[i])+1)));
        Add(pt[i],ts);
    }

    printf("%d\n", ans);
    //std::cout<<(double)clock()/CLOCKS_PER_SEC<<std::endl;
    
    return 0;
}
