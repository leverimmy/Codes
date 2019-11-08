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
inline string ccc(char x[], char y[]) {
	int lena = strlen(x), lenb = strlen(y);
	reverse(x, x + lena);
	reverse(y, y + lenb);
	memset(z, '\000', sizeof(z));
	int cnt = lena * lenb + 5;
	for(int i = 0; i < lena; i++) {
		for(int j = 0; j < lenb; j++) {
			int xx = x[i] - '0', yy = y[j] - '0';
			int zz = xx * yy;
			z[i + j] += zz;
			if(z[i + j] < '0') {
				z[i + j] += '0';
			}
			while(z[i + j] >= 10 + '0') {
				z[i + j] -= 10;
				z[i + j + 1] += 1; 
			} 
			if(z[i + j + 1] < '0') {
				z[i + j + 1] += '0';
			}
		}
	}
	while(z[cnt - 1] == '0' || z[cnt - 1] == '\000') {
		z[cnt - 1] = '\000';
		cnt--;
	}
	reverse(z, z + cnt);
	return z;
}
signed main() {
	freopen("15.in", "r", stdin);
	freopen("15.out", "w", stdout);
	while(cin >> x >> y) {
		if(x[0] == 0 || y[0] == '0') {
			cout << "0" << endl;
			continue;
		}
		cout << ccc(x, y) << endl;
		memset(x, '\000', sizeof(x));
		memset(y, '\000', sizeof(y));
	}
	return 0;
}
