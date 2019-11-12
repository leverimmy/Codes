#include <bits/stdc++.h>
#define rgi register int
using namespace std;
int n,k,m;
int a[1003][53][53],indx,now,b[53][53];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("chessboard.in","r",stdin);
    freopen("chessboard.out","w",stdout);
    cin>>n>>k>>m;
    for(rgi i=0;i<n;++i)
        for(rgi j=0;j<n;++j)
            b[i][j]=1;
    for(;m;--m)
    {
        string opt;
        cin>>opt;
        if(opt[0]=='P')
        {
            int c,u,d,l,r;
            cin>>c>>u>>l>>d>>r;
            bool odd=(u+l)&1;
            for(rgi i=u;i<=d;++i)
                for(rgi j=l;j<=r;++j)
                    if(((i+j)&1)==odd)
                        b[i][j]=c;
        }
        else if(opt[0]=='S')
        {
        	++indx,now=indx;
            memcpy(a[now],b,sizeof(b));
		}
		else if(opt[0]=='L')
		{
			cin>>now;
            memcpy(b,a[now],sizeof(a[now]));
		}
	}
    for(rgi i=0;i<n;++i)
    {
        for(rgi j=0;j<n;++j)
            cout<<b[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
