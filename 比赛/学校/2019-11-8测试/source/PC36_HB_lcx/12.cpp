#include<bits/stdc++.h>
#define int long long
#define INF 0x7ffffff
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
char z[1000001];
char x[1000001];
char y[1000001];
inline string jjj(char x[], char y[]) {
	int lena = strlen(x), lenb = strlen(y);
	reverse(x, x + lena);
	reverse(y, y + lenb);
	memset(z, '\000', sizeof(z));
	for(int i = 0; i < min(lena, lenb); i++) {
		z[i] += x[i] - y[i] + '0';
		if(z[i] < '0') {
			z[i] += 10;
			z[i + 1] -= 1;
		}
	}
	int cnt = lena;
	if(lena > lenb) {
		cnt = lena;
		for(int i = lenb; i < lena; i++) {
			z[i] += x[i];
			if(z[i] >= 10 + '0') {
				z[i] -= 10;
				z[i + 1] += 1;
				if(i == lena - 1) {
					cnt++;
				}
			}
		}
	}
	if(z[cnt - 1] == '0') {
		z[cnt - 1] = '\000';
		cnt--;
	}
	reverse(z, z + cnt);
	return z;
}
signed main() {
	freopen("12.in", "r", stdin);
	freopen("12.out", "w", stdout);
	while(cin >> x >> y) {
		cout << jjj(x, y) << endl;
		memset(x, '\000', sizeof(x));
		memset(y, '\000', sizeof(y));
	}
	return 0;
}
