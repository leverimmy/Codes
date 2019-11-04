#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define M 408
const double eps=1e-8;
typedef struct
{
	double x1,x2,y1,y2;
	void set(double x1,double y1,double x2,double y2)
	{
		this->x1=x1;
		this->y1=y1;
		this->x2=x2;
		this->y2=y2; 
	}
}
Rec;
Rec r[M];
bool map[M][M];
double x[M],y[M];
int n,nx,ny;
int Cmp(const void *a,const void *b)
{
	return *(double *)a>*(double *)b?1:-1;
}
int Find(double arr[],int low,int up,double v)
{
	int mid=(low+up)>>1;
	if(fabs(arr[mid]-v)<eps)
	return mid;
	if(arr[mid]>v)
	return Find(arr,low,mid-1,v);
	return Find(arr,mid+1,up,v);
}
int main()
{
	double x1,y1,x2,y2,ans;
	int t=1,i,j,i1,i2,j1,j2,k;
	while(scanf("%d",&n),n)
	{
		for(nx=ny=0,i=0;i<n;i++)
		{
			scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
			r[i].set(x1,y1,x2,y2);
			x[nx++]=x1;
			x[nx++]=x2;
			y[ny++]=y1;
			y[ny++]=y2;
		}
		qsort(x,nx,sizeof(x[0]),Cmp);
		qsort(y,ny,sizeof(y[0]),Cmp);
		for(i=0,j=0;i<nx;i++)
		{
			if(fabs(x[i]-x[j])<eps)
			continue;
			x[j++]=x[i];
		}
		nx=j;
		for(i=0,j=0;i<ny;i++)
		{
			if(fabs(y[i]-y[j])<eps)
			continue;
			y[j++]=y[i];
		}
		ny=j;
		memset(map,false,sizeof(map));
		for(i=0;i<n;i++)
		{
			i1=Find(x,0,nx,r[i].x1);
			i2=Find(x,0,nx,r[i].x2);
			j1=Find(y,0,ny,r[i].y1);
			j2=Find(y,0,ny,r[i].y2);
			for(j=i1;j<i2;j++)
			{
				for(k=j1;k<j2;k++)
				map[j][k]=true;
			}
		}
		ans=0.0;
		for(i=0;i<nx;i++)
		{
			for(j=0;j<ny;j++)
			{
				if(map[i][j])
				ans+=(x[i+1]-x[i])*(y[j+1]-y[j]);
			}
		}
		printf("Test case #%d/n",t++);
		printf("Total explored area: ");
		printf("%.2f/n/n",ans);
	}
	return 0;
}
