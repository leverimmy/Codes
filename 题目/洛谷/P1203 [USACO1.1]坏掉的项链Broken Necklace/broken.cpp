#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 350 + 10;

int n, ans = -1;
char str[N << 1];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	n = read();
	scanf("%s", str + 1);
	for(rgi i = 1; i <= n; ++i)str[i + n] = str[i];
	
	for(rgi i = 1, j, k, cnt1 = 0, cnt2 = 0; i <= n; ++i, cnt1 = cnt2 = 0) {
		char col1 = str[i];
		for(j = i; j <= i + n - 1; ++j)
			if(str[j] == col1 || str[j] == 'w')
				cnt1++;
			else
				break;
		
		char col2 = str[i + n - 1];
		k = i + n - 1;
		if(col2 == 'w') {
			do {
				k--;
			} while(str[k] == 'w' && k >= j);
			
			col2 = str[k];
			for(k = i + n - 1; k >= j; --k)
				if(str[k] == col2 || str[k] == 'w')
					cnt2++;
				else
					break;
		}
		else {
			for(k = i + n - 1; k >= j; --k)
				if(str[k] == col2 || str[k] == 'w')
					cnt2++;
				else
					break;
		}
		ans = std::max(ans, cnt1 + cnt2);
	}
	printf("%d", ans);
	
	return 0;
}
/*
3
rrr

77
rwrwrwrwrwrwrwrwrwrwrwrwbwrwbwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwr

*/
