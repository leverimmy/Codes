#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=4e6+5;
inline int read(){
	int s=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s;
}
int n,a[N];
int res[105];
inline void print(__int128 x){
	int cnt=0;
	do{
		res[++cnt]=x%10;
		x/=10;
	}while(x>0);
	for(int i=cnt;i>=1;i--) putchar('0'+res[i]);
}
int main(){
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	n=read();
	a[1]=read();
	__int128 ans=0;ll pre=a[1];
	for(int i=2;i<=n;i++) {
		a[i]=read();
		ans+=pre*a[i];pre+=a[i];
	}
	print(ans);
	return 0;
} 
