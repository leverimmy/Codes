#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read() {
	int x = 0, f = 1;
	char c = getchar();
	while(!isdigit(c)) {
		if(c == '-') {
			f = -1;
		}
		c = getchar();
	}
	while(isdigit(c)) {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f;
}
int next[1000001];
char a[1000001],b[1000001];
signed main() {
	freopen("2.in", "r", stdin);
	freopen("2.out", "w", stdout);
	while(cin >> (a + 1) >> (b + 1)) {
		memset(next, 0, sizeof(next));
	    int lena = strlen(a + 1), lenb = strlen(b + 1);
	    int j = 0;
	    for (int i = 2; i <= lenb; i++)
	    {
	       	while(j && b[i] != b[j+1]) {
	    		j = next[j];
	    	}
	       	if(b[j + 1] == b[i]) {
				j++;
			}
	        next[i] = j;
	    }
	    j = 0;
	    int judge = 0;
	    for(int i = 1; i <= lena; i++) {
	        while(j > 0 && b[j + 1] != a[i]) {
	           j = next[j];
	       	}
	        if (b[j + 1] == a[i]) {
	           j++;
	       	}
	        if (j == lenb) {
	        	printf("YES\n");
	        	judge = 1;
				j = next[j];
			}
	    }
	    if(judge == 0) {
	    	printf("NO\n");
		}
	}
	return 0;
}
