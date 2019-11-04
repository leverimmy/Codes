#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cctype>
#define M 5010000
#define inf 0x3f3f3f3f
#define LL long long
#define root t[0].ch[1]
using namespace std;
int n,q;
inline int read(){
	int f=1,x=0;char s=getchar();
	while (!isdigit(s)){if(s=='-')f=-1;s=getchar();}
	while (isdigit(s)){x=(x<<1)+(x<<3)+(s^48),s=getchar();}
	return x*f;
}
struct node{
	int val,cnt,siz,fa;
	int ch[2];
}t[M];
int tot,tag,ans; 
inline int New(int v,int fa){
	t[++tot].fa=fa,t[tot].cnt=t[tot].siz=1,t[tot].val=v;
	return tot;
}
inline void update(int x){
	t[x].siz=t[t[x].ch[0]].siz+t[t[x].ch[1]].siz+t[x].cnt;
}
inline int get_son(int x){
	return t[t[x].fa].ch[0]!=x;
}
inline void connect(int x,int fa,int d){
	t[x].fa=fa,t[fa].ch[d]=x;
}
inline void rotate(int x){
	int f=t[x].fa,gf=t[f].fa;
	int fson=get_son(x),gfson=get_son(f);
	connect(t[x].ch[fson^1],f,fson);connect(x,gf,gfson),connect(f,x,fson^1);
	update(f),update(x);
}
inline void splay(int x,int to){
	while (t[x].fa!=to){
		int f=t[x].fa,gf=t[f].fa;
		if (gf!=to) (t[f].ch[0]==x)^(t[gf].ch[0]==f)?rotate(x):rotate(f);
		rotate(x);
	}
	if (!to) root=x;
}
inline void insert(int now){
	int x=root;
	if (!root) root=New(now,0);
	else{
		while (1){
			t[x].siz++;
			if (t[x].val==now){
				t[x].cnt++,splay(x,0);return;
			}
			int nxt=now>t[x].val;
			if (!t[x].ch[nxt]){
				int p=New(now,x);
				t[x].ch[nxt]=p;
				splay(p,0);return;
			}
			x=t[x].ch[nxt];
		}
	}
}
inline int get_kth(int x){
	int now=root;
	while (1){
		int rank=t[now].siz-t[t[now].ch[1]].siz;
		if (x>t[t[now].ch[0]].siz&&x<=rank){
			splay(now,0);return t[now].val;
		}
		if (x<rank) now=t[now].ch[0];
		else x-=rank,now=t[now].ch[1];
	}
}
inline int find(int v)
{
	int now=root;
	while (1){
		if (!now)
			return 0;
		if (t[now].val==v){
			splay(now,0);
			return now;
		}
		int nxt=v<t[now].val?0:1;
		now=t[now].ch[nxt];
	}
}
int lower(int v)
{
	int now=root;
	int ans=-inf;
	while (now)
	{
		if (t[now].val<v&&t[now].val>ans)
			ans=t[now].val;
		int nxt=v<=t[now].val?0:1;
		now=t[now].ch[nxt];
	}
	return ans;
}
inline void dele(int x)
{
	int low=lower(x);
	int pos=find(low);
	if (!pos) return;
	ans+=t[pos].siz-t[t[pos].ch[1]].siz;
	if (!t[pos].ch[1]) return;
	connect(t[pos].ch[1],t[pos].fa,0);
	pos=t[pos].fa;
	while (pos!=root&&pos)
		update(pos),pos=t[pos].fa;
	update(root);
	return;
}
signed main(void)
{
	freopen("unhappy.in","r",stdin);
	freopen("unhappy.out","w",stdout);
	n=read(),q=read();
	for (int i=1;i<=n;i++){
		char c;cin>>c;
		if (c=='I'){
			int k=read();
			if (k>=q) k-=tag,insert(k);
			else ans++;
		}
		if (c=='A'){
			int k=read();
			tag+=k;
		}
		if (c=='S'){
			int k=read();
			tag-=k;
			dele(q-tag);
		}
		if (c=='F'){
			int k=read();
			if (k>t[root].siz){
				printf("-1\n");continue;
			}
			printf("%d\n",get_kth(t[root].siz-k+1)+tag);
		}
	}
	printf("%d",ans);
    return 0;
}



