#include <bits/stdc++.h>

using namespace std;

#define maxn 200005

int n;
struct h{
	double x,y, r;
};
h a[maxn];

bool cmp(h t, h p){
	return t.x<p.x;
}

inline bool check(int cur, double t){
	if(t>a[cur].r) return false; 
	for(int i = 1; i <= n; i++){
		if(i==cur) continue;
		double dx = a[i].x-a[cur].x;
		double dy = a[i].y-t;
		double td = sqrt(dx*dx+dy*dy);
		if(t+a[i].y > td) return false;
	}
	return true;
}

inline double ef(int cur){
	double l = 0;
	double r = a[cur].r;
	
	for(int i = 1; i <= 75; i++){
		double mid = (l+r)/2;
		if(check(cur, mid)) l = mid;
		else r = mid;
	}
	
	return r;
}

int main()
{
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>a[i].x>>a[i].r;
		a[i].y = 0;
	}
	
	sort(a+1, a+1+n, cmp);
	
	for(int i = 1; i <= n; i++){
		a[i].y = ef(i);
		cout<<fixed<<setprecision(3)<<a[i].y<<endl;
	}
	
	return 0;
}
/*
3
0 9
8 1
13 7
*/
