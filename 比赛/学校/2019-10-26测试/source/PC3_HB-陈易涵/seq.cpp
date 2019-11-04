#include <bits/stdc++.h>

using namespace std;

#define ll long long

long long a1, a2;
map<int, int> mp;
map<int, int> mp2;

int main()
{
	freopen("seq.in", "r", stdin);
	freopen("seq.out", "w", stdout);
	cin>>a1>>a2;
	if(a1<a2){
		ll t = a1;
		a1 = a2;
		a2 = t;
	}
	
	if(a1%a2==0){
		cout<<(a1/a2)+1<<endl;
		return 0;
	}
	
	if(a1<=100000){
		ll ans = 0;
		ll x1 = a1, y1 = a2, now1;
		for(int i = 1; i <= 100003; i++){
			if(i==1) now1 = a1;
			if(i==2) now1 = a2;
			if(i>=3){
				now1 = abs(x1-y1);
				x1 = y1;
				y1 = now1;
			} 
			if(mp[now1]==0){
				mp[now1] = 1;
				ans++;
			}
			if(now1==0) break;
		}
		
		cout<<ans<<endl;
		
		return 0;
	}
	
	ll cnt = 0;
	ll x = a1, y = a2, now;
	for(ll i = 1; i <= 1e5; i++){
			if(i==1) now = a1;
			if(i==2) now = a2;
			if(i>=3){
				now = abs(x-y);
				if(now%y==0){
					cout<<cnt+now/y<<endl;
					break;
				}
				
				x = y;
				y = now;
			} 
			
			if(mp2[now]==0){
				mp2[now] = 1;
				cnt++;
			}
			if(now==0) break;
	}
	
	return 0;
}
