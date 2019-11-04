#include<cstdio>
using namespace std;
int sg,tol,tot,LEA,n,N,k,tg,ans,ltg,jl;
char ch;
int l[123123],r[123123],s[123123],min,num[123123],bj[123123]; 
void rro(int& T)
{
     int k;
     k=l[T];
     num[k]+=bj[k];
     if (l[k]) bj[l[k]]+=bj[k];
     if (r[k]) bj[r[k]]+=bj[k];
     bj[k]=0;
     l[T]=r[k]; r[k]=T;
     s[k]=s[T];
     s[T]=s[l[T]]+s[r[T]]+1;
     T=k;    
}
void lro(int& T)
{
     int k;
     k=r[T];
     num[k]+=bj[k];
     if (l[k]) bj[l[k]]+=bj[k];
     if (r[k]) bj[r[k]]+=bj[k];
     bj[k]=0;
     r[T]=l[k]; l[k]=T;
     s[k]=s[T];
     s[T]=s[l[T]]+s[r[T]]+1;
     T=k;     
}
void maintain(int& T)
{
     if (s[r[T]]<s[l[l[T]]])
      rro(T);else
      if (s[r[T]]<s[r[l[T]]])
       lro(l[T]),rro(T);
       else 
       if (s[l[T]]<s[r[r[T]]])
       lro(T);else
             if (s[l[T]]<s[l[r[T]]])
              rro(r[T]),lro(T);else return;
       maintain(l[T]);
       maintain(r[T]);
       maintain(T);
}
void insert(int& T,int up)
{
     if (!num[T]) {num[T]=up; s[T]=1; return;}
     num[T]+=bj[T];
     if (l[T]) bj[l[T]]+=bj[T];                           
     if (r[T]) bj[r[T]]+=bj[T];
     bj[T]=0;
     s[T]++;
     if (up>=num[T])                                              
      if (r[T]) insert(r[T],up);                                                           
      else {tot++; r[T]=tot; insert(tot,up);}              
     if (up<num[T])                              
      if (l[T]) insert(l[T],up);
      else {tot++; l[T]=tot; insert(tot,up);}
     maintain(T);
}
void FID(int T,int rank)
{
     num[T]+=bj[T];
     if (l[T]) bj[l[T]]+=bj[T];                           
     if (r[T]) bj[r[T]]+=bj[T];
     bj[T]=0;
     if (rank==s[l[T]]+1) {jl=T;ans=num[T]; return;}  
     if (rank<=s[l[T]]) FID(l[T],rank);
     if (rank>s[l[T]]) FID(r[T],rank-1-s[l[T]]);
}
void del(int &T,int rk)
{
     num[T]+=bj[T];
     if (l[T]) bj[l[T]]+=bj[T];
     if (r[T]) bj[r[T]]+=bj[T];
     bj[T]=0;
     s[T]--;
     if (rk==num[T]){num[T]=0; T=0; return;}
     if (rk<=num[T] && l[T]) del(l[T],rk);
     if (rk>=num[T] && r[T]) del(r[T],rk);
}
int main()
{
    //freopen("unhappy.in","r",stdin);
    //freopen("unhappy.out","w",stdout);
    scanf("%d %d\n",&N,&min);
    LEA=0;
    tot=1; tol=0;
    tg=1; ltg=1;
    for (;N--;)
    {                                                                               
         scanf("%c ",&ch);
         if (ch=='I') {scanf("%d",&k); if (k>=min) 
         { 
          tol++; insert(tg,k);
          }//else LEA++;
         }
         if (ch=='S') {scanf("%d",&k); if (tol>0)
         {
            sg-=k;
            while (tol>0)             
            {
                  FID(tg,1);
                  if (ans+sg<min)          
                  {
                  del(tg,ans);
                  tol--; LEA++;
                  }else break; 
            }
            if (tg==0) {tg=tot+1; tot++;}
            bj[tg]=sg;
            sg=0;
         }
         }       
         if (ch=='A') {scanf("%d",&k); if (tol>0) sg+=k;}        
         if (ch=='F') {scanf("%d",&k); if (k>tol)  printf("-1\n");else{FID(tg+sg,tol+1-k); printf("%d\n",ans);}}                         
         scanf("\n");
    }
    printf("%d",LEA);
    return 0;
}
