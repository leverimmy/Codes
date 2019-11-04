#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 100010;
typedef unsigned long long ull;
const ull P = 1331;
int n,f,ans;
int p[N];
ull h[N],base[N];
void hash(){
	base[0]=1;
	for(int i=1; i<=n; i++){
		base[i]=base[i-1]*P;
	}
	for(int i=1; i<=n; i++){
		h[i]=h[i-1]*P+(ull)p[i];
	}
}
int main(){
	freopen("weapon.in", "r", stdin);
	feropen("weapon.out", "w", stdout);
	scanf("%d%d",&n,&f);
	for(int i=1; i<=n; i++){
		scanf("%d",&p[i]);
	}
	hash();
	for(int a=1; a<=n; a++){
		for(int len=1; len<=n; len++){
			if(a+len*2+f-1<=n){
				int l1=a,r1=a+len-1,l2=a+len+f,r2=a+len*2+f-1;
				if(h[r1]-h[l1-1]*base[len] == h[r2]-h[l2-1]*base[len]){
					ans++;
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}

