#include<bits/stdc++.h>
using namespace std;
struct node{
	int ind;
	int num;
}in[100010];
int cnt[100010];
int n;
bool cmp(node a,node b){
	if(a.num==b.num){
		return a.ind<b.ind;
	} 
	return a.num<b.num;
}
int now;
int ans[100010];
int main(){
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&in[i].num);
		in[i].ind=i;
	}
	sort(in+1,in+n+1,cmp);
	for(int i=1;i<=n;i++){
		int j=i,t=in[i].num;
		now=0;
		while(1){
			if(j>n) break;
			if(in[j].num!=t){
				i=j-1;
				break;
			}
			cnt[t]++;
			now++;
			ans[in[j].ind]=now;
			if(now>cnt[t-1] && t!=1){
				printf("-1");
				return 0;
			}	
			j++;		
		}
	}
	printf("%d\n",cnt[1]);
	for(int i=1;i<=n;i++){
		printf("%d ",ans[i]);
	}
}	

 
