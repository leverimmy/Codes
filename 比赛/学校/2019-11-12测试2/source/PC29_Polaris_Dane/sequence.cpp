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
const int M=400000;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
inline int read(){
	int x=0,f=1;char s=getchar();
	while (!isdigit(s)){if(s=='-')f=-1;s=getchar();}
	while (isdigit(s)){x=(x<<1)+(x<<3)+(s^48);s=getchar();}
	return x*f;
}
int n,k;
int a[M],s[M],pos[M][30],logn[M]={-1};
struct node{
	int t,l,r,id;
	bool operator <(const node&a)const{
		return s[id]-s[t-1]<s[a.id]-s[a.t-1];
	}
};
priority_queue<node>pq;
inline int RMQ(int l,int r){
	int k=logn[r-l+1];
	int x=pos[l][k],y=pos[r-(1<<k)+1][k];
	return s[x]>s[y]?x:y; 
}
signed main(void){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read(),k=read();
	for (int i=1;i<=n;i++) a[i]=read(),s[i]=s[i-1]+a[i],pos[i][0]=i,logn[i]=logn[i>>1]+1;
	for (int i=1;(1<<i)<=n;i++)
		for (int j=1;j+(1<<i)-1<=n;j++){
			int x=pos[j][i-1],y=pos[j+(1<<(i-1))][i-1];
			pos[j][i]=s[x]>s[y]?x:y;
		}
	for (int i=1;i<=n;i++)
		pq.push(node{i,i,n,RMQ(i,n)});
	for (int i=1;i<=k-1;i++){
		node h=pq.top();pq.pop();
		if (h.id!=h.l)
			pq.push(node{h.t,h.l,h.id-1,RMQ(h.l,h.id-1)});
		if (h.id!=h.r)
			pq.push(node{h.t,h.id+1,h.r,RMQ(h.id+1,h.r)});	
	}
	node h=pq.top();
	printf("%d",s[h.id]-s[h.t-1]);
	return 0;
}

