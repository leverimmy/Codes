#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<queue>
#include<vector> 
#define M 101000000
#define inf 1e30
#define LL long long
#define int long long
using namespace std;
inline int read(){
	int f=1,x=0;char s=getchar();
	while(!isdigit(s)){if(s=='-')f=-1;s=getchar();}
	while(isdigit(s)){x=(x<<1)+(x<<3)+(s^48);s=getchar();}
	return x*f;
}
vector<int>que;
int is[M],sum[M];
signed main(void)
{
	freopen("gen.txt","w",stdout); 
	for (int i=1;i<=1e8;i++){
		int now=i;
		if (is[i]){
			printf("%d,",i);
			goto ouuan;	
		}
		while (now){
			if (now%10!=7&&now%10!=4)
				goto ouuan;
			now/=10;
		}
		printf("%d,",i);
		que.push_back(i);
		for (int j=0;j<que.size();j++)
			if (que[j]*i<1e8)
				que.push_back(que[j]*i),is[que[j]*i]=1;
		ouuan:
		continue;
	}
    return 0;
}

