#include <cstdio>
#include <iostream>
#include <cstring>
#include <set>
#define max(x,y) (x>y)?x:y;
using namespace std;
const int maxn=20,din=10;
char s1[20],s2[20];
int da[maxn],db[maxn],a[maxn],b[maxn],c[maxn];
int la,lb,lc;
long long x,y,z;
inline int power(int x, int y)
{
	long long ans=1;
	for(register int i=1;i<=y;i++)
		ans*=x;
	return ans;
}
inline void chg()
{
	int dd[maxn];
	for(int i=0;i<=la-1;i++)
		dd[i]=a[i];
	memset(da,0,sizeof da);
	for(int i=0;i<=lb-1;i++)
		a[i]=b[i];
	memset(db,0,sizeof db);
	for(int i=0;i<=la-1;i++)
		b[i]=dd[i];
	int t=la;
	la=lb;
	lb=t;
}
inline void sub()
{
	if(la<lb)
		chg();
	else if(a[la-1]<b[lb-1])
		chg();
	for(int i=1;i<=la;i++)
	{
		c[i]=a[i]-b[i];
		if(c[i]<0)
		{
			c[i]+=din;
			c[i+1]--;
		}
	}
	lc=maxn;
	for(int i=maxn-1;i>=0;i--)
		if(!c[i])
			lc--;
		else
			break;
}
inline void init()
{
	for(int i=0;i<=strlen(s1)-1;i++)
		a[i]=(s1[i]-'0');
	for(int i=0;i<=strlen(s2)-1;i++)
		b[i]=(s2[i]-'0');
	la=strlen(s1)-1;
	lb=strlen(s2)-1;
}
set<long long>s;
int main()
{
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	//cin>>s1>>s2;
	/*
	init();
	for(register int i=1;i<=1000000;i++)
	{
		sub();
		memset(a,0,sizeof a);
		for(int i=1;i<=lb;i++)
			a[i]=b[i];
		memset(b,0,sizeof b);
		for(int i=1;i<=lc;i++)
			b[i]=c[i];
		memset(c,0,sizeof c);
		la=lb,lb=lc,lc=maxn;
	}
	*/
	long long n,m;
	cin>>n>>m;
	x=n,y=m;
	s.insert(x);
	s.insert(y);
	for(register int i=1;i<=1000000;i++)
	{
		if(x>y)
			z=x-y;
		else
			z=y-x;
		x=y,y=z;
		s.insert(z);
	}
	cout<<s.size();
}