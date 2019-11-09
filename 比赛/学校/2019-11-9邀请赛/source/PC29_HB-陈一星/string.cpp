#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<queue>
#include<cctype>
#include<set>
#include<stack>
#define LL long long
#define M 2000000
#define N 50010
#define int long long
using namespace std;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;
const double eps=1e-6;
inline int read(){
	int f=1,x=0;char s=getchar();
	while(!isdigit(s)){if (s=='-')f=-1;s=getchar();}
	while(isdigit(s)){x=(x<<1)+(x<<3)+(s^48);s=getchar();}
	return x*f;
}
int n,ans,len,cnt;
char s[M];
stack<int>c;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=read();
	cin>>s;
	for (int i=0;i<n;i++){
		if (s[i]=='(') c.push(1),len++;
		else if (!c.empty()) c.pop(),len++;
		else{
			if (ans<len) ans=len,cnt=0;
			cnt+=(ans==len);
			len=0;	
		}
	}
	if (c.empty()){
		if (ans<len) ans=len,cnt=0;
		cnt+=(ans==len);
	}
	printf("%d %d",ans,cnt);
	return 0;
}
