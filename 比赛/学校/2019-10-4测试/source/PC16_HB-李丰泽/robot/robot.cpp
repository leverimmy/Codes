#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int n,m1,m2,h[50010],res,ans=0x3f3f3f3f;
int cnt,a[50010],b[50010]; 

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*f;
}

void dfs(int x,int flag)
{	
	if(x==cnt)
	{
		ans=min(ans,res);
		return ;
	}
	if(flag==1)//ÉýÐò 
	{
		if(a[x]<a[x+1])
		{
			dfs(x+1,1);
			//
			b[x+1]+=b[x];
			res+=b[x]*m1;
			dfs(x+1,1);
			res-=b[x]*m1;
			b[x+1]-=b[x];
//			//
//			res+=b[x+1]*m2;
//			dfs(x+1,1);
//			res-=b[x+1]*m2;
		}
		if(a[x]>a[x+1])
		{
			//
			b[x+1]+=b[x];
			res+=b[x]*m2;
			dfs(x+1,1);
			res-=b[x]*m2;
			b[x+1]-=b[x];
//			//
//			res+=b[x+1]*m1;
//			dfs(x+1,1);
//			res+=b[x+1]*m1;
		}
	}
	if(flag==0)
	{
		if(a[x]<a[x+1])
		{
			//
			b[x+1]+=b[x];
			res+=b[x]*m1;
			dfs(x+1,0);
			res-=b[x]*m1;
			b[x+1]-=b[x];
//			//
//			res+=b[x+1]*m2;
//			dfs(x+1,0);
//			res+=b[x+1]*m2;
		}
		if(a[x]>a[x+1])
		{
			//
			dfs(x+1,0);
			//
			b[x+1]+=b[x];
			res+=b[x]*m2;
			dfs(x+1,0);
			res-=b[x]*m2;
			b[x+1]+=b[x];
//			//
//			res+=b[x+1]*m1;
//			dfs(x+1,0);
//			res-=b[x+1]*m1;
		}
	}
	return ;
}

int main()
{	
	freopen("robot.in","r",stdin);
	freopen("robot.out","w",stdout);	
	h[0]=0;
	n=read();
	m1=read();
	m2=read();
	swap(m1,m2);
	for(int i=1;i<=n;i++)
	{
		h[i]=read();
	}
	for(int i=1;i<=n;i++)
	{
		if(h[i]!=h[i-1])
		{
			cnt++;
			a[cnt]=h[i];
			b[cnt]=1;
		}
		else
		{
			b[cnt]++;
		}
	}	
	dfs(1,1);//ÉýÐò 
	dfs(1,0);//½µÐò 
	cout<<ans<<endl;
	return 0;
}
/*
15 5 7
10 10 10 10 10 9 2 8 7 6 1000 5 3 4 1
*/
