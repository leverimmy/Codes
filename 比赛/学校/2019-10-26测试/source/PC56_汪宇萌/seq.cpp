#include<bits/stdc++.h>
using namespace std;
long long a1,a2,now,last,tmp;
//bool vis[1000010];
//map<pair<long long,long long>,bool>mp;
long long ans;
void gcd(long long x,long long y){
	if(!y)
		return;
	ans+=x/y;
	gcd(y,x%y);
}
int main(){
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	cin>>last>>now;
	if(last==0&&now==0){
		cout<<1;
		return 0;
	}
	if(last<now)
		swap(last,now);
	gcd(last,now);
	cout<<ans+1;
	return 0; 
}
//3 11 8 3 5 2 3 1 2 1 1 0 1 1
