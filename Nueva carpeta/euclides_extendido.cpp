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
int euclides_ex(int a,int b)
{
    if(a<b)
    {
        int c=a;
        a=b;
        b=c;
    }
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
	cout<<aux_cont<<endl;
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
    for(int i=0;i<aux_cont;++i)
        cout<<"-------- ";
    cout<<endl;
    cout<<"|       ";
    cout<<"|        ";
    for(int i=0;i<aux_cont-2;++i)
        cout<<"|q"<<i+1<<"="<<cocientes[i]<<"    ";
    cout<<"|"<<endl;
    for(int i=0;i<aux_cont;++i)
        cout<<"-------- ";
    cout<<endl;
    for(int i=0;i<aux_cont;++i){
        if(i==0||us[i]<0||us[i]>10)
            cout<<"|u"<<i<<"="<<us[i]<<"   ";
        else
            cout<<"|u"<<i<<"="<<us[i]<<"    ";
    }
    cout<<"|"<<endl;
    for(int i=0;i<aux_cont;++i)
        cout<<"-------- ";
    cout<<endl;
    for(int i=0;i<aux_cont;++i){
        if(i==0||vs[i]<0||vs[i]>10)
            cout<<"|v"<<i<<"="<<vs[i]<<"   ";
        else
            cout<<"|v"<<i<<"="<<vs[i]<<"    ";
    }
    cout<<"|"<<endl;
    for(int i=0;i<aux_cont;++i)
        cout<<"-------- ";
    cout<<endl;
    cout<<"|r"<<-1<<"="<<a<<"";
    cout<<"|r"<<0<<"="<<b<<"   ";
    for(int i=0;i<aux_cont-2;++i){
        if(i==0||residuos[i]<0||residuos[i]>10)
            cout<<"|r"<<i+1<<"="<<residuos[i]<<"   ";
        else
            cout<<"|r"<<i+1<<"="<<residuos[i]<<"    ";
    }
    cout<<"|"<<endl;
    for(int i=0;i<aux_cont;++i)
        cout<<"-------- ";
    cout<<endl;
    return 0;
}

int main()
{
    euclides_ex(141,96);
	return 0;
}
