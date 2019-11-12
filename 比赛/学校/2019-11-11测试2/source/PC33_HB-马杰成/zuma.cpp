#include<bits/stdc++.h>
using namespace std;
int a[1010];
int b[1010];
int vis[1010];
int ans[1010];
int n,k;
int res=0x3f3f3f3f;
int nl[110],nr[110];
void kz(int k){
	int t=a[k];
	int j=k;
	int l,r;
	while(1){
		j--;
		if(a[j]!=t){
			break;
		}
	}
	l=j+1;
	j=k;
	while(1){
		j++;
		if(a[j]!=t){
			break;
		}
	}
	r=j-1;	
	nl[k]=l;nr[k]=r;
}
void init(){
	for(int i=1;i<=n;i++){
		kz(i);
	}
}
void dfs(int now,int sum,int step){
	if(now<1 || now>n) return;
	int l=nl[now],r=nr[now];
	if(r-l+1<k){
		sum+=k-(r-l+1);
	}
	step-=r-l+1;
	if(now!=1 && vis[l-1]==0){
		for(int j=l;j<=r;j++)
			vis[j]=1;
		dfs(l-1,sum,step);
		for(int j=l;j<=r;j++)
			vis[j]=0;
	}
	if(now!=n && vis[r+1]==0){
		for(int j=l;j<=r;j++)
			vis[j]=1;
		dfs(r+1,sum,step);
		for(int j=l;j<=r;j++)
			vis[j]=0;
	}
	if(step==0){
		res=min(res,sum);
	}
}
int main(){ 
	freopen("zuma.in","r",stdin);
	freopen("zuma.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	init(); 
	if(k==1){
		printf("0\n");
	} 
	else{
		for(int i=1;i<=n;i++){
			dfs(i,0,n);
		}
	} 
	printf("%d\n",res);
} 
