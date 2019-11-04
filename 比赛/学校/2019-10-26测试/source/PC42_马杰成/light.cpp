#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
struct node{
	int l,r,p,v,ind;
}in[100010];

bool cmp(node a,node b){
	return a.p<b.p;
}
bool cmp2(node a,node b){
	return a.ind<b.ind;
}
vector<node> now[maxn];
int l[500];
int r[500];
int a[maxn];
int belong[maxn];
int num[500][500];
int n,m;
int len,cnt;
int out[maxn];
void solve(node k){
	int L=k.l,R=k.r;
	int V=k.v,P=k.p;
	int ans=0;
	for(int i=L;i<=r[belong[L]];i++){
		if(a[i]%P==V){
			ans++;
		}
	}
	if(belong[L]!=belong[R]){
		for(int i=l[belong[R]];i<=R;i++){
			if(a[i]%P==V){
				ans++;
			}			
		}
	}
	for(int i=belong[L]+1;i<=belong[R]-1;i++){
		ans+=num[i][V];
	}
	out[k.ind]=ans;
}
void run(int k){
	for(int i=1;i<=400;i++){
		for(int j=1;j<=400;j++){
			num[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++){
		int v=a[i]%k;
		num[belong[i]][v]++;
	}
	for(int i=1;i<=m;i++){
		solve(in[i]);
	}	
}
void solve2(node k){
	int ans=0;
	for(int i=k.l;i<=k.r;i++){
		if(a[i]%(k.p)==k.v) ans++;
	}
	out[k.ind]=ans;
} 

void solve3(int k){
	run(k);
	for(int i=1;i<=m;i++){
		printf("%d\n",out[i]); 
	}
}
int main(){
	freopen("light.in","r",stdin);
	freopen("light.out","w",stdout); 
	scanf("%d%d",&n,&m);
	int len=sqrt(n);
	int cnt=n/len;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		belong[i]=(i+1)/len;
	}
	for(int i=1;i<=cnt;i++){
		l[i]=(i-1)*len+1;
		r[i]=l[i]+len-1;
	}
	if(cnt*len<n){
		l[cnt+1]=r[cnt]+1;
		r[cnt+1]=n;
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d%d%d",&in[i].l,&in[i].r,&in[i].p,&in[i].v);
		in[i].ind=i;
	}
	if(n>1000){
		solve3(in[1].p);
		return 0;
	} 
	for(int i=1;i<=m;i++){
		solve2(in[i]);
	}
	for(int i=1;i<=m;i++){
		printf("%d\n",out[i]);
	}
}



//	sort(in+1,in+m+1,cmp);
//	int pos;
//	for(int i=1;i<=m;i++){
//		if(in[i].p>sqrt(n)){
//			pos=i;
//			break;
//		}
//		now[in[i].p].push_back(in[i]);
//	}
//	for(int i=1;i<=sqrt(n);i++){
//		run(i);
//	}
//	sort(in+1,in+n+1,cmp2);
