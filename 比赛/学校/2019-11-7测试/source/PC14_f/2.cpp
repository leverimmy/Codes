#include<bits/stdc++.h>

int ExChar(char in){
	switch(in){
		case 'A':return 0;
		case 'T':return 1;
		case 'C':return 2;
		case 'G':return 3;
	}
}

char s[100];
int cnt[100][4];

signed main(void)
{
	freopen("2.in","r",stdin);
	freopen("2.out","w",stdout);
	
	int totExam,len,max=0;
	
	std::cin>>totExam;
	while(totExam--){
		std::cin>>s;
		len = strlen(s); max = std::max(max, len);
		for(int i=0;i<len;i++) cnt[i][ExChar(s[i])]++;
	}
	
	for(int i=0;i<max;i++){
		if(cnt[i][0]>=cnt[i][1]&&cnt[i][0]>=cnt[i][2]&&cnt[i][0]>=cnt[i][3]){ putchar('A'); continue; }
		if(cnt[i][1]>=cnt[i][0]&&cnt[i][1]>=cnt[i][2]&&cnt[i][1]>=cnt[i][3]){ putchar('T'); continue; }
		if(cnt[i][2]>=cnt[i][1]&&cnt[i][2]>=cnt[i][0]&&cnt[i][2]>=cnt[i][3]){ putchar('C'); continue; }
		else putchar('G');
	}
	putchar('\n');
	
	return 0;
}
