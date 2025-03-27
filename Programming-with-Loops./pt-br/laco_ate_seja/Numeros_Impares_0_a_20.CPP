//C05EX02E.CPP

#include <iostream>

using namespace std;

int main(void)
{
    int R, I = 0;

    cout << "Programa Numeros Impares de 0 a 20" << endl << endl;

    while (!(I > 20))
    {
        R = I - 2 *(I / 2);

        if(!(R==0))
            cout << I << " - ";

        I++;
    }

    cout << endl;

    cout << "Tecle <Enter> para encerrar...";
    cin.get();

    return 0;
}
