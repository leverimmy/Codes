#pragma GCC optimize("O2") 
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
int T;
int n,m;
int x[N],y[N],k[N];
int fa[N<<1];
inline int findf(int x){return fa[x]==x?x:fa[x]=findf(fa[x]);}
inline void kon(int x,int y){
	if(findf(x)!=findf(y)) fa[findf(x)]=fa[findf(y)];
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	T=read();
	while(T--){
		n=read(),m=read();
		int mx=0; 
		for(int i=1;i<=m;i++) x[i]=read()-1,y[i]=read(),k[i]=read(),mx=max(mx,k[i]);
		int flag=0;mx=log2(mx+1);
		for(int j=0;j<=mx;j++){
			for(int i=0;i<=2*n+1;i++) fa[i]=i;
			for(int i=1;i<=m;i++){
				int c=(k[i]>>j)&1;
				if(c==0) {
					if(findf(x[i]+n+1)==findf(y[i])) {flag=1;break;}
					kon(x[i],y[i]);
					kon(x[i]+n+1,y[i]+n+1);
				}else {
					if(findf(x[i])==findf(y[i])) {flag=1;break;}
					kon(x[i],y[i]+n+1);
					kon(y[i],x[i]+n+1);
				}
			}
			if(flag) break;
		}
		puts(flag?"No":"Yes");
	}
	return 0;
}
