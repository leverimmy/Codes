#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cctype>
#include<stack>
#include<vector>
#include<set>
using namespace std;
const int inf=0x3f3f3f3f;
const int M=600010;
const int N=1010;
inline int read(void){
	int f=1,x=0;char s=getchar();
	while (!isdigit(s)){if (s=='-')f=-1;s=getchar();}
	while (isdigit(s)){x=(x<<1)+(x<<3)+(s^48),s=getchar();}
	return x*f;
}
int t,a,b;
signed main(void){
	freopen("boynextdoor.in","r",stdin);
	freopen("boynextdoor.out","w",stdout);
	t=read();
	while (t--){
		a=read(),b=read();
		if (a==0||b==0){
			printf("%d\n",a-b);
			continue;
		}
		printf("%d\n",a-b-2);
	}
	return 0;
}
