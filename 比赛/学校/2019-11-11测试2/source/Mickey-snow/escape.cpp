#include<bits/stdc++.h>

enum{ pt,en,start,end };

int ReadChar(void){
    char in;
    do in = getchar(); while(in!='V' && in!='.' && in!='+' && in!='J');
    switch(in){
    case '.': return pt; break;
    case '+': return en; break;
    case 'V': return start; break;
    case 'J': return end; break;
    } return -1;
}

const int MAXN = 550;

int map[MAXN][MAXN],dis[MAXN][MAXN];

struct Point{
    int y,x; int val;
    Point(){}
    Point(const int& iy,const int& ix) : y(iy),x(ix) {}
    Point(const int& iy,const int& ix,const int& ival) : y(iy),x(ix),val(ival) {}

    bool operator < (const Point& comp) const { return val < comp.val; }
    Point operator + (const Point& add) const { return Point(y+add.y,x+add.x); }
    Point& operator += (const Point& add){ return *this = *this + add; }
}dlt[]={Point(-1,0),Point(1,0),Point(0,-1),Point(0,1)};

signed main(void)
{
    freopen("escape.in","r",stdin);
    freopen("escape.out","w",stdout);
    
    int totLine,totList,stx,sty;

    scanf("%d%d", &totLine,&totList);
    for(int i=0;i<totLine;i++)
        for(int j=0;j<totList;j++){
            map[i][j] = ReadChar();
            if(map[i][j] == start) stx=j,sty=i;
        }
    
    std::queue<Point> que;
    memset(dis,-1,sizeof(dis));
    for(int i=0;i<totLine;i++)
        for(int j=0;j<totList;j++)
            if(map[i][j] == en){
                dis[i][j] = 0; que.push(Point(i,j,0));
            }
    Point nowAt,nxt;
    while(!que.empty()){
        nowAt = que.front(); que.pop();
        for(int i=0;i<4;i++){
            nxt = nowAt + dlt[i];
            if(nxt.y>=0 && nxt.y<totLine && nxt.x>=0 && nxt.x<totList && dis[nxt.y][nxt.x]==-1){
                dis[nxt.y][nxt.x] = nowAt.val + 1; que.push(Point(nxt.y,nxt.x,nowAt.val+1));
            }
        }
    }

    int ans = INT_MAX;
    std::priority_queue<Point> queue;
    queue.push(Point(sty,stx,dis[sty][stx])); dis[sty][stx] = -1;
    while(!queue.empty()){
        nowAt = queue.top(); queue.pop(); ans = std::min(ans, nowAt.val);
        if(map[nowAt.y][nowAt.x] == end) break;
        for(int i=0;i<4;i++){
            nxt = nowAt + dlt[i];
            if(nxt.y>=0 && nxt.x>=0 && nxt.y<totLine && nxt.x<totList && dis[nxt.y][nxt.x]!=-1){
                queue.push(Point(nxt.y,nxt.x,std::min(nowAt.val,dis[nxt.y][nxt.x]))); dis[nxt.y][nxt.x] = -1;
            }
        }
    }

    printf("%d\n", ans);
    
    return 0;
}
