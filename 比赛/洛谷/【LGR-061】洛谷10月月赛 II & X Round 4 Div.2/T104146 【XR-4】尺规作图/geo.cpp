#include <bits/stdc++.h>
#define rgi register int
#define rgl register long long
#define il inline
#define ll long long

using namespace std;

const int oo = 0x3f3f3f3f;
const double PI = 3.1415926535897932;

int id;

il int read() {
    rgi x = 0, f = 0, ch;
    while(!isdigit(ch = getchar())) f |= ch == '-';
    while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

double solve1(double a, double b, double c) {
	return (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
}

double solve2(double a, double b, double c) {
	return (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
}

int main() {
// 	freopen("data.out", "w", stdout);
	scanf("%d", &id);
	if(id == 1) {
		puts("3");
		puts("1 1.00000 0.00000 0.00000 0.00000");
		puts("1 0.00000 0.00000 1.00000 0.00000");
		puts("2 0.50000 0.866025 0.50000 -0.866025");
	}
	if(id == 2) {
		puts("3");
		puts("1 1 0 5.23124577 4.31624417");
		puts("1 0 0 5.23124577 4.31624417");
		puts("2 5.23124577 4.31624417 5.23124577 -4.31624417");
	}
	if(id == 3) {
		puts("5");
        puts("1 0 0 1 0");
        puts("1 1 0 0 0");
        puts("2 0.5 0.866025 0.5 -0.866025");
        puts("1 0.5 1 0.5 0");
        puts("2 -0.491620 0.870810 0.991620 0.129190");
	}
	if(id == 4) {
		puts("10");
		puts("1 1 0 0 0");
		puts("1 2 0 0 0");
		puts("1 4 0 0 0");
		puts("1 8 0 0 0");
		puts("1 16 0 0 0");
		puts("1 32 0 0 0");
		puts("1 64 0 0 0");
		puts("1 128 0 0 0");
		puts("1 256 0 0 0");
		puts("1 512 0 0 0");
	}
	if(id == 5) {
		puts("10");
		puts("1 0 0 1 0");
		puts("1 -1 0 1 0");
		puts("1 1 0 -3 0");
		puts("1 5 0 -3 0");
		puts("1 13 0 -3 0");
		puts("1 29 0 -3 0");
		puts("1 61 0 -3 0");
		puts("1 125 0 0 0");
		puts("1 250 0 0 0");
		puts("1 500 0 0 0");
	}
	if(id == 7) {
		
	}
	return 0;
}
