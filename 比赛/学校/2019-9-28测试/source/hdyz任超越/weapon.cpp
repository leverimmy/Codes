#include <iostream>
#include <cstdio>
#define Re register
using namespace std;

const int maxn = 1e5 + 10;

int n, f, ans, flag;
int p[maxn];

int f_;
char ch_;
template <class T>
	inline T read(T &x_){
		x_ = 0, f_ = 1, ch_ = getchar();
		while (ch_ < '0' || ch_ > '9'){if (ch_ == '-') f_ = -1; ch_ = getchar();}
		while (ch_ >= '0' && ch_ <= '9') x_ = (x_ << 3) + (x_ << 1) + ch_ - 48, ch_ = getchar();
		return x_ *= f_;
	}

int main(){
	freopen ("weapon.in", "r", stdin);
	freopen ("weapon.out", "w", stdout);	
	read(n);
	read(f);
	for (Re int i = 1;i <= n; ++i) read(p[i]);
	for(Re int i = 1;i <= n; ++i){
		for(Re int j = 1;j <=n && i+j+j+f-1 <= n; ++j){
			flag = 0;
			for(Re int k = i;k <= i+j-1; ++k){
				if(p[k] != p[k+j+f]){
					flag = 1;
					break;
				}
			}
			if(!flag) ans++;
		}
	}
	printf("%d", ans);
	return 0;
}
