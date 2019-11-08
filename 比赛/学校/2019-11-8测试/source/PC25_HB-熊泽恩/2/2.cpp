#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define il inline

const int N = 1e6 + 10;

int flag, _next[N];
char A[N], B[N];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

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

void KMP(char strA[], char strB[]) {
	int lenA = strlen(strA + 1);
	int lenB = strlen(strB + 1);
	
	for(rgi i = 0, j = 0; i <= lenA;) {
		
		if(j == lenB) {
			flag = 1;
			return;
		}
		
		if(strA[i + 1] == strB[j + 1])
			i++, j++;
		
		else {
			if(j == 0)
				i++;
			else
				j = _next[j];
		}
		
	}
	
}

int main() {
	freopen("2.in", "r", stdin);
	freopen("2.out", "w", stdout);
	
	while(scanf("%s %s", A + 1, B + 1) != EOF) {
		flag = 0;
		Get_Next(B);
		
		KMP(A, B);
		
		if(flag)	puts("YES");
		else		puts("NO");
	}
	return 0;
}

