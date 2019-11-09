#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stack>
using namespace std;
int front[900000],a[200010],order[200010];
int n,T,ans,len;
void Discrete(){
	sort(order+1,order+n+1);
	len = unique(order+1,order+n+1)-order-1;
	for (int i = 1;i<=n;i++)
		a[i] = lower_bound(order+1,order+len+1,a[i])-order;
}
void modify1(int o,int l,int r,int Now,int d){
	if (!front[o]) return;
	if (r < Now){
		if (front[o] + d > ans) ans = front[o] + d;return;
	}
	int mid = (l+r)>>1;
	if (l < Now) modify1(o*2,l,mid,Now,d);
	if (mid+1 < Now) modify1(o*2+1,mid+1,r,Now,d);
}
void modify(int o,int l,int r,int Now,int d){
	if (l == r){
		ans = max(ans,d);front[o] = max(front[o],d);return;
	}
	int mid = (l+r) >> 1;
	if (Now<=mid) modify(o*2,l,mid,Now,d);
	else modify(o*2+1,mid+1,r,Now,d);
	front[o] = max(front[o*2],front[o*2+1]);
}
stack <int> S;
int main(){
	freopen("gfw.in","r",stdin);
	freopen("gfw.out","w",stdout);
	ans = 0;memset(front,0,sizeof(front));
	scanf("%d",&n);
	for (int i = 1;i<=n;i++)
		scanf("%d",&a[i]),order[i] = a[i];
	Discrete();
	for (int i = 1;i<=n;i++){
		if (S.empty() || S.top() < a[i])S.push(a[i]);
		else{
			int d = 0;int Size = S.size();
			while (!S.empty()){
				d++;int Now = S.top();S.pop();
				modify1(1,1,len,Now,d);
				modify(1,1,len,Now,Size-d+1);
			}
			S.push(a[i]);
		}
	}
	if (!S.empty()){
		int d = 0;int Max = S.top();
		while (!S.empty()){
			d++;int Now = S.top();S.pop();
			modify1(1,1,len,Now,d);
		}
		modify(1,1,len,Max,d);
	}
	printf("%d\n",ans);
	return 0;
}
