#include<bits/stdc++.h>
using namespace std;
const int N=2000005,base=131;
typedef unsigned long long ll;
inline int read(){
	int s=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s;
}
int n,m;
char s[N];
int ch[N][26],tot=0;
int w[N],ed[N*26];
inline void ins(char *s,int w){
	int len=strlen(s);int rt=0;
	for(int i=0;i<len;i++){
		int t=s[i]-'a';
		if(!ch[rt][t]) ch[rt][t]=++tot;
		rt=ch[rt][t];
	}
	ed[rt]=w;
}
inline int query(char *s){
	int len=strlen(s);int rt=0;
	for(int i=0;i<len;i++){
		int t=s[i]-'a';
		if(!ch[rt][t]) return -1;
		rt=ch[rt][t];
	}
	return ed[rt];
}
int main(){
	freopen("liverpool.in","r",stdin);
	freopen("liverpool.out","w",stdout);
	memset(ed,-1,sizeof(ed));
	n=read();
	for(int i=1;i<=n;i++) {
		scanf("%s",s);w[i]=read();
		ins(s,w[i]);
	}
	m=read();
	for(int i=1;i<=m;i++) {
		int x=read();ll ans=0;
		while(x--){
			scanf("%s",s);
			int t=query(s);
			if(t==-1) {
				puts("-1");
				goto end;
			}
			ans+=t;
		}
		printf("%lld\n",ans);
		end:;
	}
	return 0;
} 
