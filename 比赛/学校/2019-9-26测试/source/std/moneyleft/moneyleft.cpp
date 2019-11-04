#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,x,y,a[210][210],f[210][210];
int Fmax(int x1,int x2,int x3,int x4,int x5){
    return max(max(x1,x2),max(max(x3,x4),x5));
}
int main(){
    freopen("moneyleft.in","r",stdin);
    freopen("moneyleft.ans","w",stdout);
    scanf("%d%d",&n,&m);
    memset(a,0,sizeof(a));
    memset(f,0,sizeof(f));
    for(int i=1;i<=n;i++){
        for(int j=2;j<=m+1;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=2;i<=m+1;i++)f[1][i]=a[1][i];
    for(int i=2;i<=n;i++){
        for(int j=2;j<=m+1;j++){
            f[i][j]=a[i][j]+Fmax(f[i-1][j-2],f[i-1][j-1],f[i-1][j],f[i-1][j+1],f[i-1][j+2]);
        }
    }
    x=n;y=(m/2)+2;
    printf("%d\n",Fmax(f[x][y-2],f[x][y-1],f[x][y],f[x][y+1],f[x][y+2]));
}