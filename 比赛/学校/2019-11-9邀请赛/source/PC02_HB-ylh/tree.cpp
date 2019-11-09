#include <bits/stdc++.h>
#define maxn 100005
const int lim=10000005;
int n,a[maxn],not_prime[lim+5],head[lim+5]={0},tail=0,lp[maxn],rp[maxn],fa[maxn],prime[1000005],tl=0;
struct edge {
	int v,next;
}edges[lim+5];
void add_edge(int v,int p){
	//printf("%d + %d\n",v,p);
	edges[++tail].v=v;
	edges[tail].next=head[p];
	head[p]=tail;
}
void sieve(){
	for(int i=2;i<=lim;++i){
		if (not_prime[i])continue;
		else prime[++tl]=i;
		for(int j=i*2;j<=lim;j+=i)not_prime[j]=1;
	}//for(int i=2;i<=lim;++i)if(!not_prime[i])
}

void prework(){
	std::memset(head,0,sizeof(head));
	tail=0;
	for(int i=1;i<=n;++i){
		lp[i]=0,rp[i]=n+1;
		int x=a[i];
		for(register int j=1;prime[j]*prime[j]<=x;++j){
			int p=prime[j];
			if (x%p==0){
				while (x%p==0)x/=p;
				add_edge(i,p);
			}
		}if (x)add_edge(i,x);
	}
	for(int i=2;i<=lim;++i){
		if (not_prime[i]||!head[i])continue;
		//printf("%d:",i);
		std::vector<int>vec;
		//printf("%d ",head[i]);
		for(register int j=head[i];j;j=edges[j].next){
			//printf("%d ",j);
			vec.push_back(edges[j].v);
			
		}//printf("\n");
		std::sort(vec.begin(),vec.end());
		for(register int i=0;i<vec.size()-1;++i)lp[vec[i+1]]=std::max(lp[vec[i+1]],vec[i]);
		for(register int i=1;i<vec.size();++i)rp[vec[i-1]]=std::min(rp[vec[i-1]],vec[i]);
	}//for(int i=1;i<=n;++i)printf("%d %d\n",lp[i],rp[i]);
}

int check(int x,int l,int r){
	if (l<=lp[x]&&lp[x]<=r)return 0;
	if (l<=rp[x]&&rp[x]<=r)return 0;
	return 1;
}

int solve(int l,int r){
	if (l>r)return 0;
	int p;
	for(int i=1;i<=(r-l+1);++i){
		if (check(l+i-1,l,r)){
			p=l+i-1;break;
		}if (check(r-i+1,l,r)){
			p=r-i+1;break;
		}
	}fa[solve(l,p-1)]=p;
	fa[solve(p+1,r)]=p;
	return p;
}
			

void work(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	prework();
	fa[solve(1,n)]=0;
	for(int i=1;i<=n;++i)printf("%d ",fa[i]);printf("\n");
}

int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	sieve();//printf("%d ",tl);
	int t;
	scanf("%d",&t);while (t--)work();
	return 0;
}
