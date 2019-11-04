#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define MAXN 30
#define ii pair<int,int>

char s[10];
int n,m,go[4][4],sx1,sx2,sy1,sy2;
bool book[MAXN][MAXN][MAXN][MAXN];
char a[MAXN][MAXN];
//nswe

struct data{
	ii P,H;
	int cnt;
};

void premake(){
	go[0][0]=-1,go[0][1]=0,go[1][0]=1,go[1][1]=0;
	go[2][0]=0,go[2][1]=-1,go[3][0]=0,go[3][1]=1;
	for(int i=0;i<4;i++){
		if(s[i]=='W') go[i][2]=0,go[i][3]=-1;
		if(s[i]=='E') go[i][2]=0,go[i][3]=1;
		if(s[i]=='N') go[i][2]=-1,go[i][3]=0;
		if(s[i]=='S') go[i][2]=1,go[i][3]=0;
	}
}

void bfs(){
	queue <data> Q;
	Q.push((data){ii(sx1,sy1),ii(sx2,sy2),0});
	book[sx1][sy1][sx2][sy2]=true;
	while(!Q.empty()){
		data cur=Q.front();Q.pop();
		//printf("%d %d %d %d\n",cur.P.first,cur.P.second,cur.H.first,cur.H.second);
		if(cur.cnt<255){
			for(int i=0;i<4;i++){
				ii P1=ii(cur.P.first+go[i][0],cur.P.second+go[i][1]);
					if(P1.first<1 || P1.first>n || P1.second<1 || P1.second>m) continue;
					if(a[P1.first][P1.second]=='!' || a[P1.first][P1.second]=='#') continue;
				ii H1=ii(cur.H.first+go[i][2],cur.H.second+go[i][3]);
					if(H1.first<1 || H1.first>n || H1.second<1 || H1.second>m) continue;
					if(a[H1.first][H1.second]=='!') continue;
					if(a[H1.first][H1.second]=='#') H1=cur.H;
				if((P1==cur.H && H1==cur.P) || H1==P1){
					cout<<cur.cnt+1;
					return;
				}
				if(!book[P1.first][P1.second][H1.first][H1.second]){
					book[P1.first][P1.second][H1.first][H1.second]=true;
					Q.push((data){P1,H1,cur.cnt+1});
				}
			}
		}
	}
	cout<<"Impossible";
}

int main()
{
    freopen("escape.in","r",stdin);
    freopen("escape.out","w",stdout);
    scanf("%d %d\n",&n,&m);
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    		scanf("%c",&a[i][j]);
    		if(a[i][j]=='P') sx1=i,sy1=j;
    		if(a[i][j]=='H') sx2=i,sy2=j;
    	}
    	getchar();
    }
    scanf("%s",s);
    premake();
    bfs();
    return 0;
}
