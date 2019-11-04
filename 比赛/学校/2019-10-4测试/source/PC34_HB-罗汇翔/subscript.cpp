#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<map>
using namespace std;
int t;
queue<string>q;
priority_queue<string,vector<string>,greater<string> >qq; 
map<string,int>m; 
string s,ss;
int k;
int p,r;
int y;
string s1,s2;
int cnt;
int vis[100010];
int main()
{
	freopen("subscript.in","r",stdin);
	freopen("subscript.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		while(!q.empty())q.pop();
		while(!qq.empty())qq.pop();
		cin>>s;
		q.push(s);
		qq.push(s);
		m[s]=i;
		while(!q.empty())
		{
			cnt++;
			s=q.front();
			q.pop();
			k=s.find(']',0);
			while(k!=string::npos)
			{
				p=k-1;r=p;
				while(s[r]!='[' || vis[r]==cnt)r--;
				s1=s.substr(r+1,p-r);
				y=r-1;
				vis[r]=cnt;
				while(y>=0 && s[y]!='[')y--;
				s2=s.substr(y+1,r-y-1);
				ss=s;
				ss.replace(y+1,s2.size(),s1);
				ss.replace(y+s1.size()+2,s1.size(),s2);			
				if(m[ss]!=i)
				{
					m[ss]=i;
				    qq.push(ss);
				    q.push(ss);
				}
				k=s.find(']',k+1);
			}
		}
		cout<<qq.top()<<endl;
	}
	return 0;
}
