#include<bits/stdc++.h>
using namespace std;
priority_queue<__int128,vector<__int128>,greater<__int128> >pq;
__int128 n,t,t1,t2;
__int128 ans;
inline long long read(){
    long long x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
	{
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
	{
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
inline void outp(__int128 o1){
//	if(o1<0)
//		putchar('-'),o1=-o1;
	__int128 o2=o1/10;
	if(o2)
		outp(o2);
	putchar((o1-(o2<<1)-(o2<<3))^48);
}
int main(){
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i)
		t=read(),pq.push(t);
	for(int i=1;i<n;++i){
		t1=pq.top(),pq.pop();
		t2=pq.top(),pq.pop();
		ans+=t1*t2;
		pq.push(t1+t2);
	}
	outp(ans);
	return 0;
}
