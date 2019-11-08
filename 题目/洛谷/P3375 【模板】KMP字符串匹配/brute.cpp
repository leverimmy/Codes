#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 1e6 + 10;

char A[N], B[N];
int lena, lenb;

int main() {
	
	scanf("%s", A + 1);	lena = strlen(A + 1);
	scanf("%s", B + 1);	lenb = strlen(B + 1);
	
	for(rgi l = 1, r = l + lenb - 1; r <= lena; ++l, r = l + lenb - 1) {
		int flag = 1;
		for(rgi i = l; i <= r && flag; ++i) {
			if(A[i] != B[i - l + 1])
				flag = 0;
		}
		if(flag)	printf("%d\n", l);
	}
	
	return 0;
}

