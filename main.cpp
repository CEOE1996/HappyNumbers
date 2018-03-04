#include <iostream>
#include "list.h"
#include "node.h"
#include "num.h"
#include <stdio.h>

using namespace std;

int main()
{
    int Op = 0;
    do{
        int Ent = 0, NInt = 0;
        unsigned long long int Sum;
        bool b = 0;
        Num N;
        Node Nodo;
        List NumOriginal;
        fflush(stdin);
        cout << "Numeros Felices" << endl << "Introduce un Numero: ";
        while(Ent != 32){
            Ent = getchar();
            if(Ent >= 48 and Ent <= 57 ){
                NumOriginal.insertData(NumOriginal.lastPos(), Num(Ent - 48));
            }
        }
        cout << "Longitud Numero: " << NumOriginal.getCounter() << endl;
        List WorkNumber;
        WorkNumber.copyList(NumOriginal);

        do{
            NInt++;
            WorkNumber.SquareNumbers();
            Sum = WorkNumber.SumNumbers();
            if(Sum == 1){
                //if(Num(Sum).IsPrimo())cout << "Primo Feliz ;D" << endl;
                cout << "Numero Feliz =D" << endl;
                b = 1;
            }
            else{
                WorkNumber.deleteAll();
                WorkNumber.SetNumbers(Sum);
            }
        }while(!b and NInt < 20);
        if(!b) cout << "Numero Infeliz =(" << endl;
        fflush(stdin);
        cout << "Deseas Probar Otro Numero? [S / N]" << endl;
        Op = getchar();
    }while(Op == 83 or Op == 115);
    return 0;
}
