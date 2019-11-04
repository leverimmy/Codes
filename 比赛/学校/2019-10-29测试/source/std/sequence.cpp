#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define gs ((c < '0' || c > '9')  &&  c != '-')
int getint() { int w = 0, q = 0; char c = getchar(); while (gs) c = getchar(); if (c == '-') q = 1, c = getchar(); while (!gs) w = w * 10 + c - '0', c = getchar(); return q ? -w : w; }
#define r(A) A = getint()
#define chk(x, y) (A[x] < A[y] ? y : x)
const int ys = 1000010;
using namespace std;
 
long long x, A[ys], An;
int exp[ys], pos[ys], q[ys], w[ys];
int Max[ys / 2][22];
int l[ys], r[ys], M[ys];
int n, k, L, R, top;
 
bool cmp(int a, int b)  {  return A[M[a]] - A[w[a] - 1] > A[M[b]] - A[w[b] - 1];  }
void up(int x)
{
	int j = x, w, lt = exp[x];
	for (; w = j, (j >>= 1)  &&  cmp(lt, exp[j]); )
		exp[w] = exp[j], pos[exp[w]] = w;
	
	exp[w] = lt;
	pos[lt] = w;
}
void down(int x)
{
	int j = x, w, lt = exp[x];
	for (; w = j, (j <<= 1) <= top  &&  (cmp(exp[j], lt)  ||  j < top  &&  cmp(exp[j + 1], lt));
			 exp[w] = exp[j], pos[exp[w]] = w)
		if (j < top  &&  cmp(exp[j + 1], exp[j]))  ++j;
	
	exp[w] = lt;
	pos[lt] = w;
}
void update(int x)
{
	if (x != 1  &&  cmp(exp[x], exp[x >> 1]))  up(x);
	else  down(x);
}
void Prepare()
{
	int now = 2, t = 0;
	rep(i, 1, n)  {
		if (i > now)  now <<= 1, t++;
		q[i] = t;
	}
	
	for (int i = n; i; --i)  {
		Max[i][0] = i;
		int r = 1;
		for (int j = 1; r + i - 1 <= n; ++j, r <<= 1)
			Max[i][j] = chk(Max[i][j - 1], Max[i + r][j - 1]); 
	}
}
int query(int l, int r)
{
	int x = q[r - l + 1];
	return chk(Max[l][x], Max[r - (1 << x) + 1][x]);
}
void New(int L, int R, int y, int ap)
{
	if (R > n)  R = n;
	if (L > R)  return;
	w[ap] = y;
	l[ap] = L;
	r[ap] = R;
	M[ap] = query(l[ap], r[ap]);
	exp[pos[ap] = ++top] = ap;
	update(top);
}
int main()
{
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	
	r(n); r(k); r(L); r(R);
	rep(i, 1, n)  {
		scanf("%I64d", &x);
		A[i] = x + A[i - 1];
	}
  
	Prepare();
	
	int ap = 0;
	rep(i, 1, n)
		New(i + L - 1, i + R - 1, i, ++ap);
	
	rep(i, 1, k)  {
		int y = exp[1], z = M[y];
    
		An += A[z] - A[w[y] - 1];
		
		int Rt = r[y];
			
		exp[1] = exp[top]; pos[exp[1]] = 1;
		--top;  update(1);
    
		New(l[y], z - 1, w[y], y);
		New(z + 1, Rt, w[y], ++ap);
	}
	
	printf("%I64d", An);
}
