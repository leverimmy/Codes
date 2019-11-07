#include<bits/stdc++.h>
using namespace std;
int a,b,lst;
int main(){
	freopen("10.in","r",stdin);
	freopen("10.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=(b-a)/5;++i){
		if(i%2){
			for(int j=(i-1)*5;j<(i-1)*5+5;++j)
				cout<<j+a<<' ';
			cout<<endl;
		}
		else{
			for(int j=(i-1)*5+4;j>=(i-1)*5;--j)
				cout<<j+a<<' ';
			cout<<endl;
		}
	}
	if(((b-a)/5)%2==0){
		for(int i=((b-a)/5)*5+a;i<=b;++i)
			cout<<i<<' ';
	}
	else{
		for(int i=b;i>=((b-a)/5)*5+a;--i)
			cout<<i<<' ';
	}
	return 0;
}
