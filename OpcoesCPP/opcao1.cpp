// Bibliotecas
#include <iostream>
using namespace std;
// Bibliotecas gerais
#include <fstream>
#include <limits>
// Incluindo arquivos
#include "../OpcoesHPP/opcao1.hpp"
// Incluindo arquivos
#include "../ClassesHPP/alunos.hpp"
#include "../ClassesHPP/pessoas.hpp"
#include "../ClassesHPP/professores.hpp"

/*ALUNOS*/

// Escrevendo aluno no arquivo
void escrevendoAlunoArquivo(Alunos *aluno)
{
    ofstream arquivo;
    if(Alunos::TAMALUNO == 0) arquivo.open("alunos.txt");
    else arquivo.open("alunos.txt", ios::app);
    // Nome
    arquivo << aluno->getNome() << endl
    // Data
    << aluno->getDia() << endl
    << aluno->getMes() << endl
    << aluno->getAno() << endl
    // CPF
    << aluno->getCpf() << endl
    // Número de matrícula
    << aluno->getNumeroMatricula() << endl
    << "xxxxx" << endl;
    arquivo.close();
} // Fim da função escrevendoAlunoArquivo

// Cadastrar alunos
void cadastrarAluno(Pessoas *pessoa[], Alunos *aluno[])
{
    string nome;
    // Nome
    cout << "\n\nDigite seu nome: ";
    cin.ignore();
    getline(cin, nome);
    // CPF
    std::string cpf = registrandoCpf(pessoa);
    // Data
    int dia, mes, ano;
    bool erro = true;
    while (erro)
    {
        cout << "\nDigite sua data de nascimento[xx/xx/xxxx]: ";
        scanf("%d/%d/%d", &dia, &mes, &ano);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (!validandoData(dia, mes, ano)) erro = false;
    } // Fim do while
    // Matrícula
    string matricula = registrandoMatricula(aluno);
    // Adicionando
    try
    {
        aluno[Alunos::TAMALUNO] = new Alunos(nome, dia, mes, ano, cpf, matricula);
        escrevendoAlunoArquivo(aluno[Alunos::TAMALUNO]);
        // Mensagens
        cout << "\nPessoa cadastrada com sucesso!";
        cout << endl << "Total de pessoas: " << Pessoas::TAMPES;
        cout << endl << "Total de professores: " << Professores::TAMPROFESSOR;
        cout << endl << "Total de alunos: " << Alunos::TAMALUNO;
    }// Fim do try
    catch(bad_alloc x)
    {
        cout << "\nMemória máxima atingida";
    }// Fim do catch
} // Fim da função cadastrarAluno

// Conferindo matrícula
/*bool conferinfoMatricula(string matricula, Alunos *aluno[])
{
    for (int i=0; i<Alunos::TAMALUNO; i++)
    {
       if(aluno[i]->getNumeroMatricula()==matricula) return false;
    }
    return true;
}*/

// Registrando matrícula
string registrandoMatricula(Alunos *aluno[])
{
    string matricula;

    cout << "\nDigite seu número de matrícula: ";
    getline(cin, matricula);
    return matricula;
} // Fim da função registrandoMatricula

/*PROFESSORES*/

// Escrevendo professor no arquivo
void escrevendoProfessorArquivo(Professores *professor)
{
    ofstream arquivo;
    if(Professores::TAMPROFESSOR == 0) arquivo.open("professores.txt");
    else arquivo.open("professores.txt", ios::app);
    // Nome
    arquivo << professor->getNome() << endl
    // Data
    << professor->getDia() << endl
    << professor->getMes() << endl
    << professor->getAno() << endl
    // CPF
    << professor->getCpf() << endl
    // Titulação
    << professor->getTitulacao() << endl
    << "xxxxx" << endl;
    arquivo.close();
} // Fim da função escrevendoProfessorArquivo

// Cadastrar professor
void cadastrarProfessor(Pessoas *pessoa[], Professores *professor[])
{
    // Nome
    string nome;
    cout << "\n\nDigite seu nome: ";
    cin.ignore();
    getline(cin, nome);
    // CPF
    string cpf = registrandoCpf(pessoa);
    // Data
    int dia, mes, ano;
    bool erro = true;
    while (erro)
    {
        cout << "\nDigite sua data de nascimento[xx/xx/xxxx]: ";
        scanf("%d/%d/%d", &dia, &mes, &ano);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (!validandoData(dia, mes, ano)) erro = false;
    } // Fim do while
    // Título
    string titulo = registrandoTitulo();
    // Adicionando
    try
    {
        professor[Professores::TAMPROFESSOR] = new Professores(nome, dia, mes, ano, cpf, titulo);
        escrevendoProfessorArquivo(professor[Professores::TAMPROFESSOR]);
        // Mensagens
        cout << "\nPessoa cadastrada com sucesso!";
        cout << endl << "Total de pessoas: " << Pessoas::TAMPES;
        cout << endl << "Total de professores: " << Professores::TAMPROFESSOR;
        cout << endl << "Total de alunos: " << Alunos::TAMALUNO;
    }// Fim do try
    catch(bad_alloc x)
    {
        cout << "\nMemória máxima atingida";
    }// Fim do catch
} // Fim da função cadastrarProfessor

// Registrando título
string registrandoTitulo()
{
    int x;
    bool erro = true;
    cout << "\nEscolhendo o título do professor:";
    while (erro)
    {
        cout << "\n1 para: Especialista";
        cout << "\n2 para: Mestre";
        cout << "\n3 para: Doutor";
        cout << "\nDigite: ";
        cin >> x;
        if(x >= 1 && x <= 3) erro = false;
        else cout << "\nSomente números de 1 a 3\a";
    } // Fim do while
    string titulo;
    switch (x)
    {
    case 1:
        titulo = "Especialista";
        break;
    case 2:
        titulo = "Mestre";
        break;
    case 3:
        titulo = "Doutor";
        break;
    default:
        break;
    } // Fim do switch
    return titulo;
} // Fim da função registrandoTitulo

/*GERAL*/

// Verificando se ano é bissexto
bool ehbissexto (int ano)
{
    bool teste = false;
    if((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) teste = true;
    return teste;
} // Fim da função ehbissexto

// Validando data
bool validandoData(int dia, int mes, int ano)
{
    bool erro = false;
    bool bissexto = ehbissexto(ano);
    //Verificação do mes
    if (mes < 1 || mes > 12)
    {
        cout << "\nMês inválido\a";
        erro = true;
    } // Fim do if
    //Verificação do ano
    if (ano <= 1900 || ano > 2025)
    {
        cout << "\nAno inválido\a";
        erro = true;
    } // Fim do if
    //Verificação do dia
    if(!erro)
    {
        if ((mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) && (dia < 1 || dia > 31))
        {
            cout << "\nDia inválido\a";
            erro = true;
        } // Fim do if
        else if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && (dia < 1 || dia > 30))
        {
            cout << "\nDia inválido\a";
            erro = true;
        } // Fim do else if
        else if (mes == 2)
        {
            if ((bissexto && (dia < 1 || dia > 29)) || (!bissexto && (dia < 1 || dia > 28)))
            {
                cout << "\nDia inválido\a";
                erro = true;
            } // Fim do if
        } // Fim do else if
    } // Fim do if (!erro)
    return erro;
} // Fim da função validandoData

// Conferindo se CPF existe 
/*bool conferindoCpf(Pessoas *pessoa[], string cpf)
{
    for (int i=0; i<Pessoas::TAMPES; i++)
    {
        if(pessoa[i]->getCpf()==cpf) return false;
    }
    return true;
}*/

// Registrando CPF
string registrandoCpf(Pessoas *pessoa[])
{
    string cpf;
    cout << "\nDigite seu cpf[xxx.xxx.xxx-xx]: ";
    getline(cin, cpf);
    return cpf;
} // Fim da função registrandoCpf

// Escolha opção 1
int escolhaOpcao1()
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
} // Fim da função escolhaOpcao1

// Opções opção 1
void opcoesOpcao1(int x, Pessoas *pessoa[], Alunos *aluno[], Professores *professor[])
{
    switch (x)
    {
    case 0:
        break;
    case 1:
        cadastrarProfessor(pessoa, professor);
        break;
    case 2:
        cadastrarAluno(pessoa, aluno);
        break;
    default:
        break;
    } // Fim do switch
} // Fim da função opcoesOpcao1

// Opção 1
void opcao1(Pessoas *pessoa[], Alunos *aluno[], Professores *professor[])
{
    cout << "\n\n1.0 – Voltar ao menu anterior[0]";
    cout << "\n1.1 - Cadastrar Professor[1]";
    cout << "\n1.2 - Cadastrar Aluno[2]";
    int x = escolhaOpcao1();
    opcoesOpcao1(x, pessoa, aluno, professor);
} // Fim da função opcao1