#include <bits/stdc++.h>
using namespace std;

#define DB	double
#define lf	else if
#define	I64	long long
#define Rd()	(rand() << 15 | rand())
#define For(i,a,b)	for(int i=a;i<=b;i++)
#define Rep(i,a,b)	for(int i=a;i>=b;i--)
	
#define fi	first
#define se	second
#define MK	make_pair
#define PA	pair<int, int>

#define CH	(ch=getchar())
int		IN()	{
		int x= 0, f= 0, ch;
		for (; CH < '0' || ch > '9';)	f= (ch == '-');
		for (; ch >= '0' && ch <= '9'; CH)	(x*= 10)+= ch - '0';
		return	f ? -x : x;
}

#define n	1000005

int		T, N, K, M, V[n], A[n];

I64		S[n];

int		main()	{
		freopen("diary.in", "r", stdin);
		freopen("diary.out", "w", stdout);
	
		N= 1000000;
		
		For(i, 2, N)	if	(! V[i])	{
			A[++ M]= i;
			for (int x= i + i; x <= N; x+= i)	V[x]= 1;
		}
		
		For(i, 1, M)	S[i]= S[i-1] + A[i];
		
		T= IN();
		for (; T--; )	{
			N= IN();
			K= IN();
			
			if	(K > M)	puts("-1");
			lf	(S[K] > N)	puts("-1");
			else	{
				int l= K, r= M+1;
				for (; l + 1 < r; )	{
					int Mid= (l + r) >> 1;
					if	(S[Mid] - S[Mid - K] <= N)	l= Mid;
						else	r= Mid;
				}
				
				printf("%d\n", S[l] - S[l - K]);
			}
		}
	
		return	0;
}