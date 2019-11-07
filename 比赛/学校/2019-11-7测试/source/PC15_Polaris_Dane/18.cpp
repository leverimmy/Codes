#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cctype>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdlib>
#define int long long
using namespace std;
const int M=100000;
const int inf=0x7f7f7f7f;
const int mod=1e9+7;
const double eps=1e-6;
inline int read(){
	int x=0,f=1;char s=getchar();
	while (!isdigit(s)){if (s=='-') f=-1;s=getchar();}
	while (isdigit(s)){x=(x<<1)+(x<<3)+(s^48);s=getchar();}
	return x;
}
int n,m,fa[M],cnt;
inline int find(int x){
	return fa[x]==x?fa[x]:fa[x]=find(fa[x]);	
}
signed main(void){
	freopen("18.in","r",stdin);
	freopen("18.out","w",stdout);
	n=read(),m=read();cnt=n;
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=m;i++){
		int u=read(),v=read();
		int U=find(u),V=find(v);
		if (U!=V) fa[U]=V,cnt--;
	}
	printf("%d",cnt);
	return 0;
}

