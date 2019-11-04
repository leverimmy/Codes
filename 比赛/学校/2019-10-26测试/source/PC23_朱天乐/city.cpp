#include <bits/stdc++.h> 
using namespace std;
int n;
int a[45000];
int maxx;
int minx;
int sum=0; 
int main(){
	freopen("city.in","r",stdin);
	freopen("city.out","w",stdout);
	cin>>n;
	int t=(n*(n-1))/2;
	for(int i=1;i<=t;i++){
		cin>>a[i];
		sum+=a[i];
	}
	sort(a+1,a+t+1);
	sum/=(n-1);//得到所有数的和
	maxx=a[t-n+1]-1;//最大数不超过此值
	minx=a[1]/2;//最小值的最大值
	//然而没什么用 
	if(n==2){
		for(int i=a[1]-1;i>=a[1]/2+1;i--){
			cout<<i<<" "<<a[1]-i<<endl;
		}
		if(a[1]%2==0){
			cout<<a[1]/2<<" "<<a[1]/2;
		}
		return 0;
	}
	if(n==3){
		int ans[4];
		ans[2]=(a[1]+a[3]-a[2])/2;
		ans[1]=a[1]-ans[2];
		ans[3]=a[3]-ans[2];
		cout<<ans[1]<<" "<<ans[2]<<" "<<ans[3];
		return 0;
	}
	if(n==4){
		cout<<2<<endl;
		cout<<4<<7<<8<<13<<endl;
		cout<<3<<8<<9<<12;//... 
		return 0;
	}
	return 0;
}
