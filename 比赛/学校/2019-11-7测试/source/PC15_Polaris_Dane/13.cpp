#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cctype>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdlib>
#define int long long
using namespace std;
const int M=100000;
const int inf=0x7f7f7f7f;
const int mod=1e9+7;
const double eps=1e-6;
inline int read(){
	int x=0,f=1;char s=getchar();
	while (!isdigit(s)){if (s=='-') f=-1;s=getchar();}
	while (isdigit(s)){x=(x<<1)+(x<<3)+(s^48);s=getchar();}
	return x;
}
int n,cnt,pre;
vector<int>s,num; 
signed main(void){
	freopen("13.in","r",stdin);
	freopen("13.out","w",stdout);
	pre=n=read();
	for (int i=2;i<=n;i++){
		if (n%i) continue;
		int cnt=0;
		s.push_back(i);
		while (n%i==0) cnt++,n/=i;
		num.push_back(cnt);
	}
	printf("%d=",pre);
	for (int i=0;i<s.size();i++){
		printf("%d",s[i]);
		if (num[i]!=1) printf("^%d",num[i]);
		if (i!=s.size()-1) printf("*");
	}
	return 0;
}

