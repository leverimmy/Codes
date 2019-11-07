#include <bits/stdc++.h>

char s[10000],t[10000];
char word[11][100]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
char level[100][100]={"","","shi","bai","qian"}; 

int n;

void print(){
	int flag=0;
	int x=std::min(n,4);
	for(int i=x;i>=1;i--){
		if (s[i]=='0')flag++;
		else {
			if (flag)printf("ling ");
			flag=0;
			if (!((x==n)&&s[i]=='1'&&i==2))std::cout<<word[s[i]-'0']<<" ";
			if (i>1)std::cout<<level[i]<<" ";
		}
	}
}

int main(){
	freopen("3.in","r",stdin);
	freopen("3.out","w",stdout);
	scanf("%s",t+1);
	int x=std::strlen(t+1);
	
	std::reverse(t+1,t+x+1);
	for(int i=8;i>=0;i-=4){
		if (i>=x)continue;
		for(int j=1;j<=4;++j)s[j]=t[i+j];
		n=std::min(4,x-i);
	//	printf("%d ",n);
		print();
		if (i==8)printf("yi ");
		if (i==4)printf("wan ");
	}
	return 0;
}
