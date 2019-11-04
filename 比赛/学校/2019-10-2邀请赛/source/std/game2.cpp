#include<iostream>
#include<stdio.h>
int n,m;
#define MAX 1000
char mat[MAX][MAX];
int sx,sy,ex,ey;
int mark[MAX][MAX];
int top;
int q[500000][2];
int cos[MAX][MAX];

int another[500000][2];
using namespace std;
int dir[4][2] = {
	{-1, 0},
	{1, 0},
	{0,1},
	{0,-1}
};

void expend1(int from, int to){
	if(to - from +1 <= 0)return;
	int i,j;
	int x,y;
	for(i=from;i<=to;i++)
	{
		for(j=0;j<4;j++)
		{
			x = q[i][0] + dir[j][0];
			y = q[i][1] + dir[j][1];
			if(0<=x && x < n)
				if(0<=y && y < m)
					if(mark[x][y] == 0)
						
							if(mat[q[i][0]][q[i][1]] != mat[x][y]){
								q[top][0]=x;
								q[top][1]=y;
								mark[x][y]=1;
								top++;
							}
						
		}
	}
}

void BFS(int x,int y,char w){
	int s=0,t=0,f;
	another[t][0]=x,another[t][1]=y;
	int i;
	while(s<=t){
		
		for(i=0;i<4;i++)
		{
			x = another[s][0] + dir[i][0];
			y = another[s][1] + dir[i][1];
			
			if(0<=x && x < n)
				if(0<=y && y < m)
					if(mark[x][y] == 0)
						if(mat[x][y] == w){
							q[top][0]=x;
							q[top][1]=y;
							mark[x][y]=1;
							top++;
							t++;
							another[t][0]=x,another[t][1]=y;
						}
		}
		s++;
	}
}

			

			

void expend0(int from, int to){
	if(to - from +1 <= 0)return;
	int i,j;
	int x,y;
	for(i=from;i<=to;i++)
	{
		BFS(q[i][0], q[i][1], mat[q[i][0]][q[i][1]]);
	}
}





void search(){
	int s=0, e =-1;
	if(sx == ex && sy == ey){
		cout<<0<<endl;
		return;
	}
	mark[sx][sy]=1;
	q[top][0]=sx, q[top][1]=sy;
	top++;
	int step = 0;
	int f;
	expend0(0,0);
	if(mark[ex][ey]==1){
			cout<<0<<endl;
			return;
		}
	while(1){
		s = e + 1;
		
		e = top - 1;
		
		if(s > e)break;
		
		expend1(s,e);
		expend0(e+1, top-1);
		if(mark[ex][ey]==1){
			cout<<step + 1 <<endl;
			return;
		}
		step++;
	}
}





void process()
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			cin>>mat[i][j];
			mark[i][j]=0;
			cos[i][j]=-1;
		}
		cin>>sx>>sy>>ex>>ey;
		top=0;
		search();
}




int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	while(cin>>n>>m && !(n == 0 && m == 0))process();
}
