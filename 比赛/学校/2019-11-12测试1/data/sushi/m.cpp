#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
#define File(s) freopen(s".in","r",stdin),freopen(s".in","w",stdout);

using namespace std;
typedef long long llg;

#define ss 5000
#define st 10
int n,m,T;

int main(){
	File("sushi");
	srand(time(NULL));
	T=st;
	printf("%d\n",T);
	while(T--){
		n=rand()%ss+1; n=ss;
		for(int i=1;i<=n;i++)
			printf("%c",rand()%2?'B':'R');
		printf("\n");
	}
	return 0;
}
