#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int oo = 0x3f3f3f3f;
const int N = 1e5 + 10;

int n, m;

std::deque <int> dq, tmp;

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	freopen("dance.in", "r", stdin);
	freopen("dance.out", "w", stdout);
	n = read(), m = read();
	if(n <= 5000) {
		for(rgi i = 1; i <= n; ++i) dq.push_back(0);
		for(rgi i = 1; i <= m; ++i) {
			int opt = read(), k, b, s, id, ans = oo, ans_id;
			switch(opt) {
				case 1:
					k = read();
					for(rgi j = 1; j <= k; ++j) dq.push_front(0);
					break;
				case 2:
					k = read();
					for(rgi j = 1; j <= k; ++j) dq.push_back(0);
					break;
				case 3:
					b = read(), s = read();
					while(!dq.empty()) {
						tmp.push_back(dq.front());
						dq.pop_front();
					}
					id = 1;
					while(!tmp.empty()) {
						dq.push_back(tmp.front() + b + s * (id - 1));
						id++;
						tmp.pop_front();
					}
					break;
			}
			tmp.clear(), id = 1;
			while(!dq.empty()) {
				tmp.push_back(dq.front());
				if(dq.front() < ans) ans = dq.front(), ans_id = id;
				dq.pop_front();
				id++;
			}
			printf("%d %d\n", ans_id, id);
			while(!tmp.empty()) {
				dq.push_back(tmp.front());
				tmp.pop_front();
			}
		}
		return 0;
	}
//	else {
//		Build();
//		for(rgi i = 1; i <= m; ++i) {
//			int opt = read();
//			switch(opt) {
//				case 1:
//					k = read();
//					Add_Front(k);
//				case 2:
//					k = read();
//					Add_Back(k);
//				case 3:
//			}
//		}
//	}
	return 0;
}
/*
1 8
1 1
3 1 1
3 1 1
2 1
2 1
3 1 1
2 1
3 1 5

1 20
2 1
3 1 1
3 1 1
3 1 1
2 1
3 1 1
2 1
3 1 1
3 1 1
3 1 1
3 1 1
1 1
1 1
3 1 1
2 1
2 1
2 1
3 1 1
1 1
3 1 1

*/
