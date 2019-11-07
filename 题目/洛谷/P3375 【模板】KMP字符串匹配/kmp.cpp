#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 1e6 + 10;

char A[N], B[N];
int LENB, _next[N];

void Get_Next(char str[]) {
	int len = strlen(str + 1);
	
	for(rgi i = 2, j = 0; i <= len; ++i) {
		
		while(j > 0 && str[j + 1] != str[i])
			j = _next[j];
		if(str[j + 1] == str[i])
			++j;
		_next[i] = j;
	}
}

void KMP(char strA[], char strB[]) {
	int lena = strlen(strA + 1), lenb = strlen(strB + 1);
	
	for(rgi i = 0, j = 0; i <= lena;) {
		
		if(j == lenb)
			printf("%d\n", i - lenb + 1);
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
	scanf("%s", A + 1);
	scanf("%s", B + 1);	LENB = strlen(B + 1);
	
	Get_Next(B);
	KMP(A, B);
	
	for(rgi i = 1; i <= LENB; ++i)	printf("%d ", _next[i]);
	return 0;
}
/*
ABABABC
ABA

*/
