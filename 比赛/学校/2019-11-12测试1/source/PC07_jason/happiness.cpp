#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
int n,m;
int sa[400001],tax[400001],rnk[400001],tp[400001];
char s[400001];
void qsort()
{
	for(int i=1;i<=m;i++) tax[i]=0;
	for(int i=1;i<=n;i++) tax[rnk[i]]++;
	for(int i=1;i<=m;i++) tax[i]+=tax[i-1];
	for(int i=n;i>=1;i--) sa[tax[rnk[tp[i]]]--]=tp[i];
}
void suffix_sort()
{
	m=1000;
	for(int i=1;i<=n;i++)
		rnk[i]=s[i],tp[i]=i;
	qsort();
	for(int w=1,p=0;p<n;m=p,w<<=1)
	{
		p=0;
		for(int i=n-w+1;i<=n;i++)
			tp[++p]=i;
		for(int i=1;i<=n;i++)
			if(sa[i]>w)
				tp[++p]=sa[i]-w;
		qsort();
		swap(rnk,tp);
		rnk[sa[1]]=p=1;
		for(int i=2;i<=n;i++)
			if(tp[sa[i]]==tp[sa[i-1]]&&tp[sa[i]+w]==tp[sa[i-1]+w])
				rnk[sa[i]]=p;
			else
				rnk[sa[i]]=++p;
	}
}
int height[400001];
void get_height()
{
	int k=0;
	for(int i=1;i<=n;i++)
		if(rnk[i]!=1)
		{
			if(k) k--;
			int j=sa[rnk[i]-1];
			while(i+k<=n&&j+k<=n&&s[i+k]==s[j+k])
				k++;
			height[rnk[i]]=k;
		}
}

int t[400001];
void update(int x,int l,int r,int pos,int ind)
{
	if(l==r)
	{
		t[x]=ind;
		return;
	}
	int mid=(l+r)/2;
	if(pos<=mid)update(x*2,l,mid,pos,ind);
	else update(x*2+1,mid+1,r,pos,ind);
	t[x]=min(t[x*2],t[x*2+1]);
}
int query(int x,int st,int ed,int l,int r)
{
	if(st>r||ed<l) return 999999999;
	if(st>=l&&ed<=r) return t[x];
	int mid=(st+ed)/2;
	return min(query(x*2,st,mid,l,r),query(x*2+1,mid+1,ed,l,r));
}

struct segtree
{
	int t[400001];
	int mx;
	segtree(){mx=100000;}
	void update(int x,int l,int r,int pos,int ind)
	{
		if(l==r)
		{
			t[x]=ind;
			return;
		}
		int mid=(l+r)/2;
		if(pos<=mid)update(x*2,l,mid,pos,ind);
		else update(x*2+1,mid+1,r,pos,ind);
		t[x]=max(t[x*2],t[x*2+1]);
	}
	void modify(int pos,int ind){update(1,1,mx,pos,ind);}
	int query(int x,int st,int ed,int l,int r)
	{
		if(st>r||ed<l) return 0;
		if(st>=l&&ed<=r) return t[x];
		int mid=(st+ed)/2;
		return max(query(x*2,st,mid,l,r),query(x*2+1,mid+1,ed,l,r));
	}
	int ask(int l,int r){return query(1,1,mx,l,r);}
}tr[11];

int num;
int at[400001];
void clear(int x)
{
	for(int i=1;i<=x;i++)
		tr[at[sa[i]]].modify(sa[i],0);
}
int p[11];
int judge(int x)
{
	memset(p,0,sizeof(p));
	for(int i=1;i<=n;i++)
	{
		int las=999999999;
		int j=at[sa[i]];
		tr[j].modify(sa[i],i);
		p[j]=max(tr[j].ask(1,sa[i]-x),tr[j].ask(sa[i]+x,tr[j].mx));
		for(int j=1;j<=num;j++)
		{
			if(!p[j]) 
			{
				las=0;
				break;
			}
			las=min(las,p[j]);
		}
		if(las!=0)
		{
			if(query(1,1,n,las+1,i)>=x)
			{
				clear(i);
				return las;
			}
		}
	}
	clear(n);
	return 0;
}


char c[400001];
signed main()
{
	freopen("happiness.in","r",stdin);
	freopen("happiness.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int sep_cnt=0;
		scanf("%d",&num);
		
		cin>>s+1;
		n=strlen(s+1);
		for(int i=1;i<=n;i++)
			at[i]=1;
		s[++n]=++sep_cnt;
		for(int i=2;i<=num;i++)
		{
			cin>>c+1;
			int n1=strlen(c+1);
			for(int j=1;j<=n1;j++)
				s[++n]=c[j],at[n]=i;
			s[++n]=++sep_cnt;
		}
		
		suffix_sort();
		get_height();
						
		for(int i=1;i<=n;i++)
			update(1,1,n,i,height[i]);
						
		int l=0,r=n,pos;
		while(l+1<r)
		{
			int mid=(l+r)/2;
			int place=judge(mid);
			if(place)
				l=mid,pos=place;
			else
				r=mid;
		}
		
		printf("%d\n",l);
		for(int i=sa[pos];i<=sa[pos]+l-1;i++)
			printf("%c",s[i]);
		printf("\n");
	}
	return 0;
}
/*
1
3
changjunjschamgjunjschangjunjs
chsjchangjunjschangjunjs
chanchannchangjunjsschangjunjs
*/