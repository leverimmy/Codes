#include<bits/stdc++.h>
using namespace std;

const int Maxn=1<<30;

int n,m,ansmap[1010][1010][2],pmap[1010][1010];

int main(){
	freopen("lemouse.in","r",stdin);
	freopen("lemouse.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&pmap[i][j]);
		}
	}
	ansmap[1][1][0]=ansmap[1][1][1]=pmap[1][1]+pmap[1][2]+pmap[2][1];
	for(int i=2;i<=n;i++){
		ansmap[i][1][0]=ansmap[i-1][1][0]+pmap[i][2]+pmap[i+1][1];
		ansmap[i][1][1]=Maxn;
	}
	for(int j=2;j<=m;j++){
		ansmap[1][j][1]=ansmap[1][j-1][1]+pmap[1][j+1]+pmap[2][j];
		ansmap[1][j][0]=Maxn;
	}
	for(int i=2;i<=n;i++){
        for(int j=2;j<=m;j++){
            ansmap[i][j][0]=min(ansmap[i-1][j][0]+pmap[i][j-1],ansmap[i-1][j][1])+pmap[i][j+1]+pmap[i+1][j];
            ansmap[i][j][1]=min(ansmap[i][j-1][0],ansmap[i][j-1][1]+pmap[i-1][j])+pmap[i][j+1]+pmap[i+1][j];
        }
    }
	cout<<min(ansmap[n][m][0],ansmap[n][m][1]);
}
