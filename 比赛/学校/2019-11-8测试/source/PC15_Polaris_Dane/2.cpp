#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<set>
#include<algorithm>
#include<cctype>
#include<stack>
#include<queue>
#define int long long
using namespace std;
const int M=200200;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
inline int read(){
	int x=0,f=1;char s=getchar();
	while (!isdigit(s)){if(s=='-')f=-1;s=getchar();}
	while (isdigit(s)){x=(x<<1)+(x<<3)+(s^48);s=getchar();}
	return x*f;
}
struct trie{
	int end,ch[26],nxt;	
}t[M];
int cnte;
char s[M],y[M];
inline void insert(int now,int depth){
	if (strlen(s)==depth+1){
		t[now].end=1;return;
	}
	if (!t[now].ch[s[depth]-'a']) t[now].ch[s[depth]-'a']=++cnte;
	insert(t[now].ch[s[depth]-'a'],depth+1);
}
queue<int>q;
inline void bfs(void){
	for (int i=0;i<26;i++){
		if (t[0].ch[i]){
			t[t[0].ch[i]].nxt=0;
			q.push(t[0].ch[i]);
		}
	}
	while (!q.empty()){
		int h=q.front();
		for (int i=0;i<26;i++){
			if (!t[h].ch[i]) continue;
			t[t[h].ch[i]].nxt=t[t[h].nxt].ch[i];
			q.push(t[h].ch[i]);
		}
	}
}
inline int check(void){
	int now=0;
	for (int i=0;i<strlen(y);i++){
		now=t[now].ch[y[i]-'a'];
		for (int j=now;j;j=t[j].nxt)
			if (t[j].end) return 1;
	}
	return 0;
}
signed main(void){
	freopen("2.in","r",stdin);
	freopen("2.out","w",stdout);
	while (scanf("%s",y)!=EOF){
		scanf("%s",s);
		memset(t[0].ch,0,sizeof(t[0].ch));cnte=0;
		insert(0,0);
		if (check()) printf("YES\n");
		else printf("NO\n");
	}
	return 0;	
}
