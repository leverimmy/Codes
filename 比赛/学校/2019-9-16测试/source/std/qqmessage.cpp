#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 2010

string s1,s2,s3,s4,name;
int cnt;

struct message
{
	string s1,s2,s3,s4;
}v[MAXN];

bool cmp(const message &a,const message &b){
	if(a.s1.compare(b.s1)==0){
		return a.s2.compare(b.s2)<=0;
	}
	else return a.s1.compare(b.s1)<=0;
}

int main()
{
    freopen("qqmessage.in","r",stdin);
    freopen("qqmessage.out","w",stdout);
    cin>>name;getchar();
    while(cin>>s1){
    	cin>>s2>>s3;getchar();
    	getline(cin,s4);
    	if(s3.compare(name)==0) v[++cnt]=(message){s1,s2,s3,s4};
    }
    sort(v+1,v+1+cnt,cmp);
    for(int i=1;i<=cnt;i++) 
    	cout<<v[i].s4<<endl;
    return 0;
}