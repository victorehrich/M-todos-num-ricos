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

float bissecao(float a, float b, float tolerancia){
    float funcA,funcB,funcC,c;
    int cont = 0;
    int aux = 0;
    funcA = funcao(a);
    funcB = funcao(b);
        while(fabs(b-a)>tolerancia){
            cont ++;
            c = (a+b)/2;
            funcC = funcao(c);
            cout<<aux<<"c: "<<c<<"| F(c): "<<funcC<<"\n";
            aux++;

            if(funcA*funcC < 0){
                b=c;
                funcB=funcC;
            }
            else{
                a=c;
                funcA=funcC;
            }
        }
    cont ++;
    c = (a+b)/2;
    funcC = funcao(c);
    cout<<aux<<"c: "<<c<<"| F(c): "<<funcC<<"\n";

    cout<<"numero de iteracoes:"<<cont-1<<"\n";
    return c;
}
int main(){
    auto inicio = chrono::high_resolution_clock::now();
    float a,b,c,tolerancia;
    cout<<"Metodo da Bissecao\n";
    cout<<"Funcao x^3+8*x-7\n";
    cout<<"valor de a:0\n";
    a=0;
    cout<<"valor de b:2\n";
    b=1;
    cout<<"valor da tolerancia:0.03\n";
    tolerancia=0.03;
    c = bissecao(a,b,tolerancia);
    cout<< "Raiz aproximada = " << setprecision(4) << c;
    auto resultado = chrono::high_resolution_clock::now() - inicio;
    long long microseconds = chrono::duration_cast<chrono::microseconds>(resultado).count();
    cout<<"\nTempo de execucao:"<<microseconds<<"ms\n";
    //system("pause");
    return 0;

}
