#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
const int maxn=1000010;
using namespace std;
int n;
int a[maxn];
int p,k;
int m;
int vis[maxn];
int pre[maxn];
int flag1;
struct node{
	int p;
	int k;
}in[maxn];
vector<int > rem;
bool cmp(node a,node b){
	return a.k<b.k;
}
int b[maxn];
int last;
void init(int k){
	memset(b,0,sizeof(b));
	for(int i=1;i<=n;i++)
		b[i]=a[i]+k;
	int t=0;
	memset(pre,0,sizeof(pre));
	memset(vis,0,sizeof(vis));
	while(1){
		t++;
		if(t==n+1) break;
		if(vis[t]) continue;
		int now=t;
		rem.clear();
		rem.push_back(t); 
		while(1){
			if(now>n){
				for(int i=0;i<rem.size();i++){ 
					vis[rem[i]]=1;
					pre[rem[i]]=rem.size()-i-1;
				}
					break;
			}
			if(vis[now]){
				for(int i=0;i<rem.size();i++){
					pre[rem[i]]+=rem.size()-i-1+pre[now];
					vis[rem[i]]=1;
				}
				break;
			}
				now+=b[now];
				rem.push_back(now);
		}
	}	
}
int main(){
	freopen("array.in","r",stdin);
	freopen("array.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&m);
	if(n<=100 && m<=100){
		for(int i=1;i<=m;i++){
			scanf("%d%d",&p,&k);
			int q=0;
			int now=p;
			while(1){
				if(now>n) break;
				now+=a[now]+k;
				q++;
			}
			printf("%d\n",q);
		}
	}
	else{
		for(int i=1;i<=m;i++){
			scanf("%d%d",&in[i].p,&in[i].k);
			if(in[i].k!=0) flag1=1;
		}
		if(!flag1){
			int t=0;
			while(1){
				t++;
				if(t==n+1) break;
				if(vis[t]) continue;
				int now=t;
				rem.clear();
				rem.push_back(t); 
				while(1){
					if(now>n){
						for(int i=0;i<rem.size();i++){ 
							vis[rem[i]]=1;
							pre[rem[i]]=rem.size()-i-1;
						}
							break;
					}
					if(vis[now]){
						for(int i=0;i<rem.size();i++){
							pre[rem[i]]+=rem.size()-i-1+pre[now];
							vis[rem[i]]=1;
						}
						break;
					}
					now+=a[now];
					rem.push_back(now);
				}
			}
	//		for(int i=1;i<=n;i++)
	//			cout<<pre[i]<<endl;
			for(int i=1;i<=m;i++){
				printf("%d\n",pre[in[i].p]);
			}
		}
		else{
			sort(in+1,in+1+m,cmp);
			for(int i=1;i<=m;i++){
				if(in[i].k!=k){
					init(in[i].k);
					printf("%d\n",pre[in[i].p]);
				}
				else{
					printf("%d\n",pre[in[i].p]);
				}
			}
		}
	}
}
