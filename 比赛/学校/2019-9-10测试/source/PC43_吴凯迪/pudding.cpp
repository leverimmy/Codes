#include<bits/stdc++.h>

struct Node{
	int l,r;
	Node(){}
	Node(const int& il,const int& ir) : l(il),r(ir) {}
	
	bool operator < (const Node& Comp) const {
		return l < Comp.l;
	}
};

std::map<int, std::set<Node>*> map;

signed main(void)
{
	freopen("pudding.in","r",stdin);
	freopen("pudding.out","w",stdout);
	
	int totNums,totOptn,opt,fr,to,last,now,cnt=1,begin,end;
	
	scanf("%d%d%d",&totNums,&totOptn,&last); fr = 0;
	for(int i=1;i<totNums;i++){
		scanf("%d", &now);
		if(now != last){
			if(map[last] == NULL) map[last] = new std::set<Node>;
			map[last]->insert(Node(fr,i-1)); fr = i; ++cnt; last = now;
		} 
	} 
	if(map[last] == NULL) map[last] = new std::set<Node>;
	map[last]->insert(Node(fr,totNums-1));
	
	std::pair<std::set<Node>::iterator, bool> ret;
	std::set<Node>::iterator nowAt,prev,nxt; bool mark;
	while(totOptn--){
		scanf("%d", &opt);
		switch(opt){
		case 1:
			scanf("%d%d", &fr,&to);
			if(map[fr] == NULL) break;
			if(map[to] == NULL){ map[to] = map[fr]; map[fr] = NULL; break; }
			
			for(std::set<Node>::iterator it=map[fr]->begin();it!=map[fr]->end();it++){
				ret = map[to]->insert(*it);
				nowAt = ret.first; prev = --nowAt; ++nowAt; nxt = ++nowAt; --nowAt;
				if(nowAt != map[to]->begin() && nxt != map[to]->end() && nowAt->l-1==prev->r && nowAt->r+1==nxt->l){
					begin = prev->l; end = nxt->r; cnt -= 2;
					map[to]->erase(prev,++nxt); map[to]->insert(Node(begin,end));
				} else if(nowAt != map[to]->begin() && nowAt->l-1==prev->r){
					begin = prev->l; end = nowAt->r; --cnt;
					map[to]->erase(prev,nxt); map[to]->insert(Node(begin,end));
				} else if(nxt != map[to]->end() && nowAt->r+1==nxt->l){
					begin = nowAt->l; end = nxt->r; --cnt;
					map[to]->erase(nowAt,++nxt); map[to]->insert(Node(begin,end));
				}
			} delete map[fr]; map[fr] = NULL;
			break;
		case 2:
			printf("%d\n", cnt);
			break;
		default: assert(false); break;
		}
	}
	
	return 0;
}
