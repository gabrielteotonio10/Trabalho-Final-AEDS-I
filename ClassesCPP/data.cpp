// Bibliotecas
#include <iostream>
using namespace std;
// Incluindo arquivos
#include "../ClassesHPP/pessoas.hpp"
#include "../ClassesHPP/data.hpp"
// Set dia
void Data::setDia(int dia)
{
    this->dia = dia;
} // Fim da função setDia
// Get dia
int Data::getDia()
{
    return this->dia;
} // Fim da função getDia
// Set mês
void Data::setMes(int mes)
{
    this->mes = mes;
} // Fim da função setMes
// Get mês
int Data::getMes()
{
    return this->mes;
} // Fim da função getMes
// Set ano
void Data::setAno(int ano)
{
    this->ano = ano;
} // Fim da função setAno
// Get ano
int Data::getAno()
{
    return this->ano;
} // Fim da função getAno