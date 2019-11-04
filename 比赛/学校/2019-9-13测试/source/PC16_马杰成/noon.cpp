#include<bits/stdc++.h>
#define eps 1e-8
using namespace std;
int n,m;
int ans=0;
double a[100010];
double k;
int main(){
	freopen("noon.in","r",stdin);
	freopen("noon.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n<=1000 && m<=1000){
		for(int i=1;i<=n;i++)
			a[i]=-1;
		for(int i=1;i<=m;i++){
			int x;double y;
			scanf("%d%lf",&x,&y);
			a[x]=y;
			ans=0;
			k=0;
			for(int j=1;j<=n;j++){
				if(a[j]==-1) continue;
				if(a[j]/j>k){
					k=a[j]/j;
					ans++;
				}		
			}
			printf("%d\n",ans);
		}
		return 0;
	}
	for(int i=1;i<=m;i++){
		int x;double y;
		scanf("%d%lf",&x,&y);
		if(y/x-k>eps){
			k=y/x;
			ans++;
		}
		printf("%d\n",ans);
	}
}

