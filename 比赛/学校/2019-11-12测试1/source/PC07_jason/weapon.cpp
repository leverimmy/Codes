#include<bits/stdc++.h>
using namespace std;
unsigned long long hsh1[2000001],prod1[2000001];
unsigned long long get_hash1(int l,int r)
{
	return (hsh1[r]-hsh1[l-1])*prod1[1000-l];
}
unsigned long long hsh2[2000001],prod2[2000001];
unsigned long long get_hash2(int l,int r)
{
	return (hsh2[r]-hsh2[l-1])*prod2[1000-l];
}
int a[1000001];
const unsigned long long base1=1000000007;
const unsigned long long base2=1000000009;
signed main()
{
	freopen("weapon.in","r",stdin);
	freopen("weapon.out","w",stdout);
	prod1[0]=(unsigned long long)1;
	for(int i=1;i<=2000;i++)
		prod1[i]=(unsigned long long)1ll*prod1[i-1]*base1;
	int n,l;
	scanf("%d%d",&n,&l);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);

	unsigned long long prod=1;
	for(int i=1;i<=n;i++)
		hsh1[i]=hsh1[i-1]+a[i]*prod,prod*=base1;
	
	prod=1;
	for(int i=1;i<=n;i++)
		hsh2[i]=hsh2[i-1]+a[i]*prod,prod*=base2;

	int ans=0;
	
	for(int i=1;i<=n;i++)
		for(int j=i+l+1;j<=n;j++)
		{
			int len=j-l-i;
			if(i+len*2+l-1>n) continue;
			if(get_hash1(i,i+len-1)==get_hash1(i+len+l,i+len*2+l-1))
			if(get_hash2(i,i+len-1)==get_hash2(i+len+l,i+len*2+l-1))
				ans++;
		}
	printf("%d",ans);
	return 0;
}
