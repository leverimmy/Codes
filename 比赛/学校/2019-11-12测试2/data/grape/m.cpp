#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
#define File(s) freopen(s".in","r",stdin),freopen(s".in","w",stdout);

using namespace std;
typedef long long llg;

#define ss 1000
int n,m,T;

int main(){
	File("grape");
	srand(time(NULL));
	n=ss; m=ss; T=ss+500;
	printf("%d %d %d\n",n,m,T);
	for(int i=1;i<=m;i++){
		int r=rand()%ss+1,l=rand()%r;
		printf("%d %d %d %d\n",rand()%n+1,rand()%n+1,l,r);
	}
	return 0;
}
