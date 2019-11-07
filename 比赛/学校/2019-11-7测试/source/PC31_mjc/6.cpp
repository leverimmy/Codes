#include<bits/stdc++.h>
using namespace std;
int n;
string num[50]={"","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
string f[50];
int main(){
	freopen("6.in","r",stdin);
	freopen("6.out","w",stdout); 
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		f[i]=f[i-1]+num[i]+f[i-1];
	}
	cout<<f[n]<<endl;
}
