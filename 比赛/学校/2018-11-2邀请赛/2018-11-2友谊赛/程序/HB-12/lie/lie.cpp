#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
using namespace std;

struct hito {
	int taka, miji;
} tachi[100010], biyou[100010];
int itte[100010], kazu[100010];

inline bool operator<(hito a, hito b) {
	return a.miji == b.miji ? a.taka < b.taka : a.miji > b.miji;
}

int main() {
	int n, ans = 0; scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &tachi[i].taka, &tachi[i].miji);
	}
	sort(tachi, tachi + n);
	int cur = 0, sam = 1, t = 0, t2 = 0;
	while (cur <= n) {
		if (tachi[cur].miji == tachi[cur - 1].miji) {
			biyou[t++] = tachi[cur++]; continue;
		}
		int i = 0;
		while (i < t)
			if (!(biyou[i++].taka == itte[t2] && ++kazu[t2]) && ((itte[++t2] = biyou[i - 1].taka), itte[t2 - 1]) + biyou[i - 1].miji != n - t) //lying
				ans += kazu[t2 - 1];
		if (itte[t2] + biyou[1].miji != n - t) ans += kazu[t2];
	}
	printf("%d", ans);
	return 0;
}