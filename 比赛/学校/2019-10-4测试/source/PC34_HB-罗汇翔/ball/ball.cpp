#include<iostream>
#include<cstdio>
using namespace std;
const int mod=1000000007;
int n,m,k;
int a[10010];
int t;
void a1(int k)
{
	int p=0;
	for(int i=0;i<=10000;i++)
	{
		a[i]=a[i]*k+p;
		p=a[i]/10;
		a[i]=a[i]%10;
	}
}
void a2(int k)
{
	long long x=0;
	for(int i=10000;i>=0;i--)
	{
		x=x*10+a[i];
		a[i]=x/k;
		x=x%k;
	}
}
void a3()
{
	long long x=0;
	for(int i=10000;i>=0;i--)
	{
		x=x*10+a[i];
		x=x%mod;
	}
	cout<<x<<endl;
}
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin>>n>>m>>k;
	n=n-k;
	m--;
	a[0]=1;
	if(m>n)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=m;i++)
	{
		a1(n-i+1);
		a2(i);
	}
	a3();
	return 0;
}
