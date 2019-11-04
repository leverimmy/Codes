#include<iostream>
using namespace std;
long long x,y,a[50050],b[50050],ex,ey;
int n;
int main(){
	freopen("wave.in","r",stdin);
	freopen("wave.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	for(int i=1;i<=n;i++){
		long long dx=0,dy=0;
		for(int j=i+1;j<=n;j++){
			if(a[j]<a[i]) dx=max(dx,a[j]);		
			if(b[j]<b[i]) dy=max(dy,b[j]);
		}
		x+=(a[i]-dx);
		y+=(b[i]-dy);
	}
	cout<<x+y;
	return 0;
}
