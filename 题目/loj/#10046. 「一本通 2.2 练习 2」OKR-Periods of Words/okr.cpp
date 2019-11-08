#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 1e6 + 10;

int n, ans, _next[N];
char A[N];

void Get_Next(char str[]) {
	int len = strlen(str + 1);
	
	for(rgi i = 1, j = 0; i < len; ++i, j = _next[i]) {
		while(j > 0 && str[i + 1] != str[j + 1])
			j = _next[j];
		if(str[i + 1] == str[j + 1])
			j++;
		_next[i + 1] = j;
	}
}

int main() {
	std::cin >> n;
	scanf("%s", A + 1);
	Get_Next(A);
	for(rgi i = 1; i <= n; ++i) ans += _next[i];
	std::cout << ans;
	return 0;
}

