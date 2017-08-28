#include <iostream>
using namespace std;

int mod(int a, int b)
{
	int c=a-(b*(a/b));
	if(c<0){
		c=b+c;
		return c;
	}
	else
	   return c;
}


int euclides(int a, int b)
{
	int q;
	int r;
	while(r!=0)
	{
	q=a/b;
	r=mod(a,b);
	cout<<a<<"="<<b<<"*"<<q<<"+"<<r<<endl;
	a=b;
	if(r!=0)
		b=r;
	}
	return b;
}


int main()
{
	cout<<euclides(96,141)<<endl;
	return 0;
}


