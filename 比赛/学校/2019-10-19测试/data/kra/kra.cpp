#pragma GCC optimize(3)
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
#define FOR(i,n,m) for(int i=n;i<=m;i++)
struct ccc{int data,ran;}cc[300010];
int k[300010],r[300010],h[300010];
int n,m,minr=1000000010,c,t;
int mysearch(int x)
{
    int l=0,r=c-1,mid;
    while(l<r)
    {
        mid=l+ceil(1.0*(r-l)/2);
        if(cc[mid].data>=x) r=mid-1;
        else l=mid;
    }
    if(cc[r].data<x) return r;
    else return -1;
}bool mycomp(ccc x,ccc y) {return x.data<=y.data;}
int main()
{
	///freopen("kra9.in","r",stdin);
    ///freopen("kra.out","w",stdout);
	cin>>n>>m;FOR(i,1,n){
        cin>>r[i];
        if(r[i]<minr) {
            minr=r[i];cc[c].data=r[i];
            cc[c].ran=i;c++;
        }
	}FOR(i,0,(c-1)/2) swap(cc[i],cc[c-1-i]);
	///FOR(i,0,c-1)cout<<cc[i].data<<" ";cout<<endl;
	h[0]=n+1;FOR(i,1,m){
        cin>>k[i];t=mysearch(k[i]);
        if(t!=-1) h[i]=min(h[i-1]-1,cc[t].ran-1);
        else h[i]=h[i-1]-1;
        ///cout<<t<<' '<<h[i]<<endl;
	}if(h[m]>0) cout<<h[m];
	else cout<<0;
	return 0;
}
/*
7 3
5 6 4 3 6 2 3
3 2 5
*/
