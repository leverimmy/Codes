#include<bits/stdc++.h>
using namespace std;
int n,a[110][110],gnum,bnum;
vector<int>gchip;
int main(){
	freopen("7.in","r",stdin);
	freopen("7.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)
			cin>>a[i][j];
	}
	for(int i=1;i<=n;++i){
		gnum=bnum=0;
		for(int j=1;j<=n;++j){
			if(j==i)
				continue;
			if(a[i][j])
				gnum++;
			else
				bnum++;
		}
		if(gnum>=bnum)
			gchip.push_back(i);
	}
	for(int i=0;i<gchip.size();++i)
		cout<<gchip[i]<<' ';
	return 0;
}
