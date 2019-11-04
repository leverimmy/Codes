#include <bits/stdc++.h>
using namespace std;

#define DB	double
#define lf	else if
#define I64	long long
#define Rd()	(rand() << 15 | rand())
#define For(i,a,b)	for(int i=a;i<=b;i++)
#define Rep(i,a,b)	for(int i=a;i>=b;i--)
	
#define fi	first
#define se	second
#define MK	make_pair
#define PA	pair<int, int>

#define CH	(ch=getchar())
int IN()	{
		int x= 0, f= 0, ch;
		for (; CH < '0' || ch > '9';)	f= (ch == '-');
		for (; ch >= '0' && ch <= '9'; CH)	(x*= 10)+= ch - '0';
		return	f ? -x : x;
}

#define n	1005

int N, A[n], B[n];

int F[5][5];

int main()	{
		freopen("sort.in", "r", stdin);
		freopen("sort.out", "w", stdout);
	
		N= IN();
		For(i, 1, N)	A[i]= B[i]= IN();
		
		sort(B+1, B+N+1);
		
		For(i, 1, N)	F[A[i]][B[i]] ++;

		int	Ans= min(F[1][2], F[2][1]) + min(F[1][3], F[3][1]) + min(F[2][3], F[3][2]);
		
		assert(abs(F[1][2] - F[2][1]) == abs(F[1][3] - F[3][1]));
		assert(abs(F[1][2] - F[2][1]) == abs(F[2][3] - F[3][2]));
		
		Ans+= abs(F[1][2] - F[2][1]) * 2;
		printf("%d\n", Ans);
		
		return	0;
}