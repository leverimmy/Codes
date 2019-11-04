#include<bits/stdc++.h>
using namespace std;
int n,m;
int visl[100010];
int visr[100010];
int main(){
	freopen("rush.in","r",stdin);
	freopen("rush.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		visl[x]=1;
		visr[y]=1;
	}
	int cnt1=0,cnt2=0,ans=0;
	for(int i=1;i<=n;i++){
		if(!visl[i]){
			cnt1++;
		}
	}
	for(int i=1;i<=n;i++){
		if(!visr[i]){
			cnt2++;
		}
	}
	printf("%d\n",cnt1+cnt2);
//	if(cnt1>=cnt2){
//		for(int i=1;i<=n;i++){
//			if(visl[i] && !visr[i]){
//				ans++;
//			}
//		}
//		printf("%d\n",ans+cnt1);
//	}
//	if(cnt2>cnt1){
//		for(int i=1;i<=n;i++){
//			if(visr[i] && !visl[i]){
//				ans++;
//			}
//		}
//		printf("%d\n",ans+cnt2);
//	}
	
}
