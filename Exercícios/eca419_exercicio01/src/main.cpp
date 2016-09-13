#include <stdlib.h>
#include <iostream>
#include "eca419/exercicio01/Pessoa.h"
#include "eca419/exercicio01/CNH.h"

using namespace eca419::exercicio01;

int main(int argc, char *argv[])
{
	Pessoa adrianohrl("Adriano Henrique Rossette Leite",
					 23, sexos::MASCULINO);
	adrianohrl.aniversariou();
	std::cout << std::endl << adrianohrl.str() << std::endl;

	RG adrianohrl_rg("123456789", "Minha Mae", "32/13/2222", "Meu Pai");
	if (adrianohrl.addDocumento<RG>(adrianohrl_rg))
	{
		std::cout << "\nO documento " << adrianohrl_rg.str() << " foi adicionado com sucesso!!!\n";
		std::cout << adrianohrl.str() << std::endl;
		adrianohrl_rg.setEmissao("antes de ontem");
		adrianohrl_rg.setEmissor("SSP/MG");
		if (adrianohrl.updateDocumento<RG>(adrianohrl_rg))
		{
			std::cout << "\nO documento " << adrianohrl_rg.str() << " foi alterado com sucesso!!!\n";
			std::cout << adrianohrl.str() << std::endl;
		}
	}

	CPF adrianohrl_cpf("123456", adrianohrl_rg);
	if (adrianohrl.addDocumento<CPF>(adrianohrl_cpf))
	{
		std::cout << "\nO documento " << adrianohrl_cpf.str() << " foi adicionado com sucesso!!!\n";
		std::cout << adrianohrl.str() << std::endl;
	}

	CNH adrianohrl_cnh("123", adrianohrl_rg, adrianohrl_cpf, "ontem");
	if (adrianohrl.addDocumento<CNH>(adrianohrl_cnh))
	{
		std::cout << "\nO " << adrianohrl_cnh.str() << " foi adicionado com sucesso!!!\n";
		std::cout << adrianohrl.str() << std::endl << std::endl;
		if (adrianohrl.removeDocumento(adrianohrl_cnh))
		{
			std::cout << "\nO documento " << adrianohrl_cnh.str() << " foi removido com sucesso!!!\n";
			std::cout << adrianohrl.str() << std::endl;
		}
	}

	return EXIT_SUCCESS;
}
