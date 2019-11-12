#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
int n;
char s[N];
ll res;
int main(){
	freopen("sushi.in","r",stdin);
	freopen("sushi.out","w",stdout);
	int T;scanf("%d",&T);
	while(T--){
		scanf("%s",s+1);n=strlen(s+1);
		res=1e18;
		for(int i=n+1;i<2*n;i++) s[i]=s[i-n];
		int l=0,r=0,p=1;ll ans=0;
		for(int i=1;i<=n;i++) if(s[i]=='R') ans+=n-i-r,r++;
		res=ans;
		for(int i=1;i<=n;i++){
			while(p<i+n){
				if(s[p]=='R') {
					ll t=ans;r--;
					t+=p-i-l-(i+n-1-p-r);
					l++;
					if(t<=ans) ans=t;
					else {l--,r++;break;} 
				}
				p++;
			}
			res=min(res,ans);
			if(s[i]=='R') l--,r++;
			else ans+=r-l;
		}
		printf("%lld\n",res);
	}
	return 0;
} 
