#include<bits/stdc++.h>
using namespace std;
int n,k,a[100010];
long long now;
vector<long long>v;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
inline void outp(int o1){
	if(o1<0)
		putchar('-'),o1=-o1;
	register int o2=o1/10;
	if(o2)
		outp(o2);
	putchar((o1-(o2<<1)-(o2<<3))^48);
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=n;++i)
		a[i]=read();
	for(int i=1;i<=n;++i){
		now=0;
		for(int j=i;j<=n;++j){
			now+=a[j];
//			cout<<now<<endl;
			v.push_back(now);
		}
	}
	sort(v.begin(),v.end(),greater<long long>());
	printf("%lld",v[k-1]);
}
