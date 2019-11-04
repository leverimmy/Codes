#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int T;
string s;
int main() {
	freopen("subscript.in","r",stdin);
	freopen("subscript.out","w",stdout);
	cin>>T;
	for(int i=1; i<=T; i++) {
		getline(cin,s);
		int ls=s.size();
		if(ls<=3) {
			cout<<s;
		} else if(s[0]<s[3]) swap(s[0],s[3]);
		cout<<s;
		getchar();
	}
	return 0;
}
