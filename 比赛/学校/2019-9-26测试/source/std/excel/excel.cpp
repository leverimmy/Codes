/*三点的费用就是“以‘三点中离得最远的两点’作为矩形对角两点”的矩形的边长，枚举边长n^2可过。
ans*6是因为可以看做3个行列不同的点中选两个行列不同的，3！
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#define inf 1000000000
#define mod 1000000007
#define ll long long
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m,mn,mx;
int t1[10005],t2[10005];
void cal()
{
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(2*(i+j)>=mn&&2*(i+j)<=mx)
				ans=(ans+(ll)t1[i]*t2[j]*6%mod)%mod;
	printf("%d\n",ans);
}
int main()
{
	freopen("excel.in","r",stdin);
	freopen("excel.out","w",stdout);
	n=read();m=read();mn=read();mx=read();
	for(int i=1;i<=n;i++)t1[i]=(n-i)*(i-1);
	for(int i=1;i<=m;i++)t2[i]=(m-i)*(i-1);
	cal();
	return 0;
}
