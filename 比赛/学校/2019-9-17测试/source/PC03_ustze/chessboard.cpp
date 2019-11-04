#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int n;
int g[N][N],match[N],used[N];
char s[N];
int dfs(int u){
    for(int i=1;i<=2*n;i++)
        if(g[u][i]&&!used[i]){
            used[i]=1;
            if(!match[i]||dfs(match[i])){
                match[i]=u;
                return 1;
            }
        }
    return 0;
}
int main(){
	freopen("chessboard.in","r",stdin);
	freopen("chessboard.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
    	scanf("%s",s+1);
    	for(int j=1;j<=n;j++){
    		if(s[j]=='.')
    			g[i][j+n]=1;
		}
	}
	int ans=0;
    for(int i=1;i<=n;i++){
        memset(used,0,sizeof(used));
        if(dfs(i)) ans++;
    }
    printf("%d",ans);
    return 0;
}
