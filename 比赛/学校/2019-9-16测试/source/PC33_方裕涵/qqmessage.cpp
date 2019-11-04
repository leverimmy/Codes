#include <iostream>
#include <algorithm>
#define MAXn 1002
using namespace std;
string s1,s2,s3,s4,mainchar;
int cnt;
struct note {
	string sa,sb,sc,sd;
} a[MAXn];
bool cmp(const note &a,const note &b) {
	if(a.sa.compare(b.sa)==0) {
		return a.sb.compare(b.sb)<=0;
	} else return a.sa.compare(b.sa)<=0;
}
int main() {
	freopen("qqmessage.in","r",stdin);
	freopen("qqmessage.out","w",stdout);
	cin>>mainchar;
	getchar();
	while(cin>>s1) {
		cin>>s2>>s3;
		getline(cin,s4);
		getline(cin,s4);
		if(s3==mainchar){
			cnt++;
			a[cnt].sa=s1;
			a[cnt].sb=s2;
			a[cnt].sc=s3;
			a[cnt].sd=s4;
		}
	}
	sort(a+1,a+1+cnt,cmp);
	for(int i=1; i<=cnt; i++)
		cout<<a[i].sd<<endl;
	return 0;
}
