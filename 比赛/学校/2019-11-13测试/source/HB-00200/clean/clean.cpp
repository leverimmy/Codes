#include<bits/stdc++.h>
using namespace std;
struct node{
	int l,r;
}in[1000010];
bool cmp(node a,node b){
	if(a.l==b.l) return a.r<b.r;
	return a.l<b.l;
}
int last;
int n,m;
int ans;
int main(){
	freopen("clean.in","r",stdin);
	freopen("clean.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&in[i].l,&in[i].r);
	}
	sort(in+1,in+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(last<in[i].l){
			if(in[i].r-in[i].l+1>0)
				ans+=in[i].r-in[i].l+1;
		}
		if(last==in[i].l){
			if(in[i].r-in[i].l>0)
				ans+=in[i].r-in[i].l;
		}
		if(last>in[i].l){
			if(in[i].r-last>0)
				ans+=in[i].r-last;
		}
		last=max(last,in[i].r);
	}
	printf("%d\n",n-ans);
}
