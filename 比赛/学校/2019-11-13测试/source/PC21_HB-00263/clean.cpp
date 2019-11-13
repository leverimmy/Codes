#include<bits/stdc++.h>
using namespace std;
inline int qread(){
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
void qwrite(int o1){
	if(o1<0)
		putchar('-'),o1=-o1;
	register int o2=o1/10;
	if(o2)
		qwrite(o2);
	putchar((o1-(o2<<1)-(o2<<3))^48);
}
int len,n;
int cf[500010];
int main(){
	freopen("clean.in","r",stdin);
	freopen("clean.out","w",stdout);
	len=qread(),n=qread();
	int l,r;
	for(int i=1;i<=n;++i){
		l=qread(),r=qread();
		cf[l]++,cf[r+1]--;
	}
	int now=0,ans=0;
	for(int i=1;i<=len;++i){
		now+=cf[i];
		if(now<=0)
			ans++;
	}
	qwrite(ans);
	return 0;
}
