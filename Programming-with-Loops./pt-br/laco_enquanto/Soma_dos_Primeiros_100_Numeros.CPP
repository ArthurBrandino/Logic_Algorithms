//C05EX01C.CPP

#include <iostream>

using namespace std;

int main(void)
{
    int X, I =0;

    cout << "Programa Soma dos Primeiros 100 Numeros" << endl << endl;

    while (I <= 100)
    {
        X = X + I;

        cout << X << " - ";

        I++;
    }

    cout << endl << endl;

    cout << "Tecle <Enter> para encerrar...";
    cin.get();

    return 0;
}
