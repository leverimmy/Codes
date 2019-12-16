#include<iostream>
#include<cstdio>
using namespace std;
int n,m,p;
int e[5010][5010];
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>n>>m;
	int a,b,c;
	for(int i=1;i<=m;i++){
		cin>>a>>b>>c;
		e[a][b]=c;
		e[b][a]=c;
	}
	return 0;
}
