#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <stack>
#include <vector>
using namespace std;
const int N = 20;
const string k[11]={"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu", "shi"};
const string n[5]={"", "", "wan", "yi"};
const string m[5]={"", "", "shi", "bai", "qian"};
stack<string> stk[4];
char s[N];
int a[N];
vector<string> ans[4];
int main(){
	freopen("3.in", "r", stdin);
	freopen("3.out", "w", stdout);
	scanf("%s", s+1);
	int len=strlen(s+1);
	for(int i=1; i<=len; i++){
		a[i]=s[i]-'0';
	}
	reverse(a+1, a+1+len);
	int flag=0;
	for(int i=1; i<=3; i++){
		if(i==2 && len==4){
			break;
		}
		if(i==3 && len==8){
			break;
		}
		if(flag==1){
			break;
		}
		for(int j=1; j<=4; j++){
			if((i-1)*4+j>len){
				flag=1;
				break;
			}
			if(a[(i-1)*4+j]==0){
				if(!stk[i].empty() && stk[i].top()!="ling"){
					stk[i].push(k[a[(i-1)*4+j]]);
				}
				continue;
			}
			stk[i].push(m[j]);
			stk[i].push(k[a[(i-1)*4+j]]);
		}
	}
	for(int i=1; i<=3; i++){
		while(!stk[i].empty()){
			if(stk[i].top()!=""){
				ans[i].push_back(stk[i].top());
			}
			stk[i].pop();
		}
	}
	for(int i=1; i<=3; i++){
		len=ans[i].size();
		if(ans[i][len-1]=="ling"){
			ans[i].pop_back();
		}
	}
	for(int i=1; i<=3; i++){
		len=ans[i].size();
		for(int j=0; j<len; j++){
			cout<<ans[i][j]<<" ";
		}
	}
	return 0;
}

