#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
int n,w;
double sum;
double x[101];
double dfs(int left,double last_sum,int now){
	if(n-now<left||left<0||now>n){
		return 999999999;
	}
	if(!left&&now==n){
		return last_sum*now;
	}
	return min(dfs(left,last_sum+x[now],now+1),dfs(left-1,x[now],now+1)+last_sum*now);
}
int main(){
	freopen("pb.in","r",stdin);
	freopen("pb.out","w",stdout);
	cin>>n>>w;
	for(int i=0;i<n;i++){
		cin>>x[i];
		sum+=x[i];
	}
	for(int i=0;i<n;i++){
		x[i]/=sum;
		x[i]*=-1;
	}
	sort(x,x+n);
	for(int i=0;i<n;i++){
		x[i]*=-1;
	}
	printf("%.4f",dfs(w-1,0.000000,0));
	return 0;
}

