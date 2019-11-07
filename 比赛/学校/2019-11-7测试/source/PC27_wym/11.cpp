#include<bits/stdc++.h>
using namespace std;
long double x,tmp;
int main(){
	freopen("11.in","r",stdin);
	freopen("11.out","w",stdout);
	while(true){
		tmp=0.00;
		cin>>x;
		if(x==0.00)
			return 0;
		int ans=2;
		tmp+=1.00/ans;
		while(true){
			if(tmp>=x)
				break;
			ans++;
			tmp+=1.00/ans;
		}
		cout<<ans-1<<" card(s)"<<endl;
	}
}
