#include <cstdio>
#include <cmath>
#define log2(n) log(n)/log(2)

using namespace std;

int n;

int pow2(int power)
{
    if(power==0)
        return 1;
    else
        return 2*pow2(power-1);
}

void dfs(int x)
{
    if(x==0)	return;
    int t=log2(x);
    if(t==0)	printf("2(0)");
    if(t==1)	printf("2");
    if(t>1)
    {
        printf("2(");
        dfs(t);
        printf(")");
    }
    if(x!=pow2(t))
    {
        printf("+");
        dfs(x-pow2(t));
    }
}

int main()
{
    scanf("%d",&n);
    dfs(n);
    return 0;
}