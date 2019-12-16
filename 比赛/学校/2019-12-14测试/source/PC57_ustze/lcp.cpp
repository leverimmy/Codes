#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N=1e5+5,base=19260817;
int n,m;
char s[N];
ull h[N],pw[N];
inline ull get_hash(int l,int r){
	return h[r]-h[l-1]*pw[r-l+1];
}
int main(){
	freopen("lcp.in","r",stdin);
	freopen("lcp.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	pw[0]=1;
	for(int i=1;i<=n;i++) h[i]=h[i-1]*base+(s[i]-'a'+1),pw[i]=pw[i-1]*base;
	for(int i=1;i<=m;i++){
		int a,b;scanf("%d%d",&a,&b);
		int len=min(n-a+1,n-b+1);
		int l=1,r=len,p=-1;
		while(l<=r){
			int mid=(l+r)>>1;
			if(get_hash(a,a+mid-1)==get_hash(b,b+mid-1)) l=mid+1;
			else p=mid,r=mid-1;
		}
		if(p!=-1) printf("%d\n",s[a+p-1]>s[b+p-1]);
		else printf("%d\n",a<=b);
	}
	return 0;
}
/*
5 2 
abaab 
1 3 
1 4

*/
