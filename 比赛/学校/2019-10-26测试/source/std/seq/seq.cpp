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

I64		A, B, Ans;

int		main()	{
		freopen("seq.in", "r", stdin);
		freopen("seq.out", "w", stdout);
	
		cin >> A >> B;
		if	(A < B)	swap(A, B);
		
		for (; B; )	{
			Ans+= A / B;
			A= A % B;
			swap(A, B);
		}
		
		cout << Ans + 1 << endl;
		
		return	0;
}