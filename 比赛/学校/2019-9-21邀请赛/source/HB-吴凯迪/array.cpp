#include<bits/stdc++.h>

const int MAXN = 1e5+10;
const int sqr = 350;

int a[MAXN];
int D[sqr+10][MAXN];

signed main(void)
{
	freopen("array.in","r",stdin);
	freopen("array.out","w",stdout);
	
	int totNums,totOptn;
	int p,k,ans;
	
	scanf("%d", &totNums); 
	for(int i=1;i<=totNums;i++) scanf("%d", a+i);
	
	for(int i=0;i<=sqr;i++)
		for(int j=totNums;j>0;--j){
			if(j+a[j]+i > totNums) D[i][j]=1;
			else D[i][j]=D[i][j+a[j]+i]+1;
		}
	
	scanf("%d", &totOptn);
	while(totOptn--){
		scanf("%d%d", &p,&k);
		
		if(k <= sqr) printf("%d\n",D[k][p]);
		else {
			for(ans=0;p<=totNums;ans++) p = p+a[p]+k;
			printf("%d\n",ans);
		}
	}
	
	return 0;
}
