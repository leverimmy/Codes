#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read()
{
	re int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10-48+ch;ch=getchar();}
	return x*f;
}
const int maxn=100005;
int n,f,p[maxn],ans;
bool jd;
int main()
{
	freopen("weapon.in","r",stdin);
	freopen("weapon.out","w",stdout);
	n=read(),f=read();
	for(re int i=1;i<=n;i++)
		p[i]=read();
	for(re int i=1;i<=n;i++)
	{
		for(re int j=1;j<=n&&i+j*2+f-1<=n;j++)
		{
			jd=0;
			for(re int k=i;k<=i+j-1;k++)
			{
				if(p[k]!=p[k+j+f])
				{
					jd=1;
					break;
				}
			}
			if(!jd)
				ans++;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
