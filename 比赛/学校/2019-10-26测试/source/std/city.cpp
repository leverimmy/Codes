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

#define n	305
#define m	100005

int		N, M, C, A[n], S[m], H[n][n];

multiset<int>	G;

void	Back(int K)	{
		For(i, 1, K)	For(j, 1, i-1)	G.insert(A[i] + A[j]);
}

void	Work()	{
		For(i, 1, 3)	For(j, i+1, 3)	G.erase(G.find(A[i] + A[j]));
		
		For(i, 4, N)	{
			int x= (*(G.begin())) - A[1];
			
			if	(x < A[i-1])	{
				Back(i-1);	return;
			}
			else	{
				int flag= 1;
				For(j, 1, i-1)	{
					int t= x + A[j];
					
					if	(G.find(t) == G.end())	{
						For(k, 1, j-1)	G.insert(x + A[k]);
						flag= 0;
						break;
					}
					
					G.erase(G.find(t));
				}
				if	(! flag)	{
					Back(i-1);	return;
				}
				A[i]= x;
			}
		}
		
		C++;
		For(i, 1, N)	H[C][i]= A[i];
		Back(N);
}

int		main()	{
		freopen("city.in", "r", stdin);
		freopen("city.out", "w", stdout);
	
		N= IN();
		M= N * (N-1) / 2;
		
		For(i, 1, M)	S[i]= IN(), G.insert(S[i]);
		sort(S+1, S+M+1);
		
		For(i, 3, N)	if	(i == 3 || S[i] != S[i-1]){
			int	t= S[1] + S[2] + S[i];
			if	(t % 2 == 1)	continue;
			
			t/= 2;
			A[1]= t - S[i];
			A[2]= t - S[2];
			A[3]= t - S[1];
			
			if	(A[1] <= 0)	continue;
			
			Work();
		}
		
		printf("%d\n", C);
		For(i, 1, C)	{
			For(j, 1, N)	printf("%d ", H[i][j]);
			puts("");
		}
		
		return	0;
}
