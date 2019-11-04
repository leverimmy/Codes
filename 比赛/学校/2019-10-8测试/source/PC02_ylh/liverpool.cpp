#include <bits/stdc++.h>
#define maxn 2000005
int n,w,q,t,sum[maxn],ch[maxn][26]={0},tail=1;
char s[maxn];

void insert(int w){
	int len=std::strlen(s+1),rt=1;
	for(int i=1;i<=len;++i){
		if (!ch[rt][s[i]-'a'])ch[rt][s[i]-'a']=++tail;
		rt=ch[rt][s[i]-'a'];
	}sum[rt]=w;
}

int find(){
	int len=std::strlen(s+1),rt=1;
	for(int i=1;i<=len;++i){
		if (!ch[rt][s[i]-'a'])return 0;
		rt=ch[rt][s[i]-'a'];
	}return sum[rt];
}

int main(){
	freopen("liverpool.in","r",stdin);
	freopen("liverpool.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%s%d",s+1,&w);
		insert(w);
	}scanf("%d",&q);
	while (q--){
		long long ans=0;
		scanf("%d",&t);
		for(int i=1;i<=t;++i){
			scanf("%s",s+1);
			int d=find();
			if (d&&ans!=-1)ans+=d;
			else ans=-1;
		}printf("%lld\n",ans);
	}
	return 0;
}
