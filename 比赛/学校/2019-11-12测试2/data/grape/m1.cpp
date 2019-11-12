#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
#define File(s) freopen(s".in","r",stdin),freopen(s".in","w",stdout);

using namespace std;
typedef long long llg;

#define sn 1000
#define sm 2000
#define st 2000
int n,m,T,a[sn+1];

void rra(){
	for(int i=2;i<=n;i++)
		for(int j=1;j<=3;j++){
			int x=rand()%(i-1)+1;
			swap(a[x],a[i]);
		}
}

int main(){
	File("grape");
	srand(time(NULL));
	n=rand()%sn+1;
	m=rand()%sm+1;
	T=rand()%st+1;
	n=sn; m=sm; T=st;
	printf("%d %d %d\n",n,m,T);
	for(int i=1;i<=n;i++) a[i]=i;
	while(m){
		rra();
		int siz=min(rand(),min(n,m)),l,r; m-=siz;
		for(int i=1;i<siz;i++){
			r=rand()%T+1; l=rand()%r;
			printf("%d %d %d %d\n",a[i],a[i+1],l,r);
		}
		r=rand()%T+1; l=rand()%r;
		printf("%d %d %d %d\n",a[siz],a[1],l,r);
	}
	return 0;
}
