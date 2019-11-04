#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

struct rec{
	int a,b,power;
}edge[500050];

struct poi{
	vector<int> sons;
	vector<int> powers;
	int val;
}pois[100050];

int fa[100050];
int m,n;
LL ans;

bool cmpEdge(rec x,rec y){
	return x.power<y.power;
}

int get(int x){
	if(x==fa[x]) return x;
	return fa[x]=get(fa[x]);
}

void dfs(int fa,int so){
	//cout<<fa<<endl;
	ans+=pois[so].val;
	for(int i=0;i<pois[so].sons.size();i++){
		if(pois[so].sons[i]!=fa || so==1){
			pois[pois[so].sons[i]].val=max(pois[so].val,pois[so].powers[i]);
			dfs(so,pois[so].sons[i]);
		}
	}
}

int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>edge[i].a>>edge[i].b>>edge[i].power;
	}
	if(m==n-1) goto oktree;
	sort(edge+1,edge+m+1,cmpEdge);
	for(int i=1;i<=n;i++){
		fa[i]=i;
		poi P;
		P.val=0;
		pois[i]=P;
	}
	for(int i=1;i<=m;i++){
		int aa=get(edge[i].a);
		int bb=get(edge[i].b);
		if(aa==bb) continue;
		//cout<<aa<<' '<<bb<<endl;
		fa[aa]=bb;
		pois[edge[i].a].sons.push_back(edge[i].b);
		pois[edge[i].a].powers.push_back(edge[i].power);
		pois[edge[i].b].sons.push_back(edge[i].a);
		pois[edge[i].b].powers.push_back(edge[i].power);
	}
	oktree:
	if(m==n-1){
		for(int i=1;i<=m;i++){
		pois[edge[i].a].sons.push_back(edge[i].b);
		pois[edge[i].a].powers.push_back(edge[i].power);
		pois[edge[i].b].sons.push_back(edge[i].a);
		pois[edge[i].b].powers.push_back(edge[i].power);
		}
	}
	/*for(int i=1;i<=m;i++){
		cout<<edge[i].a<<"--"<<edge[i].b<<':'<<edge[i].power<<endl;
	}
	for(int i=1;i<=n;i++){
		cout<<i<<':'<<fa[i]<<endl;
	}*/
	ans=0;
	pois[1].val=0;
	//cout<<"233"<<endl;
	dfs(0,1);
	cout<<ans;
}
