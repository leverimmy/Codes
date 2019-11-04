#include<iostream>
#include<cstring>
#define ri register int
using namespace std;
string str,str1,str2,str3,str4;
inline bool cmp(string str1,string str2)
{
	ri len1=str1.size(),len2=str2.size(),m=min(len1,len2);
	for(ri i=0;i<m;++i)
	{
		if(str1[i]>str2[i])
		{
			return true; 
		}
		if(str1[i]<str2[i])
		{
			return false;
		}
	}
	return len1>len2;
}
inline void change(ri begin,ri end)
{
	if(str[end]!=']')
	{
		return;
	}
	ri ans,i,c=0;
	for(i=end;i!=begin;--i)
	{
		if(str[i]==']')
		{
			++c;
		}
		if(str[i]=='[')
		{
			--c;
		}
		if(!c)
		{
			ans=i;
			break;
		}
	}
	change(begin,ans-1);
	change(ans+1,end-1);
	str1=str2="";
	for(i=begin;i<ans;++i)
	{
		str1+=str[i];
	}
	for(i=ans+1;i<end;++i)
	{
		str2+=str[i];
	}
	if(cmp(str1,str2))
	{
		str3=str4="";
		for(i=0;i<begin;++i)
		{
			str3+=str[i];
		}
		for(i=end;i<str.size();++i)
		{
			str4+=str[i];
		}
		str=str3+str2+"["+str1+str4;
	}
	return; 
}
int main()
{
	freopen("subscript.in","r",stdin);
	freopen("subscript.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ri T;
	cin>>T;
	for(ri i=0,size;i<T;++i)
	{
		cin>>str;
		size=str.size();
		if(size<4)
		{
			cout<<str<<'\n';
			continue;
		}
		change(0,size-1);
		cout<<str<<'\n';
	}
	return 0;
}
