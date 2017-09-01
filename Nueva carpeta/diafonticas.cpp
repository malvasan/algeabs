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

int diafonticas(int a,int b,int c)
{
	
	int y;
	y=euclides(a,b);
	float mul;
	int cont=0;
	if(c%y!=0)
		return 0;
	else {
		mul=c/y;
		cout<<endl;
		cout<<endl;
		cout<<a<<" es divisible entre "<<b<<endl;
		cout<<"Si tiene solucion"<<endl;
	}
	int cocientes[20];	//cont
	int residuos[20];	//cont
	int aux_cont=cont+2;
	int q;
	int r;
	int aux_a=a;
	int aux_b=b;
	while(r!=0)
	{
		q=aux_a/aux_b;
		r=mod(aux_a,aux_b);
		aux_a=aux_b;
		if(r!=0){
			aux_b=r;
			cocientes[cont]=q;
			residuos[cont]=r;
			cont++;
		}
	}
	int cont2=0;
	int us[10+2];	// cont 
	int vs[10+2]; 	// cont
	us[0]=1;
	us[1]=0;
	vs[0]=0;
	vs[1]=1;
	while(cont!=0)
	{
		us[cont2+2]=us[cont2]+(-cocientes[cont2]*us[cont2+1]);
		vs[cont2+2]=vs[cont2]+(-cocientes[cont2]*vs[cont2+1]);
		cont2++;
		cont--;
	}
	int u,v;
	u=us[cont2+1];
	v=vs[cont2+1];
	
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<"EL mcd es: "<<y<<endl;
	cout<<"Si hay resouesta "<<y<<"|"<<c<<"="<<mul<<endl;
	cout<<"("<<a<<"*"<<u<<"*"<<mul<<")"<<"+"<<"("<<b<<"*"<<v<<"*"<<mul<<")"<<"="<<c<<endl;

	cout<<"Los valores son:"<<u*mul<<" "<<v*mul<<endl;
}

main()
{
	
	diafonticas(525,100,50);
}
