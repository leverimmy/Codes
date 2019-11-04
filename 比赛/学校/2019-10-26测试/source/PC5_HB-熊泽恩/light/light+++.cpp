#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define il inline

const int N = 1e5 + 10;

int n, m;
int a[N];

std::vector <int> vec[N];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int Binary_Search_Low(int rem, int val) {
	
	int l = 0, r = vec[rem].size() - 1, res;
	
	while(l < r) {
		int mid = l + r >> 1;
		if(vec[rem][mid] >= val)
			r = mid, res = mid;
		else
			l = mid + 1;
	}
	return res;
}

int Binary_Search_Hig(int rem,int val) {
	
	int l = 0, r = vec[rem].size() - 1, res;
	
	while(l < r) {
		int mid = l + r + 1 >> 1;
		if(vec[rem][mid] <= val)
			l = mid, res = mid;
		else
			r = mid - 1;
	}
	
	return res;
}

int main() {
	freopen("light.in", "r", stdin);
	freopen("light.out", "w", stdout);
	n = read(), m = read();
	if(n <= 1000) {
		for(rgi i = 1; i <= n; ++i)	a[i] = read();
		for(rgi i = 1; i <= m; ++i) {
			int l = read(), r = read(), p = read(), v = read(), res = 0;
			for(rgi j = l; j <= r; ++j)	res += (a[j] % p == v);
			printf("%d\n", res);
		}	return 0;
	}
	else {
		for(rgi i = 1; i <= n; ++i) a[i] = read();
		
		int l1 = read(), r1 = read(), p1 = read(), v1 = read();
		
		for(rgi i = 1; i <= n; ++i) vec[a[i] % p1].push_back(i);
		
		int low1 = Binary_Search_Low(v1, l1);
		int hig1 = Binary_Search_Hig(v1, r1);
		printf("%d\n", hig1 - low1 + 1);
		
		for(rgi i = 2; i <= m; ++i) {
			int l = read(), r = read(), p = read(), v = read();
			int low = Binary_Search_Low(v, l);
			int hig = Binary_Search_Hig(v, r);
			printf("%d\n", hig - low + 1);
		}
		return 0;
	}
	return 0;
}
/*
5 2
1 5 2 3 7
1 3 2 1
2 5 3 0

5 2
1 5 2 3 7
1 3 2 1
2 5 2 0

*/
