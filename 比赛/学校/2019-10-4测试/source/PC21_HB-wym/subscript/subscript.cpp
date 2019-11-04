#include<bits/stdc++.h>
using namespace std;
int t,len;
char c[100010];
inline bool cmp(string x,string y)
{
	for(int i=1;i;i++)
	{
		if(x[i-1]<y[i-1])
			return true;
		if(x[i-1]>y[i-1])
			return false;
		if(y[i-1]=='\0')
			return false;
		if(x[i-1]=='\0')
			return true;
	}
}
int proc(int l,int r)
{
	int nd;
	string s1="",s2="";
	s1.append(c,l,r-l+1);
//	cout<<"s1:"<<s1<<endl;
	for(int i=r+2;i<len;i++)
	{
		if(c[i]=='[')
			i=proc(r+2,i-1);
		if(c[i]==']')
		{
			nd=i-1;
			break;
		}
	}
	s2.append(c,r+2,nd-r-1);
//	cout<<"s2:"<<s2<<endl;
	if(cmp(s2,s1))
	{
		for(int i=l;i<=(l+nd-r-2);i++)
			c[i]=s2[i-l];
		c[l+nd-r-1]='[';
		for(int i=l+nd-r;i<=nd;i++)
			c[i]=s1[i-nd+r-l];
	}
	return nd+2;
}
int main()
{
	freopen("subscript.in","r",stdin);
	freopen("subscript.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		memset(c,0,sizeof(c));
		scanf("%s",c);
//		cout<<"c:"<<c<<endl;
		len=strlen(c);
		for(int i=0;i<len;i++)
		{
			if(c[i]=='[')
			{
//				cout<<"i:"<<i<<endl;
				i=proc(0,i-1)-1;
			}
		}
		cout<<c<<endl;
	}
	return 0;
}

