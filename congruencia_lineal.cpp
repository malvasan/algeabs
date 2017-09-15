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
int inversa(int a,int b)
{

	int q;
	int r;
	int aux_a=a,aux_b=b;
	int cont=0;
	while(r!=0)
	{
        q=aux_a/aux_b;
        r=mod(aux_a,aux_b);
        aux_a=aux_b;
        if(r!=0){
            aux_b=r;
            cont++;
        }
	}
	int cocientes[cont];
	int residuos[cont];
	int aux_cont=cont+2;
	cont=0;
	r=10;
	aux_a=a;
	aux_b=b;
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
    int us[cont+2];
	int vs[cont+2];
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
    //cout<<u<<endl;
    return u;
}

void con_line(int num,int modulo,int congruencia)
{
    int inver=inversa(congruencia,modulo);
    int resultado_sin=inver*num;
    int resultado_con=mod(inver*num,modulo);
    char r= 240;
    cout<<congruencia<<"x"<<r<<num<<"(mod"<<modulo<<")"<<endl;
    cout<<endl;
    cout<<"La respuesta de la congruencia lineal es donde x es: "<<mod(resultado_con*congruencia,modulo)<<endl;
    cout<<endl;
    cout<<"Otros posibles resultados para x: "<<resultado_con<<" ";
    for(int i=1;i<5;i++)
        cout<<resultado_con+(i*modulo)<<" ";
    cout<<endl;
    cout<<endl;
    cout<<"Mas resultados para x: "<<resultado_sin <<" ";
    for(int i=1;i<5;i++)
        cout<<resultado_sin-(i*modulo)<<" ";
    cout<<endl;
}

int main()
{
    con_line(4,7,3);
}
