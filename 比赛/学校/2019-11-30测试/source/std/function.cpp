#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<map>
using namespace std;
map<int,int> a[100010];
int len,n;
typedef map<int,int>::iterator poi;
int ok(int p,int x,int y){
	if (a[p].empty()) return true;
	poi i = a[p].lower_bound(x);
	if (i == a[p].begin()) return false;
	--i;
	if (i->second >= y) return false;
	return true;
}
void Add_Node(int p,int x,int y){
	if (!a[p].empty()){
		poi i = a[p].lower_bound(x),j = i;--j;
		if (i != a[p].end() && (i->first == x && i->second <= y)) return;
		if (i != a[p].begin() && (j->second == y)) return;
		j = i;
		while ((j != a[p].end()) && (j->second >= y)) ++j;
		a[p].erase(i,j);
	}
	a[p][x] = y;
}
void insert(int x,int y){
	if (ok(len,x,y)){
		Add_Node(++len,x,y);return;
	}
	int l = 0,r = len,mid,ans = 0;
	while (l < r){
		mid = (l+r)>> 1;
		if (ok(mid,x,y)) ans = max(ans,mid),l = mid+1;
		else r = mid;
	}
	if (ans + 1 <= len && !ok(ans+1,x,y))
		Add_Node(ans+1,x,y);
}
int main(){
	freopen("function.in","r",stdin);
	freopen("function.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1;i<=n;i++){
		int x,y;scanf("%d%d",&x,&y);insert(x,y);
	}
	printf("%d\n",len);
	return 0;
}
