#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
typedef long long ll;
#define mp make_pair
#define X first
#define Y second
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf=0x7f7f7f7f;
const int N=2e5+5;
int n,m;
ll fr,K,B;
pair<ll,ll> stk[N];
int top=0,la=inf;
inline double slope(pll i,pll j){
	return (j.Y-i.Y)*1.0/(j.X-i.X);
}
inline bool chkmin(ll &x,ll y){
	if(y<x) {x=y;return 1;}
	return 0;
}
int main(){
	freopen("dance.in","r",stdin);
	freopen("dance.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=m;i++){
		int opt=read();
		if(opt==1) {
			int k=read();
			fr=0;n+=k;
			K=B=0;top=0;
			puts("1 0");
		}else if(opt==2) {
			int k=read();
			pll p=mp(n+1,K*n+B);
			while(top>1&&slope(stk[top],p)>slope(stk[top-1],stk[top]))  top--;
			stk[++top]=p;
			if(fr==0) puts("1 0");
			else {
				if(la==inf) la=n+1;
				printf("%d 0\n",la);
			}
			n+=k;
		}else {
			int b=read(),k=read();
			K+=k,B+=b;
			if(k!=0||b!=0) la=inf;
			fr+=b;
			int p=1;ll mn=fr;
			if(top<=4000){
				for(int j=1;j<=top;j++) 
					if(chkmin(mn,K*(stk[j].X-1)+B-stk[j].Y))
						p=stk[j].X;
			}else {
				for(int j=1;j<=2000;j++) 
					if(chkmin(mn,K*(stk[j].X-1)+B-stk[j].Y))
						p=stk[j].X;
				for(int j=top-2000;j<=top;j++) 
					if(chkmin(mn,K*(stk[j].X-1)+B-stk[j].Y))
						p=stk[j].X;
			}
			printf("%d %lld\n",p,mn);
		}
	}
	return 0;
}
