#include <bits/stdc++.h>
using namespace std;

long long a1,a2,ans;
int a[200000];
//bool f[2000000];

map<int,int> f;

long long read()
{
	long long res=0,p=1;char ch=getchar();
	while(!isdigit(ch)) {if(ch=='-')p=-1; ch=getchar();}
	while(isdigit(ch)) res=res*10+ch-'0',ch=getchar();
	return res*p;
}

int main()
{
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	a1=read(),a2=read();
//	cout << a1 << " " << a2 << endl;
	if(a1==a2 || a1==0 || a2==0)
	{
		cout << 2 << endl;
		return 0;
	}
	//ans+=2;
	//f[a1]=f[a2]=1;
	//a[1]=a1,a[2]=a2;
//	f[1]=9012;
//	cout << f.count(1) << endl;
	f[a1]=++ans;f[a2]=++ans;
	while(true)
	{
//		cout << ans <<endl;
		int k=abs(a1-a2);
//		cout << k << endl;
//		if(!f[k]) f[k]=1,ans++,a[ans]=k;
		if(!f.count(k)) f[k]=++ans;
		if(k==0) break;
		a1=a2,a2=k;
	}
	cout << ans << endl;
	return 0;
}
