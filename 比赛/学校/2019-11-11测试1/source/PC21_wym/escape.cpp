#include<bits/stdc++.h>
using namespace std;
int midd,maxx=1010,minn=0,n,m,stx,sty,edx,edy,l[510][510];
char mp[510][510];
bool vis[510][510];
struct pos{
	int x,y;
}mv[5];
struct status{
	int x,y,len;
};
vector<pos>adv;
inline void init(){
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			mp[i][j]='.',l[i][j]=-1;
	for(int i=0;i<=m+1;++i)
		l[0][i]=0x3f3f3f3f,l[n+1][i]=0x3f3f3f3f;
	for(int i=0;i<=n+1;++i)
		l[i][0]=0x3f3f3f3f,l[i][m+1]=0x3f3f3f3f;
	mp[stx][sty]='V',mp[edx][edy]='J';
	for(int i=0;i<adv.size();++i)
		mp[adv[i].x][adv[i].y]='+';
}
inline void proc(int len){
	init();
	queue<status>q;
	for(int i=0;i<adv.size();++i){
		q.push((status){adv[i].x,adv[i].y,len}),
		l[adv[i].x][adv[i].y]=0x3f3f3f3f;
	}
	while(!q.empty()){
		status now=q.front();
		q.pop();
		if(!now.len)
			continue;
		for(int i=1;i<=4;++i){
			if(mp[now.x+mv[i].x][now.y+mv[i].y]=='.'&&l[now.x+mv[i].x][now.y+mv[i].y]<now.len)
			{
				mp[now.x+mv[i].x][now.y+mv[i].y]='+',
				l[now.x+mv[i].x][now.y+mv[i].y]=now.len-1,
				q.push((status){now.x+mv[i].x,now.y+mv[i].y,now.len-1});
			}
		}
	}
}
inline bool findpath(){
	queue<pos>q;
	q.push((pos){stx,sty});
	memset(vis,false,sizeof(vis));
	for(int i=0;i<=m+1;++i)
		vis[0][i]=true,vis[n+1][i]=true;
	for(int i=0;i<=n+1;++i)
		vis[i][0]=true,vis[i][m+1]=true;
	vis[stx][sty]=true;
	while(!q.empty()){
		pos now=q.front();
		if(now.x==edx&&now.y==edy)
			return true;
		q.pop();
		for(int i=1;i<=4;++i)
			if(!vis[now.x+mv[i].x][now.y+mv[i].y]&&mp[now.x+mv[i].x][now.y+mv[i].y]!='+'){
				vis[now.x+mv[i].x][now.y+mv[i].y]=true,
				q.push((pos){now.x+mv[i].x,now.y+mv[i].y});
			}
	}
	return false;
}
int main(){
	freopen("escape.in","r",stdin);
	freopen("escape.out","w",stdout);
	mv[1]=(pos){-1,0},
	mv[2]=(pos){0,1},
	mv[3]=(pos){1,0},
	mv[4]=(pos){0,-1};
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j){
			cin>>mp[i][j];
			if(mp[i][j]=='+')
				adv.push_back((pos){i,j});
			else if(mp[i][j]=='V')
				stx=i,sty=j;
			else if(mp[i][j]=='J')
				edx=i,edy=j;
		}
	while(minn<maxx){
		midd=(maxx+minn)>>1;
		proc(midd);
		if(findpath())
			minn=midd+1;
		else
			maxx=midd;
	}
	cout<<minn<<endl;
	return 0;
}
