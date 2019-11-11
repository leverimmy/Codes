#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const double dk = 0.997;
const int N = 1e5 + 10;

int a, b, num[N];
ll ans = -998244353, best;
char arr[N], ANS[N];

std::vector <int> xxx, ooo;

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

ll calc() {
	ll res = 0, X = 0, O = 0;
	for(rgi i = 1; i <= a + b; ++i) {
		if(arr[i] == 'x') {
			X++;
			res += O * O;
			O = 0;
		}
		if(arr[i] == 'o')	{
			O++;
			res -= X * X;
			X = 0;
		}
	}
	res += O * O - X * X;
	return res;
}

void SA()
{
	int T = 5000;
	while(T > 1e-10)
	{
		ll posO = rand() % a;
		ll posX = rand() % b;

		std::swap(arr[xxx[posX]], arr[ooo[posO]]);
		std::swap(xxx[posX], ooo[posO]);
		
		ll cur_ans = calc();
		ll delta = cur_ans - ans;
		if(delta > 0)
			ans = cur_ans;
		else if(RAND_MAX * exp(-delta / T) <= rand())
		{
			std::swap(xxx[posX], ooo[posO]);
			std::swap(arr[xxx[posX]], arr[ooo[posO]]);
			ans = cur_ans;
		}
		if(ans >= best) {
			for(rgi i = 1; i <= a + b; ++i)
				ANS[i] = arr[i];
			best = ans;
		}
		T *= dk;
	}
}

int main() {
	freopen("cards.in", "r", stdin);
	freopen("cards.out", "w", stdout);
	srand(time(0));
	a = read(), b = read();
	if(a <= 10 && b <= 10) {
		for(rgi i = 1; i <= b; ++i)	arr[i] = 'x';
		for(rgi i = 1; i <= a; ++i)	arr[b + i] = 'o';
		
		for(rgi i = 1; i <= a; ++i)	num[i] = 0;
		for(rgi i = 1; i <= b; ++i)	num[a + i] = 1;
		
		do {
			ll res = 0, X = 0, O = 0;
			for(rgi i = 1; i <= a + b; ++i) {
				if(num[i] == 1) {
					X++;
					res += O * O;
					O = 0;
				}
				if(num[i] == 0)	{
					O++;
					res -= X * X;
					X = 0;
				}
			}
			res += O * O - X * X;
			
			if(res >= ans) {
				ans = res;
				for(rgi i = 1; i <= a + b; ++i)	ANS[i] = num[i] ? 'x' : 'o';
			}
		} while(std::next_permutation(num + 1, num + a + b + 1));
		printf("%d\n", ans);
		puts(ANS + 1);
	}
	else {
		for(rgi i = 1; i <= a; ++i)	arr[i] = 'o';
		for(rgi i = 1; i <= b; ++i)	arr[a + i] = 'x';
		
		std::random_shuffle(arr + 1, arr + a + b + 1);
		
		for(rgi i = 1; i <= a + b; ++i) {
			if(arr[i] == 'x')	xxx.push_back(i);
			if(arr[i] == 'o')	ooo.push_back(i);
			ANS[i] = arr[i];
		}
		
		ans = best = calc();
		
		if(a == 0 || b == 0) {
			printf("%d\n", best);
			for(rgi i = 1; i <= a + b; ++i)	printf("%c", ANS[i]);
			return 0;
		}
		
		for(rgi i = 1; i <= 1000; ++i)	SA();
		
		
		printf("%d\n", best);
		for(rgi i = 1; i <= a + b; ++i)	printf("%c", ANS[i]);
	}
	
	return 0;
}
/*
0 4

10 10

2 3

*/
