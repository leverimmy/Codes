#include <bits/stdc++.h>
#define rgi register int
#define fin(s) freopen(s,"r",stdin)
#define fout(s) freopen(s,"w",stdout)
using namespace std;
const int n=4;
const int nn=16;
int a[6][6],b[18]={0,1,2,15,16,12,14,3,5,13,7,10,4,8,11,6,9},sum[15];
inline bool check()
{
	for(rgi i=1;i<=nn;++i)
		a[(i-1)/4+1][(i-1)%4+1]=b[i];
	for(rgi i=1;i<=n;++i)
	{
		for(rgi j=1;j<=n;++j)
			sum[i]+=a[i][j];
		if(i>1&&sum[i]!=sum[i-1])
			return 0;
	}
	for(rgi i=1;i<=n;++i)
	{
		for(rgi j=1;j<=n;++j)
			sum[i+4]+=a[j][i];
		if(sum[i+4]!=sum[i+3])
			return 0;
	}
	for(rgi i=1;i<=n;++i)
		sum[9]+=a[i][i];
	if(sum[9]!=sum[8])
		return 0;
	for(rgi i=1;i<=n;++i)
		sum[10]+=a[i][n-i+1];
	if(sum[10]!=sum[9])
		return 0;
	return 1;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	//fin("20.in"),fout("20.out");
	//return 0;
	for(rgi i=1;i<=nn;++i)
		b[i]=i;
	
	do
	{
		memset(a,0,sizeof(a));
		memset(sum,0,sizeof(sum));
		if(check())
		{
			cout<<"{";
			for(rgi i=1;i<nn;++i)
				cout<<b[i]<<",";
			cout<<b[nn]<<"},";
		}
	}while(next_permutation(b+1,b+nn+1));
	return 0;
}

