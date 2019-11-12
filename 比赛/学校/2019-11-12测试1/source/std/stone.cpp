#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
unsigned long long n,len,lenp,lena,ksum,psum;
ll sum[10000],ans[10000],pow[10000];

inline int read ()
{
	int s=0;
	char ch=getchar ();
	while (ch<'0'||ch>'9') ch=getchar ();
	while (ch>='0'&&ch<='9') {s=s*10+ch-'0';ch=getchar ();}
	return s;
}

void jinwei ()
{
	while (ksum) {
		len++;
		sum[len]=ksum%10;
		ksum/=10;
	}
	while (psum) {
		lenp++;
		pow[lenp]=psum%10;
		psum/=10;
	}
}

int main ()
{
	ll x,l;
	freopen ("stone.in","r",stdin);
	freopen ("stone.out","w",stdout);
	n=read ();
	for (int i=1;i<=n;i++) x=read (),ksum+=x,psum+=x*x;
	jinwei ();
	for (int i=1;i<=len;i++)
		for (int j=1;j<=len;j++)
			ans[i+j-1]+=sum[i]*sum[j];
	lena=len*2;
	for (int i=1;i<=lenp;i++) ans[i]-=pow[i];
	for (int i=1;i<=lena;i++) {
		if (ans[i]>=10) ans[i+1]+=ans[i]/10,ans[i]%=10;
		else if (ans[i]<0) ans[i]+=10,ans[i+1]--;
	}
	for (int i=lena;i>=1;i--) {
		if (ans[i]%2==1) ans[i-1]+=10;
		ans[i]>>=1;
	}
	while (!ans[lena]) lena--;
	for (int i=lena;i>=1;i--) cout<<ans[i];
	return 0;
}
