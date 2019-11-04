#include <bits/stdc++.h>
#define inf 998244353
#define maxn 5005
#define maxm 200010
#define ll long long 
#define rgl register ll
#define rgi register int
using namespace std;


inline void read(rgi &x)
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
inline void write(rgi x)
{
    if(x<0)
		putchar('-'),x=-x;
    if(x>9)
		write(x/10);
    putchar(x%10+'0');
}

int n,m;
int to[maxm],w[maxm],nxt[maxm],begin[maxn],cnt;
int go[maxn];
ll cntgo,cntgoback;
vector<int> protect[maxn];

int dist[maxn];
bool book[maxn];
struct point{
	int num,wv;
	bool operator <(const point& tt)const
	{
		return wv<tt.wv;
	}
};
priority_queue<point> pq;

int dij()
{
	memset(book,0,sizeof(book));
	for(rgi i=1;i<=n;++i)
		dist[i]=inf;
	dist[1]=0;
	pq.push((point){1,0});
	rgi tn,tw,nv,nw;
	point t;
	while(!pq.empty())
	{
		t=pq.top();
		pq.pop();
		tn=t.num,tw=t.wv;
		if(!book[tn])
			book[tn]=1;
		else
			continue;
		for(rgi i=0;i<protect[tn].size();++i)
		{
			--go[protect[tn][i]];
			--cntgo;
		}
		protect[tn].clear();
//		cout<<tn<<" fgdf\n";
		for(rgi i=begin[tn];i;i=nxt[i])
		{
			nv=to[i],nw=w[i];
//			cout<<nv<<" "<<nw<<" fkugetgrg\n";
			if(!book[nv]&&!go[nv]&&dist[nv]>tw+nw)
			{
				dist[nv]=tw+nw;
				pq.push((point){nv,dist[nv]});
//				cout<<"ofdshgo\n";
			}
		}
	}
	return dist[n];
}

void addedge(rgi a,rgi b,rgi c)
{
	nxt[++cnt]=begin[a],begin[a]=cnt,to[cnt]=b,w[cnt]=c;
}
int main()
{
	freopen("bomb.in","r",stdin);
	freopen("bomb.out","w",stdout);
	read(n),read(m);
	rgi a,b,c;
	for(;m;--m)
	{
		read(a),read(b),read(c);
		addedge(a,b,c),addedge(b,a,c);
	}
	for(rgi i=2;i<n;++i)
	{
		read(a);
		for(;a;--a)
		{
			read(b);
			protect[i].push_back(b);
			++go[b];
			++cntgo;
		}
	}
	cntgoback=cntgo;
	rgi ans=dij();
	while(ans>=inf)
	{
		if(cntgo==cntgoback)
		{
			puts("Mission Failed");
			return 0;
		}
		cntgoback=cntgo;
		ans=dij();
//		puts("hello");
//		for(rgi i=1;i<=n;i++)
//			write(dist[i]),putchar(' ');
//		putchar('\n');
	}
	write(ans);
	return 0;
}

/*
6 6
1 2 1
1 4 3
2 3 1
2 5 2
4 6 2
5 3 2
0
1 6
0
2 4 6
*/
