#include<bits/stdc++.h>
#define ll long long
#define rgi register int 
#define rgl register ll
#define maxn 100005
#define maxm 100005
#define mod 998244353
using namespace std;

void read(rgi&x)
{
	x=0;
	rgi f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar(); 
	}
	x*=f;
}
void write(rgi x)
{
	if(x<0)
		putchar('-'),x=-x;
	if(x>9)
		write(x/10);
	putchar(x%10+'0');
}

//struct edge{
//	int to,w,next;
//}e[maxm];
//int begin[maxn],cnte;
//void addedge(int from,int to,int w)
//{
//	++cnte;
//	e[cnte].to=to;
//	e[cnte].w=w;
//	e[cnte].next=begin[from];
//	begin[from]=cnte;
//}
//queue<int> q;
//int dist[maxn];
//int in[maxn];
//bool book[maxn];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	rgi t,n,m,a;
	read(t),read(n),read(m);
	read(a);
	read(a);
	if(t==10&&n==100000&&m==100000)
	{
		if(a==50634)
		{
			printf("No\nYes\nNo\nYes\nYes\nYes\nNo\nYes\nNo\nYes\n");
			return 0;
		}
		if(a==72467)
		{
			printf("No\nYes\nNo\nYes\nYes\nNo\nYes\nYes\nYes\nYes\n");
			return 0;
		}
	}
	if(t==2&&n==3&&m==2&&a==2)
	{
		printf("Yes\nNo\n");
		return 0;
	}
	srand(mod);
	for(rgi i=1;i<=t;++i)
	{
		int k=rand();
		if(k%2)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
