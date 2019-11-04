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
	srand(1);
	freopen("jump1.in","w",stdout);
	cout<<100<<" "<<15<<endl;
	for(int i=1;i<=100;i++)fa[i]=i;
	for(int i=1;i<=15;i++)
	{	
		int x=rand()%100,y=rand()%100;
		if(Get(x)==Get(y)){ i--; continue; }
		cout<<x<<" "<<y<<endl;
	}
	return 0;
}

