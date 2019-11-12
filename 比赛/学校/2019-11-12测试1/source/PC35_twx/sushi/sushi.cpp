#include <bits/stdc++.h>

using namespace std;
const int N = 1000010;
const int INF = 0x3f3f3f3f;
int read(){
	char ch=getchar();
	int res=0;
	while(ch<'0' || ch>'9'){
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		res=res*10+ch-'0';
		ch=getchar();
	}
	return res;
}
int T,n,ans=INF;
char str[N<<1];
int f[4][N<<1];
int main(){
	freopen("sushi.in", "r", stdin);
	freopen("sushi.out", "w", stdout);
	T=read();
	while(T--){
		ans=INF;
		scanf("%s",str+1);
		n=strlen(str+1);
		for(int i=1; i<=n; i++){
			str[i+n]=str[i];
		}
		for(int k=0; k<n; k++){
			int cnt=0;
			for(int i=k; i<=k+n; i++){
				if(str[i]=='B'){
					cnt++;
				}
				else{
					f[0][i]=cnt;
				}
			}
			cnt=0;
			for(int i=n+k; i>=k; i--){
				if(str[i]=='B'){
					cnt++;
				}
				else{
					f[1][i]=cnt;
				}
			}
			cnt=0;
			for(int i=k; i<=n+k; i++){
				if(str[i]=='R'){
					cnt++;
				}
				else{
					f[2][i]=cnt;
				}
			}
			cnt=0;
			for(int i=n+k; i>=k; i--){
				if(str[i]=='R'){
					cnt++;
				}
				else{
					f[3][i]=cnt;
				}
			}
			int ans1=0,ans2=0;
			for(int i=k; i<=n+k; i++){
				if(str[i]=='R'){
					ans1+=min(f[0][i], f[1][i]);
				}
				else{
					ans2+=min(f[2][i], f[3][i]);
				}
			}
			ans=min(ans, min(ans1, ans2));
		}
		printf("%d\n",ans);
	}
	return 0;
}

