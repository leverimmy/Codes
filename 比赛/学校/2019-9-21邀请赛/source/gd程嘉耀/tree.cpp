#include<bits/stdc++.h>
using namespace std;
const int Maxn=5e5+5;
int n,m,x,y,c;
struct AB{
	int from,to,len,next;
}f[Maxn];
int g[Maxn];
int ans[Maxn];
bool b[Maxn];
int sum;
void dfs(int pos,int maxn){
	ans[pos]=min(ans[pos],maxn);
	for(int i=g[pos];i>0;i=f[i].next){
		if(b[f[i].to]==false){
			b[f[i].to]=true;
			dfs(f[i].to,max(maxn,f[i].len));
			b[f[i].to]=false;
		}
		
	}
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(register int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&c);
		f[i*2-1].from=x;
		f[i*2].from=y;
		f[i*2-1].to=y;
		f[i*2].to=x;
		f[i*2-1].len=f[i*2].len=c;
		f[i*2-1].next=g[x];
		f[i*2].next=g[y];
		g[x]=i*2-1;
		g[y]=i*2;
	}
	memset(ans,0x7f,sizeof(ans));
	b[1]=true;
	dfs(1,0);
	//cout<<"@"<<endl;
	for(register int i=2;i<=n;i++){
		//cout<<ans[i]<<" ";
		sum+=ans[i];
	}
	cout<<sum;
}
