#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define il inline

const int N = 1e5 + 10;

int n, m, flag;
int a[N];

std::vector <int> vec[(int)1e4 + 10];

struct QUERY {
	int l, r, p, v, id;
} query[N];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int write(int x) {
	if(x < 0)	putchar('-'), x = -x;
	int tmp = x / 10;
	if(tmp)	write(tmp);
	putchar(x - (tmp << 1) - (tmp << 3) + '0');
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
	for(rgi i = 1; i <= n; ++i)	a[i] = read();
	for(rgi i = 1; i <= m; ++i) 
		query[i].l = read(), query[i].r = read(), 
		query[0].p = query[i].p = std::min(10001, read()), query[i].v = read(),
		query[i].id = i, flag |= query[i].p != query[i - 1].p;
	
	if(flag) {
		for(rgi i = 1; i <= m; ++i) {
			int res = 0;
			for(rgi j = query[i].l; j <= query[i].r; ++j)	res += (a[j] % query[i].p == query[i].v);
//			printf("%d\n", res);
			write(res), putchar('\n');
		}	return 0;
	}
	
	else {
		for(rgi i = 1; i <= n; ++i) vec[a[i] % query[1].p].push_back(i);
		
		for(rgi i = 1; i <= m; ++i) {
			int low = Binary_Search_Low(query[i].v, query[i].l);
			int hig = Binary_Search_Hig(query[i].v, query[i].r);
//			printf("%d\n", hig - low + 1);
			write(hig - low + 1), putchar('\n');
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
