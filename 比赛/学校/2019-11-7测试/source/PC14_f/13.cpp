#include<bits/stdc++.h>

signed main(void)
{
	freopen("13.in","r",stdin);
	freopen("13.out","w",stdout);
	
	bool flag = true;
	int n,cnt,now=2;
	std::cin>>n;
	std::cout<<n<<"=";
	while(n>1){
		cnt = 0;
		while(n%now==0){
			n /= now; ++cnt;
		}
		if(cnt > 0){
			if(!flag) putchar('*');
			else flag = false;
			printf("%d", now);
			if(cnt>=2) printf("^%d", cnt);
		} ++now;
	}
	
	return 0;
}
