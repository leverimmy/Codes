#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int > base;
int ans[20];
void dfs(int step,int tar){
	if(step==tar+1){
		int t=0;
		for(int i=tar;i>=1;i--){
			t=t*10+ans[i];
		}
		base.push_back(t);
		return;
	}	
	for(int i=1;i<=2;i++){
		if(i==1){
			ans[step]=4;
			step++;
			dfs(step,tar);
			step--;
			ans[step]=0;
		}
		if(i==2){
			ans[step]=7;
			step++;
			dfs(step,tar);
			step--;
			ans[step]=0;		
		}
	}
} 
int t;
vector<int > now;
signed main(){
	freopen("prd.in","r",stdin);
	freopen("prd.out","w",stdout);
	for(int i=1;i<=12;i++){
		dfs(1,i);
	}
	sort(base.begin(),base.end());
	scanf("%lld",&t);
	while(t--){
		int a,b;
		int res=0;
		scanf("%lld%lld",&a,&b);
		now.clear();
		for(int i=0;i<base.size();i++){
			if(base[i]>b){
				break;
			}
			now.push_back(base[i]);
			if(!now.empty()){
				int ys=b/base[i];
				int rs=a/base[i];
				for(int j=0;j<now.size();j++){
					if(now[j]<=ys){
						now.push_back(now[j]*base[i]);
					}
				}
			}
		}
		for(int j=0;j<now.size();j++){
			if(now[j]>=a){
				cout<<now[j]<<endl;
				res++;
			}
		}
		printf("%lld\n",res);
	}
}
