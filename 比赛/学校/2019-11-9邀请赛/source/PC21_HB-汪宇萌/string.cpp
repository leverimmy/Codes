#include<bits/stdc++.h>
using namespace std;
string s;
int n,cnt[1000010],mx,mmx;
stack<int>stk;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n>>s;
	for(int i=0;i<n;++i){
		if(s[i]=='('){
			stk.push(i);
		}
		else{
			if(stk.empty()){
				mx=0;
			}
			else{
				mx+=2;
//				cout<<mx<<endl;
				mmx=max(mx,mmx);
				cnt[mx]++,
				stk.pop();
			}
		}
	}
	printf("%d %d",mmx,cnt[mmx]);
	return 0;
}
