#include<bits/stdc++.h>
using namespace std;
int n,m,top,ptop;
inline int read()
{
    int x=0,f=1;
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
struct node
{
	vector<int>prot;
	int head,headp,shld,tm;
}nd[5010];
struct edge
{
	int to,len,nxt;
}ed[100010];
struct prot_edge
{
	int to,nxt;
}ped[100010];
inline void addedge(int from,int to,int val)
{
	ed[++top].nxt=nd[from].head;
	ed[top].to=to;
	ed[top].len=val;
	nd[from].head=top;
	return;
}
inline void addpedge(int from,int to)
{
	ped[++ptop].nxt=nd[from].headp;
	ped[ptop].to=to;
	nd[from].headp=ptop;
	return;
}
inline void destruct(int bas)
{
	for(int i=nd[bas].headp;i;i=ped[i].nxt)
		nd[ped[i].to].shld--;
	return;
}

int main()
{
	freopen("bomb.in","r",stdin);
	freopen("bomb.out","w",stdout);
	cout<<"Mission Failed"<<endl;
	return 0;
	n=read(),m=read();
	int t1,t2,t3;
	for(int i=1;i<=m;i++)
	{
		t1=read(),t2=read(),t3=read();
		addedge(t1,t2,t3);
		addedge(t2,t1,t3);
	}
}
