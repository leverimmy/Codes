#include <bits/stdc++.h>
int n,k,a[105],f[105][105];
int calc(int l,int r){
	if (l>r)return 0;
	if (f[l][r]!=-1)return f[l][r];
	f[l][r]=1e9;
	int last=0;
	for(int i=1;i<=100;++i){
		int flag=0;
		for(int j=l;j<=r;++j)if(a[j]==i)flag=1;
		if (!flag)continue;
		std::vector<std::pair<int,int> >vec;vec.push_back(std::make_pair(l,l-1));
		for(int j=l;j<=r;++j){
			if (a[j]!=i)continue;
			int s=j;
			while (j<r&&a[j+1]==i)j++;
			vec.push_back(std::make_pair(s,j));
		}vec.push_back(std::make_pair(r+1,r));
		int g[105][8];
		std::memset(g,63,sizeof(g));
		g[0][0]=0;
		int len=vec.size()-1;
		int sum=0;
		for(int i=1;i<=len;++i){
			sum=vec[i].second-vec[i].first+1;
			for(int j=0;j<=k;++j){
				for(int l=i-1;l>=0;--l){
					g[i][j]=std::min(g[i][j],g[l][std::max(0,j-sum)]+calc(vec[l].second+1,vec[i].first-1));
				}//g[i][j]=std::min(g[i][j],g[i-1][j]+calc(vec[i-1].second+1,vec[i].second));
			//	if (l==1&&r==n)printf("%d ",g[i][j]);
			}//if (l==1&&r==n)printf("\n");
		}
		for(int j=0;j<=k;++j)f[l][r]=std::min(f[l][r],g[len][j]+(k-j));//if (l==1&&r==n)printf("->%d\n",f[l][r]);
	}//printf("f %d %d = %d\n",l,r,f[l][r]);
	return f[l][r];
}
			

int main(){
	freopen("zuma.in","r",stdin);
	freopen("zuma.out","w",stdout);
	std::memset(f,-1,sizeof(f));
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	printf("%d",calc(1,n));
	return 0;
}
