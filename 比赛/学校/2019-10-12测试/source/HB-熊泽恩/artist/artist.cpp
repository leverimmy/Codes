#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

using namespace std;

const int oo = 0x7fffffff;
const int N = 5e5 + 10;

int n, pos;
double T, ans = oo;

double pre_a, suf_a, pre_b, suf_b;
double pre, suf, pre_cost, suf_cost;

struct people {
	double a, b;
} p[N], s[N];

struct node {
	double ans; int pos; double pre_a, pre_b, suf_a, suf_b, pre, suf;
} res;

int main() {
//	freopen("artist.in", "r", stdin);
//	freopen("artist.out", "w", stdout);
	scanf("%d", &n);
	for(rgi i = 1; i <= n; ++i) {
		scanf("%lf %lf", &p[i].a, &p[i].b);
		s[i].a = s[i - 1].a + p[i].a;
		s[i].b = s[i - 1].b + p[i].b;
	}
	scanf("%lf", &T);
	for(rgi i = 1; i <= n - 1; ++i) {
		pre_a = s[i].a, pre_b = s[i].b;
		suf_a = s[n].a - s[i].a, suf_b = s[n].b - s[i].b;
		
		pre = pre_b * T / (pre_a + pre_b);
		suf = suf_b * T / (suf_a + suf_b);
		
//		pre_cost = pre_b * pre_a * T / (pre_a + pre_b);
		pre_cost = pre * pre_a;
//		suf_cost = suf_b * suf_a * T / (suf_a + suf_b);
		suf_cost = suf * suf_a;
		
		if(pre_cost + suf_cost < ans) {
			ans = pre_cost + suf_cost;
//			printf("tmp : %.4lf\n", ans);
//			res = (node){ans, i, pre_a, pre_b, suf_a, suf_b, pre, suf};
		}
	}
//	printf("pos = %d\n", res.pos);
//	printf("pre_a = %.4lf\n", res.pre_a);
//	printf("pre_b = %.4lf\n", res.pre_b);
//	printf("suf_a = %.4lf\n", res.suf_a);
//	printf("suf_b = %.4lf\n", res.suf_b);
//	printf("pre = %.6lf\n", res.pre);
//	printf("suf = %.6lf\n", res.suf);
	printf("%.2f", ans);
	return 0;
}
/*
2
92.81 64.62
34.91 94.89
61.78

*/
