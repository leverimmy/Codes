#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int read() {
	int w=1,x=0,ch=getchar();
	for(; ch<'0'||ch>'9'; ch=getchar())if(ch=='-')w=-1;
	for(; ch>='0'&&ch<='9'; ch=getchar())x=x*10+ch-'0';
	return x*w;
}
int n,F,p[10010];
namespace baoli {
	int ans = 0;
	void main() {
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++) {
				if(i+j*2+F-1<=n) {
					bool flag = true;
					for(int k=0; k<j; k++) {
						if(p[i+k]!=p[i+j+F+k]) {
							flag = false;
							break;
						}
					}
					if(flag) ans++;
				}
			}
		printf("%d\n",ans);
		exit(0);
	}
}
namespace pts60 {
	const int MAXN = (int)1e3+10;
	const long long MOD = 19260817,MOD1 = 998244353,base = 1000;
	int b[MAXN];
	long long hash1[MAXN],hash2[MAXN],B1[MAXN],B2[MAXN];
	long long Calhash1(int x,int y) {
		return (hash1[x] - hash1[y-1]*B1[x-y+1]%MOD+MOD)%MOD;
	}
	long long Calhash2(int x,int y) {
		return (hash2[x] - hash2[y-1]*B2[x-y+1]%MOD1+MOD1)%MOD1;
	}
	void main() {
		for(int i=1;i<=n;i++)b[i] = p[i];
		sort(b+1,b+1+n);
		int len = unique(b+1,b+1+n) - b - 1;
		for(int i=1;i<=n;i++){
			p[i] = lower_bound(b+1,b+1+len,p[i]) - b;
		}
		B1[0] = B2[0] = 1;
		for(int i=1; i<=n; i++)B1[i] = B1[i-1]*base%MOD,B2[i] = B2[i-1]*base%MOD1;
		for(int i=1; i<=n; i++) {
			hash1[i] = (hash1[i-1]*base%MOD+p[i])%MOD;
			hash2[i] = (hash2[i-1]*base%MOD1+p[i])%MOD1;
		}
		int ans = 0;
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++) {
				if(i+j*2+F-1<=n) {
					if(Calhash1(i+j-1,i)==Calhash1(i+j*2+F-1,i+j+F)&&Calhash2(i+j-1,i)==Calhash2(i+j*2+F-1,i+j+F))
					ans++;
				}
			}
		printf("%d\n",ans);
		exit(0);
	}
}
int main() {
	freopen("weapon.in","r",stdin);
	freopen("weapon.out","w",stdout);
	n = read(),F = read();
	for(int i=1; i<=n; i++) {
		p[i] = read();
	}
	if(n<=100)baoli::main();
	if(n<=1000)pts60::main();
	return 0;
}
