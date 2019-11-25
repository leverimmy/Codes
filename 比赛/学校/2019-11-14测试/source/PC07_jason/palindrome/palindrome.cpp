#include<bits/stdc++.h>
using namespace std;
struct node
{
	int len,fail,f1;
	int ch[26];
}t[500001];
int las,tot;
char str[500001];
void init()
{
	str[0]=-1;
	
	t[0].fail=1,t[0].len=0;
	t[1].fail=0,t[1].len=-1;
	
	las=0,tot=1;
}
int f[500001];
int get_fail(int u,int x)
{
	while(str[x-t[u].len-1]!=str[x])
		u=t[u].fail;
	return u;
}
int get_f1(int u,int x,int len)
{
	while(str[x-t[u].len-1]!=str[x]||(t[u].len+2)*2>len)
		u=t[u].fail;
	return u;
}
void insert(int x)
{
	int c=str[x]-'a';
	int p=get_fail(las,x);
	if(!t[p].ch[c])
	{
		int np=++tot;
		t[np].len=t[p].len+2;
		t[np].fail=t[get_fail(t[p].fail,x)].ch[c];
		if(t[np].len==1) t[np].f1=0;
		else t[np].f1=t[get_f1(t[p].f1,x,t[np].len)].ch[c];
		t[p].ch[c]=np;
	}
	las=t[p].ch[c];
	f[las]++;
}
vector<int>e[500001];
int ans[500001];
int par[500001];
void dfs(int u)
{
	if(u!=0&&t[u].len%2==0&&t[t[u].f1].len*2==t[u].len&&t[u].f1!=0)
		par[u]=par[t[u].f1]+1;
	if(u!=1&&t[u].len%2==1&&t[t[u].f1].len*2+1==t[u].len&&t[u].f1!=0)
		par[u]=par[t[u].f1]+1;
	if(!par[u]) par[u]=1;	
	for(int i=0;i<e[u].size();i++)
	{
		dfs(e[u][i]);
		f[u]+=f[e[u][i]];
	}
	if(u!=0&&u!=1)
		ans[par[u]]+=f[u];
}
signed main()
{
	freopen("palindrome.in","r",stdin);
	freopen("palindrome.out","w",stdout);
	cin>>str+1;
	init();
	int n=strlen(str+1);
	for(int i=1;i<=n;i++)
		insert(i);
	for(int i=1;i<=tot;i++)
		e[t[i].fail].push_back(i);
	dfs(0);
	for(int i=n;i>=1;i--)
		ans[i]+=ans[i+1];
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	return 0;
}
/*
abbaabbaabbaabba
*/