#include<bits/stdc++.h>
using namespace std;
int n;
int m;
string s;
char ch;
inline int read()
{
	int x=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x;
}
int a,b;
string s1,s2;
int ans;
int main()
{
	freopen("lcp.in","r",stdin);
	freopen("lcp.out","w",stdout);
	n=read();m=read();
	ch=getchar();
	while(!islower(ch))ch=getchar();
	while(islower(ch))
	{
		s=s+ch;
		ch=getchar();
	}
    for(int i=1;i<=m;i++)
	{
		a=read();
		b=read();
		s1=s.substr(a-1,n-a+1);
		s2=s.substr(b-1,n-b+1);
		ans=(s1>=s2);
		printf("%d\n",ans);
	} 
	return 0;
} 
