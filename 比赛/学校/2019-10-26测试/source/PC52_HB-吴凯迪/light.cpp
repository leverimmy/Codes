#include<bits/stdc++.h>

const int MAXN = 100000+5;
const int MAXM = MAXN;

struct Node{
	int ID,to,mod,val; bool positive;
	Node(){}
	Node(const int& iID,const int& ito,const int& imod,const int& ival,const bool& ipos) : ID(iID),to(ito),mod(imod),val(ival),positive(ipos) {}
	bool operator () (const Node& a,const Node& comp) const { return a.to < comp.to; }
}query[MAXM<<1];

int num[MAXN],ans[MAXM],table[105][105],appear[10005];

signed main(void)
{
	freopen("light.in","r",stdin);
	freopen("light.out","w",stdout);
	
	int totNums,totOptn,fr,to,val,mod,nowAt=0;
	
	scanf("%d%d", &totNums,&totOptn);
	for(int i=0;i<totNums;i++) scanf("%d", num+i);
	
	for(int i=0;i<totOptn;i++){
		scanf("%d%d%d%d", &fr,&to,&mod,&val);
		query[i<<1] = Node(i,fr-2,mod,val,false);
		query[(i<<1)|1] = Node(i,to-1,mod,val,true);
	} 
	
	totOptn <<= 1;
	std::sort(query,query+totOptn,Node());
	
	for(int i=0;i<totOptn;i++){
		for(;nowAt <= query[i].to;++nowAt){
			for(int j=1;j<=100;j++)
				++table[j][num[nowAt]%j];
			++appear[num[nowAt]];
		}
		
		if(query[i].mod <= 100)
			ans[query[i].ID] += (query[i].positive ? 1 : -1) * table[query[i].mod][query[i].val];
		else{
			for(int k=0;k*query[i].mod+query[i].val <= 10000;k++)
				ans[query[i].ID] += (query[i].positive ? 1 : -1) * appear[query[i].mod*k+query[i].val];
		}
	}
	
	totOptn >>= 1;
	for(int i=0;i<totOptn;i++)
		printf("%d\n", ans[i]);
	
	return 0;
}
