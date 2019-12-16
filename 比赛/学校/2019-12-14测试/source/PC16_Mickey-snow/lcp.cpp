#include<bits/stdc++.h>
#define nullptr NULL

int ReadChar(void){
	char in;
	do in = getchar(); while(!('a'<=in && in<='z'));
	return in-'a';
}

const int INT_32_MAX = 10000000;
const int MAXN = 100050;
const int MAXK = 28;

//Suffix Tree
struct Node{
	int start,len,totLen;
	Node *ch[MAXK],*link;
	Node(){ start = 0; len = 0; memset(ch,NULL,sizeof(ch)); link = nullptr; totLen = 0; }
	Node(const int& istart,const int& ilen) : start(istart), len(ilen) { memset(ch,NULL,sizeof(ch)); link = nullptr; totLen = 0; }
}*t0,*nowAt,*virt;
void Build(void){ t0 = new Node(); nowAt = t0; virt = new Node(); }
int s[MAXN],totLen,remain;
void Attend(const int& add){
	s[totLen++] = add; ++remain;
	for(Node* t,*last=virt; remain;){
		while(nowAt->ch[s[totLen-remain]]!=nullptr && remain>nowAt->ch[s[totLen-remain]]->len){
			t = nowAt->ch[s[totLen-remain]]; remain -= t->len; nowAt = t;
		}
		Node*& v = nowAt->ch[s[totLen-remain]]; const int endChar_v = v==nullptr ? MAXK-1 : s[v->start+remain-1];
		if(v==nullptr || endChar_v==add){
			last->link = nowAt; last = nowAt;
			if(v == nullptr) v = new Node(totLen-remain,INT_32_MAX);
			else break;
		} else {
			Node* split = new Node(v->start,remain-1); 
			v->start += remain-1; v->len -= remain-1;
			split->ch[endChar_v] = v; split->ch[add] = new Node(totLen-1,INT_32_MAX);
			last->link = v = split; last = split;
		} if(nowAt == t0) --remain; else nowAt = nowAt->link;
	}
}

int rank[MAXN],cnt;
void Dfs(Node* nowAt,const int prevtot){
	int ch = 0;
	for(int i=0;i<MAXK;i++) if(nowAt->ch[i] != nullptr) ++ch;
	if(ch == 0) nowAt->len = totLen-nowAt->start;
	
	nowAt->totLen = prevtot + nowAt->len;
	for(int i=0;i<MAXK;i++)
		if(nowAt->ch[i] != nullptr)
			Dfs(nowAt->ch[i], nowAt->totLen);
	
	if(ch == 0) rank[totLen-nowAt->totLen] = cnt++;
}

signed main(void)
{
	freopen("lcp.in","r",stdin);
	freopen("lcp.out","w",stdout);
	
	int totChar,totQuery,a,b;
	
	scanf("%d%d", &totChar,&totQuery); Build();
	for(int i=0;i<totChar;i++) Attend(ReadChar()+1); Attend(0); //puts("OK");
	Dfs(t0,0);
	
	//for(int i=0;i<=totChar;i++) std::cout<<rank[i]<<' '; std::cout<<std::endl;
	while(totQuery--){
		scanf("%d%d",&a,&b); --a; --b;
		puts(rank[a]<rank[b] ? "0" : "1");
	}
	
	return 0;
}
