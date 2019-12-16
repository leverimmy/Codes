#include<bits/stdc++.h>

const int MAXN = 1500;

struct Item{
    long long a,b; int ID;
    Item(){}
    Item(const long long& ia,const long long& ib) : a(ia),b(ib) {}
    
    bool operator < (const Item& comp) const {
        return b>comp.b || b==comp.b&&a<comp.a;
    }
    bool operator > (const Item& comp) const{
        return a>comp.a || a==comp.a&&b>comp.b;
    }
    bool operator () (const Item& a, const Item& comp) const{
        return a.a>comp.a || a.a==comp.a&&a.b<comp.b;
    }
    Item operator + (const Item& add) const{ return Item(a+add.a,b+add.b); }
    Item& operator += (const Item& add){ return *this = *this + add; }

    Item A(void){ return Item(a,0LL); }
    Item B(void){ return Item(0LL,b); }
}val[MAXN];

int sum[MAXN],totItem;
bool Check(int pos){
    for(;pos<=totItem;++pos)
        if(sum[pos]+1 > (pos+1>>1)) return false;
    return true;
}
void Pick(int pos){
    for(;pos<=totItem;++pos) ++sum[pos];
}

signed main(void)
{
    freopen("shopping.in","r",stdin);
    freopen("shopping.out","w",stdout);
    
    int targ; char first[20];

    scanf("%d%s", &totItem,first);
    for(int i=1;i<=totItem;i++) scanf("%lld%lld", &val[i].b,&val[i].a);
    std::sort(val+1,val+totItem+1);

    long long delt;
    if(*first == 'C'){
        delt = val[1].b;
        for(int i=2;i<=totItem;i++) val[i-1] = val[i];
        --totItem;
    } else delt = 0LL;
    
    for(int i=1;i<=totItem;i++) val[i].ID = i;
    std::sort(val+1,val+totItem+1,Item());
    Item ans = Item(0LL,0LL); int cnt=0;
    for(int i=1;i<=totItem;i++)
        if(cnt<=(totItem+1>>1) && Check(val[i].ID)){
            Pick(val[i].ID);
            ans += val[i].A();
            ++cnt;
        } else ans += val[i].B();

    printf("%lld %lld\n", ans.b+delt,ans.a);
    
    return 0;
}
