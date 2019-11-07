#include<bits/stdc++.h>
using namespace std;
string s[110];
int main(){
	freopen("6.in","r",stdin);
	freopen("6.out","w",stdout);
	int n;
	cin>>n;
	s[1]="A";
	for(int i=2;i<=n;++i){
		s[i].append(s[i-1]);
		s[i].append(1,s[i-1][s[i-1].length()/2]+1);
		s[i].append(s[i-1]);
	}
	int len=s[n].length();
	for(int i=0;i<len;++i)
		putchar(s[n][i]);
	return 0;
}
