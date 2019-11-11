#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int NMax=65535;
int N;
vector<int> E[NMax],E2[NMax];
int fas[NMax][16],depth[NMax];
int list[NMax];
int cnt[NMax];
int LCA(int a,int b){
	if (depth[a]>depth[b])swap(a,b);
	int d=depth[b]-depth[a];
	for (int i=15;i>=0;i--)
		if (d&(1<<i))b=fas[b][i];
	if (b==a)return a;
	for (int i=15;i>=0;i--)
		if (fas[a][i]!=fas[b][i])
			a=fas[a][i],b=fas[b][i];
	return fas[a][0];
}
int main()
{
  freopen ("catas.in" , "r", stdin);
  freopen ("catas.out", "w", stdout);
	scanf("%d",&N);
	N++;
	for (int i=1;i<N;i++){
		int x;
		while (scanf("%d",&x),x)
			E[i].push_back(x),E2[x].push_back(i);
		if (E[i].size()==0)
			E[i].push_back(0),E2[0].push_back(i);
	}
	for (int i=0;i<N;i++)cnt[i]=E[i].size();
	list[0]=0;
	for (int i=0,lc=1;i<N;i++){
		int x=list[i];
		for (int j=0;j<(int)E2[x].size();j++){
			int y=E2[x][j];
			if (!--cnt[y]){
				list[lc++]=y;
			}
		}
	}
	depth[0]=0;
	for (int i=0;i<16;i++)fas[0][i]=0;
	for (int i=1;i<N;i++){
		int x=list[i];
		int u=-1;
		for (int j=0;j<(int)E[x].size();j++){
			int y=E[x][j];
			if (u==-1)u=y;
			else u=LCA(u,y);
		}
		depth[x]=depth[u]+1;
		fas[x][0]=u;
		for (int i=1;i<16;i++)
			fas[x][i]=fas[fas[x][i-1]][i-1];
	}
	for (int i=0;i<N;i++)cnt[i]=1;
	for (int i=N-1;i>=0;i--){
		int x=list[i];
		cnt[fas[x][0]]+=cnt[x];
	}
	for (int i=1;i<N;i++)
		printf("%d\n",cnt[i]-1);
	return 0;
}

