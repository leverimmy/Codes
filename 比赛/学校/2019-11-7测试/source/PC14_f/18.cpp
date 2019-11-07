#include<bits/stdc++.h>

int up[3050];
int FindTop(const int nowAt){
	return up[nowAt]==nowAt ? nowAt : (up[nowAt] = FindTop(up[nowAt]));
}

signed main(void)
{
	freopen("18.in","r",stdin);
	freopen("18.out","w",stdout);
	
	int totSet,totMerge,fr,to;
	
	scanf("%d%d", &totSet,&totMerge);
	for(int i=0;i<=totSet;i++) up[i] = i;
	while(totMerge--){
		scanf("%d%d", &fr,&to);
		fr = FindTop(fr); to = FindTop(to);
		if(fr != to){
			--totSet;
			up[fr] = to;
		}
	}
	
	printf("%d\n", totSet);
	
	return 0;
}
