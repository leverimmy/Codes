#include <iostream>
#include <string>
#include <cmath>
#define rgi register int
using namespace std;
int n,m,sx,sy,ex,ey;
string s[50];
int main()
{
	ios::sync_with_stdio(false);
	freopen("slikar.in","r",stdin);
	freopen("slikar.out","w",stdout);
	cin>>n>>m;
	for(rgi i=0;i<n;++i)
		cin>>s[i];
	for(rgi i=0;i<n;++i)
		for(rgi j=0;j<m;++j)
			if(s[i][j]=='D')
			{
				ex=i,ey=j;
				break;
			}
	for(rgi i=0;i<n;++i)
		for(rgi j=0;j<m;++j)
			if(s[i][j]=='S')
			{
				sx=i,sy=j;
				break;
			}
	cout<<abs(sx-ex)+abs(sy-ey)<<endl;
	return 0;
}
