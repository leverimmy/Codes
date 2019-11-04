int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch)
	{
		if (ch=='-')f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
