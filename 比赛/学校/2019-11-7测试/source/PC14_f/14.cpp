#include<bits/stdc++.h>

bool book[6];
int target[]={1,2,-1,0,1};
int rank[5];

bool Check(void){
	if(*rank != 5) return false;
	if(rank[4]==2 || rank[4]==3) return false;
	if(*rank+*(rank+1)!=7) return false;
	if(*(rank+1)+*(rank+2)!=3) return false;
	if(rank[3]==3)if(rank[4]==4) return true;
	else rank[1]--;
	else return false;
	return false;
}
void Dfs(const int& nowAt){
	if(nowAt >= 5){
		if(Check()){ for(int i=0;i<5;i++) std::cout<<rank[i]<<' '; std::cout<<std::endl; exit(0); }
	}
	
	for(int i=1;i<=5;i++)
		if(!book[i]){
			book[i] = true; rank[nowAt] = i;
			Dfs(nowAt+1);
			book[i] = false;
		}
}

signed main(void)
{
	freopen("14.out","w",stdout);
	
	Dfs(0);
	for(int i=0;i<5;i++) std::cout<<rank[i]<<' ';
	std::cout<<std::endl;
	return 0;
}
