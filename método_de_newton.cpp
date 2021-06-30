#include <iostream>
#include <math.h>
using namespace std;

int main(){
    //variaveis contadoras
    int i;

    //Recebe o número de iteraçôes
    cout << "Digite a quantidade de iterações que você deseja fazer:\n";
    int n;
    n=3;
    //cin >> n;
    float x[n];
    float y[n];
    /*//Recebe os valores tabelados para x
    cout << "Digite os valores de X0...Xn:\n";

    for(i=0;i<n;i++){
        cout << "X["<<i<<"] = \n";
        cin >> x[i];
    }

    //Recebe os valores tabelados para y
    cout << "Digite os valores de Y0...Yn:\n";

    for(i=0;i<n;i++){
        cout << "Y["<<i<<"] = \n";
        cin >> y[i];
    }*/
    x[0] = -1;
        x[1] = 0;
        x[2] = 2;

        y[0] = 4;
        y[1] = 1;
        y[2] = -1;

    //Imprime na tela a tabela
    for(i=0;i<n;i++){
        cout << "X["<<i<<"] = "<<x[i]<<" | Y[" <<i<<"] = "<<y[i]<<"\n";
    }
    float d[n];
    for(i=1;i<n;i++){
        d[i-1] = (y[i]-y[i-1])/(x[i]-x[i-1]);
    }
    cout << "\n";
    for(i=0;i<n-1;i++){
        cout << "d["<<i<<"] = "<<d[i]<<"\n";
    }
    for(i=1;i<n-1;i++){
        d[i+1] = (d[i]-d[i-1])/(x[2]-x[0]);
    }
    cout << "\n";
    for(i=0;i<n-2;i++){
        cout << "d["<<2<<"] = "<<d[2]<<"\n";
    }

    float p,x1;

    cout << "Digite o valor do ponto x:\n";
    //cin >> x1;
    x1=1;

    p = y[0]+d[0]*(x1-x[0])+d[2]*(x1-x[0])*(x1-x[1]);

    cout << "p = " <<y[0]<<" + "<<d[0]<<" * "<<x1-x[0]<<" + "<< d[2]<<" * "<<x1-x[1]<<" * "<<x1-x[0]<<"\n";

    cout << "p = " <<p;

    return 0;
}
