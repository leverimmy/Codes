#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
#define N 100005

using namespace std;

int match[N];
char st[N];int n;
int nxt[N];
bool cmp(int l0,int r0,int l1,int r1){
//	puts("===");
	for (int i=l0,j=l1;;i=nxt[i],j=nxt[j]){
//		printf("%c %c\n",st[i],st[j]);
		if (st[i]!=st[j]) return st[i]<st[j];
		else if (i==r0||j==r1) return i==r0;
	}
}
int cnt[N];
void solve(int &l,int r){
	if (isalpha(st[r])){
		if (cnt[r+1]-cnt[l]) for (;;);
		return;
	}
	if (match[r]==-1) for (;;);
	int mid=match[r],u=mid-1,v=mid+1,ed=r--;
//	printf("%d %d %d %d %d %d\n",l,u,mid,v,r,ed);
	solve(l,u);
	solve(v,r);
	if (!cmp(l,u,v,r))
		swap(l,v),swap(u,r);
	nxt[u]=mid;
	nxt[mid]=v;
	nxt[r]=ed;
/*	for (int i=l;;i=nxt[i]){
		putchar(st[i]);
		if (i==ed) break;
	}
	puts("");*/
}


int stk[N],top;
void work(){
	scanf("%s",st);
	n=strlen(st);
	for (int i=0;i<n;++i) nxt[i]=i+1;
	cnt[0]=0;
	for (int i=0;i<n;++i) cnt[i+1]=cnt[i]+!isalpha(st[i]);
	top=0;
	memset(match,-1,sizeof(match));
	for (int i=0;i<n;++i)
		if (st[i]=='[') stk[top++]=i;
		else if (st[i]==']') match[i]=stk[--top];
	if (top) for (;;);
//	for (int i=0;i<n;++i) printf("%d ",match[i]);puts("");
	int l=0;
	solve(l,n-1);
//	puts("");return;
	for (int i=l;i<n;i=nxt[i]) putchar(st[i]);
	puts("");
}

int main(){
//	freopen ("subscript.in","r",stdin);
//	freopen ("subscript.out","w",stdout);
	int T;scanf("%d",&T);
	while (T--) work();
	return 0;
}
/*
4
aaa[bbb]
a[b[abbb]]
b[a[azzz]]
x[a][b[a]]

*/
