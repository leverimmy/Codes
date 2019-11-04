#include<bits/stdc++.h>

//const long long INT64_MAX = 1LL<<63;
const int MOD = 19896400;

int Read(std::string& str){
    char in; int hash = 0;
    do in = getchar(); while(!('a'<=in && in<='z'));
    do{
	str += in;
	hash = (hash+in) % MOD;
	in = getchar();
    } while('a'<=in && in<='z');
    return hash;
}
int Hash(const std::string& a){
    int len = a.length(),hash=0;
    for(int i=0;i<len;i++)
	hash = (hash+a[i]) % MOD;
    return hash;
}

struct Node{
    std::string name;
    long long val;
    Node(){}
    Node(const std::string& iname, const long long& ival) : name(iname),val(ival) {}
};
std::vector<Node> box[MOD];
long long Find(const std::string& targ){
    int hash = Hash(targ);
    for(int i=0;i<box[hash].size();i++)
	if(box[hash][i].name == targ) return box[hash][i].val;
    return INT64_MAX;
}

signed main(void)
{
    freopen("liverpool.in","r",stdin);
    freopen("liverpool.out","w",stdout);
    
    int totPeo,totOptn,cnt,hash;
    long long val,tot; std::string name;
    bool flag;

    scanf("%d", &totPeo);
    while(totPeo--){
	hash = Read(name); scanf("%lld", &val);
	box[hash].push_back(Node(name,val)); name = "";
    }

    scanf("%d", &totOptn);
    while(totOptn--){
	scanf("%d", &cnt); tot = 0; flag = true;
	for(int i=0;i<cnt;++i){
	    std::cin>>name;
	    val = Find(name);
	    if(val == INT64_MAX) flag = false;
	    else tot += val;
	}

	if(flag) printf("%lld\n", tot);
	else puts("-1");
    }
    
    return 0;
}
