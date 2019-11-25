#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
 
typedef long long ll;
#define MAXN 5010
const ll mul=127;
const ll MOD=23232377193;
 
char s[MAXN];
int ans[MAXN],book[MAXN],l;
 
void solve(int st)
{
	ll add=1;
	ll hash1=0;
	ll hash2=0;
	memset(book,0,sizeof(book));
	for(int i=st;i<l;i++)
	{
		hash1=(hash1*mul+(s[i]-'a'+1))%MOD;
		hash2=(hash2+add*(s[i]-'a'+1))%MOD;
		add=(add*mul)%MOD;
		if(hash1==hash2) book[i]=book[(i-st+1)/2+st-1]+1;
		ans[book[i]]++;
	}
}
 
int main()
{
	freopen("palindrome.in","r",stdin);
	freopen("palindrome.out","w",stdout);
	scanf("%s",s);
	l=strlen(s);
	for(int i=0;i<l;i++) solve(i);
	for(int i=l-1;i>=1;i--) ans[i]+=ans[i+1];
	for(int i=1;i<=l;i++) printf("%d ",ans[i]);
	return 0;
}
