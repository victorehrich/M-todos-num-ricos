#include <iostream>
#include <iomanip>
#include <math.h>
#include <chrono>
using namespace std;

float funcao(float x){
    float y;
    y = pow(x,3)+8*x-7;
    return y;
}

float secante(float x, float xi, float tolerancia){
    float funcX,funcXi,funcXii,xii;
    int cont = 0;
    int aux = 0;
    funcX = funcao(x);
    funcXi = funcao(xi);
    xii = (xi-((funcXi * (xi-x))/(funcXi-funcX)));
    funcXii = funcao(xii);
    if(fabs(funcXii)>tolerancia){
        while(fabs(funcXii)>tolerancia){
            cout<<aux<<" |Xi+1: "<<xii<<"| F(xi+1): "<<funcXii<<"\n";
            x = xi;
            xi = xii;
            funcX = funcXi;
            funcXi = funcXii;
            xii = (xi-((funcXi * (xi-x))/(funcXi-funcX)));
            funcXii = funcao(xii);

            aux++;
            cont ++;

        }
    }
    else{
        cout<<aux<<" F(xii): "<<funcXii<<"\n";
    }
    cout<<aux<<" |Xi+1: "<<xii<<"| F(xi+1): "<<funcXii<<"\n";
    cont ++;
    cout<<"numero de iteracoes:"<<cont-1<<"\n";
    return xii;
}
int main(){
    auto inicio = chrono::high_resolution_clock::now();
    float x,xi,xii,tolerancia;
    cout<<"Metodo da posicao falsa\n";
    cout<<"Funcao x^4-2*x-4\n";
    cout<<"valor de Xi-1:0\n";
    //cout<<"Digite o valor de a:\n";
    //cin>>a;
    x=0.5;
    cout<<"valor de Xi:2\n";
    //cout<<"Digite o valor de b:\n";
    //cin>>b;
    xi=0.6;
    cout<<"valor da tolerancia:0.03\n";
    //cout<<"Digite o valor da tolerancia:\n";
    //cin>>tolerancia;
    tolerancia=0.03;
    xii = secante(x,xi,tolerancia);
    cout<< "Raiz aproximada = " << setprecision(4) << xii;
    auto resultado = chrono::high_resolution_clock::now() - inicio;
    long long microseconds = chrono::duration_cast<chrono::microseconds>(resultado).count();
    cout<<"\nTempo de execucao:"<<microseconds<<"ms\n";
    //system("pause");
    return 0;

}
