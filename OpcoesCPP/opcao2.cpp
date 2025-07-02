// Bibliotecas
#include <iostream>
using namespace std;
// Bibliotecas gerais
#include <fstream>
#include <limits>
// Incluindo arquivos
#include "../OpcoesHPP/opcao2.hpp"
#include "../ClassesHPP/alunos.hpp"
#include "../ClassesHPP/pessoas.hpp"
#include "../ClassesHPP/professores.hpp"

/*PROFESSORES*/

// Listar professores
void listarProfessores(Professores *professor[])
{
    if (Professores::TAMPROFESSOR == 0) cout << "\nNão existe nenhum professor cadastrado";
    else
    {
        cout << "\n--- LISTA DE PROFESSORES ---";
        for (int i = 0; i < Professores::TAMPROFESSOR; i++)
        {
            if (professor[i] != nullptr)
            {
                cout << "\nNome: " << professor[i]->getNome()
                     << " - Data de nascimento: " << professor[i]->getDia()
                     << "/" << professor[i]->getMes()
                     << "/" << professor[i]->getAno()
                     << " - CPF: " << professor[i]->getCpf()
                     << " - Título: " << professor[i]->getTitulacao();
            } // Fim do if
        } // Fim do for
    } // Fim do else
    cout << "\n----------------------------\n";
} // Fim da função listarProfessores

/*ALUNOS*/

// Listar alunos
void listarAluno(Alunos *aluno[])
{
    if (Alunos::TAMALUNO == 0) cout << "\nNão existe nenhum aluno cadastrado";
    else
    {
        cout << "\n--- LISTA DE ALUNOS ---";
        for (int i = 0; i < Alunos::TAMALUNO; i++)
        {
            if (aluno[i] != nullptr)
            {
                cout << "\nNome: " << aluno[i]->getNome()
                     << " - Data de nascimento: " << aluno[i]->getDia()
                     << "/" << aluno[i]->getMes()
                     << "/" << aluno[i]->getAno()
                     << " - CPF: " << aluno[i]->getCpf()
                     << " - Matrícula: " << aluno[i]->getNumeroMatricula();
            } // Fim do if
        } // Fim do for
        cout << "\n-----------------------\n";
    } // Fim do else
} // Fim da função listarAluno

/*GERAL*/

// Escolha opção 2
int escolhaOpcao2()
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
    return x;
} // Fim da função escolhaOpcao2

// Opções opção 2
void opcoesOpcao2(int x, Alunos *aluno[], Professores *professor[])
{
    switch (x)
    {
    case 0:
        break;
    case 1:
        listarProfessores(professor);
        break;
    case 2:
        listarAluno(aluno);
        break;
    default:
        break;
    } // Fim do switch
} // Fim da função opcoesOpcao2

// Opção 2
void opcao2(Alunos *aluno[], Professores *professor[])
{
    cout << "\n\n2.0 – Voltar ao menu anterior[0]";
    cout << "\n2.1 - Listar Professores[1]";
    cout << "\n2.2 - Listar Alunos[2]";
    int x = escolhaOpcao2();
    opcoesOpcao2(x, aluno, professor);
} // Fim da função opcao2