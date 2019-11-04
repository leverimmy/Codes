#include<bits/stdc++.h>
using namespace std;
int t,n,m;
const int Maxn=1e5+5;
struct AB{
	int l,r,k;
}a[Maxn];
bool b;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		b=true;
		for(int i=1;i<=m;i++){
			for(int i=1;i<=n;i++){
				scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].k);
				if(a[i].k>1)b=false;
			}
		}
		printf("Yes\n");
	}
}
