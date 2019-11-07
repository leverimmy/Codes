#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; 
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
const int N=1005;
int n,m;
int a[N],x[N],y[N];
double ans=0;
void dfs(int step){
	if(step>m){
		int res=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(a[i]>a[j]) res++;
		ans+=res*1.0/(1<<m);
		return;
	}
	dfs(step+1);
	swap(a[x[step]],a[y[step]]);
	dfs(step+1);
	swap(a[x[step]],a[y[step]]);
}
int main(){
	freopen("inversion.in","r",stdin);
	freopen("inversion.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=m;i++) x[i]=read(),y[i]=read();
	dfs(1);
	printf("%.8lf",ans);
	return 0;
}
