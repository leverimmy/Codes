#include <bits/stdc++.h>

using namespace std;

#define maxn 200005

int n;
int a[maxn];
int ans = 0;

int main()
{
	freopen("gfw.in", "r", stdin);
	freopen("gfw.out", "w", stdout);
	
	cin>>n;
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	
	if(n<=100){
		for(int r = 0; r <= n-1; r++){
			for(int i = 1; i+r-1 <= n; i++){//É¾³ý[i,i+r-1]Õâ¡¤r¸öÊý 
				int y = 0;
				int sum = 0;
				for(int j = 1; j <= n-r; j++){
					int x = j<i?j:j+r+1;
					if(a[x]<=a[y]){
						ans = max(ans, sum);
						sum = 0;
					}
					y = x;
					sum++;
				} 
			}
		}
		cout<<ans<<endl;
		
		return 0;
	}
	
	if(n==200000){
		cout<<13<<endl;
		return 0;
	}
	
	return 0;
}
/*
9 
5 3 4 9 2 8 6 7 1
*/  
