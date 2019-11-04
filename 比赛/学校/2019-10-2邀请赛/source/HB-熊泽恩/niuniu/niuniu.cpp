//#pragma GCC optimize(2)
#include <cstdio>
#include <cctype>
#include <cmath>
#include <algorithm>
#define long long ll
#define rgi register int
#define il inline

using namespace std;

int T, ans;
int a[6], now[6], kill[6];
int f[20][20][20][20][20];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

il bool SIZHA(int cur[6]) {
	if(cur[2] == cur[3] && cur[3] == cur[4] && cur[4] == cur[5]) return 1;
	if(cur[1] == cur[3] && cur[3] == cur[4] && cur[4] == cur[5]) return 1;
	if(cur[1] == cur[2] && cur[2] == cur[4] && cur[4] == cur[5]) return 1;
	if(cur[1] == cur[2] && cur[2] == cur[3] && cur[3] == cur[5]) return 1;
	if(cur[1] == cur[2] && cur[2] == cur[3] && cur[3] == cur[4]) return 1;
	return 0;
}

il bool WUHUANIU(int cur[6]) {
	if(cur[1] <= 10)	return 0;
	if(cur[2] <= 10)	return 0;
	if(cur[3] <= 10)	return 0;
	if(cur[4] <= 10)	return 0;
	if(cur[5] <= 10)	return 0; 
	return 1;
}

il bool WUXIAONIU(int cur[6], int tot) {
	if(tot > 10)	return 0;
	if(cur[1] >= 5)	return 0;
	if(cur[2] >= 5)	return 0;
	if(cur[3] >= 5)	return 0;
	if(cur[4] >= 5)	return 0;
	if(cur[5] >= 5)	return 0;
	return 1; 
}

il bool HEAD(int cur[6], int tot) {
	if((tot - cur[1] - cur[2]) % 10 == 0)	return 1;
	if((tot - cur[1] - cur[3]) % 10 == 0)	return 1;
	if((tot - cur[1] - cur[4]) % 10 == 0)	return 1;
	if((tot - cur[1] - cur[5]) % 10 == 0)	return 1;
	if((tot - cur[2] - cur[3]) % 10 == 0)	return 1;
	if((tot - cur[2] - cur[4]) % 10 == 0)	return 1;
	if((tot - cur[2] - cur[5]) % 10 == 0)	return 1;
	if((tot - cur[3] - cur[4]) % 10 == 0)	return 1;
	if((tot - cur[3] - cur[5]) % 10 == 0)	return 1;
	if((tot - cur[4] - cur[5]) % 10 == 0)	return 1;
	return 0;
}

il int Get_Score(int _a, int _b, int _c, int _d, int _e) {
	int res = 0, tmp = 0, sum = 0; 
	now[1] = _a, now[2] = _b, now[3] = _c, now[4] = _d, now[5] = _e;
	/*for(rgi i = 1; i <= 5; ++i) {
		kill[i] = now[i] > 10 ? 10 : now[i];
		tmp += kill[i];
		sum += now[i]; 
	}*/
	
	kill[1] = now[1] > 10 ? 10 : now[1];
	kill[2] = now[2] > 10 ? 10 : now[2];
	kill[3] = now[3] > 10 ? 10 : now[3];
	kill[4] = now[4] > 10 ? 10 : now[4];
	kill[5] = now[5] > 10 ? 10 : now[5];
	
	tmp = kill[1] + kill[2] + kill[3] + kill[4] + kill[5];
	sum = now[1] + now[2] + now[3] + now[4] + now[5];
	
//	sort(now + 1, now + 6); sort(kill + 1, kill + 6);
	if(f[now[1]][now[2]][now[3]][now[4]][now[5]])	return f[now[1]][now[2]][now[3]][now[4]][now[5]];
	if(SIZHA(now))	res = max(res, 40);
	if(WUHUANIU(now))	res = max(res, 50);
	if(WUXIAONIU(kill, sum))	res = max(res, 60);
	if(res) return res;
	if(HEAD(kill, tmp)) {
		if(tmp % 10 == 0)	res = 30;
		else if(tmp % 10 < 7)	res = tmp % 10;
		else res = (tmp % 10) * 2;
	}
	else res = 0;
	return f[now[1]][now[2]][now[3]][now[4]][now[5]] = res;
}

il int Round(int up, int down) {
	return (up * 1.0 / down - up / down >= 0.5) ? (up / down + 1) : (up / down);
}

int main() {
	freopen("niuniu.in", "r", stdin);
	freopen("niuniu.out", "w", stdout);
	T = read();
	while(T--) {
		a[1] = read(), a[2] = read(), a[3] = read(), a[4] = read(); 
		/*for(rgi card = 1; card <= 13; ++card)
		{
			ans += Get_Score(a[1], a[2], a[3], a[4], card);
			printf("card : %d, cur_ans : %d\n", card, Get_Score(a[1], a[2], a[3], a[4], card));
		}*/
		ans += Get_Score(a[1], a[2], a[3], a[4], 1);
		ans += Get_Score(a[1], a[2], a[3], a[4], 2);
		ans += Get_Score(a[1], a[2], a[3], a[4], 3);
		ans += Get_Score(a[1], a[2], a[3], a[4], 4);
		ans += Get_Score(a[1], a[2], a[3], a[4], 5);
		ans += Get_Score(a[1], a[2], a[3], a[4], 6);
		ans += Get_Score(a[1], a[2], a[3], a[4], 7);
		ans += Get_Score(a[1], a[2], a[3], a[4], 8);
		ans += Get_Score(a[1], a[2], a[3], a[4], 9);
		ans += Get_Score(a[1], a[2], a[3], a[4], 10);
		ans += Get_Score(a[1], a[2], a[3], a[4], 11);
		ans += Get_Score(a[1], a[2], a[3], a[4], 12);
		ans += Get_Score(a[1], a[2], a[3], a[4], 13);
		
		printf("%d\n", Round(ans, 13)); ans = 0;
	}
	return 0;
}
/*
1
9 6 9 9

*/
