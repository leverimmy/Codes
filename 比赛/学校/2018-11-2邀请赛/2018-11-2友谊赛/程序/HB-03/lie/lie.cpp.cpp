#include<iostream>
#include<algorithm>
using namespace std;
int n,cnt;
long long a[100010],b[100010],a1,b1,t;
long long k[100010];
int main(){
	freopen("lie.in","r",stdin);
	freopen("lie.out","w",stdout);
	cin>>n;
	int nn=n;
	while(nn--){
		int x,y;
		cin>>x>>y;
		if((x+y)>n){
			cnt++;
			continue;
		}
		t++;
		a[t]=x;
		b[t]=y;
		a1+=a[t];
		b1+=b[t];
		k[t]+=(n-a[t]-1)+(n-b[t]-1);
		k[t]*=2;
	}
	if(a1==b1){
		cout<<cnt;
		return 0;
	}
	int s=abs(a1-b1);
	sort(k+1,k+t+1);
	for(int i=t;i;i--){
		if(s>k[i]) s-=k[i],cnt++;
		if(k[i]>s){
			cnt++;
			break;
		}
	}
	cout<<cnt;
	return 0;
}
