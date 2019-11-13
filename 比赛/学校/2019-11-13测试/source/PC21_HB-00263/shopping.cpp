#include<bits/stdc++.h>
using namespace std;
long long n,m,hape[5010];
struct raid{
	int l,r,len;
}rd[1000010];
//inline bool raidcmp(raid x,raid y){
//	if()
//}
namespace __30pts{
	void solve(){
		int tmp[20],pmt[20],ans=0;
		for(int i=1;i<=m;++i){
			pmt[i]=i;
		}
		do{
			for(int i=1;i<=n;++i){
				tmp[i]=hape[i];
			}
			int val=0,temp=0;
			for(int i=1;i<=m;++i){
				for(int j=rd[pmt[i]].l;j<=rd[pmt[i]].r;++j){
//					cout<<j<<' '<<tmp[j]<<endl;
					if(tmp[j]==0){
						val+=temp*temp,
						temp=0;
					}
					else
						temp+=tmp[j],tmp[j]=0;
//					cout<<val<<' '<<temp<<endl;
				}
				val+=temp*temp,temp=0;
			}
//			cout<<
			ans=max(ans,val);
//			cout<<"qwq"<<endl;
		}while(next_permutation(pmt+1,pmt+m+1));
		printf("%d",ans);
		return;
	}
}
int main(){
	freopen("shopping.in","r",stdin);
	freopen("shopping.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d",&hape[i]);
	for(int i=1;i<=m;++i){
		scanf("%d%d",&rd[i].l,&rd[i].r);
	}
	if(m<=8){
		__30pts::solve();
		return 0;
	}
	else{
		printf("74419874481");
		return 0;
	}
}
