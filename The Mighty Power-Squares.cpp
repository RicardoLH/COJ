#include <string>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <bits/stdc++.h>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
long long int a;
long long int b;
int t;
long long int memo[2][30];

long long int buscaNumero(long long int a){
    if( a == 0 ) return 0;
    long long int suma = 1;
    for( int i = 0; i <= 15; i++ ){
        if( memo[0][i] == a ){
            return memo[1][i];
        }else if( memo[0][i] > a ){
            long long int diferencia = a - memo[0][i-1];
            long long int resultado =  diferencia * (suma >> 1);
            return resultado + memo[1][i-1];
        }
        suma = suma << 1;
    }

}
int main(){
    cin>>t;
    memo[0][0] = 1;
    memo[1][0] = 1;
    long long int temp = 1;
    long long int suma = 1;
    for( int i = 1; i <= 15; i++ ){
        temp = temp << 1;
        memo[0][i] = temp * temp;
        long long int diferencia = memo[0][i] - memo[0][i-1]-1;
        long long int sumaTotal = suma * diferencia;
        sumaTotal += ( suma << 1 );
        sumaTotal += memo[1][i-1];
        memo[1][i] = sumaTotal;
        suma = suma << 1;
    }
    while( t-- ){
        cin>>a;
        cin>>b;
        cout<<buscaNumero(b)-buscaNumero(a-1)<<endl;
    }
    return 0;
}
