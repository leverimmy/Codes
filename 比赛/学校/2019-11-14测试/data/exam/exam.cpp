#include <bits/stdc++.h>
using namespace std;

#define MAXN 2000010

vector <int> v;
map <int,int> M;
int cnt,n,a[MAXN],b[MAXN];
int s[5],nodecnt[MAXN],edgecnt[MAXN],fa[MAXN];
int fst[MAXN],sec[MAXN],ans,book[MAXN];

int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}

bool cmp(const int &x,const int &y){
	return x>y;
}

void merge(int x,int y){
	int fx=find(x);
	int fy=find(y);
	if(fx==fy) return;
	fa[fx]=fy;
	nodecnt[fy]+=nodecnt[fx];
	s[1]=fst[fx],s[2]=sec[fx],s[3]=fst[fy],s[4]=sec[fy];
	sort(s+1,s+5,cmp);
	fst[fy]=s[1],sec[fy]=s[2];
}

int main(){
	freopen("exam0.in","r",stdin);
	freopen("exam0.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i],&b[i]);
		v.push_back(a[i]);
		v.push_back(b[i]);
	}
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++){
		if(M.find(v[i])==M.end()){
			M[v[i]]=++cnt;
			book[cnt]=v[i];
		}
	}
	for(int i=1;i<=cnt;i++){
		fa[i]=i,nodecnt[i]=1;
		fst[i]=i;
	}
	for(int i=1;i<=n;i++){
		a[i]=M[a[i]],b[i]=M[b[i]];
		merge(a[i],b[i]);
	}
	for(int i=1;i<=n;i++)
		edgecnt[find(a[i])]++;
	for(int i=1;i<=cnt;i++)if(find(i)==i){
		if(nodecnt[i]<edgecnt[i]){
			cout<<-1;
			return 0;
		}else if(nodecnt[i]==edgecnt[i]){
			ans=max(ans,fst[i]);	
		}else{
			ans=max(ans,sec[i]);
		}
	}	
	cout<<book[ans];
	return 0;
}
