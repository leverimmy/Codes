#include <cstdio>
#include <cstring>
#include <cmath>
#define EPS 1e-6

using namespace std;

double A, M[50];
int B, E[50];
char s[10010];

int main()
{
	for(int i = 0; i <= 9; i++)
		M[i] = 1 - pow(0.5, i + 1);
	for(int j = 1; j <= 30; j++)
		E[j] = (1 << j) - 1;
	while(scanf("%s", s) && strcmp(s, "0e0"))
	{
		int len = strlen(s);
		for(int i = 0; i < len; i++)
			if(s[i] == 'e')
				s[i] = ' ';
		sscanf(s, "%lf %d", &A, &B);
		for(int i = 0; i <= 9; i++)
		{
			int flag = 0;
			for(int j = 1; j <= 30; j++)
				if(fabs(log10(M[i]) + log10(2)*E[j] - B - log10(A)) < EPS)
				{
					printf("%d %d\n", i, j);
					flag = 1;
					break;
				}
			if(flag)
				break;
		}
	}
	return 0;
}
