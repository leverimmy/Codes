#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int n,m;
string s;
int main(){
	freopen("lcp.in","r",stdin);
	freopen("lcp.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int a,b;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		if(s.substr(a)<s.substr(b))cout<<0;
		else cout<<1;
		cout<<endl;
	}
	return 0;
}
