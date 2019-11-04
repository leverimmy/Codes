#include<bits/stdc++.h>
using namespace std;
struct node{
	int l,r,ind,v;
}in[200010];
bool cmp(node a,node b){
	return a.r<b.r;
}
vector<int > pp;
int n,ans;
int maxx=0;
int main(){
	freopen("interval.in","r",stdin);
	freopen("interval.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&in[i].l,&in[i].r);
		in[i].ind=i;
	}	
	sort(in+1,in+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(maxx<in[i].l){
			ans++;
			pp.push_back(in[i].ind);
			maxx=max(maxx,in[i].r);	
		}
	}
	sort(pp.begin(),pp.end()); 
	printf("%d\n",ans);
	for(int i=0;i<pp.size();i++){
		printf("%d ",pp[i]);
	}
}
