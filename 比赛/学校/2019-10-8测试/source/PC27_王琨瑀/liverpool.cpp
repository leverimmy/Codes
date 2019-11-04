#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
namespace Sonoda
{
	template<typename T> void swap(T &a,T &b)
	{
		T t;
		t=a;
		a=b;
		b=t;
	}
	template<typename T> T GCD(T a,T b)
	{
		if(b==0)
		{
			return a;
		}
		return GCD(b,a%b);
	}
	template<typename T>T Qpow(T a,T b,T p)
	{
		T res=1;
		while(b)
		{
			if(b&1)
			{
				res*=a;
				res%=p;
				b--;
			}
			else
			{
				a*=a;
				a%=p;
				b>>=1;
			}
		}
		return res;
	}
	template <typename T> void Ex_GCD(T a,T b,T &x,T &y)
	{
		if(b==0)
		{
			x=1;
			y=0;
			return;
		}
		Ex_GCD(b,a%b,x,y);
		T t=x;
		x=y;
		y=t-a/b*y;
	}
	template<typename T> inline T read()
	{
		T num = 0, w = 1;
		char c = 0;
		while (c != '-' && !isdigit(c)) c = getchar();
		if (c == '-') w = -1, c = getchar();
		while (isdigit(c)) num = num * 10 + c - '0', c = getchar();
		return num * w;
	}
	template<typename T> inline void write(T x)
	{
		if (x < 0) putchar('-'), x = -x;
		if (x / 10) write(x / 10);
		putchar(x % 10 + '0');
	}
}
const long long MAXN=2000005;
char now[MAXN];
struct TRIE
{
	long long money;
	TRIE *nxt[27];
	TRIE(){memset(nxt,NULL,sizeof(nxt));money=-1;}
};TRIE *root;

void Insert(TRIE* NowNode,long long depth,const long long &len,const long long &q)
{
	if(depth==len)
	{
		NowNode->money=q;
		return;
	}
	long long NextNode=now[depth+1]-'a'+1;
	if(!NowNode->nxt[NextNode])
	{
		TRIE *t=new TRIE();
		NowNode->nxt[NextNode]=t;
	}
	Insert(NowNode->nxt[NextNode],depth+1,len,q);
}

long long Check(TRIE *NowNode,long long depth,const long long &len)
{
	if(depth==len)
	{
		return NowNode->money;
	}
	long long NextNode=now[depth+1]-'a'+1;
	if(!NowNode->nxt[NextNode])
	{
		return -1;
	}
	return Check(NowNode->nxt[NextNode],depth+1,len);
}

int main()
{
	freopen("liverpool.in","r",stdin);
	freopen("liverpool.out","w",stdout);
	long long N=Sonoda::read<long long>();
	root=new TRIE;
	for(long long i=1;i<=N;i++)
	{
		scanf("%s",now+1);
		long long len=strlen(now+1);
		long long money=Sonoda::read<long long>();
		Insert(root,0,len,money);
	}
	long long M=Sonoda::read<long long>();
	for(long long i=1;i<=M;i++)
	{
		long long _=Sonoda::read<long long>();
		long long ans=0;
		bool flag=1;
		for(long long j=1;j<=_;j++)
		{
			scanf("%s",now+1);
			long long len=strlen(now+1);
			if(Check(root,0,len)==-1)
			{
				flag=0;
				break;
			}
			else
			{
				ans+=Check(root,0,len);
			}
		}
		if(!flag)
		{
			puts("-1");
		}
		else
		{
			printf("%lld\n",ans);
		}
	}
	return 0;
}

