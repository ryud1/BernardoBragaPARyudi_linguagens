#include <iostream>
using namespace std;

int main() {
    char simbolo;
    int estado;
    int tabelaT[11][6] = {
        { 11, 11,  6,  9, 11, 11}, 
        { 11, 11, 11,  9, 11, 11},
        {  3, 11,  0,  7, 11, 11},
        { 11,  4, 11, 11, 11, 11},
        {  5, 11, 11, 11, 11, 11},
        { 11,  2, 11, 11, 11, 11},
        { 11, 11,  0,  7, 11, 11},
        { 11, 11, 11, 11,  1, 11},
        { 11, 11, 11,  7, 11, 11},
        { 11, 11, 11, 11,  8, 11},
        { 11, 11, 11, 11, 11, 11}
    };
    bool ef[11] = {1,1,0,0,0,0,0,0,0,0,0};
    
    estado = 2;
    cout << "Simbolo: ";
    cin >> simbolo;
    while(simbolo != '$'){
        estado = tabelaT[estado][simbolo];
        cout << "Simbolo: ";
        cin >> simbolo;
    }
    if(ef[estado] == 1) {
        cout << "Sentença reconhecida!"<<endl;
    }else{
        cout << "Sentença não reconhecida!" << endl;
    } 

    return 0;
}