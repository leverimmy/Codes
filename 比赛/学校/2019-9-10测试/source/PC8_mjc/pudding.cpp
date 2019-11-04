#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100010];
int to[1000010];
int back[1000010];
int next[1000010];
int q=0;
int cnt=0;
int k=0;
int pos=1;
vector<int > p[100010];
int main(){
	freopen("pudding.in","r",stdin);
	freopen("pudding.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(!to[a[i]]){
			to[a[i]]=++q;			
		}
		a[i]=to[a[i]];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==-1) continue;
		for(int j=i+1;j<=n;j++){
			if(a[j]!=a[i]){
				next[i]=j;
				back[j]=i;
				break;
			}
			a[j]=-1;	
		}
		cnt++;
	}
	while(1){
		if(!next[pos]) {
			p[a[pos]].push_back(pos);
			break;
		}
		p[a[pos]].push_back(pos);
		pos=next[pos];
	}
	for(int i=1;i<=m;i++){
		int op;
		scanf("%d",&op);
		if(op==2){
			printf("%d\n",cnt);
		}
		if(op==1){
			int x,y;
			scanf("%d%d",&x,&y);
			x=to[x];y=to[y];
			if(y==0) continue;
			if(x==0) continue;
			for(int j=0;j<p[x].size();j++){
				if(a[p[x][j]]!=x) continue;
				int l=back[p[x][j]];
				int r=next[p[x][j]];
				if(a[r]==y){
					next[p[x][j]]=next[r];
					back[next[r]]=p[x][j];
					a[r]=-1;
					cnt--;
				}
				if(a[l]==y){
					back[p[x][j]]=back[l];
					next[back[l]]=p[x][j];
					a[l]=-1;
					cnt--;
				}
				a[p[x][j]]=y;
				p[y].push_back(p[x][j]);
			}
		}
	}
}
