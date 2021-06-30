#include<iostream>
#include <math.h>
using namespace std;

int main(){
    int n;
    cout << "Digite o número de valores de x e y:\n";
    cin >> n;

    int i;

    cout << "Digite os valores de x:";
    float x[n],x_barra = 0;
    for(i=0;i<n;i++){
        cout <<"\nx["<<i<<"] = ";
        cin >>x[i];
        x_barra +=x[i];
    }
    x_barra = x_barra/n;

    cout << "Digite os valores de y:";
    float y[n],y_barra = 0;
    for(i=0;i<n;i++){
        cout <<"\ny["<<i<<"] = ";
        cin >>y[i];
        y_barra +=y[i];
    }
    y_barra = y_barra/n;

    cout <<"\nax/ = "<< x_barra;
    cout <<"\ny/ = "<< y_barra;

    float alphad = 0 ;
    float alphan = 0 ;
    float alpha;
    for (i=0;i<n;i++){
        if(x[i]-x_barra == 0){i++;}
        alphad += (x[i]-x_barra);
    }

    for (i=0;i<n;i++){
        if(x[i]-x_barra == 0){i++;}
        alphan += ((x[i]-x_barra)*(y[i]-y_barra));
    }
    alpha = alphan/(alphad*alphad);
    cout <<"\nalpha = "<< alpha;

    float beta;
    beta = y_barra - (alpha*x_barra);
    cout <<"\nbeta = "<< beta;

    float x1,y1;

    cout << "\nDigite o valor de x que deseja interpolar:";
    cin >> x1;

    y1 = beta+(alpha*x1);
    cout << "\nO valor de y eh:"<<y1;

    return 0;
}
