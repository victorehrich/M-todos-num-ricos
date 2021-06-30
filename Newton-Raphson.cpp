#include <iostream>
#include <math.h>
#include <chrono>
#include <iomanip>
using namespace std;
float funcao(float x){
    float y;
    y = pow(x,3)+8*x-7;
    return y;
}
float derivada(float x){
    float y;
    y=3*pow(x,2)+8;
    return y;
}
float newtRaph(float xi, float tolerancia){
    int cont = 0;
    int aux = 0;
    float func, funcLinha,xii,funcXii;
    func=funcao(xi);
    funcLinha=derivada(xi);
    xii = xi - (func/funcLinha);
    funcXii = funcao(xii);
    while(fabs(funcXii)>tolerancia){
        cont++;
        cout<<aux<<" |X"<<aux+1<<" :"<<xii<<"| F(x"<<aux+1<<"): "<<funcXii<<"\n";
        xi = xii;
        func = funcXii;
        funcLinha = derivada(xi);
        xii = xi - (func/funcLinha);
        funcXii = funcao(xii);
        aux++;
    }
        cont++;
        cout<<aux<<" |X"<<aux+1<<" :"<<xii<<"| F(x"<<aux+1<<"): "<<funcXii<<"\n";
    cout<<"numero de iteracoes:"<<cont-1<<"\n";
    return xii;
}
int main()
{
    auto inicio = chrono::high_resolution_clock::now();
    float xi,xii,tolerancia;
    cout<<"Metodo de Newton-Raphson\n";
    cout<<"Funcao x^3+8*x-7\n";
    cout<<"valor inicial X0: 0.5\n";
    //cout<<"Digite o valor de a:\n";
    //cin>>a;
    xi = 0.5;
    cout<<"valor da tolerancia:0.03\n";
    //cout<<"Digite o valor da tolerancia:\n";
    //cin>>tolerancia;
    tolerancia=0.03;
    xii = newtRaph(xi,tolerancia);
    cout<< "Raiz aproximada = " << setprecision(4) << xii;
    auto resultado = chrono::high_resolution_clock::now() - inicio;
    long long microseconds = chrono::duration_cast<chrono::microseconds>(resultado).count();
    cout<<"\nTempo de execucao:"<<microseconds<<"ms\n";
    //system("pause");
    return 0;

}
