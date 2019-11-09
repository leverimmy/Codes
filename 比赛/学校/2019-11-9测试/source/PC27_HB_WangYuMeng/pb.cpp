#include<bits/stdc++.h>
using namespace std;
int n,w;
double tot,u[110],s[110],ans=2147483640;
void dfs(int pos,int now,double val,int lst){
//	printf("pos:%d now:%d lst:%d\n",pos,now,lst);
	if(now==w){
		val+=(n)*(s[n]-s[lst]);
		ans=min(ans,val);
//		if(ans>val){
////			printf("%d %d %lf %d\n",pos,now,val,lst);
//			ans=val;
//		}
		return;
	}
	if(n-pos<w-now||now>w||pos>=n+1)
		return;
	for(int i=pos+1;i<=n+1;++i)
	{
		if(val+(i-1)*(s[i-1]-s[lst])>ans)
			break;
		dfs(i,now+1,val+(i-1)*(s[(i-1)]-s[lst]),i-1);
	}
//	dfs(pos+1,now,val,lst);
}
int main(){
	freopen("pb.in","r",stdin);
	freopen("pb.out","w",stdout);
	scanf("%d%d",&n,&w);
	for(int i=1;i<=n;++i)
		scanf("%lf",&u[i]),tot+=u[i];
	for(int i=1;i<=n;++i)
		u[i]/=tot;
	sort(u+1,u+n+1,greater<double>());
	for(int i=1;i<=n;++i)
		s[i]=s[i-1]+u[i];
	dfs(1,1,0,0);
	printf("%.4lf",ans);
	return 0;
}
