// Bibliotecas
#include <iostream>
#include <locale.h>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
// Incluindo arquivos
#include "ClassesHPP/pessoas.hpp"
#include "ClassesHPP/alunos.hpp"
#include "ClassesHPP/professores.hpp"
#include "FuncoesGeraisHPP/geral.hpp"
// Definições
using namespace std;
#define _MAX 100
//Main
int main ()
{
    setlocale(LC_ALL, "Portuguese");
    system("chcp 65001 > nul");
    Pessoas *pessoa[_MAX];
    Alunos *aluno[_MAX];
    Professores *professor[_MAX];
    for (int i = 0; i < _MAX; ++i)
    {
        pessoa[i] = nullptr;
        aluno[i] = nullptr;
        professor[i] = nullptr;
    } // Fim do for
    registrandoPessoas(pessoa, aluno, professor);
    instrcoes();
    int x = escolha();
    cout << "\n\nBem-vindo, siga as instruções: ";
    while (x != 0)
    {
        opcoes(x, pessoa, aluno, professor);
        cout << "\n\n   P: " << Professores::TAMPROFESSOR;
        cout << "\n\n   A: " << Alunos::TAMALUNO;
        instrcoes();
        x = escolha();
    } // Fim do while
    fechamento ();
    liberarMemoria(pessoa, aluno, professor);
    return 0;
} // Fim da função main