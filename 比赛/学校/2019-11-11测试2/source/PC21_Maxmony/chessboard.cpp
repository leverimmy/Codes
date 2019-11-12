#include<bits/stdc++.h>
using namespace std;
int col[3510][105][105],now[55][55];
int n,k,m,t1,t2,t3,t4,t5,vrsncnt,vrsn;
string oprtn;
inline void upd(int c,int stx,int sty,int edx,int edy){
	int xlen=edx-stx+1,ylen=edy-sty+1;
//	cout<<"stx:"<<stx<<' '<<"sty:"<<sty<<e_ndl;
	for(int i=1;i<=xlen;i+=2){
		for(int j=1;j<=ylen;j+=2)
			now[i+stx-1][j+sty-1]=c;
	}
	for(int i=2;i<=xlen;i+=2){
		for(int j=2;j<=ylen;j+=2){
			now[i+stx-1][j+sty-1]=c;
		}
	}
	return;
}
inline void sav(){
	vrsncnt++;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)
			col[vrsncnt][i][j]=now[i][j];
	}
	return;
}
inline void ld(int tgtvrsn){
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)
			now[i][j]=col[tgtvrsn][i][j];
	}
	return;
}
int main(){
	freopen("chessboard.in","r",stdin);
	freopen("chessboard.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>k>>m;  
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			now[i][j]=1,col[0][i][j]=1;
	while(m--){
		cin>>oprtn;
//		cout<<oprtn<<endl;
		switch(oprtn[0]){
			case 'P':
				cin>>t1>>t2>>t3>>t4>>t5;
//				cout<<t1<<' '<<t2<<' '<<t3<<' '<<t4<<' '<<t5<<endl;
				upd(t1,t2+1,t3+1,t4+1,t5+1);
				break;
			case 'S':
				sav();
				break;
			case 'L':
				cin>>t1;
				ld(t1);
				break;
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)
			cout<<now[i][j]<<' ';
		cout<<endl;
	}
	return 0;
}
