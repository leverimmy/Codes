#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
char s[101][101];
int cnt[5];
signed main()
{
	freopen("2.in","r",stdin);
	freopen("2.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		cin>>s[i]+1;
	int len=strlen(s[1]+1);
	for(int i=1;i<=len;i++)
	{
		memset(cnt,0,sizeof(cnt));
		for(int j=1;j<=n;j++)
		{
			if(s[j][i]=='A') cnt[1]++;
			if(s[j][i]=='C') cnt[2]++;
			if(s[j][i]=='G') cnt[3]++;
			if(s[j][i]=='T') cnt[4]++;
		}	
		int mx=0,at=0;
		for(int j=1;j<=4;j++)
			if(cnt[j]>mx)
				mx=cnt[j],at=j;
		if(at==1) printf("A");
		if(at==2) printf("C");
		if(at==3) printf("G");
		if(at==4) printf("T");
	}
	return 0;
}