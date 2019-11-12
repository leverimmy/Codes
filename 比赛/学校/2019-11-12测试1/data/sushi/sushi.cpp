#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define File(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
#define maxn 2000010
#define INF (1LL<<50)

using namespace std;
typedef long long llg;

int T,n,nt[maxn],w[maxn];
llg ans,tol;
char s[maxn];

void work(){
	int la=0,nn; tol=0;
	for(int i=n<<1;i;i--)
		if(s[i]=='B') nt[i]=la,la=i;
		else nt[i]=0;
	for(int i=1;i<=n*2;i++) w[i]=w[i-1]+(s[i]=='R');
	for(int i=la;i<=n;i=nt[i])
		if(w[i]<=w[n]-w[i-1]) nn=i,tol+=w[i];
		else break;
	for(int i=nt[nn];i<=n;i=nt[i]) tol+=w[n]-w[i-1];
	ans=min(ans,tol);
	for(int i=2;i<=n;i++){
		if(s[i-1]=='R') tol-=nn-i+1-w[nn]+w[i-1];
		if(s[i+n-1]=='R') tol+=i+n-1-nn-w[i+n-1]+w[nn];
		while(nt[nn] && w[nt[nn]]-w[i-1]<=w[i+n-1]-w[nt[nn]]){
			nn=nt[nn];
			tol-=w[i+n-1]-w[nn]; tol+=w[nn]-w[i-1];
		}
		ans=min(ans,tol);
	}
}

int main(){
	File("sushi");
	scanf("%d",&T);
	while(T--){
		ans=INF;
		scanf("%s",s+1); n=strlen(s+1);
		for(int i=1;i<=n;i++) s[i+n]=s[i];
		work();
		printf("%lld\n",ans);
	}
}
