#include <iostream>
#include <math.h>
using namespace std;

int main(){
    cout  << "Digite o numero de valores que serao inseridos para x e y:\n";
    int j,i,n;
    //cin >> n;
n=3;
    float x[n],y[n];

    //cout << "Digite os valores para x";
    //for(i=0;i<n;i++){
    //cout <<"\nx["<<i<<"] = ";
    //cin >> x[i];
    //}

        x[0] = -1;
        x[1] = 0;
        x[2] = 2;

        y[0] = 4;
        y[1] = 1;
        y[2] = -1;

    //cout << "Digite os valores para y";
    //for(i=0;i<n;i++){
    //cout <<"\ny["<<i<<"] = ";
    //cin >> y[i];
    //}

    cout <<"Digite o valor do ponto que deseja fazer a interpolacao:\n";
    float xp,den,aux=1,fx=0;
    //cin >> xp;
    xp = 1;

    for(i=0;i<n;i++){
        for(j=0;j<=n;j++){
            if(j==i){
                j++;
            }
            den = 0;
            den = (xp-x[j])/(x[i]-x[j]);
            if(j!=n){
                aux*=den;
            }
        }
        fx=fx+y[i]*aux;

        aux=1;
    }
    printf("%.4f",fx);
}
