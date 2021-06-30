#include <iostream>
#include <chrono>
using namespace std;

int main(){
    auto inicio = chrono::high_resolution_clock::now();
    int i,j,k,n;
    float z[20][20], c, x[10], soma =0.0;
    n = 3;
    cout << "\nEscreva os elementos da matriz aumentada:\n";
    /*for(i=1;i<=n;i++){
        for(j=1;j<=(n+1);j++){
            cout << "z[" << i << "][" << j << "] :";
            cin >> z[i][j];
        }
    }*/

    z[1][1]=10;
    z[1][2]=2;
    z[1][3]=1;
    z[1][4]=7;
    z[2][1]=1;
    z[2][2]=5;
    z[2][3]=1;
    z[2][4]=-8;
    z[3][1]=2;
    z[3][2]=3;
    z[3][3]=10;
    z[3][4]=6;

    for(j=1;j<=n;j++){
        for(i=1;i<=n;i++){
            if(i>j){
                c=-z[i][j]/z[j][j];
                cout << "c" << c;
                for(k=1;k<=n+1;k++){
                    z[i][k] = c*z[j][k]+z[i][k];
                    cout << "\nz[" << i << "][" << k << "] : " << z[i][k]<<"\n";
                }
            }
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n+1;j++){
            if(j!=n+1){
                cout << z[i][j] << " ";
            }
            else{
                cout << z[i][j] << "\n";
            }
        }
    }
    x[n] = z[n][n+1]/z[n][n];

    for(i=n-1;i>=1;i--){
        soma = 0;
        for(j=1+i;j<=n;j++){
            soma = soma + z[i][j]*x[j];
        }
        x[i] = (z[i][n+1] - soma)/z[i][i];
    }
    cout << "\nA solucao eh: \n";
    for(i=1;i<=n; i++){
        cout << "x"<<i<<"="<<x[i]<<"\n";
    }
    auto resultado = chrono::high_resolution_clock::now() - inicio;
    long long microseconds = chrono::duration_cast<chrono::microseconds>(resultado).count();
    cout<<"\nTempo de execucao:"<<microseconds<<"ms\n";
    return 0;
}
