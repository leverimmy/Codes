#include <cstdio>
#include <cstring>

using namespace std;

int A, ans;

int main()
{
	scanf("%d", &A);
	while(A)
	{
		if(A % 8 == 1)
			ans++;
		A /= 8;
	}
	printf("%d", ans);
	return 0;
}

