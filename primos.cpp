#include <iostream>

using namespace std;

void primos(int n)
{
    int arr[n];
    char pr[n];
    for(int i=1;i<=n;i++){
        arr[i-1]=i;
        pr[i-1]='n';

    }
    pr[0]='p';
    pr[1]='p';
    for(int i=1;i<=n;i++){
        if(pr[i]=='p' || pr[i]=='n'){
            int q=arr[i];
            pr[i]='p';
            for(int i=0;i<=n;i++){
                if(pr[i]=='n'){
                    int t=arr[i]%q;
                    if(t==0)
                        pr[i]='l';
                }
            }
        }
    }
    int cont=0;
    for(int i=0;i<=n-1;i++){
        cout<<arr[i]<<"    " ;
        if(i%10==0)
            cout<<endl;
    }
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;

    for(int i=0;i<=n;i++){

        if(pr[i]=='p'){
            cout<<arr[i]<<"   ";
            cont++;
        }
        if(cont==10){
            cont=0;
            cout<<endl;
        }
    }
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
}

int main()
{
    int p;
    cout<<"Ingrese hasta que numero se buscara: ";
    cin>>p;
    primos(p);
    return 0;
}
