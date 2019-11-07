#include <bits/stdc++.h>
int f[7][100000],md[7];
int main(){
	freopen("19.in","r",stdin);
	freopen("19.out","w",stdout);
	int l,r;
	scanf("%d%d",&l,&r); 
	for(int i=1;i<=4;++i)scanf("%d",&md[i]);
	for(int i=1;i<=4;++i)f[i][1]=f[i][2]=1%md[i];
	for(int i=1;i<=r;++i){
		if (i!=1&&i!=2){
			for(int j=1;j<=4;++j)f[j][i]=(f[j][i-1]+f[j][i-2] )%md[j];
		}if (i<l)continue;
		int flag=1;
		for(int j=1;j<=4;++j)
			if (f[j][i]==0)flag=0;
		if (flag)printf("%d ",i); 
	}
	return 0;
}
