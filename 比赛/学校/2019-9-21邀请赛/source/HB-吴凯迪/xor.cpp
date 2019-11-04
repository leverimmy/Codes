#include<bits/stdc++.h>

const int MAXN = 2e5;

int up[MAXN+100];
void Cls(const int &top){ for(int i=0;i<top;i++){ up[i] = i; up[i+top] = i+top; } }
int FindTop(const int& nowAt){ return up[nowAt]==nowAt ? nowAt : up[nowAt]=FindTop(up[nowAt]); }
bool Unity(int a,int b){
	a = FindTop(a); b = FindTop(b);
	if(a == b) return false; 
	up[a] = b; return true;
}

int x[MAXN],y[MAXN],k[MAXN];

signed main(void)
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int totCases;
	int totNums,totOptns;
	bool flag,_0,_1;
	
	scanf("%d", &totCases);
	while(totCases--){
		scanf("%d%d", &totNums,&totOptns); flag = true;
		for(int i=0;i<totOptns;i++){ scanf("%d%d%d", x+i,y+i,k+i); --x[i]; }
		
		for(int bit=0;bit<=30;bit++){
			Cls(totNums+5);			
			for(int i=0;i<totOptns;i++){
				int tk = (k[i]>>bit) & 1;
				switch(tk){
				case 1:
					if(FindTop(x[i])==FindTop(y[i])){ flag = false; break; }
					Unity(x[i], y[i]+totNums+1); Unity(x[i]+totNums+1, y[i]);
					break;
				case 0:
					if(FindTop(x[i]+totNums+1)==FindTop(y[i])){ flag = false; break; }
					Unity(x[i],y[i]); Unity(x[i]+totNums+1,y[i]+totNums+1);
					break;
				} if(!flag) break;
			} if(!flag) break;
		}
		
		puts(flag ? "Yes" : "No");
	}
	
	return 0;
}
