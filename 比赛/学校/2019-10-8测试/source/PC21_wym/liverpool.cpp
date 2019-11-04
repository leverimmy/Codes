#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
int n,m,val,num;
long long ans;
unordered_map<string,int>r;
string tgt;
int main()
{
	freopen("liverpool.in","r",stdin);
	freopen("liverpool.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>tgt>>val;
		r[tgt]=val+1;
	}
	cin>>m;
	for(int j=1;j<=m;j++)
	{
		cin>>num;
		ans=0;
		for(int i=1;i<=num;i++)
		{
			cin>>tgt;
			if(r.find(tgt)==r.end())
			{
				cout<<"-1"<<endl;
				goto ouuan;
			}
			ans+=r[tgt];
		}
		ans-=num;
		if(!ans)
		{
			cout<<"-1"<<endl;
			goto ouuan;
		}
		cout<<ans<<endl;
		ouuan:
		continue;
	}
}
