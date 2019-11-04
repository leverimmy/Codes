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

#define n	55

int		N, M, V[n];

struct	Nod{
		int h, c;
}A[n];

bool	Cmp(const Nod&a, const Nod&b)	{
		return	a.h < b.h;
}

int		Cal(int l, int r, int rev)	{
		For(i, l, r)	V[i]= A[i].c;
		sort(V+l, V+r+1);
		
		int	ans= 0;
		For(i, l, r)	if	(V[i] <= rev)	rev-= V[i], ans++;
		return	ans;
}

int		main()	{
		freopen("meet.in", "r", stdin);
		freopen("meet.out", "w", stdout);
	
		N= IN();
		For(i, 1, N)	A[i].c= IN();
		For(i, 1, N)	A[i].h= IN();
		M= IN();
		
		sort(A+1, A+N+1, Cmp);
		
		int	Ans= 0;
		For(i, 1, N)	if	(M >= A[i].c)	Ans= 1;
		
		For(l, 1, N)	For(r, l+1, N)	{
			int rev= M - (A[r].h - A[l].h);
			if	(rev < 0)	break;
			
			rev-= A[l].c + A[r].c;
			if	(rev >= 0)	Ans= max(Ans, Cal(l+1, r-1, rev) + 2);
		}
		
		printf("%d\n", Ans);
		
		return	0;
}