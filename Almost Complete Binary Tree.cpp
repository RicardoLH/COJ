#include <string>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <bits/stdc++.h>


using namespace std;
int t;
int m;
long long int n;
long long int r;
long long int sumaNodos[15];
long long int factoriales[5000];
long long int inversosMod[5000];
long long int a;
long long int b = 1000000007;
long long int d;
long long int x;
long long int y;
void euclides( long long int a, long long int b, long long int *d, long long int *x, long long int *y ){
    if( b == 0 ){
        *d = a;
        *x = 1;
        *y = 0;
    }else{
        euclides( b, a%b, d, x, y );
        long long int xl = 0;
        long long int yl = 0;
        xl = *x;
        yl = *y;
        *x = yl;
        *y = xl - ((a/b)*yl);
    }
}


int main(){
    cin>>t;
    sumaNodos[0] = 1;
    int suma = 1;
    for( int i = 1; i <= 13; i++ ){
        suma = suma << 1;
        sumaNodos[i] = sumaNodos[i-1] + suma;
    }
    factoriales[0] = 1;
    for( int i = 1; i <= 3000; i++ ){
        factoriales[i] = ( factoriales[i-1] * i ) % 1000000007 ;
    }
    inversosMod[0] = 1;
    for( int i = 1; i <= 3000; i++ ){
        long long int numero = factoriales[i-1] * i ;
        euclides(numero,b,&d,&x,&y);
        if( x <= 0 ){
            inversosMod[i] = b + x;
        }else{
            inversosMod[i] = x;
        }
    }
    while( t-- ){
        cin>>m;
        for( int i = 0; i <= 12; i++ ){
            if( sumaNodos[i] == m ){
                cout<<"0"<<endl;
                break;
            }else if( sumaNodos[i] > m ){
                n = sumaNodos[i] - sumaNodos[i-1];
                r = n - (sumaNodos[i] - m);
                // n! / r!(n-r)!;
                long long int resultado = ( ( (factoriales[n] * inversosMod[r]) % 1000000007 ) * inversosMod[n-r] ) % 1000000007;
                cout<<(resultado-1)<<endl;
                break;
            }
        }

    }
    return 0;
}
