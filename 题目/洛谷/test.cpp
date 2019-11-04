#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#define re register
using namespace std;

inline int read() { //读入优化
	int X = 0, w = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') w = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') X = (X << 3) + (X << 1) + c - '0', c = getchar();
	return X * w;
}

struct node {
	int x, y, w;
};

node a[1010];
int n, sx, sy;

double ansx, ansy; //全局最优解的坐标
double ans = 1e18, t; //全局最优解、温度
const double delta = 0.993; //降温系数

inline double calc_energy(double x, double y) { //计算整个系统的能量
	double rt = 0;
	for (re int i = 1; i <= n; i++) {
		double deltax = x - a[i].x, deltay = y - a[i].y;
		rt += sqrt(deltax * deltax + deltay * deltay) * a[i].w;
	}
	return rt;
}

inline void simulate_anneal() { //SA主过程
	double x = ansx, y = ansy;
	t = 2000; //初始温度
	while (t > 1e-14) {
		double X = x + ((rand() << 1) - RAND_MAX) * t;
		double Y = y + ((rand() << 1) - RAND_MAX) * t; //得出一个新的坐标
		double now = calc_energy(X, Y);
		double Delta = now - ans;
		if (Delta < 0) { //接受
			x = X, y = Y;
			ansx = x, ansy = y, ans = now;
		}
		else if (exp(-Delta / t)*RAND_MAX > rand()) x = X, y = Y; //以一个概率接受
		t *= delta;
	}
}

inline void Solve() { //多跑几遍SA，减小误差
	ansx = (double)sx / n, ansy = (double)sy / n; //从平均值开始更容易接近最优解
	simulate_anneal();
	simulate_anneal();
	simulate_anneal();
}

int main() {
	srand(19260817);
	srand(rand());
	srand(rand()); //玄学srand
	n = read();
	for (re int i = 1; i <= n; i++) {
		a[i].x = read(), a[i].y = read(), a[i].w = read();
		sx += a[i].x, sy += a[i].y;
	}
	Solve();
	printf("%.3f %.3f\n", ansx, ansy);
	return 0;
}
