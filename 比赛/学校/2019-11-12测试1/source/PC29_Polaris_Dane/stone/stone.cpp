#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<set>
#include<algorithm>
#include<cctype>
#include<stack>
#include<queue>
using namespace std;
const int M=4000010;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
inline int read(){
	int x=0,f=1;char s=getchar();
	while (!isdigit(s)){if(s=='-')f=-1;s=getchar();}
	while (isdigit(s)){x=(x<<1)+(x<<3)+(s^48);s=getchar();}
	return x*f;
}
inline void write(__int128 a){
	if(a) write(a/10);
	else return;
	putchar(a%10+48);
}
__int128 a,ans;
priority_queue<__int128>pq;
signed main(void){
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	int n=read();
	for (int i=1;i<=n;i++){
		int x=read();a=x,pq.push(a);
	}
	for (int i=1;i<=n-1;i++){
		__int128 b=pq.top();pq.pop();
		__int128 c=pq.top();pq.pop();
		ans=ans+b*c;
		pq.push(b+c);
	}
	write(ans);
	return 0;
}
