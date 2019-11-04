#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int bj[234232],num[232022],s[233203],ans,r[233230],l[233230];
int N,ming,k,tot,tol,LEA,sg,tg;
char ch;
void updata(int T)
{
     num[T]+=bj[T];
     if (l[T]) bj[l[T]]+=bj[T];
     if (r[T]) bj[r[T]]+=bj[T];
     bj[T]=0;
}
void lo(int &T)
{
     int kk; kk=r[T];
     r[T]=l[kk]; l[kk]=T; 
     s[T]=s[l[T]]+s[r[T]]+1;
     s[kk]=s[l[kk]]+s[r[kk]]+1;
     T=kk; 
}
void ro(int &T)
{
     int kk; kk=l[T];
     l[T]=r[kk]; r[kk]=T;
     s[T]=s[l[T]]+s[r[T]]+1;
     s[kk]=s[l[kk]]+s[r[kk]]+1;
     T=kk;
}
void maintain(int &T)
{
     if (s[r[T]]<s[l[l[T]]]) ro(T);else
      if (s[r[T]]<s[r[l[T]]]) lo(l[T]),ro(T);else
       if (s[l[T]]<s[r[r[T]]]) lo(T);else
        if (s[l[T]]<s[l[r[T]]]) ro(r[T]),lo(T);else return;
     maintain(l[T]); maintain(r[T]); maintain(T);
}
void insert(int &T,int up)
{
     if (!T) {T=++tot; num[T]=up; s[T]=1; return;}
     if (up>=num[T]) insert(r[T],up);
     if (up<num[T]) insert(l[T],up);
     s[T]=s[l[T]]+s[r[T]]+1;
     maintain(T);
}
void DEL(int &T)
{
     if (l[T]) DEL(l[T]);
     else {T=r[T]; return;}
     s[T]=s[l[T]]+s[r[T]]+1;
     maintain(T);
}
void FID(int T,int rank)
{

     if (rank==s[l[T]]+1) {ans=num[T]; return;}
     if (rank<=s[l[T]]) FID(l[T],rank);
     else FID(r[T],rank-1-s[l[T]]);
}
int main()
{
    freopen("unhappy.in","r",stdin);
    freopen("unhappy.out","w",stdout);
    scanf("%d %d\n",&N,&ming);
    tol=0; tot=0; LEA=0; tg=0;
    for (;N--;)
    {
          scanf("%c %d\n",&ch,&k);
          if (ch=='I')
          {
                      if (k>=ming) tol++,insert(tg,k-sg);
          }
          if (ch=='A') sg+=k;
          if (ch=='S')
          {
                      sg-=k;
                      while (tol>0)
                      {
                            FID(tg,1);
                            if (ans+sg<ming)
                            {
                                           DEL(tg);
                                           tol--;
                                           LEA++;
                            }else break;
                      }
                      
          }
          if (ch=='F')
           if (k>tol) printf("-1\n");else FID(tg,tol+1-k),printf("%d\n",ans+sg);
    }
    printf("%d",LEA);
    return 0;  
}
