#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<set>
#include<algorithm>
#include<cctype>
#include<stack>
#include<queue>
using namespace std;
const int M=200200;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
inline int read(){
	int x=0,f=1;char s=getchar();
	while (!isdigit(s)){if(s=='-')f=-1;s=getchar();}
	while (isdigit(s)){x=(x<<1)+(x<<3)+(s^48);s=getchar();}
	return x*f;
}
int q;
priority_queue<int>pq;
signed main(void){
	freopen("9.in","r",stdin);
	freopen("9.out","w",stdout);
	q=read();
	for (int i=1;i<=q;i++){
		int m=read();
		if (m==1){
			int k=read();
			pq.push(k);
		}
		else{
			if (pq.empty()){
				printf("-1\n");continue;
			}
			printf("%d\n",pq.top());pq.pop();
		}
	}
	return 0;
}
