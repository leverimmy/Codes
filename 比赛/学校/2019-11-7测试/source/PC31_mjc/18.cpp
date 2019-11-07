#include<bits/stdc++.h>
using namespace std;
int fa[10010]; 
int find(int x){
	if(fa[x]==x) return fa[x];
	return fa[x]=find(fa[x]);
}

int ans;

int n,m;
int main(){
	freopen("18.in","r",stdin);
	freopen("18.out","w",stdout);
	scanf("%d%d",&n,&m);
	ans=n;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		int eu=find(x);
		int ev=find(y);
		if(eu!=ev){
			fa[eu]=ev;
			ans--; 
		}
	}
	printf("%d\n",ans);
}
 
