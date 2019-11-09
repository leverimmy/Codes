#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n;
char s[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	scanf("%s",s+1);
	int t=0,la=0,ans=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='(') t++;
		else t--;
		if(t==0) ans=max(ans,i-la);
		if(t<0) t=0,la=i;
	}
	t=0,la=0;int cnt=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='(') t++;
		else t--;
		if(t==0) {
			if(i-la==ans) cnt++; 
		}
		if(t<0) t=0,la=i;
	}
	printf("%d %d",ans,cnt);
	return 0;
}
