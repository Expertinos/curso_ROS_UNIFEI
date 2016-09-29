#include <stdlib.h>
#include <iostream>
#include "eca419/exercicio01/Pessoa.h"
#include "eca419/exercicio01/CNH.h"

#define INT_MAX 1

using namespace eca419::exercicio01;

std::string readString();
int readInteger();

int main(int argc, char *argv[])
{
	Pessoa adrianohrl("Adriano Henrique Rossette Leite",
					 23, sexos::MASCULINO);
	adrianohrl.aniversariou();
	std::cout << std::endl << adrianohrl.str() << std::endl;

	RG *adrianohrl_rg = new RG("123456789", "Minha Mae", "32/13/2222", "Meu Pai");
	if (adrianohrl.addDocumento(adrianohrl_rg))
	{
		adrianohrl_rg = (RG*) adrianohrl.getDocumento("RG");
		std::cout << "\nO documento " << adrianohrl_rg->str() << " foi adicionado com sucesso!!!\n";
		std::cout << adrianohrl.str() << std::endl;
		RG *adrianohrl_novo_rg = (RG*) adrianohrl_rg->clone();
		adrianohrl_novo_rg->setEmissao("antes de ontem");
		adrianohrl_novo_rg->setEmissor("SSP/MG");
		if (adrianohrl.updateDocumento(adrianohrl_novo_rg))
		{
			adrianohrl_rg = (RG*) adrianohrl.getDocumento("RG");
			std::cout << "\nO documento " << adrianohrl_rg->str() << " foi alterado com sucesso!!!\n";
			std::cout << adrianohrl.str() << std::endl;
		}
		else
		{
			delete adrianohrl_novo_rg;
		}
	}
	else
	{
		delete adrianohrl_rg;
		adrianohrl_rg = NULL;
	}

	CPF *adrianohrl_cpf = new CPF("123456", *adrianohrl_rg);
	if (adrianohrl_rg && adrianohrl.addDocumento(adrianohrl_cpf))
	{
		adrianohrl_cpf = (CPF*) adrianohrl.getDocumento("CPF");
		std::cout << "\nO documento " << adrianohrl_cpf->str() << " foi adicionado com sucesso!!!\n";
		std::cout << adrianohrl.str() << std::endl;
	}
	else
	{
		delete adrianohrl_cpf;
		adrianohrl_cpf = NULL;
	}

	CNH *adrianohrl_cnh = NULL;
	if (adrianohrl.getIdade() >= 18 && adrianohrl_rg && adrianohrl_cpf)
	{
		adrianohrl_cnh = new CNH("123", adrianohrl_rg, adrianohrl_cpf, "ABCDE");
		if (adrianohrl.addDocumento(adrianohrl_cnh))
		{
			adrianohrl_cnh = (CNH*) adrianohrl.getDocumento("CNH");
			std::cout << "\nO " << adrianohrl_cnh->str() << " foi adicionado com sucesso!!!\n";
			std::cout << adrianohrl.str() << std::endl << std::endl;
			if (adrianohrl.removeDocumento(*adrianohrl_cnh))
			{
				adrianohrl_cnh = (CNH*) adrianohrl.getDocumento("CNH");
				if (!adrianohrl_cnh)
				{
					std::cout << "\nO documento foi removido com sucesso!!!\n";
				}
				else
				{
					std::cout << "\nO documento " << adrianohrl_cnh->str() << " nao foi removido com sucesso!!!\n";
				}
				std::cout << adrianohrl.str() << std::endl;
			}
		}
		else
		{
			delete adrianohrl_cnh;
			adrianohrl_cnh = NULL;
		}
	}
	else
	{
		std::cout << "\n" << adrianohrl.getNome() << " must be older than 17 years-old, have RG and CPF to have a CNH!!!";
	}
	std::cout << "\n\n" + adrianohrl.str();

	return EXIT_SUCCESS;
}

std::string readString()
{
	std::string answer("");
	std::cin.clear();
	std::cin.ignore(INT_MAX);
	std::getline(std::cin, answer);
	if (std::cin.fail())
	{
		return "";
	}
	return answer;
}

int readInteger()
{
	int number(-1);
	std::cin >> number;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(INT_MAX);
		return -1;
	}
	return number;
}
