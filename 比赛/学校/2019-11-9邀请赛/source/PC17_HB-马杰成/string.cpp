#include<bits/stdc++.h>
using namespace std;
int a[2000010];
char s[2000010];
int n,maxx;
int mjc[2000010];
int c[2000010];
int cnt;
int main(){
	freopen("string.in","r",stdin); 
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		char ch;
		cin>>ch;
		if(ch=='('){
			a[i]=0;
		}
		else{
			a[i]=1;
		}
	}
	stack<int > s;
	for(int i=1;i<=n;i++){
		int t=0;
		if(a[i]==0){
			if(s.empty()){
				cnt=0;
			}
			s.push(i);
		}
		else{
			if(!s.empty()){
				cnt++;
				c[i]=cnt;
				s.pop();
			}
		}
	}
//	for(int i=1;i<=n;i++)
//		printf("%d ",c[i]);
	for(int i=1;i<=n;i++){
		mjc[c[i]]++;
		maxx=max(maxx,c[i]);
	}
	printf("%d %d\n",maxx*2,mjc[maxx]);
}
