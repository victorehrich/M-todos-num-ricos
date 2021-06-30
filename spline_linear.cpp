#include <iostream>
#include <math.h>
using namespace std;

int main(){
    //variaveis contadoras
    int i;

    //Recebe o número de iteraçôes
    cout << "Digite a quantidade de valores que você deseja computar:\n";
    int n;
   n=3;
   // cin >> n;
float y[n];
    float x[n];
   /* //Recebe os valores tabelados para x
    cout << "Digite os valores de X0...Xn:\n";
    float x[n];
    for(i=0;i<n;i++){
        cout << "X["<<i<<"] = \n";
        cin >> x[i];
    }

    //Recebe os valores tabelados para y
    cout << "Digite os valores de Y0...Yn:\n";
    float y[n];
    for(i=0;i<n;i++){
        cout << "Y["<<i<<"] = \n";
        cin >> y[i];
    }
    for(i=0;i<n;i++){
        cout << "X["<<i<<"] = "<<x[i]<<" | Y[" <<i<<"] = "<<y[i]<<"\n";
    }*/
        x[0] = -1;
        x[1] = 0;
        x[2] = 2;

        y[0] = 4;
        y[1] = 1;
        y[2] = -1;

    float s,x1;

    cout<<"Digite o valor de x:";
    //cin >> x1;
    x1=1;

    if(x1 <= x[1] && x1 >= x[0]){
        s = (y[0]*(x[1]- x1)/(x[1]- x[0]))+(y[1]*(x1-x[0])/(x[1]-x[0]));
    }
    else if(x1 <= x[2] && x1 >= x[1]){
        s = (y[1]*(x[2]-x1)/(x[2]-x[1]))+(y[2]*(x1-x[1])/(x[2]-x[1]));
    }
    else{
        cout<< "Nao está no intervalo";
    }

    cout<<"s = "<<s;


    return 0;
}
