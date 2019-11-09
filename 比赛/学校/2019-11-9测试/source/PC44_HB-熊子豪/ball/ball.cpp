#include<bits/stdc++.h>
using namespace std;
int n;
long double x[200002];
long double r[200002];
struct node{
	int num;
	long double rx;
};
bool operator<(node a,node b){
	return a.rx<b.rx;
}
set<node>s;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	srand(time(unsigned(NULL)));
	n=read();
	for(int i=0;i<n;i++){
		x[i]=read();
		r[i]=read();
	}
	if(n<=2000){
		for(int i=0;i<n;i++){
			for(int j=0;j<i;j++){
				r[i]=min(r[i],(x[i]-x[j])/r[j]*(x[i]-x[j])/4.00000000000);
			}
			printf("%.3Lf\n",r[i]);
		}
	}
	else{
		for(int i=0;i<200;i++){
			for(int j=0;j<i;j++){
				r[i]=min(r[i],(x[i]-x[j])/r[j]*(x[i]-x[j])/4.000000000000);
				node k;
				k.num=i;
				k.rx=r[i];
				s.insert(k);
			}
			printf("%.3Lf\n",r[i]);
		}
		for(int i=200;i<n;i++){
			for(int j=i-100;j<i;j++){
				r[i]=min(r[i],(x[i]-x[j])/r[j]*(x[i]-x[j])/4.000000000000);
			}
			int step=100;
			for(set<node>::iterator it=s.begin();step--;it++){
				long double xi=x[it->num];
				long double ri=it->rx;
				r[i]=min(r[i],(x[i]-xi)/ri*(x[i]-xi)/4);
			}
			step=100;
			while(step--){
				int j=rand()%(i-100);
				r[i]=min(r[i],(x[i]-x[j])/r[j]*(x[i]-x[j])/4.00000000000);
			}
			node k;
			k.num=i;
			k.rx=r[i];
			s.insert(k);
			printf("%.3Lf\n",r[i]);
		}
	}
	return 0;
}
