#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 15;
const int M = 110;
int n,m;
char a[N][M];
int ans[M];
int cnt[5];
int work(){
	int maxc=0,mark=0;
	for(int i=1; i<=4; i++){
		if(cnt[i]>maxc){
			maxc=cnt[i];
			mark=i;
		}
		else if(cnt[i]==maxc){
			mark=i;
		}
	}
	return mark;
}
int main(){
	freopen("2.in", "r", stdin);
	freopen("2.out", "w", stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%s", a[i]+1);
	}
	m=strlen(a[1]+1);
	for(int i=1; i<=m; i++){
		memset(cnt, 0, sizeof cnt);
		for(int j=1; j<=n; j++){
			if(a[j][i]=='A'){
				cnt[1]++;
			}
			else if(a[j][i]=='C'){
				cnt[2]++;
			}
			else if(a[j][i]=='G'){
				cnt[3]++;
			}
			else if(a[j][i]=='T'){
				cnt[4]++;
			}
		}
		ans[i]=work();
	}
	for(int i=1; i<=m; i++){
		if(ans[i]==1){
			printf("A");
		}
		else if(ans[i]==2){
			printf("C");
		}
		else if(ans[i]==3){
			printf("G");
		}
		else if(ans[i]==4){
			printf("T");
		}
	}
	return 0;
}

