// Bibliotecas
#include <iostream>
using namespace std;
// Bibliotecas gerais
#include <fstream>
#include <limits>
// Incluindo arquivos
#include "../OpcoesHPP/opcao6.hpp"
#include "../ClassesHPP/alunos.hpp"
#include "../ClassesHPP/pessoas.hpp"
#include "../ClassesHPP/professores.hpp"

/*PROFESSORES*/

// Deletar todos os professores
void deletarTodosProfessores(Professores *professor[])
{
    ofstream arquivo;
    arquivo.open("pessoas.txt");
    arquivo.close();
    for(int i = 0; i < Professores::TAMPROFESSOR; i++)
    {
        delete(professor[i]);
    } // Fim do for
    cout << "\n\nPessoas apagadas com sucesso";
} // Fim da função deletarTodosProfessores

/*ALUNOS*/

// Deletar todos os alunos
void deletarTodosAlunos(Alunos *aluno[])
{
    ofstream arquivo;
    arquivo.open("alunos.txt");
    arquivo.close();
    for(int i = 0; i < Alunos::TAMALUNO; i++)
    {
        delete(aluno[i]);
    } // Fim do for
    cout << "\n\nPessoas apagadas com sucesso";
} // Fim da função deletarTodosAlunos

/*GERAL*/

// Opções opção 6
void opcoesOpcao6(int x, Alunos *aluno[], Professores *professor[])
{
    switch (x)
    {
    case 0:
        break;
    case 1:
        deletarTodosProfessores(professor);
        break;
    case 2:
        deletarTodosAlunos(aluno);
        break;
    default:
        break;
    } // Fim do switch
} // Fim da função opcoesOpcao6

// Escolha opção 6
int escolhaOpcao6()
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
} // Fim da função escolhaOpcao6

// Opção 6
void opcao6 (Alunos *aluno[], Professores *professor[])
{
    cout << "\n\n6.0 – Voltar ao menu anterior[0]";
    cout << "\n6.1 - Excluir todos os professores[1]";
    cout << "\n6.2 - Excluir todos os alunos[2]";
    int x = escolhaOpcao6();
    opcoesOpcao6(x, aluno, professor);
} // Fim da função opcao6