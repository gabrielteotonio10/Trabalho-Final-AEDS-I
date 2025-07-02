#include "../ClassesHPP/pessoas.hpp"
#include <iostream>
using namespace std;
// Variável global
int Pessoas::TAMPES = 0;
// Set dia Pessoas
void Pessoas::setDia(int dia)
{
    this->dataNascimento.setDia(dia);
} // Fim da função setDia
// Get dia Pessoas
int Pessoas::getDia()
{
    return this->dataNascimento.getDia();
} // Fim da função getDia
// Set mês Pessoas
void Pessoas::setMes(int mes)
{
    this->dataNascimento.setMes(mes);
} // Fim da função setMes
// Get mês Pessoas
int Pessoas::getMes()
{
    return this->dataNascimento.getMes();
} // Fim da função getMes
// Set dia Pessoas
void Pessoas::setAno(int ano)
{
    this->dataNascimento.setAno(ano);
} // Fim da função setAno
// Get ano Pessoas
int Pessoas::getAno()
{
    return this->dataNascimento.getAno();
} // Fim da função getAno
// Set nome
void Pessoas::setNome(string nome)
{
    this->nome = nome;
} // Fim da função setNome
// Get nome
string Pessoas::getNome()
{
    return this->nome;
} // Fim da função getNome
// Set cpf
void Pessoas::setCpf(string cpf)
{
    this->cpf = cpf;
} // Fim da função setCpf
// Get cpf
string Pessoas::getCpf()
{
    return this->cpf;
} // Fim da função getCpf