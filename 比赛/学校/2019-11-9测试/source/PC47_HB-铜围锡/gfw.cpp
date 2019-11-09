#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 110;
int read(){
	char ch=getchar();
	int res=0,cf=1;
	while(ch<'0' || ch>'9'){
		if(ch=='-'){
			cf=-1;
		}
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		res=res*10+ch-'0';
		ch=getchar();
	}
	return res*cf;
}
int n,ans;
int h[N];
int f[N];
int cal(int l,int r){
	int res=0;
	memset(f, 0, sizeof f);
	for(int i=1; i<=n; i++){
		if(i==l){
			i=r+1;
			if(h[i]>h[l-1]){
				f[i]=f[l-1]+1;
			}
			else{
				f[i]=1;
			}
			continue;
		}
		if(h[i]>h[i-1]){
			f[i]=f[i-1]+1;
		}
		else{
			f[i]=1;
		}
		res=max(res, f[i]);
	}
	return res;
}
int main(){
	freopen("gfw.in", "r", stdin);
	freopen("gfw.out", "w", stdout);
	n=read();
	for(int i=1; i<=n; i++){
		h[i]=read();
	}
	ans=cal(0, 0);
	for(int l=1; l<=n; l++){
		for(int r=l; r<=n; r++){
			ans=max(ans, cal(l, r));
		}
	}
	printf("%d\n",ans);
	return 0;
}

