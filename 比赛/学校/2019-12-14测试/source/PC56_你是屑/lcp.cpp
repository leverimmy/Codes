#include <bits/stdc++.h>
#define maxn 100005
int n,q,rank[maxn],tl,a,b;
char s[maxn];
const int inf=1e8;
struct suffixTree {
	
	int ch[maxn<<1][29],start[maxn<<1],len[maxn<<1],link[maxn<<1],now,rem,tail,s[maxn],n;
	void reset(){tail=1;rem=0;now=1;link[1]=0;len[0]=inf;}
	int newnode(int sta,int le){start[++tail]=sta;len[tail]=le;link[tail]=1;return tail;}
	void extend(int x){
		s[++n]=x;rem++;
		for(int last=1;rem;){
			while (rem>len[ch[now][s[n-rem+1]]])rem-=len[now=ch[now][s[n-rem+1]]];
			int &v=ch[now][s[n-rem+1]],c=s[start[v]+rem-1];
			if (!v||x==c){
				link[last]=now;last=now;
				if (!v)v=newnode(n,inf);
				else break;
			}else {
				int u=newnode(start[v],rem-1);
				ch[u][c]=v;ch[u][x]=newnode(n,inf);
				len[v]-=rem-1;start[v]+=rem-1;
				link[last]=v=u;last=u;
			}if (now==1)rem--;else now=link[now];
		}
	}
}sft;

void dfs(int u,int dep){
	int flag=0;
	for(int i=0;i<=26;++i){
		int v=sft.ch[u][i];
		if (v){dfs(v,dep+std::min(sft.len[v],n-sft.start[v]+1));flag=1;}
	}if (!flag)rank[n-dep+1]=++tl;
}
		
int main(){
	freopen("lcp.in","r",stdin);
	freopen("lcp.out","w",stdout);
	scanf("%d%d",&n,&q);
	sft.reset();
	scanf("%s",s+1);
	for(int i=1;i<=n;++i)sft.extend(s[i]-'a'+1);
	sft.extend(0);
	dfs(1,0); 
	while (q--){
		scanf("%d%d",&a,&b);
		printf("%d\n",rank[a]>=rank[b]);
	}return 0;
}



	
