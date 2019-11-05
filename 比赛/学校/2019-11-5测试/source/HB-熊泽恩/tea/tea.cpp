#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 2e4 + 10;

int n, len, ans;
char str[N];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	freopen("tea.in", "r", stdin);
	freopen("tea.out", "w", stdout);
	n = read();
	for(rgi i = 1, cnt = 0; i <= n; ++i, cnt = 0) {
		scanf("%s", str);	len = strlen(str);
		for(rgi j = 0; j < len; ++j)
			if(str[j] == 'Q' || str[j] == 'W' || str[j] == 'E' || str[j] == 'R' ||
			   str[j] == 'q' || str[j] == 'w' || str[j] == 'e' || str[j] == 'r')
				cnt++;
		if(cnt << 1 > len)	ans++;
	}
	printf("%d", ans);
	return 0;
}

