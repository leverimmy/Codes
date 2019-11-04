#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;
int T;
string str;
string work(string s){
	int len=s.length();
	string a;
	string b;
	string c;
	stack <char> sta;
	bool flag=0;
	int posc=-1;
	for(int i=0; i<len; i++){
		if(s[i]=='['){
			if(flag==0){
				flag=1;
			}
			else{
				b=b+s[i];
			}
			sta.push('[');
		}
		else if(s[i]==']'){
			if(sta.size() && sta.top()=='['){
				sta.pop();
			}
			if(sta.empty()){
				posc=i+1;
				break;
			}
			else{
				if(!flag){
					a=a+s[i];
				}
				else{
					b=b+s[i];
				}
			}
		}
		else{
			if(!flag){
				a=a+s[i];
			}
			else{
				b=b+s[i];
			}
		}
	}
	if(!flag){
		return s;
	}
	if(posc!=-1){
		for(int i=posc; i<len; i++){
			c=c+s[i];
		}
		int lenc=c.length();
		if(c[0]=='[' && c[lenc-1]==']'){
			c=c.substr(1, lenc-2);
		}
	}
//	cout<<"s:"<<s<<endl<<"a:"<<a<<endl<<"b:"<<b<<endl<<"c:"<<c<<endl<<endl;
	string A=work(a),B=work(b),C=work(c);
	string ans;
	if(A<B){
		ans=A+'['+B+']';
	}
	else{
		ans=B+'['+A+']';
	}
	if(C.length()==0){
		return ans;
	}
	if(ans<C){
		return ans+'['+C+']';
	}
	else{
		return C+'['+ans+']';
	}
}
int main(){
	freopen("subscript.in", "r", stdin);
	freopen("subscript.out", "w", stdout);
	scanf("%d",&T);
	while(T--){
		cin>>str;
		if(str.length()<=2){
			cout<<str<<endl;
		}
		cout<<work(str)<<endl;
	}
	return 0;
}

