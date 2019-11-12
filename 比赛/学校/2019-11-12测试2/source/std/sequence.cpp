#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define File(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout);
#define maxn 100010
#define INF (1LL<<50)

using namespace std;
typedef long long llg;

int n,a[maxn],ld,c[maxn];
llg k,l,r,mid,w[maxn],d[maxn],yu[maxn];

inline int getint(){
	int w=0;bool q=0;
	char c=getchar();
	while((c>'9'||c<'0')&&c!='-') c=getchar();
	if(c=='-') q=1,c=getchar();
	while(c>='0'&&c<='9') w=w*10+c-'0',c=getchar();
	return q?-w:w;
}

void add(int x,int y){while(x<=ld) c[x]+=y,x+=x&(-x);}
int sum(int x){
	int t=0;
	while(x) t+=c[x],x-=x&(-x);
	return t;
}

int find(llg x){
	int l=1,r=ld,mid;
	while(l!=r){
		mid=(l+r)>>1;
		if(d[mid]>=x) r=mid;
		else l=mid+1;
	}
	return l;
}

bool pd(llg x){
	llg now=0;
	for(int i=n,j;i;i--){
		add(w[i],1);
		j=find(x+yu[i-1]);
		now+=sum(ld)-sum(j-1);
	}
	for(int i=1;i<=n;i++) add(w[i],-1);
	return now>=k;
}

int main(){
	File("sequence");
	n=getint(); scanf("%lld",&k);
	for(int i=1;i<=n;i++){
		a[i]=getint();
		w[i]=w[i-1]+a[i]; d[++ld]=yu[i]=w[i];
		l+=min(a[i],0); r+=max(a[i],0);
	}
	d[++ld]=INF;
	sort(d+1,d+ld+1); ld=unique(d+1,d+ld+1)-d-1;
	for(int i=1;i<=n;i++) w[i]=find(w[i]);
	while(l!=r){
		mid=(l+r+1)>>1;
		if(pd(mid)) l=mid;
		else r=mid-1;
	}
	printf("%lld",l);
	return 0;
}
