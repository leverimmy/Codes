#include <stdio.h>
int x[300001],s[300001],book[200001]={0};
int main()
{
    freopen("catchcow.in","r",stdin);
	  freopen("catchcow.out","w",stdout);    
        int i,k,e,tail,head,t;
    scanf("%d%d",&k,&e);
    head=1;tail=1;
    x[tail]=k;
    s[tail]=0;
    tail++;
    book[k]=1;
    while(1>0)
    {
        t=x[head]*2;
        if(t<=100000 && book[t]==0)
        {
            x[tail]=t;
            s[tail]=s[head]+1;
            tail++;
            book[t]=1;
            if(x[tail-1]==e)
                break;
        }         
        t=x[head]-1;
        if(t<=100000 && book[t]==0)
        {
            x[tail]=t;
            s[tail]=s[head]+1;
            tail++;
            book[t]=1;
            if(x[tail-1]==e)
                break;
        }         
        t=x[head]+1;
        if(t<=100000 && book[t]==0)
        {
            x[tail]=t;
            s[tail]=s[head]+1;
            tail++;
            book[t]=1;
            if(x[tail-1]==e)
                break;
        }
          
        head++;
    }
    printf("%d",s[tail-1]);
    return 0;
}
