#include <bits/stdc++.h>
using namespace std;

int read()
{
	int res=0,p=1;char ch=getchar();
	while(!isdigit(ch)) {if(ch=='-')p=-1; ch=getchar();}
	while(isdigit(ch)) res=res*10+ch-'0',ch=getchar();
	return res*p;
}

const unsigned long long mod=1e15+7;
int n,m;
unsigned long long h[100010],powa[100010];
char a[100010];

unsigned long long qp(long long a,long long b)
{
	if(b==0) return 1;
	if(b==1) return a;
	if(b&1)
	{
		unsigned long long res=qp(a,b/2)%mod*qp(a,b/2)%mod;
		return res*a%mod;
	}
	else
	{
		unsigned long long res=qp(a,b/2)%mod*qp(a,b/2)%mod;
		return res%mod;
	}
}

unsigned long long get(int st,int en)
{
	return ((h[en]-(h[st-1]*qp(26,en-st+1))%mod)%mod+mod)%mod;
}

int main()
{
	freopen("lcp.in","r",stdin);
	freopen("lcp.out","w",stdout);
	n=read(),m=read();
	scanf("%s",a);
	powa[0]=1;
	for(int i=1;i<=n;i++)
	{
		powa[i]=(powa[i-1]*26);
	}
	for(int i=n;i>=1;i--) h[n-i+1]=(h[n-i]+(a[i-1]-'a'+1)*powa[n-i]);
//	cout << 1 << endl; 
//	for(int i=1;i<=n;i++) cout << powa[i] << " ";
	for(int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		x=n-x+1,y=n-y+1;
//		cout << h[x] << " " << h[y] << endl;
		if(x>=y)
		{
			int dif=x-y;
	//		cout << h[x] << " " << h[y]*powa[dif] << endl;
			if(h[x]<((h[y]*powa[dif])))
			{
				cout << 1 << endl;
				continue ;
			}
			else
			{
				cout << 0 << endl;
				continue;
			}
		}
		else
		{
			int dif=y-x;
			if(h[y]<=((h[x]*powa[dif])))
			{
				cout << 0 << endl;
				continue ;
			}
			else
			{
				cout << 1 << endl;
				continue;
			}
		}
	}
	return 0;
}
/*
5 4
abaab
1 3
1 4
4 2
3 2
*/
