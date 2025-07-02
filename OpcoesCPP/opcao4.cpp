// Bibliotecas
#include <iostream>
using namespace std;
#include <limits>
// Incluindo arquivos
#include "../OpcoesHPP/opcao4.hpp"
#include "../ClassesHPP/alunos.hpp"
#include "../ClassesHPP/pessoas.hpp"
#include "../ClassesHPP/professores.hpp"

/*PROFESSOR*/

// Pesquisar Professor por CPF
void pesquisarProfessorCPF(Professores *professor[])
{
    cout << "\n\nPesquisar professor por CPF";
    string cpf;

    cout << "\nDigite o CPF que deseja procurar: ";
    getline(cin, cpf);
    bool achou = false;
    for (int i = 0; i < Professores::TAMPROFESSOR; i++)
    {
        if(professor[i] != nullptr && cpf == professor[i]->getCpf())
        {
            cout << "\nNome: " << professor[i]->getNome()
                 << " - Data de nascimento: " << professor[i]->getDia()
                 << "/" << professor[i]->getMes()
                 << "/" << professor[i]->getAno()
                 << " - CPF: " << professor[i]->getCpf()
                 << " - Título: " << professor[i]->getTitulacao() << endl;
            achou = true;
            return;
        } // Fim do if
    } // Fim do for
    if(!achou) cout << "\nNão existe ninguém com esse CPF, verifique se digitou corretamente";
} // Fim da função pesquisarProfessorCPF

/*ALUNO*/

// Pesquisar Aluno por CPF
void pesquisarAlunoCPF(Alunos *aluno[])
{
    cout << "\n\nPesquisar aluno por CPF";
    string cpf;

    cout << "\nDigite o CPF que deseja procurar: ";
    getline(cin, cpf);
    bool achou = false;
    for (int i = 0; i < Alunos::TAMALUNO; i++)
    {
        if(aluno[i] != nullptr && cpf == aluno[i]->getCpf())
        {
            cout << "\nNome: " << aluno[i]->getNome()
                 << " - Data de nascimento: " << aluno[i]->getDia()
                 << "/" << aluno[i]->getMes()
                 << "/" << aluno[i]->getAno()
                 << " - CPF: " << aluno[i]->getCpf()
                 << " - Matrícula: " << aluno[i]->getNumeroMatricula() << endl;
            achou = true;
            return;
        } // Fim do if
    } // Fim do for
    if(!achou) cout << "\nNão existe ninguém com esse CPF, verifique se digitou corretamente";
} // Fim da função pesquisarAlunoCPF

/*GERAL*/

// Opções opção 4
void opcoesOpcao4(int x, Alunos *aluno[], Professores *professor[])
{
    switch (x)
    {
    case 0:
        break;
    case 1:
        pesquisarProfessorCPF(professor);
        break;
    case 2:
        pesquisarAlunoCPF(aluno);
        break;
    default:
        break;
    } // Fim do switch
} // Fim da função opcoesOpcao4

// Escolha opção 4
int escolhaOpcao4()
{
    int x;
    bool erro = true;
    while(erro)
    {
        cout << "\n\nDigite o que deseja: ";
        cin >> x;
        if(x >= 0 && x <= 2) erro = false;
        else cout << "Somente números de 0 a 2\a";
    } // Fim do while
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return x;
} // Fim da função escolhaOpao4

// Opção 4
void opcao4(Alunos *aluno[], Professores *professor[])
{
    cout << "\n\n4.0 – Voltar ao menu anterior[0]";
    cout << "\n4.1 - Pesquisar Professores por CPF[1]";
    cout << "\n4.2 - Pesquisar Alunos por CPF[2]";
    int x = escolhaOpcao4();
    opcoesOpcao4(x, aluno, professor);
} // Fim da função opcao4