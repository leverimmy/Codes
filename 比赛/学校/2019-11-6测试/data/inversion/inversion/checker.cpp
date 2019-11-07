#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
const double eps=1e-6;
int main(int argc,char *argv)
{
	registerTestlibCmd(argc,argv);
	double xs=ouf.readDouble(),bd=ans.readDouble();
	if(fabs(xs-bd)<=eps)
		quitf(_ok,"AC");
	else
		quitf(_wa,"Should be %lf instead of %lf",bd,xs);
}
