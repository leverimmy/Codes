#include<bits/stdc++.h>
using namespace std;
int n,s,nowx=1,nowy=1;
int ans[110][110];
int main(){
	freopen("16.in","r",stdin);
	freopen("16.out","w",stdout);
	cin>>n>>s;
	for(int i=n;i<n+s;++i){
		ans[nowx][nowy]=i;
		nowx++;
	}
	nowx--,nowy++;
	for(int i=n+s;i<n+s*2-1;++i){
		ans[nowx][nowy]=i;
		nowy++;
	}
	nowx--,nowy--;
	for(int i=n+s*2-1;i<n+s*3-2;++i){
		ans[nowx][nowy]=i;
		nowx--;
	}
	nowx++,nowy--;
	for(int i=n+s*3-2;i<n+s*4-4;++i){
		ans[nowx][nowy]=i;
		nowy--;
	}
	for(int i=1;i<s;++i){
		for(int j=1;j<s;++j){
			if(ans[i][j]){
				cout<<ans[i][j]<<' ';
			}
			else
				cout<<"   ";
		}
		cout<<ans[i][s]<<endl;
	}
	for(int i=1;i<s;++i)
		cout<<ans[s][i]<<' ';
	cout<<ans[s][s];
	return 0;
}
