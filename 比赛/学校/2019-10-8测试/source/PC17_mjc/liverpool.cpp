#include<bits/stdc++.h>
#define int long long
using namespace std;
map<string , int > mb;

int n;
int m; 
int read(){
	int f=1,ans=0;
	char ch=getchar();
	while(ch>'9' || ch<'0'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch<='9' && ch>='0'){
		ans=ans*10+ch-'0';
		ch=getchar();
	}
	return ans*f;
}
struct trie{
	int next[30];
	bool end;
}t[2000010];
int v[2000010];
int tot=0;
void update(char *s,int x){
	int now=0,p=0;
	for(int i=0;s[i];i++){
		if(!t[now].next[s[i]-'a']){
			t[now].next[s[i]-'a']=++tot;
		}
		now=t[now].next[s[i]-'a'];
	}
	v[now]=x;
	t[now].end=1;
}
int query(char *s){
	int now=0,p=0;
	for(int i=0;s[i];i++){
		if(!t[now].next[s[i]-'a']){
			return -1;
		}
		now=t[now].next[s[i]-'a'];
	}
	if(t[now].end!=1){
		return -1;
	}	
	return v[now];
} 
char s[2000010];
signed main(){
	freopen("liverpool.in","r",stdin);
	freopen("liverpool.out","w",stdout);
//	ios::sync_with_stdio(0); 
	n=read();
	for(int i=1;i<=n;i++){
		scanf("%s",s);
		int x;
		x=read();
		update(s,x);
	}
	m=read();
	for(int i=1;i<=m;i++){
		int x;
			x=read();
		int ans=0,f=0;
		for(int j=1;j<=x;j++){
			scanf("%s",s);
			int k=query(s);
			if(k==-1){
				f=1;
				printf("-1\n");
				break;
			}	
			ans+=k;	
		}
		if(!f)
			printf("%lld\n",ans);
	}
}
