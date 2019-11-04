#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
double k[100010],x,y,h[100010];
inline int read()
{
    int x=0,f=1;
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
    return x*f;
}
void _20pts()
{
	double MAX=-1;
	while(m--)
	{
		x=read();
		y=read();
		if((y/x>MAX)&&(y>=0))
		{
			MAX=y/x;
			ans++;
		}
		printf("%d\n",ans);
	}
	return;
}
int main()
{
	freopen("noon.in","r",stdin);
	freopen("noon.out","w",stdout);
	n=read();
	m=read();
	if(n>1000&&m>1000)
	{
		_20pts();
		return 0;
	}
	for(int i=1;i<=m;i++)
		h[i]=-1;
	while(m--)
	{
		x=read();
		y=read();
		h[(int)x]=y;
		double MAX=-1;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			if((h[i]/(double)i>MAX)&&(h[i]>=0))
			{
				MAX=h[i]/(double)i;
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
