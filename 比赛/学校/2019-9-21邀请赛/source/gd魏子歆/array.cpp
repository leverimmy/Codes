#include<bits/stdc++.h>
using namespace std;

int n,m,a[100010];
int yu[310][100010];

int main(){
	//freopen("array.in","r",stdin);
	//freopen("array.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cin>>m;
	int p,k,las,ans;
	for(int i=0;i<=300;i++){
		for(int j=n;j>=1;j--){
				las=j;
				las+=a[las]+i;
				yu[i][j]=(las>n)?1:yu[i][las]+1;
				//cout<<"fuc ";
			}
	}
	for(int i=1;i<=m;i++){
		cin>>p>>k;
		if(k<=300){
			cout<<yu[k][p];
		}else{
			ans=0;
			while(p<=n){
				ans++;
				p+=a[p]+k;
			}
			cout<<ans;
		}
		if(i!=m) cout<<endl;
	}
	return 0;
}
