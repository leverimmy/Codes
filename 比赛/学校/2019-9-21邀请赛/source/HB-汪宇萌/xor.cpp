#include<bits/stdc++.h>
using namespace std;
long long n,m,x[200010],y[200010],k[200010],t,t1,t2,t3,t4;
int f[33][200010],splt[50];
bool flag;
inline long long read()
{
    long long x=0,f=1;
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
inline void split(long long bas)
{
	memset(splt,0,sizeof(splt));
	int num=0;
	while(bas)
	{
		num++;
		splt[num]=bas&1;
		bas>>=1;
	}
	splt[0]=num;
	return;
}
inline long long find(int dig,long long bas)
{
	if(f[dig][bas]==bas)
		return bas;
	f[dig][bas]=find(dig,f[dig][bas]);
	return f[dig][bas];
}
int main()
{
 	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	t=read();
	while(t--)
	{
		flag=false;
		n=read();
		m=read();
		for(int i=1;i<=32;i++)
		{
			for(int j=1;j<=n+1;j++)
				f[i][j]=j,f[i][j+n]=j+n;
		}
		for(int i=1;i<=m;i++)
		{
			x[i]=read();
			y[i]=read();
			k[i]=read();
//			if(x[i]==y[i]&&k[i]!=0)
//				flag=true;
		}
		if(flag)
		{
			printf("No\n");
			continue;
		}
		for(int i=1;i<=m;i++)
		{
//			cout<<endl<<"k:"<<k[i]<<endl;
			if(flag)
				break;
			split(k[i]);
			for(int j=1;j<=splt[0];j++)
			{
				t1=find(j,x[i]-1);
				t2=find(j,x[i]+n-1);
				t3=find(j,y[i]);
				t4=find(j,y[i]+n);
				if(!splt[j])
				{
					if(t2==t3)
					{
						printf("No\n");
						flag=true;
						break;
					}
					f[j][t3]=t1;
					f[j][t4]=t2;
				}
				else
				{
					if(t1==t3)
					{
						printf("No\n");
						flag=true;
						break;
					}
					f[j][t4]=t1;
					f[j][t3]=t2;
				}
			}
		}
		if(!flag)
			printf("Yes\n");
	}
}
