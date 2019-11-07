#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int n,ans;
int main(){
	freopen("12.in", "r", stdin);
	freopen("12.out", "w", stdout);
	scanf("%d",&n);
	for(int i=1; i*i<=n; i++){
		if((n%i)==0){
			if(i*i==n){
				ans++;
			}
			else{
				ans+=2;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}

