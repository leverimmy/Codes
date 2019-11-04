#include <bits/stdc++.h>
#define rgi register int
#define ll long long
#define il inline

using namespace std;

const int N = 3e5 + 10;

int n, ans;
int a[N], cnt[N], s[N];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

bool Check2(int x) {
	
}

bool Check1(int x, int cur_k) {// eat cur_k at once, use x times
	if(s[n] > cur_k * x)	return 0; 
	int l2 = 1, r2 = s[n] / cur_k, ans2;
	while(l2 < r2) {// binary search the answer to 
		int mid2 = l2 + r2 >> 1;
		if(Check2(mid2))
			mid2 = 
		else
			mid2 = 
		ans2 = mid2;
	}
	
	return ans2;//
}

int main() {
	n = read();
	for(rgi i = 1; i <= n; ++i) a[i] = read(), cnt[a[i]]++;
	sort(a + 1, a + n + 1);
	sort(cnt + 1, cnt + n + 1, greater<int>());
	for(rgi i = 1; i <= n; ++i)	s[i] = s[i - 1] + cnt[i];
	for(rgi i = 1; i <= n; ++i) {
		int l1 = 1, r1 = n;
		while(l1 < r1) {// binary search the answer to (eat i at once)
			int mid1 = l1 + r1 >> 1;
			if(Check1(mid1, i))
				l1 = mid1;
			else
				r1 = mid - 1;
			ans = mid1;
		}
		printf("%d\n", ans);
	}
	return 0;
}

