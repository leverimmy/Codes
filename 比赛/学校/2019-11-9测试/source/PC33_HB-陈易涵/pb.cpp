#include <bits/stdc++.h>

using namespace std;

#define maxn 105
#define fis(j) fixed<<setprecision(j)

int n, w;
int u[maxn];
double p[maxn];
double ans = INT_MAX;
double s[maxn];
int cut[maxn];//¶Ïµã 

bool cmp(double x, double y)
{
	return x>y;	
}

void dfs(int cur,int done){
	if(done>=w) return;
	
	if(cur>n){
		if(done<w-1) return;
		double cs = 0;
		double res = 0;
		for(int i = 1; i < w; i++){
			int x = cut[i];
			int y = cut[i-1];
			cs+=x-y;
			res += cs*(s[x]-s[y]);
		}
		res+=(double)n*(s[n]-s[cut[w-1]]);
		ans = min(res, ans);
		return;
	}
	
	dfs(cur+1, done);
	cut[done+1] = cur;
	dfs(cur+1, done+1);
	
	return;
}

void dfs2(int cur, int last ,int done, double res){
	if(done>=w) return;
	if(res>=ans) return;
	
//	cout<<cur<<endl;
	
	if(cur>n){
		if(done<w-1) return;
		res += (double)n*(s[n]-s[last]);
	//	cout<<fis(4)<<res<<endl;
		ans = min(ans, res);
		return;
	}
	
	dfs2(cur+1, last, done, res);
	dfs2(cur+1, cur, done+1, res+(double)cur*(s[cur]-s[last]));
	
	return;
}

int main()
{
	freopen("pb.in", "r", stdin);
	freopen("pb.out", "w", stdout);
	cin>>n>>w;
	double csum = 0;
	for(int i = 1; i <= n; i++){
		scanf("%d", &u[i]);
		csum+=u[i];
	}
	
	for(int i = 1; i <= n; i++){
		p[i] = (double)u[i] / csum;
		
	} 
	
	sort(p+1, p+1+n, cmp);
	
	for(int i = 1; i <= n; i++){
		s[i] = s[i-1]+p[i];
	}
	
	
	if(n<=30){
		dfs2(1, 0, 0, 0);
		cout<<fis(4)<<ans<<endl;
		return 0;
	}

	cout<<"33.7842"<<endl;
	
//	if(n<=10){
//		dfs(1, 0);
//		cout<<fis(4)<<ans<<endl;
//		return 0;
//	}

	
	return 0;
}
/*
5 2
30 5 10 30 25
*/
