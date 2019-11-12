#include <bits/stdc++.h>

using namespace std;
const int N = 1010;
const int M = 100010;
int n,k,m,q;
char str[10];
struct opt{
	int c,x1,y1,x2,y2;
}tmp[M],op[M];
vector<int> v;
int a[M];
int b[N][N];
void update(int c,int x1,int y1,int x2,int y2){
	for(int i=x1; i<=x2; i+=2){
		for(int j=y1; j<=y2; j+=2){
			b[i][j]=c;
		}
	}
	for(int i=x1+1; i<=x2; i+=2){
		for(int j=y1+1; j<=y2; j+=2){
			b[i][j]=c;
		}
	}
}
int main(){
	freopen("chessboard.in", "r", stdin);
	freopen("chessboard.out", "w", stdout);
	scanf("%d%d%d",&n,&k,&m);
	for(int i=1; i<=m; i++){
		scanf("%s",str);
		if(str[0]=='P'){
			scanf("%d%d%d%d%d",&tmp[i].c,&tmp[i].x1,&tmp[i].y1,&tmp[i].x2,&tmp[i].y2);
		}
		else if(str[0]=='S'){
			tmp[i].c=-1;
			v.push_back(i);
		}
		else if(str[0]=='L'){
			int x;
			scanf("%d",&x);
			a[i]=v[x-1];
		}
	}
	int now=m;
	while(now>0){
		if(a[now]==0){
			if(tmp[now].c!=-1){
				op[++q]=tmp[now];
			}
			now--;
		}
		else{
			now=a[now]-1;
		}
	}
	reverse(op+1, op+1+q);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			b[i][j]=1;
		}
	}
	for(int i=1; i<=q; i++){
		update(op[i].c, op[i].x1+1, op[i].y1+1, op[i].x2+1, op[i].y2+1);
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			printf("%d ",b[i][j]);
		}
		printf("\n");
	}
	return 0;
}

