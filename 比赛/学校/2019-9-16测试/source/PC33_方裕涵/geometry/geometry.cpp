#include <iostream>
using namespace std;
#define MAXN 404
int n,m,q,fa[MAXN],cnt,b[MAXN],h;
bool flag;
int find(int x) {
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
void join(int x,int y) {
	int p1=find(x),p2=find(y);
	if(p1!=p2) fa[p2]=p1;
}

void read(char t,int x,int y) {
	if(t=='p') {
		join(x,y);
		join(x+n,y+n);
	} else {
		join(x,y+n);
		join(x+n,y);
	}
}

bool judge(int x,int y) {
	int p1=find(x),p2=find(y);
	if(p1==p2) return 1;
	else return 0;
}
int main() {
	freopen("geometry.in","r",stdin);
	freopen("geometry.out","w",stdout);
	scanf("%d %d %d\n",&n,&m,&q);
	flag=false;
	for(int i=1; i<=2*n; i++) fa[i]=i;
	for(int i=1; i<=m; i++) {
		char c,t;
		int x,y;
		scanf("%c%d %c %c%d\n",&c,&x,&t,&c,&y);
		read(t,x,y);
	}
	for(int i=1; i<=n; i++)
		if(find(i)==find(i+n)) {
			flag=true;
			break;
		}
	if(flag) {
		cout<<"There must be something wrong!";
		return 0;
	}
	for(int i=1; i<=n; i++)
		for(int j=i+1; j<=n; j++)
			if(find(i)==find(j))
				cnt++;
	int ans=cnt;
	for(int i=1; i<=q; i++) {
		int x,y;
		scanf("%d%d\n",&x,&y);
		if(judge(x,y)) b[++h]=1;
		else if(judge(x,y+n)) b[++h]=0;
		else b[++h]=2;
	}
	cout<<ans<<endl;
	for(int i=1; i<=h; i++)
		if(b[i]==1) cout<<"Parallel."<<endl;
		else if(b[i]==0) cout<<"Vertical."<<endl;
		else cout<<"No idea."<<endl;
	return 0;
}
