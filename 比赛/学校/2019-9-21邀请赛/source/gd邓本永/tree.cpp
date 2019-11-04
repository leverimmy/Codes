#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5, M=5e5+5;
int n, m, h[N], f[N], s, x, y, z;
int sz, pos[N], t[N];
struct AB{
    int a,b,c,n;
}d[M*2];
void update(int u){
	for(int i=pos[u];i>1;i>>=1){
		if(f[t[i]]>=f[t[i>>1]]) break;
		swap(t[i], t[i>>1]);
		swap(pos[t[i]], pos[t[i>>1]]);
	}
	for(int i=pos[u], j;(j=(i<<1))<=sz;i=j){
		if((i<<1|1)<=sz&&f[t[i<<1|1]]<f[t[i<<1]]) j=(i<<1|1);
		if(f[t[i]]<=f[t[j]]) break;
		swap(t[i], t[j]);
		swap(pos[t[i]], pos[t[j]]);
	}
}
void push(int u){
	t[++sz]=u, pos[u]=sz;
	update(sz);
}
int pop(){
	int ret=t[1];
	t[1]=t[sz--];
	pos[t[1]]=1;
	update(t[1]);
	return ret;
}

void charu(int i, int a, int b, int c){
    d[i].a=a;
    d[i].b=b;
    d[i].c=c;
    d[i].n=h[a];
    h[a]=i;
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d", &x, &y, &z);
        charu(i, x, y, z);
        charu(i+m, y, x, z);
    }
    memset(f, 0x7f, sizeof(f));
    f[1]=0;
    for(int i=1;i<=n;i++) push(i);
    while(sz){
        int a=pop();
        for(int k=h[a];k;k=d[k].n){
            int b=d[k].b, c=d[k].c;
            if(max(f[a], c)<f[b]){
                f[b]=max(f[a],c);
                update(b);
            }
        }
    }
    long long ans=0;
    for(int i=2;i<=n;i++){
    	ans+=f[i];
	}
	cout<<ans;
}
