#include<cstdio>
#include<algorithm>
#define ri register int
inline int read(){
	ri x=0;register char ch=getchar();
	while(ch>'9' || ch<'0')ch=getchar();
	while(ch<='9' && ch>='0')
		x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return x;
}
char c[100005];
int n,m;
inline bool cmp(ri x,ri y){
	for(;x<=n && y<=n;++x,++y)
		if(c[x]!=c[y])
		return c[x]<c[y];
	return x>=y;
}
int main(){
	freopen("lcp.in","r",stdin);
	freopen("lcp.out","w",stdout);
	n=read(),m=read();
	scanf("%s",c+1);
	for(ri i=1,a,b;i<=m;++i){
		puts(cmp(read(),read())?"1":"0");
	}
	return 0;
}
