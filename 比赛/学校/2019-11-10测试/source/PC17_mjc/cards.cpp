#include<bits/stdc++.h>
#define int long long
using namespace std;

int a,b;
int maxx;
int ot[200010];
struct nod{
	int l,r,siz;
};
struct cmp{
	bool operator () (const nod &a,const nod &b){
		return a.siz<b.siz;
	}
};
int profit(int l,int r){
	int mid=(l+r)/2;
	int ori=(r-l+1)*(r-l+1);
	int now=(mid-l+1)*(mid-l+1)+(r-mid)*(r-mid);
	return (ori-now);
}
int outprize(int m){
	if(m==1) return 0;
	int ori=m*m;
	int now=(m-1)*(m-1)+1;
	return ori-now;
}
int vol,pos;
int ans,ans2=-1e18;
int judge(int l,int r,int m){
	int ok=profit(l,r)-outprize(m);
	if(ok>0){
		ans+=ok;
		return 1;
	}
	else{
		return 0;
	}
}
priority_queue<nod,vector<nod>,cmp> pq;
void solve1(){
	pq.push((nod){a+1,a+b,b});
	vol=a;
	ans=a*a-b*b;
	while(1){
		if(pq.top().siz==1 || vol==0) break;
		nod u=pq.top();
		int l=u.l,r=u.r;
		if(judge(l,r,vol)==0){
			break;
		}
		else{
			vol--;
			pq.pop();
			int mid=(l+r)/2;
			pq.push((nod){l,mid,mid-l+1});
			pq.push((nod){mid+1,r,r-mid});
		}
	}	
}
void print1(){
	printf("%lld\n",ans);
	for(int i=1;i<=vol;i++){
		printf("o");
	}
	int pr=0;
	while(!pq.empty()){
		nod u=pq.top();
		pq.pop();
		int l=u.l,r=u.r;
		for(int i=1;i<=r-l+1;i++){
			printf("x");
		}
		if(pr+vol<a){
			pr++;
			printf("o");
		}
	}
}
int mjc_big,mjc_small,mjc_b_cnt,mjc_s_cnt;
void go(int k){
	int an=0;
	int n=a-k+2;
	an=a-k+k*k;
	int big=b%n;
	int small=n-big;
	int big_n=b/n+1;
	int small_n=b/n;
	an-=(big_n*big_n*big)+(small_n*small_n*small);
	if(an>ans2){
		ans2=an;
		pos=n;
		mjc_big=big_n;
		mjc_small=small_n;
		mjc_b_cnt=big;
		mjc_s_cnt=small;
	}
}
signed main(){
	freopen("cards.in","r",stdin);
	freopen("cards.out","w",stdout);
	scanf("%lld%lld",&a,&b);
	for(int i=1;i<=a;i++){
		go(i);
	}
	printf("%lld\n",ans2);
//	for(int i=1;i<=mjc_b_cnt;i++){
//		if()
//		for(int j=1;j<=mjc_big;j++){
//			printf("x");
//		}
//		printf("o");
//	}
//	a-=mjc_b_cnt;
//	for(int i=1;i<=mjc_s_cnt;i++){
//		if(i==mjc_s_cnt){
//			for(int k=1;k<=a;k++){
//				printf("o");
//			}
//		}
//		else{
//			printf("o");
//			a--;
//		}
//		for(int j=1;j<=mjc_small;j++){
//			printf("x");
//		}
//	}
//	int siz=b/pos;
	int c=0,ct=0;
	for(int i=1;i<=b;i++){
		if(i<=mjc_b_cnt){
			for(int j=1;j<=mjc_big;j++){
				printf("x");
			}
		}
		else{
			for(int j=1;j<=mjc_small;j++){
				printf("x");
			}
		}
		c++;
		if(c==pos-2){
			ct++;
			if(ct==pos){
				for(int j=1;j<=a;j++){
					printf("o");
				}
			}
			else{
				a--;
				printf("o");
			}
			c=0;
		}
	}
}
