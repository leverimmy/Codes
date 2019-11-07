#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 290;
double x;
double a[N];
int main(){
	freopen("11.in", "r", stdin);
	freopen("11.out", "w", stdout);
	for(int i=2; i<=280; i++){
		a[i]=a[i-1]+(double)1.0/(double)i;
	}
	while(scanf("%lf",&x)){
		if(x==0){
			break;
		}
		int pos=lower_bound(a+1, a+1+280, x)-a-1;
		printf("%d card(s)\n",pos);
	}
	return 0;
}

