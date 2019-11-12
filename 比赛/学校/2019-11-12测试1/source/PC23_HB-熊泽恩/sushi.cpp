#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 1e6 + 10;

int T, n, tot;
int nxt[N];
char str[N];

struct INTERVAL {
	int l, r;
	int cnt, val;
} bet1[N], bet2[N];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int dist(int u, int v) {
	if(v > u)
		return std::min(v - u, u + n - v);
	else
		return std::min(u - v, v + n - u);
}

int main() {
	freopen("sushi.in", "r", stdin);
	freopen("sushi.out", "w", stdout);
	T = read();
	while(T--) {
		int ans1 = 0, ans2 = 0, max_B = -1, max_R = -1, posB, posR, tot;
		scanf("%s", str + 1);	n = strlen(str + 1);
		
		for(rgi i = 1; i <= n; ++i) {
			if(str[i] != str[i - 1] || i == 1) {
				bet1[++tot].cnt = 1;
				bet1[tot].l = bet1[tot].r = i;
				bet1[tot].val = str[i] == 'B' ? 1 : -1;
			}
			else {
				bet1[tot].cnt++;
				bet1[tot].r = i;
			}
		}
		
		for(rgi i = 1; i <= n; ++i) {
			bet2[i].cnt = bet1[i].cnt;
			bet2[i].l = bet1[i].l;
			bet2[i].r = bet1[i].r;
			bet2[i].val = bet1[i].val;
		}
		
		for(rgi i = 1; i <= n; ++i)	nxt[i] = i + 1;	nxt[n] = 1;
		
		for(rgi i = 1; i <= tot; ++i) {
			if(bet1[i].val == 1) {
				if(bet1[i].cnt > max_B) {
					posB = i;
					max_B = bet1[i].cnt;
				}
			}
			else if(bet1[i].val == -1) {
				if(bet1[i].cnt > max_R) {
					posR = i;
					max_R = bet1[i].cnt;
				}
			}
		}
		
		for(rgi i = (bet1[posB].r + 1 > n ? bet1[posB].r + 1 - n : bet1[posB].r + 1); i != (bet1[posB].l - 1 < 1 ? bet1[posB].l - 1 + n : bet1[posB].l - 1); i = nxt[i]) if(str[i] == 'B') { // B
			int dis1 = dist(i, bet1[posB].l - 1 < 1 ? bet1[posB].l - 1 + n : bet1[posB].l - 1);
			int dis2 = dist(i, bet1[posB].r + 1 > n ? bet1[posB].r + 1 - n : bet1[posB].r + 1);
			if(dis1 < dis2) {
				ans1 += dis1;
				bet1[posB].l--;	if(bet1[posB].l < 1)	bet1[posB].l += n;
			}
			else {
				ans1 += dis2;
				bet1[posB].r++;	if(bet1[posB].r > n)	bet1[posB].r -= n;
			}
		}
		
		for(rgi i = (bet2[posR].r + 1 > n ? bet2[posR].r + 1 - n : bet2[posR].r + 1); i != (bet2[posR].l - 1 < 1 ? bet2[posR].l - 1 + n : bet2[posR].l - 1); i = nxt[i]) if(str[i] == 'R') {
			int dis1 = dist(i, bet2[posR].l - 1 < 1 ? bet2[posR].l - 1 + n : bet2[posR].l - 1);
			int dis2 = dist(i, bet2[posR].r + 1 > n ? bet2[posR].r + 1 - n : bet2[posR].r + 1);
			if(dis1 < dis2) {
				ans2 += dis1;
				bet2[posR].l--;	if(bet2[posR].l < 1)	bet2[posR].l += n;
			}
			else {
				ans2 += dis2;
				bet2[posR].r++;	if(bet2[posR].r > n)	bet2[posR].r -= n;
			}
		}
		
		printf("%d\n", std::min(ans1, ans2));
		
	}
	return 0;
}

