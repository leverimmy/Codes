#include <bits/stdc++.h>
#define maxn 200005
#define ll long long
int n,m,opt,x,y,hd,tp;
std::pair<ll,ll>q[maxn<<1];
ll k,b;

void push_back(ll x,ll y){
	#define x2 q[tp].first
	#define y2 q[tp].second
	#define x1 q[tp-1].first
	#define y1 q[tp-1].second
	while (tp-hd+1>=2){
		if ((__int128)(y-y2)*(x2-x1)<(__int128)(y2-y1)*(x-x2))tp--;
		else break;
	}
	q[++tp].first=x;q[tp].second=y;
	#undef x2
	#undef y2
	#undef x1
	#undef y1
}

void push_front(ll x,ll y){
	#define x2 q[hd].first
	#define y2 q[hd].second
	#define x1 q[hd+1].first
	#define y1 q[hd+1].second
	while (tp-hd+1>=2){
		if ((__int128)(y2-y)*(x1-x2)>=(__int128)(y1-y2)*(x2-x))hd++;
		else break;
	}
	q[hd].first=x;q[hd].second=y;
	#undef x2
	#undef y2
	#undef x1
	#undef y1
}

void update(ll k){
	#define x2 q[tp].first
	#define y2 q[tp].second
	#define x1 q[tp-1].first
	#define y1 q[tp-1].second
	while (hd<tp&&(__int128)(y2-y1)>=(__int128)k*(x2-x1))tp--;
	#undef x2
	#undef y2
	#undef x1
	#undef y1
}

int main(){
	freopen("dance.in","r",stdin);
	freopen("dance.out","w",stdout);
	scanf("%d%d",&n,&m);
	k=b=0;tp=0;hd=1;
	push_back(0,0);
	while (m--){
		scanf("%d",&opt);
		if (opt==1){
			scanf("%d",&x);
			b+=x*k;
			n+=x;
			push_front(0,-b);
		}if (opt==2){
			scanf("%d",&x);
			push_back(n,-k*n-b);
			n+=x;
		}if (opt==3){
			scanf("%d%d",&x,&y);
			b+=x;k+=y;
		}update(-k);
	//	for(int i=hd;i<=tp;++i)printf(">%lld %lld\n",q[i].first,q[i].second);
		printf("%d %lld\n",q[tp].first+1,k*q[tp].first+q[tp].second+b);
	}
	return 0;
}
