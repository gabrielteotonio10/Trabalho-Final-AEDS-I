// Bibliotecas
#include <iostream>
using namespace std;
// Bibliotecas gerais
#include <fstream>
#include <limits>
// Incluindo arquivos
#include "../OpcoesHPP/opcao5.hpp"
#include "../ClassesHPP/alunos.hpp"
#include "../ClassesHPP/pessoas.hpp"
#include "../ClassesHPP/professores.hpp"

/*PROFESSORES*/
// pesquisaCpfProfessor
bool pesquisaCpfProfessor(string cpf, Professores *professor[])
{
    for(int i = 0; i < Professores::TAMPROFESSOR; i++)
    {
        if (professor[i] != nullptr && professor[i]->getCpf() == cpf) return true;
    } // Fim do for
    return false;
} // Fim da função pesquisaCpfProfessor

// posicaoProfessor
int posicaoProfessor(string cpf, Professores *professor[])
{
    for(int i = 0; i < Professores::TAMPROFESSOR; i++)
    {
        if (professor[i] != nullptr && professor[i]->getCpf() == cpf) return i;
    } // Fim do for
    return -1;
} // Fim da função posicaoProfessor

// excluindoProfessor
void excluindoProfessor(Professores *professor[], int x)
{
    if (professor[x] != nullptr) {
        delete professor[x];
        professor[x] = nullptr;
    } // Fim do if
    for (int i = x; i < Professores::TAMPROFESSOR -1; i++)
    {
        professor[i] = professor[i+1];
    } // Fim do for
    professor[Professores::TAMPROFESSOR -1] = nullptr;
} // Fim da função excluindoProfessor

// apagandoProfessoresArquivo
void apagandoProfessoresArquivo()
{
    ofstream arquivo;
    arquivo.open("professores.txt");
    arquivo.close();
} // Fim da função apagandoProfessoresArquivo

// reescrevendoArquivoProfessor
void reescrevendoArquivoProfessor(Professores *professor[])
{
    ofstream arquivo;
    arquivo.open("professores.txt", ios::app);
    for (int i=0; i<Professores::TAMPROFESSOR; i++)
    {
        arquivo << professor[i]->getNome() << endl
        << professor[i]->getDia() << endl
        << professor[i]->getMes() << endl
        << professor[i]->getAno() << endl
        << professor[i]->getCpf() << endl
        << professor[i]->getTitulacao() << endl
        << "xxxxx" << endl;
    } // Fim do for
    arquivo.close();
} // Fim da função reescrevendoArquivoProfessor

// excluirProfessor
void excluirProfessor(Professores *professor[])
{
    cout << "\n\nExcluir um professor";
    string cpf;
    cout << "\nDigite o CPF do professor que deseja excluir[0 para sair]: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, cpf);
    if(cpf == "0") return;
    if(pesquisaCpfProfessor(cpf, professor))
    {
        string teste;
        cout << "Tem certeza que deseja excluir " << cpf << " ?[S/N]: ";
        cin >> teste;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if(teste == "S" || teste == "s")
        {
            int x = posicaoProfessor(cpf, professor);
            excluindoProfessor(professor, x);
            apagandoProfessoresArquivo();
            reescrevendoArquivoProfessor(professor);
            cout << "\nProfessor excluido com sucesso!";
        } // Fim do if (teste == "S" || teste == "s")
    } // Fim do if (pesquisaCpfProfessor(cpf, professor))
    else cout << "Não existe ninguém com esse CPF, confira se digitou certo";
} // Fim da função excluirProfessor

/*ALUNOS*/

// pesquisaCpfAluno
bool pesquisaCpfAluno(string cpf, Alunos *aluno[])
{
    for(int i = 0; i < Alunos::TAMALUNO; i++)
    {
        if (aluno[i] != nullptr && aluno[i]->getCpf() == cpf) return true;
    } // Fim do for
    return false;
} // Fim da função pesquisaCpfAluno

// posicaoAluno
int posicaoAluno(string cpf, Alunos *aluno[])
{
    for(int i = 0; i < Alunos::TAMALUNO; i++)
    {
        if (aluno[i] != nullptr && aluno[i]->getCpf() == cpf) return i;
    } // Fim do for
    return -1;
} // Fim da função posicaoAluno

// excluindoAluno
void excluindoAluno(Alunos *aluno[], int x)
{
    if (aluno[x] != nullptr) {
        delete aluno[x];
        aluno[x] = nullptr;
    } // Fim do if
    for (int i = x; i < Alunos::TAMALUNO -1; i++)
    {
        aluno[i] = aluno[i+1];
    } // Fim do for
    aluno[Alunos::TAMALUNO -1] = nullptr;
} // Fim da função excluindoAluno

// apagandoAlunosArquivo
void apagandoAlunosArquivo()
{
    ofstream arquivo;
    arquivo.open("alunos.txt");
    arquivo.close();
} // Fim da função apagandoAlunosArquivo

// reescrevendoArquivoAluno
void reescrevendoArquivoAluno(Alunos *aluno[])
{
    ofstream arquivo;
    arquivo.open("alunos.txt", ios::app);
    for (int i=0; i<Alunos::TAMALUNO; i++)
    {
        arquivo << aluno[i]->getNome() << endl
        << aluno[i]->getDia() << endl
        << aluno[i]->getMes() << endl
        << aluno[i]->getAno() << endl
        << aluno[i]->getCpf() << endl
        << aluno[i]->getNumeroMatricula() << endl
        << "xxxxx" << endl;
    } // Fim do for
    arquivo.close();
} // Fim da função reescrevendoArquivoAluno

// excluirAluno
void excluirAluno(Alunos *aluno[])
{
    cout << "\n\nExcluir um aluno";
    string cpf;
    cout << "\nDigite o CPF do aluno que deseja excluir[0 para sair]: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, cpf);
    if(cpf == "0") return;
    if(pesquisaCpfAluno(cpf, aluno))
    {
        string teste;
        cout << "Tem certeza que deseja excluir " << cpf << " ?[S/N]: ";
        cin >> teste;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if(teste == "S" || teste == "s")
        {
            int x = posicaoAluno(cpf, aluno);
            excluindoAluno(aluno, x);
            apagandoAlunosArquivo();
            reescrevendoArquivoAluno(aluno);
            cout << "\nAluno excluido com sucesso!";
        } // Fim do if (teste == "S" || teste == "s")
    } // Fim do if (pesquisaCpfAluno(cpf, aluno))
    else cout << "Não existe ninguém com esse CPF, confira se digitou certo";
} // Fim da função excluirAluno

/*CÓDIGOL GERAL*/

// opcoesOpcao5
void opcoesOpcao5(int x, Alunos *aluno[], Professores *professor[])
{
    switch (x)
    {
    case 0:
        break;
    case 1:
        excluirProfessor(professor);
        break;
    case 2:
        excluirAluno(aluno);
        break;
    default:
        break;
    } // Fim do switch
} // Fim da função opcoesOpcao5

// escolhaOpcao5
int escolhaOpcao5()
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
} // Fim da função escolhaOpcao5

// opcao5
void opcao5(Alunos *aluno[], Professores *professor[])
{
    cout << "\n\n5.0 – Voltar ao menu anterior[0]";
    cout << "\n5.1 - Excluir professor pelo CPF[1]";
    cout << "\n5.2 - Excluir aluno pelo CPF[2]";
    int x = escolhaOpcao5();
    opcoesOpcao5(x, aluno, professor);
} // Fim da função opcao5