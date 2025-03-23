//C05EX01F.CPP

#include <iostream>

using namespace std;

int main(void)
{
    int R, I = 0;

    cout << "Programa Numeros Divisiveis por 4 menores de 200" << endl << endl;

    while (I < 200)
    {
        R = I - 4 *(I / 4);

        if (R == 0)
            cout << I << " - ";
        I++;
    }

    cout << endl;
    cout << "Tecle <Enter> para encerrar...";
    cin.get();

    return 0;
}
