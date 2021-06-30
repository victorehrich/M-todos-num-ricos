#include <iostream>
#include <math.h>
using namespace std;


//Usaremos a função 1/x^2;

int main(){
    // n -> numero de subintervalos;
    int n,i;
    cout << "Digite o numero de subintervalos\n";
    cin >> n;
    float x[n+1],y[n+1],limInf,limSup;

    cout <<"Digite os dois limites de integracao\n";
    cin >> limInf;
    cin >> limSup;

    float aux,somatorio;

    aux = (-limInf + limSup)/n;
    if(limInf<limSup){
        for(i=0;i<=n;i++){
            x[i] = limInf + aux*i;
            cout<< "x[" <<i << "]: " << x[i] << " || "<<aux <<"\n";
        }
    }
    else{
        for(i=0;i<=n;i++){
            x[i] = limSup + aux*i;
        }
    }
    for(i=0;i<=n;i++){
        y[i] = 1/(pow(x[i],2));
        cout<< "y[" <<i << "]: " << y[i] << " || "<<aux <<"\n";
    }
    float resultado;

    for(i=1;i<n;i++){
        somatorio+=y[i];
        //cout << i << " |" << somatorio <<"\n";
    }

    resultado = (aux/2)*(y[0]+y[n] + 2*(somatorio));

    cout << "O resultado eh:" << resultado << "\n";

    float resultado_2;

    resultado_2 = (-1/limSup) + (1/limInf);

    cout << "a precisao foi de:" << fabs((resultado/resultado_2)-1) << " sendo 0 a precisão = 100%";

    return 0;
}
