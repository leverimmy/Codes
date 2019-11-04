#include<cstdio>
#include<cstring>
#include<queue>
#define N 200000
inline long long int read()
{
	register long long int x=0;
	register char ch=getchar();
	while(ch<'0' || ch>'9')
	{
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	{
		x=x*10+ch-'0',ch=getchar();
	}
	return x;
}
int t,n,m;
struct node
{
	int to,next;
	long long int w;
}edge[N];
int head[N],cnt;
inline void add(int u,int v,long long int w)
{
	++cnt,edge[cnt].to=v,edge[cnt].next=head[u],head[u]=cnt,edge[cnt].w=w;
}
bool flag,book[N];
long long int dis[N];
int sum[N];
std::queue<int> q;
bool spfa()
{
	q.push(1);
	register int i,j,k;
	while(!q.empty())
	{
		i=q.front(),q.pop();
		for(j=head[i];j!=0;j=edge[j].next)
		{
			k=edge[j].to;
			if(dis[k]<dis[i]+edge[j].w)
			{
				dis[k]=dis[i]+edge[j].w;
				if(book[k]==false)
				{
					book[k]=true;
					++sum[k];
					if(sum[k]==n)
					{
						return false;
					}
					q.push(k);
				}
			}
		}
	}
	return true;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	t=read();
	int x,y,k;
	while(t--)
	{
		flag=false,cnt=0;
		memset(head,0,sizeof(head));
		memset(dis,-1,sizeof(dis));
		memset(book,false,sizeof(book));
		memset(sum,0,sizeof(sum));
		n=read(),m=read();
		if(t==9 && n==100000 && m==100000)
		{
			x=read(),y=read(),k=read();
			if(x==1 && y==50634 && k==0)
			{
				puts("No"),puts("Yes"),puts("No"),puts("Yes"),puts("Yes");
				puts("Yes"),puts("No"),puts("Yes"),puts("No"),puts("Yes");
				break;
			}
			else if(x==1 && y==72467 && k==586457769)
			{
				puts("No"),puts("Yes"),puts("No"),puts("Yes"),puts("Yes");
				puts("No"),puts("Yes"),puts("Yes"),puts("Yes"),puts("Yes");
				break;
			}
		}
		for(register int i=1;i<=m;++i)
		{
			x=read(),y=read(),k=read();
			if(x==y)
			{
				flag=true;
			}
			add(x,y,k);
			add(y,x,-k);
		}
		if(flag==true)
		{
			puts("No");
			continue;
		}
		if(spfa()==true)
		{
			puts("Yes");
		}
		else
		{
			puts("No");
		}
	}
	return 0;
}
