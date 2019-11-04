#include <bits/stdc++.h>
#define lim 1000000
#define maxn 100005

int n,m,t,opt,x,y,ch[maxn<<5][2]={0},cnt[maxn<<5]={0},L[maxn<<5]={0},R[maxn<<5]={0},root[lim*2]={0},ans=0,tail=0;

void update(int rt){
	cnt[rt]=cnt[ch[rt][0]]+cnt[ch[rt][1]];
	L[rt]=L[ch[rt][0]];R[rt]=R[ch[rt][1]];
	if (L[ch[rt][1]]&&R[ch[rt][0]])cnt[rt]--;
}

int insert(int rt,int l,int r,int p){
	if (!rt)rt=++tail;
	if (l==r){L[rt]=R[rt]=cnt[rt]=1;return rt;}
	int mid=(l+r)>>1;
	if (p<=mid)ch[rt][0]=insert(ch[rt][0],l,mid,p);
	else ch[rt][1]=insert(ch[rt][1],mid+1,r,p);
	update(rt);return rt;
}

int merge(int x,int y){
	if (!x||!y)return x+y;
	ch[y][0]=merge(ch[x][0],ch[y][0]);
	ch[y][1]=merge(ch[x][1],ch[y][1]);
	update(y);
	return y;
}

int main(){
	freopen("pudding.in","r",stdin);
	freopen("pudding.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i){
		scanf("%d",&t);root[t]=insert(root[t],1,n,i);
	}for (int i=1;i<=lim;++i){if (root[i])ans+=cnt[root[i]];}
	while (m--){
		scanf("%d",&opt);
		if (opt==2)printf("%d\n",ans);
		if (opt==1){
			scanf("%d%d",&x,&y);
			if (x==y)continue;
			ans-=cnt[root[x]]+cnt[root[y]];
			root[y]=merge(root[x],root[y]);root[x]=0;
			ans+=cnt[root[y]];
		}
		
	}return 0;
}                    

