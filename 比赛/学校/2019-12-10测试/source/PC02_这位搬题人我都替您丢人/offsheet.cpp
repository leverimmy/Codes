#include <bits/stdc++.h>
struct node {
	long long x,y;
}a[10005],b[10005];
long long dis(int i,int j){
	if (j==0||i==0)return 0;
	return abs(a[i].x-b[j].x)+abs(a[i].y-b[j].y);
}int cmp(node a,node b){
	return a.x<b.x;
}
int n,x,y,c,match[10005],match2[10005],tl1,tl2;
long long ans=0;

int main(){
	freopen("offsheet.in","r",stdin);
	freopen("offsheet.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d%d%d",&x,&y,&c);
		while (c--){a[++tl1].x=x;a[tl1].y=y;}
	}for(int i=1;i<=n;++i){
		scanf("%d%d%d",&x,&y,&c);
		while (c--){b[++tl2].x=x;b[tl2].y=y;}
	}for(int l=0;l<=1;++l){
		//std::random_shuffle(a+1,a+tl1+1);
		long long sum=0;
		std::memset(match,0,sizeof(match));
		std::memset(match2,0,sizeof(match2));
		for(int i=1;i<=tl1;++i){
			int s=0;
			for(int j=1;j<=tl2;++j){
				if (!match[j]&&(!s||dis(i,j)>dis(i,s)))s=j;
			}
			match[s]=i;match2[i]=s;sum+=dis(i,s);
		}for(register int k=0;k<100;++k){
			int flag=0;
			for(int i=1;i<=tl1;++i){
				for(register int j=1;j<=tl1;++j){
					if (0<-(dis(i,match2[i])+dis(j,match2[j]))+dis(i,match2[j])+dis(j,match2[i])){
					//	assert(sum-dis(i,match2[i])-dis(j,match2[j])+dis(i,match2[j])+dis(j,match2[i])>sum);
						sum=sum-dis(i,match2[i])-dis(j,match2[j])+dis(i,match2[j])+dis(j,match2[i]);
						ans=std::max(ans,sum);
						std::swap(match2[i],match2[j]);
						flag=1;
					}
				}
			}if (!flag)break;
		}
			ans=std::max(ans,sum);
	}
	printf("%lld",ans);
	return 0;
}
