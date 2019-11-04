#include <bits/stdc++.h>
using namespace std;

const int mod=1e9+7;

int read()
{
	int res=0,p=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')p=-1; ch=getchar();}
	while(isdigit(ch)) res=res*10+ch-'0',ch=getchar();
	return res*p;
}

int n,m,k,cnta=1,cntb=1,cntc;
//char c[1000],aa[1000],ba[1000];

unsigned long long gcd(unsigned long long a,unsigned long long b)
{
	if(a%b==0) return b;
	if(b%a==0) return a;
	while(a!=b)
	{
		if(a==1 || b==1) return 1;
//		cout << a << " " << b << endl;
		if(a>b) b=a-b,a=a-b;
		else a=b-a,b=b-a;
		if(a==b) return a;
	}
}

unsigned long long c(int a,int b)
{
	unsigned long long res=1,div=1;
	for(int i=1;i<=b;i++)
	{
		div*=i;
		res*=a-i+1;
		if(res%div==0)
		{
			res=res/div;
			div=1; 
		}
//		cnta=mult(aa[1000],i,cnta);
//		cntb=mult(ba[1000],a-i+1,cntb);
	}
	return res/div%mod;
//	cha(aa[1000],cnta);cha(ba[1000],cntb);
//	div(aa[1000],ba[1000],cnta,cntb);
}

/*void cha(char a[],int cnt)
{
	for(int i=1;i<=cnt/2;i++)
	{
		char k=a[i];
		a[i]=a[cnt-i+1];
		a[cnt-i+1]=a[i];
	}
}

int mult(char a[],long long b,int cnt)
{
	for(int i=cnt;i>=1;i--)
	{
		a[i]*=b;
		while(a[i]-'0'>=10)
		{
			a[i]-=10;
			if(!a[i+1])
			{
				a[i+1]='0';
				cnt++;
			}
			a[i+1]++;
		}
	}
	return cnt;
}

void div(char a[],char b[],int cnta,int cntb)
{
	
}*/

int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	n=read(),m=read(),k=read();
	if(m==1){cout << 1 << endl;return 0;}
	n-=k,--m;
	if(m>n){cout << 0 << endl;return 0;}
	if(m==n){cout << 1 << endl;return 0;}
	if(m==1){cout << n << endl;return 0;}
	m=min(m,n-m);
	//aa[1]='1',ba[1]='1';
	unsigned long long ans=c(n,m);
	//for(int i=1;ca[i];i++)
	//	cout << ca[i];
	//cout << endl;
	cout << ans << endl;
	return 0;
}
