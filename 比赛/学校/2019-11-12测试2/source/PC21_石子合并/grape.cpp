#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
inline void outp(int o1){
	if(o1<0)
		putchar('-'),o1=-o1;
	register int o2=o1/10;
	if(o2)
		outp(o2);
	putchar((o1-(o2<<1)-(o2<<3))^48);
}
int edcnt,n,m,t,head[200010],col[200010];
struct edge{
	int to,nxt,st,nd;
};
edge ed[400010];
inline void addedge(int from,int to,int st,int nd){
	ed[++edcnt].nxt=head[from],
	ed[edcnt].to=to,
	ed[edcnt].st=st,
	ed[edcnt].nd=nd,
	head[from]=edcnt;
}
bool dye(int now,int t,int typ){
	if(col[now]&&col[now]!=typ)
		return false;
	if(col[now])
		return true;
	col[now]=typ;
	bool tmp=true;
	for(int i=head[now];i;i=ed[i].nxt){
		if(ed[i].st>t||ed[i].nd<t)
			continue;
		if(!dye(ed[i].to,t,-typ))
			return false;
	}
	return true;
}
inline void fun(int x){
	memset(col,0,sizeof(col));
	for(int i=1;i<=n;++i){
		if(col[i])
			continue;
		if(!dye(i,x,1)){
			printf("No\n");
			return;
		}
	}
	printf("Yes\n");
	return;
}
int main(){
	freopen("grape.in","r",stdin);
	freopen("grape.out","w",stdout);
	n=read(),m=read(),t=read();
	int t1,t2,t3,t4;
	for(int i=1;i<=m;++i){
		t1=read(),t2=read(),t3=read(),t4=read();
		addedge(t1,t2,t3+1,t4),addedge(t2,t1,t3+1,t4);
	}
	for(int i=1;i<=t;++i){
		fun(i);
	}
	return 0;
}
