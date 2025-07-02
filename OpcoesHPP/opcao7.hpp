#ifndef OPCAO7_H  
#define OPCAO7_H
// Bibliotecas
#include <iostream>
using namespace std;
// Incluindo arquivos
#include "../ClassesHPP/alunos.hpp"
#include "../ClassesHPP/pessoas.hpp"
#include "../ClassesHPP/professores.hpp"

void opcao7(Alunos *aluno[], Professores *professor[]);
int escolhaOpcao7();
void opcoesOpcao7(int x, int *mes, Alunos *aluno[], Professores *professor[]);
void alunosAniversariantesMes(Alunos *aluno[]);
void professoresAniversariantesMes(Professores *professor[]);
int pegandoMesAniversariante();
#endif