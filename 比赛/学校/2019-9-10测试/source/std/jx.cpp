/*当前不取就从前一个取或不取中选最优。
当前取，那前一个可以不取，也可以取。前一个取又分两种，一是i跟i-1连在一起，二是i自成一个子序列。
*/
#include <queue>
#include <stack>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int f[1000006][4][2],n,a[1000006];
int main(){
//    freopen("jx.in","r",stdin);
//    freopen("jx.out","w".,stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    memset(f,128,sizeof(f)); f[0][0][0]=0;
    for (int i=1;i<=n;i++)
        for (int j=0;j<=3;j++){
            f[i][j][0]=max(f[i-1][j][0],f[i-1][j][1]);//当前不取就从前一个取或不取中选最优
            if (j-1>=0) f[i][j][1]=max(f[i-1][j-1][0]+a[i],f[i-1][j-1][1]+a[i]);
            //当前取，那前一个可以不取，也可以取。
            f[i][j][1]=max(f[i][j][1],f[i-1][j][1]+a[i]);
           //前一个取分两种，一是i自成一个子序列，二是i跟i-1连在一起。
        }
    printf("%d",max(f[n][3][0],f[n][3][1]));
    fclose(stdin); fclose(stdout);
    return 0;
}
