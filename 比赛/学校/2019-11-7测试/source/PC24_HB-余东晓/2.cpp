#include<cstdio>
#include<cstring>
#include<cassert>
#include<climits>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<iostream>
#include<map>
#include<stack>
#include<queue>
#include<vector>
#define ll long long
#define INF 0x3f3f3f3f
char str[11][110],out[110];
int cnt[110][26];
signed main()
{
	freopen("2.in","r",stdin);
	freopen("2.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%s",str[i]);
	int p=strlen(str[1]);
	for(int i=0;i<p;i++)
	{
		for(int j=1;j<=n;j++)
			cnt[i][str[j][i]-'A']++;
		for(int j=25;j>=0;j--)
			if(cnt[i][j]>=cnt[i][out[i]-'A'])
				out[i]=j+'A';
	}
	for(int i=0;i<p;i++)
		putchar(out[i]);
	return puts(""),0;
}
