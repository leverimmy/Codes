#include <bits/stdc++.h>
using namespace std;

int MOD=1e9+7,INF=26;

int n,f,p[100010],a[100010];
long long num;
int c[500001];

int lowbit(int x)
{
	return x&(-x);
}

void update(int x,int y)
{
	for(;x<=n;x+=lowbit(x))
		c[x]+=y;
}

long long sum(int x)
{
	long long ans=0;
	for(;x;x-=lowbit(x))
		ans+=c[x];
	return ans;
}

long long getsum(int l,int r)
{
	return (sum(r)-sum(l-1));
}

int read()
{
	char ch=getchar();int res=0,p=1;
	while(!isdigit(ch)) { if(ch=='-')p=-1; ch=getchar();}
	while(isdigit(ch)) res=res*10+ch-'0',ch=getchar();
	return res*p;
}


int main()
{
	freopen("weapon.in","r",stdin);
	freopen("weapon.out","w",stdout);
	n=read(),f=read();
	for(int i=1;i<=n;i++) a[i]=read(),update(i,a[i]);
	for(int len=(n-f)/2;len>=1;len--)
		for(int i=1;i<=n+1-len*2-f;i++)
			if(getsum(i,i+len-1)==getsum(i+len+f,i+2*len+f-1))
				num++;
	cout << num << endl;
	return 0;
}
