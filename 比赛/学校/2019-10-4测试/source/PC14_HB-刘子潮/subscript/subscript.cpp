#include<iostream>
#include<cstring>
#include<stack>
#define maxi(a,b) ((a)>(b)?(a):(b))
#define ri register int
#define N 100005
int t;
std::string a,c,d,f;
int s[N],e[N],b[N];
std::stack<int> stack;
int main()
{
	freopen("subscript.in","r",stdin);
	freopen("subscript.out","w",stdout);
	std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0);
	std::cin>>t;
	for(ri i=1;i<=t;++i)
	{
		s[0]=0,e[0]=0,std::cin>>a;
		if(a.size()<4)
		{
			std::cout<<a<<'\n';
			continue;
		}
		for(ri j=0;j<a.size();++j)
		{
			if(a[j]=='[')
			{
				stack.push(j),++s[0],s[s[0]]=j,b[j]=s[0];
			}
			else if(a[j]==']')
			{
				e[b[stack.top()]]=j,stack.pop();
			}
		}
		for(ri j=1;j<=s[0];++j)
		{
			c="",d="";
			for(ri k=0;k<s[i];++k)
			{
				c+=a[k];
			}
			for(ri k=s[i]+1;k<e[i];++k)
			{
				d+=a[k];
			}
			if(!d.compare(c))
			{
				std::cout<<d+"["+c+"]"<<'\n';
			}
			else
			{
				std::cout<<a<<'\n';
			}
			continue;
		}
	}
	return 0;
}
