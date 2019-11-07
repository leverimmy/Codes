#include <bits/stdc++.h>
#define rgi register int
#define fin(s) freopen(s,"r",stdin)
#define fout(s) freopen(s,"w",stdout)
using namespace std;
int n;
string s[15],ans;
struct sta
{
	int tim,id;
}a[6];
inline bool cmp(sta p,sta q)
{
	if(p.tim==q.tim)
		return p.id<q.id;
	return p.tim>q.tim;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	fin("2.in"),fout("2.out");
	cin>>n;
	for(rgi i=1;i<=n;++i)
	{
		cin>>s[i];
		int len=s[i].size();
		for(rgi j=0;j<len;++j)
		{
			if(s[i][j]=='A')
				s[i][j]=1;
			else if(s[i][j]=='C')
				s[i][j]=2;
			else if(s[i][j]=='G')
				s[i][j]=3;
			else if(s[i][j]=='T')
				s[i][j]=4;
		}
	}
	int len=s[1].size();
	for(rgi i=0;i<len;++i)
	{
		memset(a,0,sizeof(a));
		for(rgi i=1;i<=4;++i)
			a[i].id=i;
		for(rgi j=1;j<=n;++j)
			++a[s[j][i]].tim;
		sort(a+1,a+5,cmp);
		ans.push_back(a[1].id);
	}
	for(rgi i=0;i<len;++i)
	{
		if(ans[i]==1)
			ans[i]='A';
		else if(ans[i]==2)
			ans[i]='C';
		else if(ans[i]==3)
			ans[i]='G';
		else if(ans[i]==4)
			ans[i]='T';
	}
	cout<<ans<<endl;
	return 0;
}
