#include<bits/stdc++.h>

const int MAXN = 500005;

template<typename T1,typename T2>
struct pair{
    T1 first; T2 second;
    pair(){}
    pair(const T1& ifr,const T2& isec) : first(ifr), second(isec) {}
};
template<typename T1,typename T2>
pair<T1,T2> make_pair(const T1& ifr,const T2& isec){ return pair(ifr,isec); }

pair<long double, long double> arr[MAXN];

signed main(void)
{
    freopen("artist.in","r",stdin);
    freopen("artist.out","w",stdout);
    
    pair<long double,long double> sum = make_pair((long double)0,(long double)0);
    long double fr,sec,T,k1,k2,k3,k4,a,b; int totPeo;

    std::cin>>totPeo;
    for(int i=0;i<totPeo;i++){
	std::cin>>arr[i].first>>arr[i].second;
	sum.first += arr[i].first; sum.second += arr[i].second;
    }
    std::cin>>T;

    k1 = T/(sum.first+sum.second)*sum.first;
    long double min = sum.first*k1;
    pair<long double, long double> asum = make_pair((long double)0,(long double)0);
    for(register int i=0;i<totPeo-1;i++){
	asum.first += arr[i].first; asum.second += arr[i].second;
	sum.first -= arr[i].first; sum.second -= arr[i].second;
	k1 = T/(asum.first+asum.second)*asum.first;
	k3 = T/(sum.first+sum.second)*sum.first;
	min = std::min(min, asum.first*k1+sum.first*k3);
	//std::cout<<asum.first<<' '<<asum.second<<' '<<sum.first<<' '<<sum.second<<' '<<k1<<' '<<k2<<' '<<k3<<' '<<k4<<' '<<min<<std::endl;
    }

    printf("%.2Lf\n", min);
    //std::cout<<(double)clock()/CLOCKS_PER_SEC<<std::endl;
    
    return 0;
}
