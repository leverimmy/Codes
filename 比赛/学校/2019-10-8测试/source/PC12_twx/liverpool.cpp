#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
const int N = 2000010;
int n,m,root,cntn;
int read(){
	int res=0;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		res=res*10+ch-'0';
		ch=getchar();
	}
	return res;
}
char s[N];
struct node{
	long long w;
	bool vis;
	int nxt[26];
}tr[N];
void insert(char *s, long long w){
	int len=strlen(s);
	int now=root;
	for(int i=0; i<len; i++){
		int d=s[i]-'a';
		if(!tr[now].nxt[d]){
			tr[now].nxt[d]=++cntn;
		}
		now=tr[now].nxt[d];
	}
	tr[now].w+=w;
	tr[now].vis=1;
}
long long query(char *s){
	int len=strlen(s);
	int now=root;
	for(int i=0; i<len; i++){
		int d=s[i]-'a';
		if(!tr[now].nxt[d]){
			return -1;
		}
		now=tr[now].nxt[d];
	}
	if(!tr[now].vis){
		return -1;
	}
	else{
		return tr[now].w;
	}
}
signed main(){
	freopen("liverpool.in", "r", stdin);
	freopen("liverpool.out", "w", stdout);
	n=read();
	for(int i=1; i<=n; i++){
		scanf("%s",s);
		long long w=(long long)read();
		insert(s, w);
	}
	m=read();
	for(int i=1; i<=m; i++){
		int num=read();
		long long ans=0;
		for(int j=1; j<=num; j++){
			scanf("%s",s);
			if(ans==-1){
				continue;
			}
			long long w=query(s);
			if(w==-1){
				ans=-1;
			}
			else{
				ans+=w;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

