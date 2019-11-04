#include <iostream>
#include <string>
#include <algorithm>
#define il inline
#define rgi register int

using namespace std;
int n,m,q,mina=2147483647,maxa=-2147483647;
int a[202][202],ans;
string s;
signed main()
{
	ios::sync_with_stdio(false);
	freopen("geometry.in","r",stdin);
	freopen("geometry.out","w",stdout);
	cin>>n>>m>>q;
	for(rgi i=1;i<=m;++i)
	{
		cin>>s;
		int p=s[1]-'0';
		cin>>s;
		int st;
		if(s[0]=='p')
			st=1;
		else
			st=-1;
		cin>>s;
		int q=s[1]-'0';
		mina=min(mina,min(p,q));
		maxa=max(maxa,max(p,q));
		if(a[p][q]==0)
			a[p][q]=st,a[q][p]=st;
		else
		{
			puts("There must be something wrong!");
			return 0;
		}
	}
	for(rgi k=mina;k<=maxa;++k)
		for(rgi i=mina;i<=maxa;++i)
		{
			if(i==k)
				continue;
			for(rgi j=mina;j<=maxa;++j)
			{
				if(k==j||i==j)
					continue;
				if(a[i][k]==-1&&a[k][j]==-1)
				{
					if(a[i][j]!=-1)
						a[i][j]=1,a[j][i]=1;
					else
					{
						puts("There must be something wrong!");
						return 0;
					}
				}
				if(a[i][k]==1&&a[k][j]==1)
				{
					if(a[i][j]!=-1)
						a[i][j]=1,a[j][i]=1;
					else
					{
						puts("There must be something wrong!");
						return 0;
					}
				}
			}
		}
	for(rgi k=mina;k<=maxa;++k)
		for(rgi i=mina;i<=maxa;++i)
		{
			if(i==k)
				continue;
			for(rgi j=mina;j<=maxa;++j)
			{
				if(k==j||i==j)
					continue;
				if(a[i][k]==-1&&a[k][j]==-1)
				{
					if(a[i][j]!=-1)
						a[i][j]=1,a[j][i]=1;
					else
					{
						puts("There must be something wrong!");
						return 0;
					}
				}
				if(a[i][k]==1&&a[k][j]==1)
				{
					if(a[i][j]!=-1)
						a[i][j]=1,a[j][i]=1;
					else
					{
						puts("There must be something wrong!");
						return 0;
					}
				}
			}
		}
	for(rgi i=mina;i<=maxa;++i)
		for(rgi j=mina;j<=maxa;++j)
			if(a[i][j]==1)
			{
				++ans;
				//cout<<i<<" "<<j<<endl;
			}
	cout<<(ans>>1)<<endl;
	for(;q;--q)
	{
		cin>>s;
		int p=s[1]-'0';
		cin>>s;
		int q=s[1]-'0';
		if(a[p][q]==1)
			cout<<"Parallel."<<endl;
		else if(a[p][q]==-1)
			cout<<"Vertical."<<endl;
		else
			cout<<"No idea."<<endl;
	}
	return 0;
}

