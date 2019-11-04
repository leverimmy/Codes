#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <iostream>
#define MAXN 50
using namespace std;
int a[MAXN],b[MAXN],c[MAXN],book[MAXN];
int num[MAXN],NEXT[MAXN],n,cnt;
char s1[MAXN],s2[MAXN],s3[MAXN];

int check() {
    for(int i=n-1,x=0;i>=0;i--) 
	{
        int A=num[a[i]],B=num[b[i]],C=num[c[i]];
        if((A+B+x)%n!=C)
			return 0;
        x=(A+B+x)/n;
    }
    return 1;
}

int can_cut()
{
    if(num[a[0]]+num[b[0]]>=n)
        return 1;
    for(int i=n-1;i>=0;i--)
	{
        int A=num[a[i]],B=num[b[i]],C=num[c[i]];
        if(A==-1||B==-1||C==-1) 
			continue;
        if((A+B)%n!=C&&(A+B+1)%n!=C)
            return 1;
    }
    return 0;
}

void print() {
    for(int i=0;i<n;i++)
        printf("%d ",num[i]);
}

void dfs(int x)
{
    if(can_cut())
		return;
    if(x==n)
	{
        if(check())
			print();
        return;
    }
    for(int i=n-1;i>=0;i--)
	{
        if(!book[i])
		{
            num[NEXT[x]]=i;
            book[i]=1;
            dfs(x+1);
            num[NEXT[x]]=-1;
            book[i]=0;
        }
	}
    return;
}
int get_int(char c)
{
    return c-'A';
}

void get_next(int x)
{
    if(!book[x])
	{
        book[x]=1;
        NEXT[cnt++]=x;
    }
    return;
}

int main()
{
    scanf("%d",&n);
    scanf("%s%s%s",s1,s2,s3);
    for(int i=0;i<n;i++)
	{
        a[i]=get_int(s1[i]);
        b[i]=get_int(s2[i]);
        c[i]=get_int(s3[i]);
        num[i]=-1;
    }
    for(int i=n-1;i>=0;i--)
	{
        get_next(a[i]);
        get_next(b[i]);
        get_next(c[i]);
    }
    for(int i=0;i<n;i++)
		book[i]=0;
    dfs(0);
    return 0;
}