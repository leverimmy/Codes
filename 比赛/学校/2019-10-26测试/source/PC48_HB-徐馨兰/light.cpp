#include <bits/stdc++.h>
using namespace std;

int n,m,a[10010];

int read()
{
	int res=0,p=1;char ch=getchar();
	while(!isdigit(ch)) {if(ch=='-')p=-1; ch=getchar();}
	while(isdigit(ch)) res=res*10+ch-'0',ch=getchar();
	return res*p;
} 

int main() 
{
	freopen("light.in","r",stdin);
	freopen("light.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int test=1;test<=m;test++)
	{
		int l=read(),r=read(),p=read(),v=read(),ans=0;
		for(int i=l;i<=r;i++) if(a[i]%p==v) ans++;
		cout << ans << endl;
	}
	return 0;
}
