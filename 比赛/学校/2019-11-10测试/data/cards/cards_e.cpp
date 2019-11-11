#include <cstdio>
#include <cstring>
#define LL long long
#define N 100010
FILE *in, *out, *ans, *grade, *log;
int a, b;
char ch[N], player[N], stder[N];

void WA() {fprintf (grade, "0");}

void print (char *s) {fprintf (log, "%s", s);}

bool same (char *a, char *b) {
	for (int i = 0; a[i] || b[i]; i++)
		if (a[i] != b[i]) return 0;
	return 1;
}

LL count (char *d) {
	LL ans(0); int st[2] = {0};
	for (int i = 0, j; d[i]; i++) {
		if (d[i] != 'o' && d[i] != 'x') return (1LL << 60);
		for (j = i; d[j + 1] == d[i]; j++);
		ans += 1LL * (j - i + 1) * (j - i + 1) * (d[i] == 'o'? 1 : -1);
		st[d[i] == 'o'] += j - i + 1;
		i = j;
	}
	if (st[1] != a || st[0] != b) return (1LL << 60);
	return ans;
}

LL getnum (char *t) {
	LL s = 0; bool flag = 0;
	for (int i = 0; t[i]; i++) {
		if (t[i] == '-') flag = 1, i ++;
		s = s * 10 + t[i] - '0';
	}
	return flag? -s : s;
}

int main (int argc, char *argv[])
{
	in = fopen (argv[1], "r");//in
	out = fopen (argv[2], "r");//out
	ans = fopen (argv[3], "r");//ans
	//argv[4]; full
	grade = fopen (argv[5], "w");//grade
	log = fopen (argv[6], "w");//log
	fscanf (in, "%d %d", &a, &b);
	if (fscanf (out, "%s", player) == EOF || fscanf (ans, "%s", stder) == EOF)
		return WA(), print ("Your output is empty!"), 0;
	
	if (! same (player, stder))
		return WA(), print ("Your answer is wrong!"), 0;
	
	fscanf (out, "%s", ch);
	if (strlen (ch) != a + b)
		return WA(), print ("first"), 0;
	if (count (ch) != getnum (stder))
		return WA(), print ("Your string is wrong!"), 0;

	fprintf (grade, argv[4]);
	return 0;
}
