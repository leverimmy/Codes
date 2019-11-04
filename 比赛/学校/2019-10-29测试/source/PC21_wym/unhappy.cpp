#include<bits/stdc++.h>
using namespace std;
int n,k,min_salary,num_left,tag;
char opt;
vector<int>firma;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
	{
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
	{
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
inline void outp(int o1){
	if(o1<0)
		putchar('-'),o1=-o1;
	register int o2=o1/10;
	if(o2)
		outp(o2);
	putchar((o1-(o2<<1)-(o2<<3))^48);
}
int main(){
	freopen("unhappy.in","r",stdin);
	freopen("unhappy.out","w",stdout);
    n=read(),min_salary=read();
    for(int _=1;_<=n;++_){
		cin>>opt,k=read();
//		cout<<opt<<' '<<k<<endl;
        if(opt=='I'){
        	if(k<min_salary)
        		continue;
    		vector<int>::iterator L=lower_bound(firma.begin(),firma.end(),k-tag);
            firma.insert(L,k-tag);
        }
        else if(opt=='A'){
            tag+=k;
    	}
        else if(opt=='S'){
            tag-=k;
            for(vector<int>::iterator it=firma.begin();it!=firma.end();++it){
            	if(*it<min_salary-tag)
					firma.erase(--it),num_left++;
				else
					break;
			}
		}
		else{
			if(k>firma.size())
				outp(-1);
            else
				outp(firma[firma.size()-k]+tag);
            putchar('\n');
        }
    }
    outp(num_left);
    return 0;
}
