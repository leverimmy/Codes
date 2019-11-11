#include <cstdio>
using namespace std;

#define LY(p) freopen (p".in", "r", stdin); freopen (p".out", "w", stdout)
#define L_L "%I64d"
#define LL long long
int a, b, ai, fir = 1;
LL s, t, r, as;

int main()
{
	LY("cards");
	scanf ("%d %d", &a, &b);
	if (a == 0) {
		printf (L_L"\n", -1LL * b * b);
		for (int i = 1; i <= b; i++) printf ("x");
		return 0;
	}
	if (b == 0) {
		printf (L_L"\n", 1LL * a * a);
		for (int i = 1; i <= a; i++) printf ("o");
		return 0;
	}
	fir = 1;
	as = -(1LL << 50);
	for (int i = 1; i <= a; i++) {
		s = 1LL * (a - i + 1) * (a - i + 1) + (i - 1);
		t = b / (i + 1), r = b % (i + 1);
		s -= 1LL * (i + 1 - r) * t * t + 1LL * r * (t + 1) * (t + 1);
		if (s > as)
			as = s, ai = i;
		if (i + 1 >= b) break;
	}
	t = b / (ai + 1), r = b % (ai + 1);
	printf (L_L"\n", as);
	for (int i = 1; ; i ^= 1)
		if (i & 1)
			if (r > 0) {
				r --;
				for (int j = 1; j <= t + 1; j++) printf ("x");
				b -= t + 1;
			}
			else {
				if (b) {
					for (int j = 1; j <= t; j++) printf ("x");
					b -= t;
				}
				if (! b) break;
			}
		else
			if (fir) {
				for (int j = 1; j <= a - ai + 1; j++) printf ("o");
				fir = 0;
			}
			else
				printf ("o");
	return 0;
}
