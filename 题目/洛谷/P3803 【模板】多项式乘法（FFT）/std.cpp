#include <cstdio>
#include <cmath>
#define Maxn 1350000
using namespace std;
const double Pi=acos(-1);
int n,m;
struct CP
{
  CP (double xx=0,double yy=0){x=xx,y=yy;}
  double x,y;
  CP operator + (CP const &B) const
  {return CP(x+B.x,y+B.y);}
  CP operator - (CP const &B) const
  {return CP(x-B.x,y-B.y);}
  CP operator * (CP const &B) const
  {return CP(x*B.x-y*B.y,x*B.y+y*B.x);}
  //????
}f[Maxn<<1],p[Maxn<<1],sav[Maxn<<1];
void dft(CP *f,int len)
{
  if (len==1)return ;//??
  //????????? 
  CP *fl=f,*fr=f+len/2;
  for (int k=0;k<len;k++)sav[k]=f[k];
  for (int k=0;k<len/2;k++)//?????
    {fl[k]=sav[k<<1];fr[k]=sav[k<<1|1];}
  dft(fl,len/2);
  dft(fr,len/2);//?????
  //??????????????(len????),???????
  CP tG(cos(2*Pi/len),sin(2*Pi/len)),buf(1,0);
  for (int k=0;k<len/2;k++){
    //??buf = (len??????k?) 
    sav[k]=fl[k]+buf*fr[k];//(1)
    sav[k+len/2]=fl[k]-buf*fr[k];//(2)
    //????????Tips???
    buf=buf*tG;//?????????
  }for (int k=0;k<len;k++)f[k]=sav[k];
}
void idft(CP *f,int len)
{
  if (len==1)return ;//??
  //????????? 
  CP *fl=f,*fr=f+len/2;
  for (int k=0;k<len;k++)sav[k]=f[k];
  for (int k=0;k<len/2;k++)//?????
    {fl[k]=sav[k<<1];fr[k]=sav[k<<1|1];}
  idft(fl,len/2);
  idft(fr,len/2);//?????
  CP tG(cos(2*Pi/len),  -  sin(2*Pi/len)),buf(1,0);
              //???  ????! 
  for (int k=0;k<len/2;k++){
    //??buf = (len???????k?) 
    sav[k]=fl[k]+buf*fr[k];
    sav[k+len/2]=fl[k]-buf*fr[k];
    buf=buf*tG;//??????????
  }for (int k=0;k<len;k++)f[k]=sav[k];
}
int main()
{
  scanf("%d%d",&n,&m);
  for (int i=0;i<=n;i++)scanf("%lf",&f[i].x);
  for (int i=0;i<=m;i++)scanf("%lf",&p[i].x);
  for(m+=n,n=1;n<=m;n<<=1);//?????2??
  dft(f,n);dft(p,n);//DFT
  for(int i=0;i<n;++i)f[i]=f[i]*p[i];//?????
  idft(f,n);//IDFT
  for(int i=0;i<=m;++i)printf("%d ",(int)(f[i].x/n+0.49));
  //??????n
  return 0;
}
