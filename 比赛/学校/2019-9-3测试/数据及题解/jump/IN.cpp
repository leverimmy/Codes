#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
int fa[100005]={0};
int Get(int x)
{
	if(x==fa[x])return x;
	return fa[x]=Get(fa[x]);
}
int main()
{	
	srand(time(NULL));
	freopen("jump10.in","w",stdout);
	int M=100000,N=10000;
	cout<<N<<" "<<M<<endl;
	for(int i=0;i<M;i++)fa[i]=i;
	for(int i=1;i<=N;i++)
	{	
		int x=rand()%M,y=rand()%M;
		//if(Get(x)==Get(y)){ i--; continue; }
		cout<<x<<" "<<y<<endl;
		//fa[Get(x)]=Get(y);
	}
	return 0;
}

