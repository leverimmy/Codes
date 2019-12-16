#include<cstdio>
#include<algorithm>
#define ri register int
using namespace std;
inline int read(){
	ri x=0;register char ch=getchar();
	while(ch>'9' || ch<'0')ch=getchar();
	while(ch<='9' && ch>='0')
		x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return x;
}
struct edge{
	int x,y,z;
	inline bool operator<(const edge &a)const{
		return z<a.z;
	}
}e[300005];
int dis[105][105],fa[100005];
inline int find(ri x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ri n=read(),m=read();
	for(ri i=0;i<m;++i)e[i].x=read(),e[i].y=read(),e[i].z=read();
	if(n<=100){
		sort(e,e+m);
		for(ri i=1;i<=n;++i)fa[i]=i;
		for(ri i=0,x,y,z,fx,fy;i<m;++i){
			x=e[i].x,y=e[i].y,z=e[i].z;
			if((fx=find(x))==(fy=find(y)))continue;
			for(ri i=1;i<=n;++i)
				for(ri j=1;j<=n;++j)
					if(find(i)==fx && find(j)==fy)
						dis[i][j]=dis[j][i]=z;
			fa[fx]=fy;
		}
		ri p=read();
		for(ri i=0;i<p;++i)printf("%d\n",dis[read()][read()]);
	}
}
