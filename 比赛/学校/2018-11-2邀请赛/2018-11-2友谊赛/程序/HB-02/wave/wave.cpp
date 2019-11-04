#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
long long ans=0;
int x[50005];
int y[50005];
int max1=0,max2=0;
int main(){
	freopen("wave.in","r",stdin);
	freopen("wave.out","w",stdout);
	cin>>n;
	int cntx=0;
	int cnty=0;
	int a,b;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
	}
	max1=x[n];
	max2=y[n];
	ans=x[n]+y[n];
	for(int i=n-1;i>=1;i--){
		if(x[i]>max1){
			ans+=x[i]-max1;
			ans+=y[i];
			max1=x[i];
//			cout<<max1<<" "<<max2<<endl;
		}
	    if(y[i]>max2){
			ans+=y[i]-max2;
			ans+=x[i];
			max2=y[i];
//			cout<<max1<<" "<<max2<<endl;
		} 
	}
	cout<<ans<<endl;
	return 0;
}
//	sort(m+1,m+n+1,cmp); 
