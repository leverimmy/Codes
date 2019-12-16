#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
namespace Sonoda
{
	template<typename T> void swap(T &a,T &b){T t;t=a;a=b;b=t;}
	template<typename T> T GCD(T a,T b){if(b==0){return a;}return GCD(b,a%b);}
	template<typename T>T Qpow(T a,T b,T p){T res=1;while(b){if(b&1){res*=a;res%=p;b--;}else{a*=a;a%=p;b>>=1;}}return res;}
	template<typename T> void Ex_GCD(T a,T b,T &x,T &y){if(b==0){x=1;y=0;return;}Ex_GCD(b,a%b,x,y);T t=x;x=y;y=t-a/b*y;}
	template<typename T> inline T read(){T num = 0, w = 1;char c = 0;while (c != '-' && !isdigit(c)) c = getchar();if (c == '-') w = -1, c = getchar();while (isdigit(c)) num = num * 10 + c - '0', c = getchar();return num * w;}
	template<typename T> inline void write(T x){if (x < 0) putchar('-'), x = -x;if (x / 10) write(x / 10);putchar(x % 10 + '0');}
}
const int MAXN=1005;
struct NODE
{
	int w1,w2;
};
NODE a[MAXN];
char opt[MAXN];
int cnt;
int book[MAXN];
int ans1,ans2,ans;
int out1,out2;
int main()
{
	freopen("shopping.in","r",stdin);
	freopen("shopping.out","w",stdout);
	int N=Sonoda::read<int>();
	scanf("%s",opt);
	if(opt[0]=='L')
	{
		cnt=1;
	}//odd--L
	else
	{
		cnt=0;
	}//even--C
  	for(int i=1;i<=N;i++)
  	{
  		a[i].w1=Sonoda::read<int>();
  		a[i].w2=Sonoda::read<int>();
	}
	for(int i=1;i<=N;i++)
	{
		book[i]=i;
	}
	do
	{
		ans1=0,ans2=0;
		for(int i=1;i<=N;i++)
		{
			if(cnt%2==1)
			{
				ans1+=a[book[i]].w2;
			}
			else
			{
				ans2+=a[book[i]].w1;
			}
			cnt++;
		}
		if(ans1+ans2>ans)
		{
			out1=ans1;
			out2=ans2;
			ans=ans1+ans2;
		}
	}
	while(next_permutation(book+1,book+1+N));
	printf("%d %d",out1,out2);
    return 0;
}

