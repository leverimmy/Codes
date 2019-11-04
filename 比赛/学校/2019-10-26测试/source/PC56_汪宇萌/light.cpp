#include<bits/stdc++.h>
using namespace std;
int n,m,a[1010],nowl=0,nowr=0,bl,head[1010],nxt[100010],valmax;
int tmp[1010],now,ans[100010],l,r,p,v,Ans;
struct query{
	int l,r,p,v,id;
//	const bool operator <(query &b)const{
//		return l/bl==b.l/bl?r<b.r:l<b.l;
//	}
}q[100010];
inline void dlt(int pos,int num){
	tmp[a[pos]%q[num].p]--;
}
inline void add(int pos,int num){
	tmp[a[pos]%q[num].p]++;
}
bool cmp(query x,query y)
{
	return x.l/bl==y.l/bl?x.r<y.r:x.l<y.l;
}
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
	{
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
	{
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
int main(){
	freopen("light.in","r",stdin);
	freopen("light.out","w",stdout);
	n=read(),m=read();
	bl=(int)n/(int)sqrt(m);
	if(n<=1000&&m<=1000){
		for(int i=1;i<=n;++i){
			a[i]=read(),nxt[i]=head[a[i]],head[a[i]]=i,valmax=max(valmax,a[i]);
		}
		for(int i=1;i<=m;++i){
			scanf("%d%d%d%d",&l,&r,&p,&v);
			Ans=0;
			while(v<=valmax){
				now=head[v];
				while(now>=l){
					if(now>=l&&now<=r)
						Ans++;
					now=nxt[now];	
				}
				v+=p;
			}
			printf("%d\n",Ans);
		}
		return 0;
	}
	for(int i=1;i<=n;++i)
		a[i]=read();
	for(int i=1;i<=m;++i){
		q[i]=(query){read(),read(),read(),read(),i};
	}
	sort(q+1,q+m+1,cmp);
	for(int i=1;i<=m;++i){
		while(nowl<q[i].l)
			dlt(nowl++,i);
		while(nowl>q[i].l)
			add(--nowl,i);
		while(nowr>q[i].r)
			dlt(nowr--,i);
		while(nowr<q[i].r)
			add(++nowr,i);
		ans[q[i].id]=tmp[q[i].v];
	}
	for(int i=1;i<=m;++i)
		printf("%d\n",ans[i]);
	return 0;
}
