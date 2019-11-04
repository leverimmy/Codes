#include <cstdio>

using namespace std;

int len, kase = 1;
int a[1010], b[1010];
int main()
{
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	while(scanf("%d", &len) == 1 && len)
	{
		printf("Game %d:\n", kase++);
		for(int i = 1; i <= len; i++)
			scanf("%d", &a[i]);
		while(1)
		{
			int A = 0, B = 0;
			for(int i = 1; i <= len; i++)
			{
				scanf("%d", &b[i]);
				if(a[i] == b[i])
					A++;
			}
			if(b[1] == 0)
				break;
			for(int num = 1; num <= 9; num++)
			{
				int cnt_a = 0, cnt_b = 0;
				for(int i = 1; i <= len; i++)
				{
					if(a[i] == num)
						cnt_a++;
					if(b[i] == num)
						cnt_b++;
				}
				if(cnt_a < cnt_b)
					B += cnt_a;
				else
					B += cnt_b;
			}
			printf("    (%d,%d)\n", A, B - A);
		}
	}
	return 0;
}
