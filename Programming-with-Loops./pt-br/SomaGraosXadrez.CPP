//C03EX1K.CPP

#include <iostream>


using namespace std;

int main(void)
{
    int I = 0;
    long int X = 1, S;

    cout << "Programa do somatorio do numero de graos que se pode obter num tabuleiro de xadrez" << endl << endl;

    while(I<=64)
    {
        S = S + X;
        X = X * 2;
        I++;
    }

    cout << "A o somatorio do numero de graos que se pode obter num tabuleiro de xadrez e " << S;

    cout << endl;
    cout << "Tecle <Enter> para encerrar...";
    cin.get();

    return 0;
}
