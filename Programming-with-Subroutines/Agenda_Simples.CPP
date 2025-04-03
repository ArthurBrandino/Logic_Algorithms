//C10EX01A

#include <iostream>
#include <iomanip>
#include <cctype> // Para funções de manipulação de caracteres, como toupper

using namespace std;

// Variável global que indica quantos cadastros foram realizados
int I = 0;

// Vetores globais para armazenar nome, endereço e telefone de até 10 pessoas
string nome[10], endereco[10], telefone[10];

// Função para organizar os cadastros por ordem alfabética de nome
void Organizar(void)
{
    string T;

    for(int X = 0; X < I - 1; X++) // Percorre todos os elementos cadastrados
    {
        for(int Y = X + 1; Y < I; Y++)
        {
            if(nome[Y] < nome[X]) // Verifica se o nome está fora de ordem
            {
                // Troca os nomes
                T = nome[X];
                nome[X] = nome[Y];
                nome[Y] = T;

                // Troca os endereços correspondentes
                T = endereco[X];
                endereco[X] = endereco[Y];
                endereco[Y] = T;

                // Troca os telefones correspondentes
                T = telefone[X];
                telefone[X] = telefone[Y];
                telefone[Y] = T;
            }
        }
    }
}

// Função para cadastrar novos registros
void Cadastro(void)
{
    char resp = 'S'; // Controle para continuar cadastrando

    while(I < 10 && resp != 'N') // Limite de 10 cadastros
    {
        system("cls"); // Limpa a tela no Windows
        system("clear"); // Limpa a tela no Linux

        // Cabeçalho visual
        cout << setfill('*') << setw(15) << "" << endl;
        cout << setfill(' ');
        cout << "* " << setw(3) << "CADASTRO" << setw(3) << " *" << endl;
        cout << setfill('*') << setw(15) << "" << endl;
        cout << setfill(' ');

        // Entrada dos dados
        cout << "Entre com o Nome: "; getline(cin, nome[I]);
        cout << endl;

        cout << "Exemplo: Rua Seu Nunca" << endl;
        cout << "Entre com o Endereco: "; getline(cin, endereco[I]);
        cout << endl;

        cout << "Exemplo: (XX) XXXX-XXXX" << endl;
        cout << "Entre com o Telefone: "; getline(cin, telefone[I]);
        cout << endl;

        // Deseja continuar?
        cout << "Deseja continuar cadastrando? (S/N) "; cin >> resp;
        cin.ignore(80, '\n');
        resp = toupper(resp); // Converte para maiúsculo

        I++; // Incrementa o contador de cadastros
    }

    Organizar(); // Ordena os cadastros

    cout << "Tecle <Enter> para continuar...";
    cin.get();
}

// Função para pesquisar um nome e mostrar os dados correspondentes
void Pesquisa(void)
{
    char resp = 'S';
    string pesq;

    while(resp != 'N') // Continua enquanto o usuário quiser pesquisar
    {
        system("cls");
        system("clear");

        // Cabeçalho
        cout << setfill('*') << setw(15) << "" << endl;
        cout << setfill(' ');
        cout << "* " << setw(3) << "PESQUISA" << setw(3) << " *" << endl;
        cout << setfill('*') << setw(15) << "" << endl;
        cout << setfill(' ');

        // Entrada do nome a pesquisar
        cout << "Entre com o Nome: "; getline(cin, pesq);
        cout << endl;

        // Procura nos registros
        for(int J = 0; J < I; J++)
        {
            if(pesq == nome[J]) // Se encontrou
            {
                cout << "Nome: " << nome[J] << endl;
                cout << "Endereco: " << endereco[J] << endl;
                cout << "Telefone: " << telefone[J] << endl;
                break;
            }
            if(J == 9) // Se chegou ao fim sem encontrar
                cout << "Nome " << pesq << " nao encontrado no sistema!" << endl;
        }

        // Deseja continuar?
        cout << "Deseja continuar pesquisando? (S/N) "; cin >> resp;
        cin.ignore(80, '\n');
        resp = toupper(resp);
    }
    cout << "Tecle <Enter> para continuar...";
    cin.get();
}

// Função para exibir os registros cadastrados e editar se desejado
void Registros(void)
{
    char escolhe;
    int X, N;

    do
    {
        system("cls");
        system("clear");

        // Cabeçalho
        cout << setfill('*') << setw(15) << "" << endl;
        cout << setfill(' ');
        cout << "* " << setw(3) << "Registros" << setw(3) << " *" << endl;
        cout << setfill('*') << setw(15) << "" << endl;
        cout << setfill(' ');

        // Cabeçalho da tabela
        cout << left << setw(5) << "N.o";
        cout << left << setw(20) << "NOME";
        cout << left << setw(25) << "ENDERECO";
        cout << left << setw(15) << "TELEFONE" << endl << endl;

        if(nome[0].empty()) // Se não há cadastros
        {
            cout << "Nenhum Dado foi Cadastrado!" << endl << endl;
            escolhe = 'N';
        }
        else
        {
            // Mostra todos os cadastros feitos
            for(int J = 0; J < I; J++)
            {
                cout << left << setw(5) << J + 1;
                cout << left << setw(20) << nome[J];
                cout << left << setw(25) << endereco[J];
                cout << left << setw(15) << telefone[J] << endl;
            }

            // Deseja editar?
            cout << "Deseja editar algum dado? (S/N)"; cin >> escolhe;
            cin.ignore(80, '\n');
            escolhe = toupper(escolhe);

            if(escolhe == 'S')
            {
                cout << "Entre com o N.o dos dados que deseja editar: "; cin >> X;
                cin.ignore(80, '\n');

                if(X <= 0 || X > I) {
                    cout << "Número inválido!" << endl;
                    break;
                }

                // Mostra o dado atual
                cout << left << setw(5) << "N.o";
                cout << left << setw(20) << "NOME";
                cout << left << setw(25) << "ENDERECO";
                cout << left << setw(15) << "TELEFONE" << endl << endl;

                cout << left << setw(5) << X ;
                cout << left << setw(20) << nome[X - 1];
                cout << left << setw(25) << endereco[X - 1];
                cout << left << setw(15) << telefone[X - 1] << endl << endl;

                // Menu de edição
                cout << "Tecle (1) para alterar Nome, Endereco e Telefone" << endl;
                cout << "Tecle (2) para alterar apenas o Nome" << endl;
                cout << "Tecle (3) para alterar apenas o Endereco" << endl;
                cout << "Tecle (4) para alterar apenas o Telefone" << endl;
                cout << "Tecle (0) para Cancelar a Operacao" << endl;
                cin >> N; cin.ignore(80, '\n');

                switch(N)
                {
                    case 0:
                        cout << "Operacao Cancelada!" << endl;
                        break;

                    case 1:
                        cout << "Opcao de alterar Nome, Endereco e Telefone foi Selecionada !" << endl;
                        cout << "Entre com o novo Nome: "; getline(cin, nome[X - 1]);
                        cout << "Entre com o novo Endereco: "; getline(cin, endereco[X - 1]);
                        cout << "Entre com o novo Telefone: "; getline(cin, telefone[X - 1]);
                        cout << "Mudancas Salvas com Sucesso!" << endl; break;

                    case 2:
                        cout << "Opcao de alterar apenas o Nome foi Selecionada !" << endl;
                        cout << "Entre com o novo Nome: "; getline(cin, nome[X - 1]);
                        cout << "Mudanca Salva com Sucesso!" << endl; break;

                    case 3:
                        cout << "Opcao de alterar apenas o Endereco foi Selecionada !" << endl;
                        cout << "Entre com o novo Endereco: "; getline(cin, endereco[X - 1]);
                        cout << "Mudanca Salva com Sucesso!" << endl; break;

                    case 4:
                        cout << "Opcao de alterar apenas o Telefone foi Selecionada !" << endl;
                        cout << "Entre com o novo Telefone: "; getline(cin, telefone[X - 1]);
                        cout << "Mudanca Salva com Sucesso!" << endl; break;

                    default:
                        cout << "Opcao invalida!" << endl;
                }

                Organizar(); // Reorganiza os dados após a edição
            }
        }

    }while(escolhe != 'N');

    cout << "Tecle <Enter> para continuar...";
    cin.get();
}

// Função principal
int main(void)
{
    int opcao;
    bool sair = false;

    do
    {
        system("cls");
        system("clear");

        // Exibe o menu principal
        cout << "Programa de Cadastro de Registros" << endl << endl;

        cout << setfill('*') << setw(30) << "" << endl;
        cout << setfill(' ');
        cout << "*      PAGINA INICIAL      *" << endl;
        cout << setfill('*') << setw(30) << "" << endl;
        cout << setfill(' ');

        cout << setfill('*') << setw(30) << "" << endl;
        cout << setfill(' ');
        cout << "*         (1) Cadastrar         *" << endl;
        cout << "*         (2) Pesquisar         *" << endl;
        cout << "*         (3) Registros         *" << endl;
        cout << "*         (0) Sair              *" << endl;
        cout << setfill('*') << setw(30) << "" << endl;
        cout << setfill(' ');
        cout << "Opcao: "; cin >> opcao; cin.ignore(80, '\n');

        // Executa a função com base na escolha
        switch(opcao)
        {
            case 0:
                sair = true;
                break;

            case 1:
                cout << "Opcao de Cadastro foi Selecionada !" << endl;
                cout << "Tecle <Enter> para continuar..."; cin.get();
                Cadastro(); break;

            case 2:
                cout << "Opcao de Pesquisa foi Selecionada !" << endl;
                cout << "Tecle <Enter> para continuar..."; cin.get();
                Pesquisa(); break;

            case 3:
                cout << "Opcao de Registros foi Selecionada !" << endl;
                cout << "Tecle <Enter> para continuar..."; cin.get();
                Registros(); break;

            default:
                cout << "Opcao invalida!" << endl;
        }
    }while(sair == false);

    cout << "Tecle <Enter> para encerrar...";
    cin.get();

    return 0;
}
