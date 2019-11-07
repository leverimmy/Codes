#include<bits/stdc++.h>

int sy[11][11];

signed main(void)
{
	freopen("16.in","r",stdin);
	freopen("16.out","w",stdout);
	
	int begin,siz;	
	
	std::cin>>begin>>siz;
	for(int i=0;i<siz;i++) sy[i][0] = begin++;
	for(int i=1;i<siz;i++) sy[siz-1][i] = begin++;
	for(int i=siz-2;i>=0;i--) sy[i][siz-1] = begin++;
	for(int i=siz-2;i>0;i--) sy[0][i] = begin++;
	
	for(int i=0;i<siz;i++){
		for(int j=0;j<siz;j++){
			if(sy[i][j] == 0) printf("  ");
			else printf("%d", sy[i][j]);
			putchar(' ');
		} putchar('\n');
	}
	
	return 0;
}
