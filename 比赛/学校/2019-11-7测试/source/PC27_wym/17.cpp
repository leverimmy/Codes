#include<bits/stdc++.h>
using namespace std;
int n;
char qwq[100010];
inline void outp(){
	for(int i=1;i<=n;++i)
		putchar(qwq[i]);
}
void rev(int l,int r){
	if(r-l+1<=1){
		return;
	}
	swap(qwq[l],qwq[r]);
	outp();
	putchar('\n');
	rev(l+1,r-1);
}
int main(){
	freopen("17.in","r",stdin);
	freopen("17.out","w",stdout);
	scanf("%d",&n);
	scanf("%s",qwq+1);
	rev(1,n);
	putchar('\n'); 
	outp();
}
