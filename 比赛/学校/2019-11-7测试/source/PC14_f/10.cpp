#include<bits/stdc++.h>

int a[100][5];

signed main(void)
{
	freopen("10.in","r",stdin);
	freopen("10.out","w",stdout);
	
	int begin,end,ln=0,pos=0;
	
	std::cin>>begin>>end;
	for(int i=begin;i<=end;i++){
		a[ln][pos] = i;
		if(ln&1){ if(--pos < 0) {++ln;pos=0; }}
		else{ if(++pos >=5){ ++ln;pos=4; }}
}

for(int i=0;i</*=*/ln;i++){
for(int j=0;j<5;j++)std::cout<<a[i][j]<<' ';
std::cout<<std::endl;
}

	//std::cout<<ln<<' '<<pos<<std::endl;
	if((ln&1)==0) {for(int i=0;i<pos;i++) std::cout<<a[ln][i]<<' ';}
	else{ for(int i=pos+1;i<5;i++) std::cout<<a[ln][i]<<' ';}
	std::cout<<std::endl;
	return 0;
}
