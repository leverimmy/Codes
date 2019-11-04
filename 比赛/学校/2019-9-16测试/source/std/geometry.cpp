#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 410

int n,m,q,fa[MAXN],ans;
bool flag;

int find(int x){
	return fa[x]==x ? x : fa[x]=find(fa[x]);
}

void merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx!=fy){
		if(fx<fy) swap(fx,fy);
		fa[fx]=fy;
	}
}

void solve(char type,int x,int y){
	if(type=='p') merge(x,y),merge(x+n,y+n);
	else merge(x,y+n),merge(x+n,y);
}

void solve_query(){
	char c;int x,y;
	scanf("%c%d %c%d\n",&c,&x,&c,&y);
	if(find(x)==find(y)) cout<<"Parallel."<<endl;
	else if(find(x)==find(y+n)) cout<<"Vertical."<<endl;
	else cout<<"No idea."<<endl;
}

int main()
{
    freopen("geometry.in","r",stdin);
    freopen("geometry.out","w",stdout);
    scanf("%d %d %d\n",&n,&m,&q);flag=false;
    for(int i=1;i<=2*n;i++) fa[i]=i;
    for(int i=1;i<=m;i++){
    	char c,type;int x,y;
    	scanf("%c%d %c %c%d\n",&c,&x,&type,&c,&y);
    	solve(type,x,y);
    }
    for(int i=1;i<=n;i++)
    	if(find(i)==find(i+n))
    		flag=true;
    if(flag){
    	cout<<"There must be something wrong!";
    	return 0;
    }
    for(int i=1;i<=n;i++)
    	for(int j=i+1;j<=n;j++)
    		if(find(i)==find(j))
    			ans++;
    cout<<ans<<endl;
    for(int i=1;i<=q;i++) solve_query();
    return 0;
}