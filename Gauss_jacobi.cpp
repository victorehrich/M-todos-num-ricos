#include <iostream>
#include <math.h>
#include <chrono>
using namespace std;

int main(){
    auto inicio = chrono::high_resolution_clock::now();
    int i,j,k,n,cont = 0;
    float z[20][20],b[20],x0[20],p, aux[20], aux2, aux3 ,x[20],conv;
    cout << "\nOrdem da matriz = 3:";
    n = 3;
    cout << "\nEscreva os elementos da matriz:\n";
    /*for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cout << "z[" << i << "][" << j << "] :";
            cin >> z[i][j];
        }
    }*/
    z[1][1]=10;
    z[1][2]=2;
    z[1][3]=1;
    z[2][1]=1;
    z[2][2]=5;
    z[2][3]=1;
    z[3][1]=2;
    z[3][2]=3;
    z[3][3]=10;

    /*cout << "\nEscreva os elementos do vetor b:\n";
    for(i=1;i<=n;i++){
            cout << "b[" << i << "] :";
            cin >> b[i];
    }*/
    b[1]=7;
    b[2]=-8;
    b[3]=6;

    cout << "\Elementos do vetor solucao inicial:\n";
    for(i=1;i<=n;i++){
        x0[i] = b[i]/z[i][i];
    }
    for(i=1;i<=n;i++){
        cout << x0[i] << " ";
    }

    /*cout << "\nEscreva a precisao:\n";
        cout << "p:";
        cin >> p;
    */
    p = 0.05;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cout << z[i][j] << " ";
        }
        cout << "\n";
    }
    do{
        x[1] = (1/z[1][1])*(b[1]-z[1][2]*x0[2]-z[1][3]*x0[3]);
        x[2] = (1/z[2][2])*(b[2]-z[2][1]*x0[1]-z[2][3]*x0[3]);
        x[3] = (1/z[3][3])*(b[3]-z[3][1]*x0[1]-z[3][2]*x0[2]);
        cout << x[1] << " " << x[2] << " " << x[3] <<"\n";

        aux[1] = x[1]-x0[1];
        aux[2] = x[2]-x0[2];
        aux[3] = x[3]-x0[3];


        if(fabs(aux[1])> fabs(aux[2])){
            if(fabs(aux[1])>fabs(aux[3])){
                aux2 = aux[1];
            }
            else{
                aux2 = aux[3];
            }
        }
        else{
            if(fabs(aux[2])>fabs(aux[3])){
                aux2 = aux[2];
            }
            else{
                aux2 = aux[3];
            }
        }
        if(fabs(x[1])>fabs(x[2])){
            if(fabs(x[1])>fabs(x[3])){
                aux3 = x[1];
            }
            else{
                aux3 = x[3];
            }
        }
        else{
            if(fabs(x[2])>fabs(x[3])){
                aux3 = x[2];
            }
            else{
                aux3 = x[3];
            }
        }


        conv = fabs(aux2)/fabs(aux3);
        x0[1] = x[1];
        x0[2] = x[2];
        x0[3] = x[3];
        x[1] = 0;
        x[2] = 0;
        x[3] = 0;

    cont ++;
    }while(conv>p);

    cout << "numero de iterações: " << cont;
    cout << "Solucao: " << "\nx1: " << x0[1] << "\nx2: " << x0[2] << "\nx3: " << x0[3];
    cout << "\nPrecisao: " << conv;
    auto resultado = chrono::high_resolution_clock::now() - inicio;
    long long microseconds = chrono::duration_cast<chrono::microseconds>(resultado).count();
    cout<<"\nTempo de execucao:"<<microseconds<<"ms\n";

    return 0;
}
