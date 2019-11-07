#include<bits/stdc++.h>
using namespace std;
int k,ms[20]={0,1,2,15,16,12,14,3,5,13,7,10,4,8,11,6,9};
int row[10],col[10],ang1,ang2;
inline bool check(){
	memset(row,0,sizeof(row)),memset(col,0,sizeof(col));
	ang1=ang2=0;
	for(int i=1;i<=4;++i){
		for(int j=1;j<=4;++j)
			row[i]+=ms[(i-1)*4+j],col[i]+=ms[(j-1)*4+i];
	}
	ang1=ms[1]+ms[6]+ms[11]+ms[16];
	ang2=ms[4]+ms[7]+ms[10]+ms[13];
	if((row[1]==row[2])&&(row[2]==row[3])&&(row[3]==row[4])&&(row[4]==col[1])&&(col[1]==col[2])&&(col[2]==col[3])&&(col[3]==col[4])&&(col[4]==ang1)&&(ang1==ang2)&&())
		return true;
	return false;
}
int main(){
	cin>>k;
	
}
