#include<cstdio>
using namespace std;
inline long long read(){
    long long x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x;
}
void outp(long long o1){
	register long long o2=o1/10;
	if(o2)
		outp(o2);
	putchar((o1-(o2<<1)-(o2<<3))^48);
}
struct matrix{
	long long cont[810][810];
}mt1,mt2,mtans;
long long s[810][810],n,m,t1,t2,t3,t4,limi,limj,limk,limtmp;
namespace qwq{
	void solve(){
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				mt1.cont[i][j]=read();
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j){
				mt2.cont[i][j]=read();
			}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				for(int k=1;k<=n;++k)
					mtans.cont[i][j]+=mt1.cont[i][k]*mt2.cont[k][j];
			}
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				s[i][j]=s[i][j-1]+s[i-1][j]-s[i-1][j-1]+mtans.cont[i][j];
			}
		}
		for(int i=1;i<=m;++i){
			t1=read(),t2=read(),t3=read(),t4=read();
			if(t1>t3){
				t1^=t3,
				t3^=t1,
				t1^=t3;
			}
			if(t2>t4){
				t2^=t4,
				t4^=t2,
				t2^=t4;
			}
			outp(s[t3][t4]-s[t3][t2-1]-s[t1-1][t4]+s[t1-1][t2-1]),
			putchar('\n');
		}
		return;
	}
}
int main(){
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	n=read(),m=read();
	limi=limj=limk=n/8,
	limtmp=n-limi*8;
	if(n<=200){
		qwq::solve();
		return 0;
	}
	for(int i=1;i<=n;++i){
//		cout<<i<<endl;
		for(int j=1;j+7<=n;j+=8)
			mt1.cont[i][j]=read(),
			mt1.cont[i][j+1]=read(),
			mt1.cont[i][j+2]=read(),
			mt1.cont[i][j+3]=read(),
			mt1.cont[i][j+4]=read(),
			mt1.cont[i][j+5]=read(),
			mt1.cont[i][j+6]=read(),
			mt1.cont[i][j+7]=read();
		for(int j=limj*8+1;j<=n;++j)
			mt1.cont[i][j]=read();
	}
	for(int i=1;i<=n;++i){
//		cout<<i<<endl;
		for(int j=1;j+7<=n;j+=8)
			mt2.cont[i][j]=read(),
			mt2.cont[i][j+1]=read(),
			mt2.cont[i][j+2]=read(),
			mt2.cont[i][j+3]=read(),
			mt2.cont[i][j+4]=read(),
			mt2.cont[i][j+5]=read(),
			mt2.cont[i][j+6]=read(),
			mt2.cont[i][j+7]=read();
		for(int j=limj*8+1;j<=n;++j)
			mt2.cont[i][j]=read();
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j+7<=n;j+=8){
			for(int k=1;k+7<=n;k+=8)
				mtans.cont[i][j]+=mt1.cont[i][k]*mt2.cont[k][j],
				mtans.cont[i][j]+=mt1.cont[i][k+1]*mt2.cont[k+1][j],
				mtans.cont[i][j]+=mt1.cont[i][k+2]*mt2.cont[k+2][j],
				mtans.cont[i][j]+=mt1.cont[i][k+3]*mt2.cont[k+3][j],
				mtans.cont[i][j]+=mt1.cont[i][k+4]*mt2.cont[k+4][j],
				mtans.cont[i][j]+=mt1.cont[i][k+5]*mt2.cont[k+5][j],
				mtans.cont[i][j]+=mt1.cont[i][k+6]*mt2.cont[k+6][j],
				mtans.cont[i][j]+=mt1.cont[i][k+7]*mt2.cont[k+7][j];
			for(int k=limk*8+1;k<=n;++k)
				mtans.cont[i][j]+=mt1.cont[i][k]*mt2.cont[k][j];
			for(int k=1;k+7<=n;k+=8)
				mtans.cont[i][j+1]+=mt1.cont[i][k]*mt2.cont[k][j+1],
				mtans.cont[i][j+1]+=mt1.cont[i][k+1]*mt2.cont[k+1][j+1],
				mtans.cont[i][j+1]+=mt1.cont[i][k+2]*mt2.cont[k+2][j+1],
				mtans.cont[i][j+1]+=mt1.cont[i][k+3]*mt2.cont[k+3][j+1],
				mtans.cont[i][j+1]+=mt1.cont[i][k+4]*mt2.cont[k+4][j+1],
				mtans.cont[i][j+1]+=mt1.cont[i][k+5]*mt2.cont[k+5][j+1],
				mtans.cont[i][j+1]+=mt1.cont[i][k+6]*mt2.cont[k+6][j+1],
				mtans.cont[i][j+1]+=mt1.cont[i][k+7]*mt2.cont[k+7][j+1];
			for(int k=limk*8+1;k<=n;++k)
				mtans.cont[i][j+1]+=mt1.cont[i][k]*mt2.cont[k][j+1];
			for(int k=1;k+7<=n;k+=8)
				mtans.cont[i][j+2]+=mt1.cont[i][k]*mt2.cont[k][j+2],
				mtans.cont[i][j+2]+=mt1.cont[i][k+1]*mt2.cont[k+1][j+2],
				mtans.cont[i][j+2]+=mt1.cont[i][k+2]*mt2.cont[k+2][j+2],
				mtans.cont[i][j+2]+=mt1.cont[i][k+3]*mt2.cont[k+3][j+2],
				mtans.cont[i][j+2]+=mt1.cont[i][k+4]*mt2.cont[k+4][j+2],
				mtans.cont[i][j+2]+=mt1.cont[i][k+5]*mt2.cont[k+5][j+2],
				mtans.cont[i][j+2]+=mt1.cont[i][k+6]*mt2.cont[k+6][j+2],
				mtans.cont[i][j+2]+=mt1.cont[i][k+7]*mt2.cont[k+7][j+2];
			for(int k=limk*8+1;k<=n;++k)
				mtans.cont[i][j+2]+=mt1.cont[i][k]*mt2.cont[k][j+2];
			for(int k=1;k+7<=n;k+=8)
				mtans.cont[i][j+3]+=mt1.cont[i][k]*mt2.cont[k][j+3],
				mtans.cont[i][j+3]+=mt1.cont[i][k+1]*mt2.cont[k+1][j+3],
				mtans.cont[i][j+3]+=mt1.cont[i][k+2]*mt2.cont[k+2][j+3],
				mtans.cont[i][j+3]+=mt1.cont[i][k+3]*mt2.cont[k+3][j+3],
				mtans.cont[i][j+3]+=mt1.cont[i][k+4]*mt2.cont[k+4][j+3],
				mtans.cont[i][j+3]+=mt1.cont[i][k+5]*mt2.cont[k+5][j+3],
				mtans.cont[i][j+3]+=mt1.cont[i][k+6]*mt2.cont[k+6][j+3],
				mtans.cont[i][j+3]+=mt1.cont[i][k+7]*mt2.cont[k+7][j+3];
			for(int k=limk*8+1;k<=n;++k)
				mtans.cont[i][j+3]+=mt1.cont[i][k]*mt2.cont[k][j+3];
			for(int k=1;k+7<=n;k+=8)
				mtans.cont[i][j+4]+=mt1.cont[i][k]*mt2.cont[k][j+4],
				mtans.cont[i][j+4]+=mt1.cont[i][k+1]*mt2.cont[k+1][j+4],
				mtans.cont[i][j+4]+=mt1.cont[i][k+2]*mt2.cont[k+2][j+4],
				mtans.cont[i][j+4]+=mt1.cont[i][k+3]*mt2.cont[k+3][j+4],
				mtans.cont[i][j+4]+=mt1.cont[i][k+4]*mt2.cont[k+4][j+4],
				mtans.cont[i][j+4]+=mt1.cont[i][k+5]*mt2.cont[k+5][j+4],
				mtans.cont[i][j+4]+=mt1.cont[i][k+6]*mt2.cont[k+6][j+4],
				mtans.cont[i][j+4]+=mt1.cont[i][k+7]*mt2.cont[k+7][j+4];
			for(int k=limk*8+1;k<=n;++k)
				mtans.cont[i][j+4]+=mt1.cont[i][k]*mt2.cont[k][j+4];
			for(int k=1;k+7<=n;k+=8)
				mtans.cont[i][j+5]+=mt1.cont[i][k]*mt2.cont[k][j+5],
				mtans.cont[i][j+5]+=mt1.cont[i][k+1]*mt2.cont[k+1][j+5],
				mtans.cont[i][j+5]+=mt1.cont[i][k+2]*mt2.cont[k+2][j+5],
				mtans.cont[i][j+5]+=mt1.cont[i][k+3]*mt2.cont[k+3][j+5],
				mtans.cont[i][j+5]+=mt1.cont[i][k+4]*mt2.cont[k+4][j+5],
				mtans.cont[i][j+5]+=mt1.cont[i][k+5]*mt2.cont[k+5][j+5],
				mtans.cont[i][j+5]+=mt1.cont[i][k+6]*mt2.cont[k+6][j+5],
				mtans.cont[i][j+5]+=mt1.cont[i][k+7]*mt2.cont[k+7][j+5];
			for(int k=limk*8+1;k<=n;++k)
				mtans.cont[i][j+5]+=mt1.cont[i][k]*mt2.cont[k][j+5];
			for(int k=1;k+7<=n;k+=8)
				mtans.cont[i][j+6]+=mt1.cont[i][k]*mt2.cont[k][j+6],
				mtans.cont[i][j+6]+=mt1.cont[i][k+1]*mt2.cont[k+1][j+6],
				mtans.cont[i][j+6]+=mt1.cont[i][k+2]*mt2.cont[k+2][j+6],
				mtans.cont[i][j+6]+=mt1.cont[i][k+3]*mt2.cont[k+3][j+6],
				mtans.cont[i][j+6]+=mt1.cont[i][k+4]*mt2.cont[k+4][j+6],
				mtans.cont[i][j+6]+=mt1.cont[i][k+5]*mt2.cont[k+5][j+6],
				mtans.cont[i][j+6]+=mt1.cont[i][k+6]*mt2.cont[k+6][j+6],
				mtans.cont[i][j+6]+=mt1.cont[i][k+7]*mt2.cont[k+7][j+6];
			for(int k=limk*8+1;k<=n;++k)
				mtans.cont[i][j+6]+=mt1.cont[i][k]*mt2.cont[k][j+6];
			for(int k=1;k+7<=n;k+=8)
				mtans.cont[i][j+7]+=mt1.cont[i][k]*mt2.cont[k][j+7],
				mtans.cont[i][j+7]+=mt1.cont[i][k+1]*mt2.cont[k+1][j+7],
				mtans.cont[i][j+7]+=mt1.cont[i][k+2]*mt2.cont[k+2][j+7],
				mtans.cont[i][j+7]+=mt1.cont[i][k+3]*mt2.cont[k+3][j+7],
				mtans.cont[i][j+7]+=mt1.cont[i][k+4]*mt2.cont[k+4][j+7],
				mtans.cont[i][j+7]+=mt1.cont[i][k+5]*mt2.cont[k+5][j+7],
				mtans.cont[i][j+7]+=mt1.cont[i][k+6]*mt2.cont[k+6][j+7],
				mtans.cont[i][j+7]+=mt1.cont[i][k+7]*mt2.cont[k+7][j+7];
			for(int k=limk*8+1;k<=n;++k)
				mtans.cont[i][j+7]+=mt1.cont[i][k]*mt2.cont[k][j+7];
		}
		for(int j=limj*8+1;j<=n;++j){
			for(int k=1;k+7<=n;k+=8)
				mtans.cont[i][j]+=mt1.cont[i][k]*mt2.cont[k][j],
				mtans.cont[i][j]+=mt1.cont[i][k+1]*mt2.cont[k+1][j],
				mtans.cont[i][j]+=mt1.cont[i][k+2]*mt2.cont[k+2][j],
				mtans.cont[i][j]+=mt1.cont[i][k+3]*mt2.cont[k+3][j],
				mtans.cont[i][j]+=mt1.cont[i][k+4]*mt2.cont[k+4][j],
				mtans.cont[i][j]+=mt1.cont[i][k+5]*mt2.cont[k+5][j],
				mtans.cont[i][j]+=mt1.cont[i][k+6]*mt2.cont[k+6][j],
				mtans.cont[i][j]+=mt1.cont[i][k+7]*mt2.cont[k+7][j];
			for(int k=limk*8+1;k<=n;++k)
				mtans.cont[i][j]+=mt1.cont[i][k]*mt2.cont[k][j];
		}
	}
	for(int i=1;i+7<=n;i+=8){
		for(int j=1;j+7<=n;j+=8){
			s[i][j]=s[i][j-1]+s[i-1][j]-s[i-1][j-1]+mtans.cont[i][j],
			s[i][j+1]=s[i][j]+s[i-1][j+1]-s[i-1][j]+mtans.cont[i][j+1],
			s[i][j+2]=s[i][j+1]+s[i-1][j+2]-s[i-1][j+1]+mtans.cont[i][j+2],
			s[i][j+3]=s[i][j+2]+s[i-1][j+3]-s[i-1][j+2]+mtans.cont[i][j+3],
			s[i][j+4]=s[i][j+3]+s[i-1][j+4]-s[i-1][j+3]+mtans.cont[i][j+4],
			s[i][j+5]=s[i][j+4]+s[i-1][j+5]-s[i-1][j+4]+mtans.cont[i][j+5],
			s[i][j+6]=s[i][j+5]+s[i-1][j+6]-s[i-1][j+5]+mtans.cont[i][j+6],
			s[i][j+7]=s[i][j+6]+s[i-1][j+7]-s[i-1][j+6]+mtans.cont[i][j+7];
		}
		for(int j=limj*8+1;j<=n;++j)
			s[i][j]=s[i][j-1]+s[i-1][j]-s[i-1][j-1]+mtans.cont[i][j];
		for(int j=1;j+7<=n;j+=8){
			s[i+1][j]=s[i+1][j-1]+s[i][j]-s[i][j-1]+mtans.cont[i+1][j],
			s[i+1][j+1]=s[i+1][j]+s[i][j+1]-s[i][j]+mtans.cont[i+1][j+1],
			s[i+1][j+2]=s[i+1][j+1]+s[i][j+2]-s[i][j+1]+mtans.cont[i+1][j+2],
			s[i+1][j+3]=s[i+1][j+2]+s[i][j+3]-s[i][j+2]+mtans.cont[i+1][j+3],
			s[i+1][j+4]=s[i+1][j+3]+s[i][j+4]-s[i][j+3]+mtans.cont[i+1][j+4],
			s[i+1][j+5]=s[i+1][j+4]+s[i][j+5]-s[i][j+4]+mtans.cont[i+1][j+5],
			s[i+1][j+6]=s[i+1][j+5]+s[i][j+6]-s[i][j+5]+mtans.cont[i+1][j+6],
			s[i+1][j+7]=s[i+1][j+6]+s[i][j+7]-s[i][j+6]+mtans.cont[i+1][j+7];
		}
		for(int j=limj*8+1;j<=n;++j)
			s[i+1][j]=s[i+1][j-1]+s[i][j]-s[i][j-1]+mtans.cont[i+1][j];
		for(int j=1;j+7<=n;j+=8){
			s[i+2][j]=s[i+2][j-1]+s[i+1][j]-s[i+1][j-1]+mtans.cont[i+2][j],
			s[i+2][j+1]=s[i+2][j]+s[i+1][j+1]-s[i+1][j]+mtans.cont[i+2][j+1],
			s[i+2][j+2]=s[i+2][j+1]+s[i+1][j+2]-s[i+1][j+1]+mtans.cont[i+2][j+2],
			s[i+2][j+3]=s[i+2][j+2]+s[i+1][j+3]-s[i+1][j+2]+mtans.cont[i+2][j+3],
			s[i+2][j+4]=s[i+2][j+3]+s[i+1][j+4]-s[i+1][j+3]+mtans.cont[i+2][j+4],
			s[i+2][j+5]=s[i+2][j+4]+s[i+1][j+5]-s[i+1][j+4]+mtans.cont[i+2][j+5],
			s[i+2][j+6]=s[i+2][j+5]+s[i+1][j+6]-s[i+1][j+5]+mtans.cont[i+2][j+6],
			s[i+2][j+7]=s[i+2][j+6]+s[i+1][j+7]-s[i+1][j+6]+mtans.cont[i+2][j+7];
		}
		for(int j=limj*8+1;j<=n;++j)
			s[i+2][j]=s[i+2][j-1]+s[i+1][j]-s[i+1][j-1]+mtans.cont[i+2][j];
		for(int j=1;j+7<=n;j+=8){
			s[i+3][j]=s[i+3][j-1]+s[i+2][j]-s[i+2][j-1]+mtans.cont[i+3][j],
			s[i+3][j+1]=s[i+3][j]+s[i+2][j+1]-s[i+2][j]+mtans.cont[i+3][j+1],
			s[i+3][j+2]=s[i+3][j+1]+s[i+2][j+2]-s[i+2][j+1]+mtans.cont[i+3][j+2],
			s[i+3][j+3]=s[i+3][j+2]+s[i+2][j+3]-s[i+2][j+2]+mtans.cont[i+3][j+3],
			s[i+3][j+4]=s[i+3][j+3]+s[i+2][j+4]-s[i+2][j+3]+mtans.cont[i+3][j+4],
			s[i+3][j+5]=s[i+3][j+4]+s[i+2][j+5]-s[i+2][j+4]+mtans.cont[i+3][j+5],
			s[i+3][j+6]=s[i+3][j+5]+s[i+2][j+6]-s[i+2][j+5]+mtans.cont[i+3][j+6],
			s[i+3][j+7]=s[i+3][j+6]+s[i+2][j+7]-s[i+2][j+6]+mtans.cont[i+3][j+7];
		}
		for(int j=limj*8+1;j<=n;++j)
			s[i+3][j]=s[i+3][j-1]+s[i+2][j]-s[i+2][j-1]+mtans.cont[i+3][j];
		for(int j=1;j+7<=n;j+=8){
			s[i+4][j]=s[i+4][j-1]+s[i+3][j]-s[i+3][j-1]+mtans.cont[i+4][j],
			s[i+4][j+1]=s[i+4][j]+s[i+3][j+1]-s[i+3][j]+mtans.cont[i+4][j+1],
			s[i+4][j+2]=s[i+4][j+1]+s[i+3][j+2]-s[i+3][j+1]+mtans.cont[i+4][j+2],
			s[i+4][j+3]=s[i+4][j+2]+s[i+3][j+3]-s[i+3][j+2]+mtans.cont[i+4][j+3],
			s[i+4][j+4]=s[i+4][j+3]+s[i+3][j+4]-s[i+3][j+3]+mtans.cont[i+4][j+4],
			s[i+4][j+5]=s[i+4][j+4]+s[i+3][j+5]-s[i+3][j+4]+mtans.cont[i+4][j+5],
			s[i+4][j+6]=s[i+4][j+5]+s[i+3][j+6]-s[i+3][j+5]+mtans.cont[i+4][j+6],
			s[i+4][j+7]=s[i+4][j+6]+s[i+3][j+7]-s[i+3][j+6]+mtans.cont[i+4][j+7];
		}
		for(int j=limj*8+1;j<=n;++j)
			s[i+4][j]=s[i+4][j-1]+s[i+3][j]-s[i+3][j-1]+mtans.cont[i+4][j];
		for(int j=1;j+7<=n;j+=8){
			s[i+5][j]=s[i+5][j-1]+s[i+4][j]-s[i+4][j-1]+mtans.cont[i+5][j],
			s[i+5][j+1]=s[i+5][j]+s[i+4][j+1]-s[i+4][j]+mtans.cont[i+5][j+1],
			s[i+5][j+2]=s[i+5][j+1]+s[i+4][j+2]-s[i+4][j+1]+mtans.cont[i+5][j+2],
			s[i+5][j+3]=s[i+5][j+2]+s[i+4][j+3]-s[i+4][j+2]+mtans.cont[i+5][j+3],
			s[i+5][j+4]=s[i+5][j+3]+s[i+4][j+4]-s[i+4][j+3]+mtans.cont[i+5][j+4],
			s[i+5][j+5]=s[i+5][j+4]+s[i+4][j+5]-s[i+4][j+4]+mtans.cont[i+5][j+5],
			s[i+5][j+6]=s[i+5][j+5]+s[i+4][j+6]-s[i+4][j+5]+mtans.cont[i+5][j+6],
			s[i+5][j+7]=s[i+5][j+6]+s[i+4][j+7]-s[i+4][j+6]+mtans.cont[i+5][j+7];
		}
		for(int j=limj*8+1;j<=n;++j)
			s[i+5][j]=s[i+5][j-1]+s[i+4][j]-s[i+4][j-1]+mtans.cont[i+5][j];
		for(int j=1;j+7<=n;j+=8){
			s[i+6][j]=s[i+6][j-1]+s[i+5][j]-s[i+5][j-1]+mtans.cont[i+6][j],
			s[i+6][j+1]=s[i+6][j]+s[i+5][j+1]-s[i+5][j]+mtans.cont[i+6][j+1],
			s[i+6][j+2]=s[i+6][j+1]+s[i+5][j+2]-s[i+5][j+1]+mtans.cont[i+6][j+2],
			s[i+6][j+3]=s[i+6][j+2]+s[i+5][j+3]-s[i+5][j+2]+mtans.cont[i+6][j+3],
			s[i+6][j+4]=s[i+6][j+3]+s[i+5][j+4]-s[i+5][j+3]+mtans.cont[i+6][j+4],
			s[i+6][j+5]=s[i+6][j+4]+s[i+5][j+5]-s[i+5][j+4]+mtans.cont[i+6][j+5],
			s[i+6][j+6]=s[i+6][j+5]+s[i+5][j+6]-s[i+5][j+5]+mtans.cont[i+6][j+6],
			s[i+6][j+7]=s[i+6][j+6]+s[i+5][j+7]-s[i+5][j+6]+mtans.cont[i+6][j+7];
		}
		for(int j=limj*8+1;j<=n;++j)
			s[i+6][j]=s[i+6][j-1]+s[i+5][j]-s[i+5][j-1]+mtans.cont[i+6][j];
		for(int j=1;j+7<=n;j+=8){
			s[i+7][j]=s[i+7][j-1]+s[i+6][j]-s[i+6][j-1]+mtans.cont[i+7][j],
			s[i+7][j+1]=s[i+7][j]+s[i+6][j+1]-s[i+6][j]+mtans.cont[i+7][j+1],
			s[i+7][j+2]=s[i+7][j+1]+s[i+6][j+2]-s[i+6][j+1]+mtans.cont[i+7][j+2],
			s[i+7][j+3]=s[i+7][j+2]+s[i+6][j+3]-s[i+6][j+2]+mtans.cont[i+7][j+3],
			s[i+7][j+4]=s[i+7][j+3]+s[i+6][j+4]-s[i+6][j+3]+mtans.cont[i+7][j+4],
			s[i+7][j+5]=s[i+7][j+4]+s[i+6][j+5]-s[i+6][j+4]+mtans.cont[i+7][j+5],
			s[i+7][j+6]=s[i+7][j+5]+s[i+6][j+6]-s[i+6][j+5]+mtans.cont[i+7][j+6],
			s[i+7][j+7]=s[i+7][j+6]+s[i+6][j+7]-s[i+6][j+6]+mtans.cont[i+7][j+7];
		}
		for(int j=limj*8+1;j<=n;++j)
			s[i+7][j]=s[i+7][j-1]+s[i+6][j]-s[i+6][j-1]+mtans.cont[i+7][j];
	}
	for(int i=limi*8+1;i<=n;++i){
		for(int j=1;j+7<=n;j+=8){
			s[i][j]=s[i][j-1]+s[i-1][j]-s[i-1][j-1]+mtans.cont[i][j],
			s[i][j+1]=s[i][j]+s[i-1][j+1]-s[i-1][j]+mtans.cont[i][j+1],
			s[i][j+2]=s[i][j+1]+s[i-1][j+2]-s[i-1][j+1]+mtans.cont[i][j+2],
			s[i][j+3]=s[i][j+2]+s[i-1][j+3]-s[i-1][j+2]+mtans.cont[i][j+3],
			s[i][j+4]=s[i][j+3]+s[i-1][j+4]-s[i-1][j+3]+mtans.cont[i][j+4],
			s[i][j+5]=s[i][j+4]+s[i-1][j+5]-s[i-1][j+4]+mtans.cont[i][j+5],
			s[i][j+6]=s[i][j+5]+s[i-1][j+6]-s[i-1][j+5]+mtans.cont[i][j+6],
			s[i][j+7]=s[i][j+6]+s[i-1][j+7]-s[i-1][j+6]+mtans.cont[i][j+7];
		}
		for(int j=limj*8+1;j<=n;++j)
			s[i][j]=s[i][j-1]+s[i-1][j]-s[i-1][j-1]+mtans.cont[i][j];
	}
	for(int i=1;i<=m;++i){
		t1=read(),t2=read(),t3=read(),t4=read();
		if(t1>t3){
			t1^=t3,
			t3^=t1,
			t1^=t3;
		}
		if(t2>t4){
			t2^=t4,
			t4^=t2,
			t2^=t4;
		}
		outp(s[t3][t4]-s[t3][t2-1]-s[t1-1][t4]+s[t1-1][t2-1]),
		putchar('\n');
	}
	return 0;
}
