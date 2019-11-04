#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 26 + 10;

int n, m, flag1, flag2, cnt;
int vis[N], f[N][N];
char a[N];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	n = read(), m = read(); 
	for(rgi i = 1; i <= m; ++i) {
		flag1 = flag2 = 1;	cnt = 0;
		char str[50];	scanf("%s", str);
		int x = str[0] - 'A' + 1, y = str[2] - 'A' + 1;
		if(x == y)	flag1 = 0;
		f[x][y] = 1;
		f[x][x] = 1;
		f[y][y] = 1;
		for(rgi j = 1; j <= 26; ++j)	for(rgi k = 1; k <= 26; ++k)
		f[j][k] |= f[j][x] & f[y][k];
		/*for(rgi j = 1; j <= 4; ++j) {
			for(rgi k = 1; k <= 4; ++k)
				cout << f[j][k] << " ";
			cout << endl;
		}*/
		for(rgi j = 1; j <= 26; ++j)
			for(rgi k = 1; k <= 26; ++k) {
				if(j != k && f[j][k] & f[k][j])	flag1 = 0;
				if(f[j][k] & !(f[k][j]))	cnt++;
			}
		
		if(!flag1) {
			printf("Inconsistency found after %d relations.\n", i);
			flag2 = 0;
			break;
		}
		
		if(cnt >= n * (n - 1) / 2) {
			printf("Sorted sequence determined after %d relations: ", i);
			flag2 = 0;
			for(rgi j = 1; j <= 26; ++j)	for(rgi k = 1; k <= 26; ++k)
				vis[k] += f[j][k];
			for(rgi j = 1; j <= 26; ++j)	a[vis[j]] = j + 'A' - 1;
			for(rgi j = 1; j <= n; ++j)	printf("%c", a[j]);
			printf(".\n");
			break;
		}
	} 
	if(flag2)	puts("Sorted sequence cannot be determined.");	
	return 0;
}
/*
4 6
A<B
A<C
B<C
C<D
B<D
A<B
3 2
A<B
B<A
26 1
A<Z
0 0

*/
