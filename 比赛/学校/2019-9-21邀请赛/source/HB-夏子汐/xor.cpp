#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 100005
#define ri register int
inline int read()
{
	register char ch=getchar();
	ri x=0;
	while(ch<'0' || ch>'9')
	{
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	{
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x;
}
int a[N],ne[N],la[N];
struct T
{
	int x,y,k;
	inline bool operator<(register const T &a)const
	{
		if(x==a.x)
		{
			return y<a.y;
		}
		return x<a.x;
	}
}j[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ri t=read();
	for(ri i=0,n=0,flag=1,m;i<t;++i)
	{
		n=read(),m=read();
		for(ri i=1;i<=m;++i)
		{
			j[i].x=read(),j[i].y=read(),j[i].k=read();
		}
		std::sort(j+1,j+m+1);
		ne[j[1].x]=1;
		for(ri i=2,x1,x2;i<=m;++i)
		{
			x1=j[i-1].x,x2=j[i].x;
			if(x1!=x2)
			{
				ne[x2]=i;
				la[x1]=i-1;
			}
			if(x1==x2 && j[i-1].y==j[i].y && j[i-1].k!=j[i-1].k)
			{
				flag=0;
				break;
			}
		}
		la[j[m].x]=m;
		for(ri i=1,x,y;i<=m && flag;++i)
		{
			x=j[i].x,y=j[i].y;
			if(x==j[i+1].x && y==j[i+1].y)
			{
				continue;
			}
			for(ri d=ne[x],e;d && d<=la[x] && flag;++d)
			{
				e=j[d].y+1;
				for(ri k=ne[e],y2;k && k<=la[e] && flag;++k)
				{
					y2=j[k].y;
					if(y2>y)
					{
						break;
					}
					if(y2==y)
					{
						if(j[d].x==j[i].x && j[d].y+1==j[k].x && j[k].y==j[i].y && j[i].k!=j[d].k^j[k].k)
						{
							flag=0;
						}
						break;
					}
				}
			}
		}
		puts(flag?"Yes":"No");
		for(ri i=1;i<=n;++i)
		{
			a[i]=-1;
		}
		for(ri i=1;i<=j[m-1].x;++i)
		{
			ne[i]=la[i]=0;
		}
	}
	return 0;
}
