#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;
const int N = 210010;
int n,ming,sum,ans;
char read(){
	char ch=getchar();
	while(ch!='I' && ch!='A' && ch!='S' && ch!='F'){
		ch=getchar();
	}
	return ch;
}
int root,cntn;
int pri[N],val[N],ls[N],rs[N],siz[N];
int create(int x){
	val[++cntn]=x;
	pri[cntn]=rand();
	siz[cntn]=1;
	ls[cntn]=0;
	rs[cntn]=0;
	return cntn;
}
void push_up(int x){
	siz[x]=siz[ls[x]]+siz[rs[x]]+1;
}
int merge(int x,int y){
	if(!x || !y){
		return x+y;
	}
	if(pri[x]<pri[y]){
		rs[x]=merge(rs[x], y);
		push_up(x);
		return x;
	}
	else{
		ls[y]=merge(ls[y], x);
		push_up(y);
		return y;
	}
}
void split(int p,int k,int &x,int &y){
	if(!p){
		x=y=0;
		return;
	}
	if(val[p]<k){
		x=p;
		split(rs[p], k, rs[x], y);
		push_up(x);
	}
	else{
		y=p;
		split(ls[p], k, x, ls[y]);
		push_up(y);
	}
}
int getrank(int k){
	int now=root;
	while(1){
		if(siz[ls[now]]>=k){
			now=ls[now];
		}
		else if(siz[ls[now]]+1==k){
			return val[now];
		}
		else{
			now=rs[now];
			k-=(siz[now]+1);
		}
	}
	return -1;
}
int main(){
	srand(time(0));
	scanf("%d%d",&n,&ming);
	int x=0,y=0;
	for(int i=1; i<=n; i++){
		char opt=read();
		int k;
		scanf("%d",&k);
		if(opt=='I'){
			if(k<ming){
				continue;
			}
			int pos=create(k-sum);
			root=merge(root, pos);
		}
		else if(opt=='A'){
			sum+=k;
		}
		else if(opt=='S'){
			sum-=k;
			split(root, ming-sum, x, y);
			ans+=siz[x];
			root=y;
		}
		else if(opt=='F'){
			if(!root || k>siz[root]){
				puts("-1");
			}
			else{
				printf("%d\n",getrank(siz[root]-k+1)+sum);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}

