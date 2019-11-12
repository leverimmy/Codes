#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
#define File(s) freopen(s".in","r",stdin),freopen(s".in","w",stdout);

using namespace std;
typedef long long llg;

#define ss 500
#define si 10
int n,m;

int main(){
	File("matrix");
	srand(time(NULL));
	n=rand()%ss+1; m=rand()%si+1;
	n=ss; m=si;
	printf("%d %d\n",n,m);
	for(int k=1;k<=2;k++)
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)
				printf("%d ",rand()%101);
			printf("\n");
		}
	for(int i=1;i<=m;i++){
		int a,b,c,d;
		d=rand()%n+1; c=rand()%n+1;
		b=rand()%d+1; a=rand()%c+1;
		printf("%d %d %d %d\n",a,b,c,d);
	}
	return 0;
}
