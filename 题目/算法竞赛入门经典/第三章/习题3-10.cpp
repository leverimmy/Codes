#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

struct rectangle{
	int l,w;
}r[7];

bool operator!=(struct rectangle first,struct rectangle second){
	return((first.l != second.l) || (first.w != second.w));
}

bool cmp(struct rectangle first,struct rectangle second){
	if(first.l!=second.l)
		return first.l>second.l;
	else
		return first.w>second.w;
}

int main()
{
	while(scanf("%d %d %d %d %d %d %d %d %d %d %d %d",&r[1].l,&r[1].w,&r[2].l,&r[2].w,&r[3].l,&r[3].w,&r[4].l,&r[4].w,&r[5].l,&r[5].w,&r[6].l,&r[6].w)!=EOF)
	{
		for(int i=1;i<=6;i++)
		{
			if(r[i].l<r[i].w)
				swap(r[i].l,r[i].w);
		}
		sort(r+1,r+7,cmp);
		if(r[1]!=r[2] || r[3]!=r[4] || r[5]!=r[6])
		{
			printf("IMPOSSIBLE\n");
			continue;
		}
		if(r[1].l != r[3].l || r[1].w!=r[5].l || r[3].w != r[5].w)
			printf("IMPOSSIBLE\n");
		else
			printf("POSSIBLE\n");
	}
	return 0;
}