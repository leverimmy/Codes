#include<bits/stdc++.h>
#define F(i,p,q) for(int i=p;i<=q;i++)
#define f(i,p,q) for(int i=p;i>=q;i--)
using namespace std;
const int N=200010;
int n,m,sa[N],c[N],x[N],y[N],rk[N],T,cc,a,b;
char s[N];
void work(){
	m=128;
	F(i,1,n) x[i]=s[i];
	F(i,1,n) c[x[i]]++;
	F(i,1,m) c[i]+=c[i-1];
	f(i,n,1) sa[c[x[i]]--]=i;
	for(int k=1;k<=n;k<<=1){
		cc=0;
		F(i,n-k+1,n) y[++cc]=i;
		F(i,1,n) if(sa[i]>k) y[++cc]=sa[i]-k;
		F(i,1,m) c[i]=0;
		F(i,1,n) c[x[i]]++;
		F(i,1,m) c[i]+=c[i-1];
		f(i,n,1) sa[c[x[y[i]]]--]=y[i],y[i]=0;
		swap(x,y);cc=0;
		x[sa[1]]=++cc;
		F(i,2,n) x[sa[i]]=(y[sa[i-1]]==y[sa[i]] && y[sa[i-1]+k]==y[sa[i]+k])?cc:++cc;
		if(cc==n) break;
		m=cc;
	}
	F(i,1,n) rk[sa[i]]=i;
}
int main(){
	freopen("lcp.in","r",stdin);
	freopen("lcp.out","w",stdout);
	scanf("%d%d",&n,&T);
	scanf("%s",s+1);
	work();
	while(T--){
		scanf("%d%d",&a,&b);
		printf("%d\n",rk[a]>=rk[b]);
	}
}
