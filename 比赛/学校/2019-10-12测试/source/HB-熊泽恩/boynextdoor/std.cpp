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
const int N = 5e5 + 10;

int n;	double T, ans = 1e18;

struct people {
	double a, b;
} p[N], s[N];

int main() {
	scanf("%d", &n);
	for(rgi i = 1; i <= n; ++i) {
		scanf("%lf %lf", &p[i].a, &p[i].b);
		s[i].a = s[i - 1].a + p[i].a;
		s[i].b = s[i - 1].b + p[i].b;
	}
	scanf("%lf", &T);
	for(rgi i = 1; i <= n - 1; ++i) {
		double A = s[i].a, B = s[n].a - s[i].a;
		double C = s[i].b, D = s[n].b - s[i].b;
		
		double p, q;
		
		p = min((C + D) * T / (A + C), T);
		q = ((C + D) * T - (A + C) * p) / (B + D);
		
		ans = min(ans, A * p + B * q);
		
		q = min((C + D) * T / (B + D), T);
		p = ((C + D) * T - (B + D) * q) / (A + C);
		
		ans = min(ans, A * p + B * q);
		
	}
	printf("%.2lf", ans);
	return 0;
}

