#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define File(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
#define maxn 200010
#define maxm 400010

using namespace std;
typedef long long llg;

struct data{
	int u,v,l,r;
}s[maxm],ls[maxm],rs[maxm],ms[maxm*20];
int n,m,T,fa[maxn],siz[maxn],_dis;
int S[maxm],ts,tt;
bool ans[maxm],vis[maxn];

int getint(){
	int w=0;bool q=0;
	char c=getchar();
	while((c>'9'||c<'0')&&c!='-') c=getchar();
	if(c=='-') c=getchar(),q=1;
	while(c>='0'&&c<='9') w=w*10+c-'0',c=getchar();
	return q?-w:w;
}

int find(int x){
	_dis=0;
	while(fa[fa[x]]!=fa[x]) _dis++,_dis+=vis[x],x=fa[x];
	if(fa[x]!=x) _dis++,_dis+=vis[x]; return fa[x];
}

void solve(int top,int end,int l,int r){
	bool ww=1;
	int l1=0,l2=0,lo=0,mid=l+r>>1,x=ts,y=tt;
	for(int i=top,x1,x2,a,b;i<=end;i++)
		if(s[i].l<=l && s[i].r>=r){
			a=find(s[i].u),x1=_dis;
			b=find(s[i].v),x2=_dis;
			if(a!=b){
				if(siz[a]>=siz[b]) swap(a,b),swap(x1,x2);
				siz[b]+=siz[a],fa[a]=b;
				if((x1+x2)&1) vis[a]=1;
				S[++ts]=a;
			}
			else if((x1+x2)%2==0){
				for(int j=l;j<=r;j++) ans[j]=0;
				ww=0;break;
			}
		}
		else
			if(s[i].l<=mid && s[i].r>mid) ms[++tt]=s[i],lo++;
			else if(s[i].l<=mid) ls[++l1]=s[i];
			else if(s[i].r>mid) rs[++l2]=s[i];
	if(ww){
		for(int i=1;i<=l1;i++) s[i+top-1]=ls[i];
		for(int i=1;i<=l2;i++) s[i+top-1+l1+lo]=rs[i];
		for(int i=y+1;i<=tt;i++) s[i-y+top-1+l1]=ms[i];
		if(l1+lo) solve(top,top+l1+lo-1,l,mid);
		for(int i=y+1;i<=tt;i++) s[i-y+top-1+l1]=ms[i];
		if(l2+lo) solve(top+l1,top+l1+lo+l2-1,mid+1,r);
	}
	while(ts>x){
		int u=S[ts--]; vis[u]=0;
		siz[fa[u]]-=siz[u],fa[u]=u;
	}
	tt=y;
}

int main(){
	File("grape");
	n=getint(); m=getint(); T=getint();
	for(int i=1;i<=m;i++){
		s[i].u=getint(),s[i].v=getint();
		s[i].l=getint()+1,s[i].r=getint();
	}
	for(int i=1;i<=n;i++) fa[i]=i,siz[i]=1;
	for(int i=1;i<=T;i++) ans[i]=1;
	solve(1,m,1,T);
	for(int i=1;i<=T;i++) printf(ans[i]?"Yes\n":"No\n");
	return 0;
}
