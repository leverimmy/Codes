#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
const int N = 1000010;
char str[N];
int n,ans,cnt;
int f[N];
bool ok[N];
struct data{
	int pos;
	char ch;
};
stack <data> s;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d%s",&n,str);
	for(int i=0; i<n; i++){
		if(str[i]=='('){
			s.push((data){i, '('});
		}
		else{
			if(!s.empty()){
				ok[i]=ok[s.top().pos]=1;
				s.pop();
			}
		}
	}
	for(int i=0; i<n; i++){
		if(ok[i]){
			f[i]=f[i-1]+1;
		}
		else{
			f[i]=0;
		}
		if(ans<f[i]){
			ans=f[i];
			cnt=1;
		}
		else if(ans==f[i]){
			cnt++;
		}
	}
	printf("%d %d\n",ans,cnt);
	return 0;
}

