#include <bits/stdc++.h>
using namespace std;

int read()
{
	int res=0,p=1;char ch=getchar();
	while(!isdigit(ch)) {if(ch=='-')p=-1; ch=getchar();}
	while(isdigit(ch)) res=res*10+ch-'0',ch=getchar();
	return res*p;
}

int n,s,a[50],ok;

bool dfs(int now,int rest)
{
	bool IF;
	if(now%2==0) IF=0;
	else IF=1;
	if(rest==1)
	{
		if(now%2) return 0;
		return 1;
	} 
	for(int i=1;i<=a[now];i++)
	{
		if(i>=rest)
		{
			return IF;
		}
		if(now%2==0) IF|=dfs(now%(2*n)+1,rest-i);
		if(now%2==1) IF&=dfs(now%(2*n)+1,rest-i);
	}
	if(IF==1 && now%2==1) ok=1;
	return IF;
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read();
	while(n!=0)
	{
		ok=0;
		s=read();
		for(int i=1;i<=n*2;i++) a[i]=read();
		dfs(1,s);
		cout << ok << endl;
		n=read();
	}
	return 0;
} 
/*
1 9 4 4
1 11 4 4
1 10 4 4
3 10 8 7 6 5 4 3
0
*/
