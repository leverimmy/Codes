#include<iostream>
#include<cstring>
#define MAXn 100002
#define MAXm 100002
using namespace std;
int n,m,cnt,k,i;
bool b[MAXn][2];
int main(){
	freopen("rush.in","r",stdin);
	freopen("rush.out","w",stdout);
	memset(b,true,sizeof(b));
	cin>>n>>m;
	for(i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		b[x][0]=0;
		b[y][1]=0;
	}
	if(n%2==0) k=n/2;
	else       k=n/2+1;
	for(i=1;i<=k;i++){
		if(i==k&&n%2!=0){
			if(b[i][0]!=0||b[i][1]!=0) cnt++;
			break;
		} 
		if(b[i][0]!=0){
			b[i][0]=0;
			cnt++;
		}
		if(b[n-i+1][1]!=0){
			b[n-i+1][1]=0;
			cnt++;
		}
		if(b[n-i+1][0]!=0){
			b[n-i+1][0]=0;
			cnt++;
		}
		if(b[i][1]!=0){
			b[n-i+1][1]=0;
			cnt++;
		}
	}
	int ans=cnt;
	cout<<ans;
	return 0;
}
