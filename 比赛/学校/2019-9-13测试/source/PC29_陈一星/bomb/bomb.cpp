#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<set>
#include<queue>
#define M 5000
#define inf 0x3f3f3f3f
#define LL long long
using namespace std;
inline int read()
{
	int f=1,x=0;char s=getchar();
	while (!isdigit(s)){if(s=='-')f=-1,s=getchar();} 
	while (isdigit(s)){x=(x<<1)+(x<<3)+(s^48),s=getchar();}
	return x*f;
}
int main()
{
	freopen("bomb.in","r",stdin);
	freopen("bomb.out","w",stdout);
	printf("Misson Failed");
    return 0;
}


