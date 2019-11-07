#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define il inline

ll n, low, mid, high;

void ooo(ll a) {
	if(a == 1)	printf("yi ");
	if(a == 2)	printf("er ");
	if(a == 3)	printf("san ");
	if(a == 4)	printf("si ");
	if(a == 5)	printf("wu ");
	if(a == 6)	printf("liu ");
	if(a == 7)	printf("qi ");
	if(a == 8)	printf("ba ");
	if(a == 9)	printf("jiu ");
}

void ling() {printf("ling ");}
void shi() {printf("shi ");}
void bai() {printf("bai ");}
void qian() {printf("qian ");}

void out(ll a) {
	
	int _1 = a / 1000;
	int _2 = a / 100 % 10;
	int _3 = a / 10 % 10;
	int _4 = a % 10; 
	
	if(_1) {
		if(_2) {
			if(_3) {
				if(_4)
					ooo(_1), qian(), ooo(_2), bai(), ooo(_3), shi(), ooo(_4);//ok
				else
					ooo(_1), qian(), ooo(_2), bai(), ooo(_3), shi();//ok
			}
			else {
				if(_4)
					ooo(_1), qian(), ooo(_2), bai(), ooo(_3), ling(), ooo(_4);//ok
				else
					ooo(_1), qian(), ooo(_2), bai();//ok
			}
		}
		else {
			if(_3) {
				if(_4)
					ooo(_1), qian(), ling(), ooo(_3), shi(), ooo(_4);//ok
				else
					ooo(_1), qian(), ling(), ooo(_3), shi();//ok
			}
			else {
				if(_4)
					ooo(_1), qian(), ling(), ooo(_4);//ok
				else
					ooo(_1), qian();//ok
			}
		}
	}
	else {
		if(_2) {
			if(_3) {
				if(_4)
					ooo(_2), bai(), ooo(_3), shi(), ooo(_4);//ok
				else
					ooo(_2), bai(), ooo(_3), shi();//ok
			}
			else {
				if(_4)
					ooo(_2), bai(), ooo(_3), ling(), ooo(_4);//ok
				else
					ooo(_2), bai();//ok
			}
		}
		else {
			if(_3) {
				if(_4) {
					if(_3 != 1)
						ooo(_3), shi(), ooo(_4);
					else
						shi(), ooo(_4);
				}
				else {
					if(_3 != 1)
						ooo(_3), shi();
					else
						shi();
				}
			}
			else {
				if(_4)
					ooo(_4);
				else
					ling();
			}
		}
	}
}

int main() {
	freopen("3.in", "r", stdin);
	freopen("3.out", "w", stdout);
	std::cin >> n;
	low = n % 10000;
	mid = (n / 10000) % 10000;
	high = n / 100000000;
	
//	std::cout << high << mid << low << " ";
	
	if(high) {
		out(high);
		printf("yi ");
	}
	if(mid) {
		out(mid);
		printf("wan ");
	}
	if(low) {
		out(low);
	}
	return 0;
}

