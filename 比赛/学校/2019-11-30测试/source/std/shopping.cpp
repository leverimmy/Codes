#include<cstdio>
#include<algorithm>
using std::sort;
using std::max;
typedef long long ll;
typedef long double ld;
const int N=1010;
ll read(){
	ll a=0;int op=1;char ch=getchar();
	while(ch<'0'||'9'<ch){if(ch=='-')op=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){a=a*10+ch-'0';ch=getchar();}
	return a*op;
}
void file(const char *str){
	char in[100],out[100];
	sprintf(in,"%s.in",str),sprintf(out,"%s.out",str);
	freopen(in,"r",stdin),freopen(out,"w",stdout);
}
struct object{
	ll v[2];
	bool operator<(const object &o)const{
		if(v[0]==o.v[0]){
			return v[1]<o.v[1];
		}
		return v[0]>o.v[0];
	}
};
object o[N];
ll dp[N];
bool bl[N][N];
ll r[N];
int n;
char str[100];
int get_bag(int i){
	return (i+(str[0]=='L'))>>1;
}
void input(){
	n=read();
	scanf(" %s",str);
	for(int i=1;i<=n;i++){
		o[i].v[0]=read();
		o[i].v[1]=read();
	}
}
void ini(){
	sort(o+1,o+1+n);
}
void solve(){
	for(int i=1;i<=n;i++){
		for(int j=get_bag(i);j;j--){
			if(dp[j]<=dp[j-1]+o[i].v[1]){
				dp[j]=dp[j-1]+o[i].v[1];
				bl[i][j]=1;
			}
		}
	}
}
void output(){
	int i=n,j=get_bag(n);
	ll ans=0;
	while(i){
		if(bl[i][j]){
			j--;
		}else{
			ans+=o[i].v[0];
		}
		i--;
	}
	printf("%lld %lld",ans,dp[get_bag(n)]);
}
void test(){
	input();
	ini();
	solve();
	output();
}
void all(){
	file("shopping");
	test();
}
int main(){
	all();
	return 0;
}

