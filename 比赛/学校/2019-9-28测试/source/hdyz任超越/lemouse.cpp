#include <iostream>
#include <cstdio>
#define Re register
using namespace std;

const int inf = 0x3f3f3f3f;
const int maxn = 1010;

int n, m, res, tot, ans;
int map[maxn][maxn], val[maxn][maxn];

int f_;
char ch_;
template <class T>
	inline T read(T &x_){
		x_ = 0, f_ = 1, ch_ = getchar();
		while (ch_ < '0' || ch_ > '9'){if (ch_ == '-') f_ = -1; ch_ = getchar();}
		while (ch_ >= '0' && ch_ <= '9') x_ = (x_ << 3) + (x_ << 1) + ch_ - 48, ch_ = getchar();
		return x_ *= f_;
	}
	
inline int Min(int X, int Y){
	if (X > Y) return Y;
	return X;
}

int main(){
	freopen ("lemouse.in", "r", stdin);
	freopen ("lemouse.out", "w", stdout);
	read(n);
	read(m);
	for (Re int i = 1;i <= n; ++i)
		for (Re int j = 1;j <= m; ++j){
			read(map[i][j]);
			val[i][j] = map[i][j];
			ans += map[i][j];
		}
	for (Re int i = 1;i <= n; ++i){
		for (Re int j = 1;j <= m; ++j){
			val[i][j] += Min(val[i-1][j], val[i][j-1]);
		}
	}
	printf("%d",ans*3/4);
	return 0;
}
