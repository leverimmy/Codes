#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 10010;
int n,m;
int cnte;
struct edge{
	int u,v,a,b;
}e[N];
void add(int u,int v,int a,int b){
	e[++cnte]=(edge){u, v, a, b};
}
bool cmp1(edge x,edge y){
	return x.a<y.a;
}
bool cmp2(edge x,edge y){
	return x.b>y.b;
}
int fa[N];
int find(int x){
	return x==fa[x] ? x : fa[x]=find(fa[x]);
}
double kruscal1(){
	int A=0,B=0;
	sort(e+1, e+1+cnte, cmp1);
	for(int i=1; i<=n; i++){
		fa[i]=i;
	}
	for(int i=1; i<=cnte; i++){
		int a=e[i].a,b=e[i].b,u=e[i].u,v=e[i].v;
		int fu=find(u),fv=find(v);
		if(fu!=fv){
			fa[fv]=fu;
			A+=a;
			B+=b;
		}
	}
	return (double)A/(double)B;
}
double kruscal2(){
	int A=0,B=0;
	sort(e+1, e+1+cnte, cmp2);
	for(int i=1; i<=n; i++){
		fa[i]=i;
	}
	for(int i=1; i<=cnte; i++){
		int a=e[i].a,b=e[i].b,u=e[i].u,v=e[i].v;
		int fu=find(u),fv=find(v);
		if(fu!=fv){
			fa[fv]=fu;
			A+=a;
			B+=b;
		}
	}
	return (double)A/(double)B;
}
int main(){
	freopen("mst.in", "r", stdin);
	freopen("mst.out", "w", stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; i++){
		int u,v,a,b;
		scanf("%d%d%d%d",&u,&v,&a,&b);
		add(u, v, a, b);
	}
	printf("%lf\n",min(kruscal1(), kruscal2()));
	return 0;
}

