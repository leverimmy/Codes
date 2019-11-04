#include<bits/stdc++.h>
using namespace std;

inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s;
}
const int N=1e6+5,mx=1e6;
int n,m;
int a[N];
struct node{
	int l,r;
	node(int L=0,int R=0){l=L,r=R;}
	bool operator < (const node & b) const {
		return l<b.l;
	}
};
set<node> s[N];
int siz[N],fa[N],ans;
#define IT set<node>::iterator
inline int findf(int x){return x==fa[x]?x:fa[x]=findf(fa[x]);}
int main(){
	freopen("pudding.in","r",stdin);
	freopen("pudding.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	int la=1;
	for(int i=1;i<=n;i++) {
		if(a[i]!=a[i+1]||i==n){
			s[a[i]].insert(node(la,i));
			la=i+1;siz[a[i]]++;ans++;
		}
	}
	for(int i=1;i<=mx;i++) fa[i]=i;
	int x,y,fx,fy;
	for(int i=1;i<=m;i++){
		if(read()==1){
			x=read(),y=read();
			//fx=findf(x),fy=findf(y);
			//if(x==y) continue;
			//if(siz[y]>siz[x]) swap(x,y);
			//fa[y]=x;
			swap(x,y);
			s[x].insert(s[y].begin(),s[y].end());
			for(IT it=s[y].begin();it!=s[y].end();++it){
				IT it1=s[x].lower_bound(node(it->l,-1)),it2=it1,it3=it1;
				++it3;
				if(it1==s[x].begin()){
					if(it3->l==it1->r+1) {
						int L=it1->l,R=it3->r;
						s[x].erase(it1);s[x].erase(it3);
						s[x].insert(node(L,R));ans--;
					}
				}else {
					--it2;
					if(it3==s[x].end()){
						if(it2->r==it1->l-1) {
							int L=it2->l,R=it1->r;
							s[x].erase(it1);s[x].erase(it2);
							s[x].insert(node(L,R));ans--;
						}
					}else {
						if(it2->r==it1->l-1&&it3->l==it1->r+1){
							int L=it2->l,R=it3->r;
							s[x].erase(it1);s[x].erase(it2);s[x].erase(it3);
							s[x].insert(node(L,R));ans-=2;
						}else if(it2->r==it1->l-1) {
							int L=it2->l,R=it1->r;
							s[x].erase(it1);s[x].erase(it2);
							s[x].insert(node(L,R));ans--;
						}else if(it3->l==it1->r+1) {
							int L=it1->l,R=it3->r;
							s[x].erase(it1);s[x].erase(it3);
							s[x].insert(node(L,R));ans--;
						}
					}
				}
			}
		}else printf("%d\n",ans);
	}
	return 0;
}
/*
4 3
1 2 2 1
2
1 2 1
2
*/
