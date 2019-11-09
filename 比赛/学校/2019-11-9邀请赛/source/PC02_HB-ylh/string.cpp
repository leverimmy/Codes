#include <bits/stdc++.h>
#define maxn 2000905
const int base=1000002;
int n,a[maxn],sum[maxn],pre[maxn],ans[maxn]={0};
std::vector<int>rec[maxn];
char s[maxn];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n;++i)
		a[i]=s[i]=='('?1:-1;
	for(int i=1;i<=n;++i){sum[i]=sum[i-1]+a[i];}//printf("\n");
	std::stack<int>stk;sum[0]=0;stk.push(0);
	for(int i=1;i<=n;++i){
		while (!stk.empty()&&sum[i]<=sum[stk.top()])stk.pop();
		if (!stk.empty())pre[i]=stk.top();
		else pre[i]=-1;
		stk.push(i);
	}rec[base].push_back(0);
	for(int i=1;i<=n;++i){
		//printf("%d ",pre[i]);
		int d=sum[i]+base;
		int l=0,r=rec[d].size()-1,p=-1;
		while (l<=r){
			int mid=(l+r)>>1;
			if (rec[d][mid]>pre[i]){p=mid;r=mid-1;}
			else l=mid+1;
		}//printf("%d\n",p!=-1?rec[d][p]:p);
		if (p!=-1){ans[i-rec[d][p]]++;}
		rec[d].push_back(i);
	}for(int i=n;i>=0;i--)
		if (ans[i]){printf("%d %d",i,ans[i]);break;}
	return 0;
}





