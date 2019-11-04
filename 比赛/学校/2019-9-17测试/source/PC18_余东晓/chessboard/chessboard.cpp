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
bool a[110][110],cnt[110][2];
signed main()
{
	freopen("chessboard.in","r",stdin);freopen("chessboard.out","w",stdout);int n;scanf("%d",&n);for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){char ch;std::cin>>ch;bool x=ch=='.';a[i][j]=x^1;cnt[i][0]|=x;cnt[j][1]|=x;}
	int ans1(0),ans2(0);for(int i=1;i<=n;i++)ans1+=cnt[i][0];for(int i=1;i<=n;i++)ans2+=cnt[i][1];return printf("%d\n",std::min(ans1,ans2));
}
