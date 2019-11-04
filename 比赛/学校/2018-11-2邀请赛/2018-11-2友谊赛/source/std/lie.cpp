#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<map>
#include<ctime>
#include<vector>
#include<cmath>
#include<algorithm>
#define inf 1000000000
#define ll long long
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n;
int f[100005];
vector<int> q[100005];
map<pair<int,int>,int> s;
int main()
{
	freopen("lie.in","r",stdin);
	freopen("lie.out","w",stdout); 
	n=read();
	for(int i=1;i<=n;i++)
	{
		int a=read(),b=read();
		int l=a+1,r=n-b;
		if(l>r)continue;
		s[make_pair(l,r)]++;
		if(s[make_pair(l,r)]==1)q[r].push_back(l);
	}
	for(int i=1;i<=n;i++)
	{
		f[i]=f[i-1];
		for(int j=0;j<q[i].size();j++)
			f[i]=max(f[i],f[q[i][j]-1]+min(i-q[i][j]+1,s[make_pair(q[i][j],i)]));
	}
	printf("%d\n",n-f[n]);
	return 0;
}
