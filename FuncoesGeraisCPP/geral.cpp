// Bibliotecas
#include <iostream>
using namespace std;
// Bibliotecas gerais
#include <fstream>
#include <string>
#include <limits>
#include <algorithm>
// Incluindo arquivos
#include "../FuncoesGeraisHPP/geral.hpp"
// Incluindo arquivos
#include "../ClassesHPP/alunos.hpp"
#include "../ClassesHPP/pessoas.hpp"
#include "../ClassesHPP/professores.hpp"
#include "../OpcoesHPP/opcao1.hpp"
#include "../OpcoesHPP/opcao2.hpp"
#include "../OpcoesHPP/opcao3.hpp"
#include "../OpcoesHPP/opcao4.hpp"
#include "../OpcoesHPP/opcao5.hpp"
#include "../OpcoesHPP/opcao6.hpp"
#include "../OpcoesHPP/opcao7.hpp"

// Escrita das opções
void instrcoes ()
{
    cout << "\n\n--- MENU PRINCIPAL ---";
    cout << "\n\n0 - Sair do programa";
    cout << "\n1 - Cadastrar uma pessoa";
    cout << "\n2 - Listar todas as pessoas cadastradas";
    cout << "\n3 - Pesquisar por nome";
    cout << "\n4 - Pesquisar por CPF";
    cout << "\n5 - Excluir pessoa";
    cout << "\n6 - Apagar todas as pessoas cadastradas";
    cout << "\n7 - Aniversariantes do mês";
    cout << "\n----------------------";
} // Fim da função instrcoes

// Mensagem de fechamento
void fechamento ()
{
    cout << "\n\nObrigado por usar o programa, volte quando precisar!";
} // Fim da função fechamento

// Escolha da opção
int escolha()
{
    int x;
    bool erro = true;
    while (erro)
    {
        cout << "\n\nDigite o que deseja: ";
        cin >> x;
        if (x >= 0 && x <= 7) erro = false;
        else cout << "\nSomente números de 0 a 7.\n\a";
    } // Fim do while

    return x;
} // Fim da função escolha

// Opções
void opcoes(int x, Pessoas *pessoa[], Alunos *aluno[], Professores *professor[])
{
    switch (x)
    {
    case 1:
        opcao1(pessoa, aluno, professor);
        break;
    case 2:
        opcao2(aluno, professor);
        break;
    case 3:
        opcao3(aluno, professor);
        break;
    case 4:
        opcao4(aluno, professor);
        break;
    case 5:
        opcao5(aluno, professor);
        break;
    case 6:
        opcao6(aluno, professor);
        break;
    case 7:
        opcao7(aluno, professor);
        break;
    default:
        break;
    } // Fim do switch
} // Fim da função opcoes

// is_blank
bool is_blank(const std::string& s)
{
    return s.empty() || std::all_of(s.begin(), s.end(), ::isspace);
} // Fim da função is_blank

// lerArquivoAlunos
void lerArquivoAlunos(Alunos *aluno[], Pessoas *pessoa[])
{
    std::ifstream arqAluno("alunos.txt");
    if (!arqAluno.is_open())
    {
        std::cerr << "Erro: Nao foi possivel abrir o arquivo alunos.txt" << std::endl;
        return;
    } // Fim do if (!arqAluno.is_open())

    std::string linha;
    int dia, mes, ano;
    std::string nome, cpf, matricula;
    int i = 0;

    while (std::getline(arqAluno, linha))
    {
        if (is_blank(linha) || linha == "xxxxx") {
            continue;
        } // Fim do if

        bool erro_na_leitura = false;
        nome = linha;

        auto ler_int_seguro = [&](int& var_destino, const std::string& tipo_dado) {
            if (!std::getline(arqAluno, linha)) {
                std::cerr << "Erro: Arquivo terminou inesperadamente ao ler " << tipo_dado << " para " << nome << std::endl;
                erro_na_leitura = true;
                return false;
            } // Fim do if (!std::getline(arqAluno, linha))
            try {
                var_destino = std::stoi(linha);
                return true;
            } catch (const std::invalid_argument& e) {
                std::cerr << "Erro de formato (" << tipo_dado << ") para o aluno " << nome << ": '" << linha << "' nao e um numero valido. Pulando entrada." << std::endl;
                erro_na_leitura = true;
                return false;
            } catch (const std::out_of_range& e) {
                std::cerr << "Erro de intervalo (" << tipo_dado << ") para o aluno " << nome << ": '" << linha << "' fora do limite. Pulando entrada." << std::endl;
                erro_na_leitura = true;
                return false;
            } // Fim do catch
        }; // Fim do ler_int_seguro lambda

        if (!ler_int_seguro(dia, "dia") ||
            !ler_int_seguro(mes, "mes") ||
            !ler_int_seguro(ano, "ano"))
        {
            for (int k = 0; k < 3; ++k) {
                if (!std::getline(arqAluno, linha)) break;
            } // Fim do for
            continue;
        } // Fim do if (!ler_int_seguro(dia, "dia") || ...)

        if (!std::getline(arqAluno, cpf)) {
            std::cerr << "Erro: Arquivo terminou inesperadamente ao ler o CPF para " << nome << std::endl;
            continue;
        } // Fim do if (!std::getline(arqAluno, cpf))
        if (!std::getline(arqAluno, matricula)) {
            std::cerr << "Erro: Arquivo terminou inesperadamente ao ler a matricula para " << nome << std::endl;
            continue;
        } // Fim do if (!std::getline(arqAluno, matricula))

        if (!erro_na_leitura) {
            aluno[i] = new Alunos(nome, dia, mes, ano, cpf, matricula);
            i++;
        } // Fim do if (!erro_na_leitura)
    } // Fim do while (std::getline(arqAluno, linha))
    arqAluno.close();
} // Fim da função lerArquivoAlunos

// lerArquivoProfessores
void lerArquivoProfessores(Professores *professor[], Pessoas *pessoa[])
{
    std::ifstream arqProf("professores.txt");
    if (!arqProf.is_open())
    {
        std::cerr << "Erro: Nao foi possivel abrir o arquivo professores.txt" << std::endl;
        return;
    } // Fim do if (!arqProf.is_open())

    std::string linha;
    int dia, mes, ano;
    std::string nome, cpf, titulacao;
    int i = 0;

    while (std::getline(arqProf, linha))
    {
        if (is_blank(linha) || linha == "xxxxx") {
            continue;
        } // Fim do if

        bool erro_na_leitura = false;
        nome = linha;

        auto ler_int_seguro = [&](int& var_destino, const std::string& tipo_dado) {
            if (!std::getline(arqProf, linha)) {
                std::cerr << "Erro: Arquivo terminou inesperadamente ao ler " << tipo_dado << " para " << nome << std::endl;
                erro_na_leitura = true;
                return false;
            } // Fim do if (!std::getline(arqProf, linha))
            try {
                var_destino = std::stoi(linha);
                return true;
            } catch (const std::invalid_argument& e) {
                std::cerr << "Erro de formato (" << tipo_dado << ") para o professor " << nome << ": '" << linha << "' nao e um numero valido. Pulando entrada." << std::endl;
                erro_na_leitura = true;
                return false;
            } catch (const std::out_of_range& e) {
                std::cerr << "Erro de intervalo (" << tipo_dado << ") para o professor " << nome << ": '" << linha << "' fora do limite. Pulando entrada." << std::endl;
                erro_na_leitura = true;
                return false;
            } // Fim do catch
        }; // Fim do ler_int_seguro lambda

        if (!ler_int_seguro(dia, "dia") ||
            !ler_int_seguro(mes, "mes") ||
            !ler_int_seguro(ano, "ano"))
        {
            for (int k = 0; k < 3; ++k) {
                if (!std::getline(arqProf, linha)) break;
            } // Fim do for
            continue;
        } // Fim do if (!ler_int_seguro(dia, "dia") || ...)

        if (!std::getline(arqProf, cpf)) {
            std::cerr << "Erro: Arquivo terminou inesperadamente ao ler o CPF para " << nome << std::endl;
            continue;
        } // Fim do if (!std::getline(arqProf, cpf))
        if (!std::getline(arqProf, titulacao)) {
            std::cerr << "Erro: Arquivo terminou inesperadamente ao ler a titulacao para " << nome << std::endl;
            continue;
        } // Fim do if (!std::getline(arqProf, titulacao))

        if (!erro_na_leitura) {
            professor[i] = new Professores(nome, dia, mes, ano, cpf, titulacao);
            i++;
        } // Fim do if (!erro_na_leitura)
    } // Fim do while (std::getline(arqProf, linha))
    arqProf.close();
} // Fim da função lerArquivoProfessores

// Lendo pessoas do arquivo
void registrandoPessoas(Pessoas *pessoa[], Alunos *aluno[], Professores *professor[])
{
    lerArquivoAlunos(aluno, pessoa);
    lerArquivoProfessores(professor, pessoa);
} // Fim da função registrandoPessoas

// Liberar memória
void liberarMemoria(Pessoas *pessoa[], Alunos *aluno[], Professores *professor[])
{
    for (int i = 0; i < Alunos::TAMALUNO; i++) {
        if (aluno[i] != nullptr)
        {
            delete aluno[i];
            aluno[i] = nullptr;
        } // Fim do if
    } // Fim do for
    for (int i = 0; i < Professores::TAMPROFESSOR; i++) {
        if (professor[i] != nullptr)
        {
            delete professor[i];
            professor[i] = nullptr;
        } // Fim do if
    } // Fim do for
    Professores::TAMPROFESSOR = 0;
    Pessoas::TAMPES = 0;
} // Fim da função liberarMemoria