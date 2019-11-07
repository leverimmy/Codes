#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; 
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
typedef long long ll;
const int N=55,mod=1e9+7;
int n,m;
int a[N];
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=i;
	int ans=0;
	do{
		int res=0;
		for(int i=2;i<=n;i++) res+=abs(a[i]-a[i-1]);
		if(res==m) ans++;
	}while(next_permutation(a+1,a+n+1));
	printf("%d",ans);
	return 0;
}
