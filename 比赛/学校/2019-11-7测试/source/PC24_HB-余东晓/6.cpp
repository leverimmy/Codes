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
std::string now="A";
std::string num[27]={"","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
signed main()
{
	freopen("6.in","r",stdin);
	freopen("6.out","w",stdout);
	int n;
	scanf("%d",&n);
	if(n==1)
		return puts("A"),0;
	for(int i=2;i<=n;i++)
		now+=num[i]+now;
	std::cout<<now<<std::endl;
	return 0;
}
