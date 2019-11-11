#include<bits/stdc++.h>
using namespace std;
const int N=8005;
int n;
char s[N];
int cnt[305];
int res=0,ans=0;

int main(){
	freopen("reference.in","r",stdin);
	freopen("reference.out","w",stdout);
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) cnt[s[i]-'a']++;
	for(int i=0;i<26;i++) if(cnt[i]%2==1) res++;
	if((n%2==0&&res>0)||(n%2==1&&res!=1)){
		puts("Impossible");
		return 0;
	}
	for(int i=1;i<=n/2;i++){
		if(s[i]==s[n-i+1]) continue;
		if(cnt[s[i]-'a']%2==0){
			int j=n-i+1;
			while(s[i]!=s[j]) j--;
			for(int k=j;k<=n-i;k++) swap(s[k],s[k+1]),ans++;
		}else {
			int j=i;
			while(s[n-i+1]!=s[j]) j--;
			for(int k=j;k>=i+1;k--) swap(s[k],s[k-1]),ans++;
		}
	}
	printf("%d",ans);
	return 0;
}
