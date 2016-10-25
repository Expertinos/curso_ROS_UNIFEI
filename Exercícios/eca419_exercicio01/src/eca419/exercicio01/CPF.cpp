#include "eca419/exercicio01/CPF.h"

namespace eca419
{

	namespace exercicio01
	{

		CPF::CPF(std::string numero, std::string nome_mae)
			: Documento(numero, nome_mae)
		{}

		CPF::CPF(std::string numero, const Documento& outro)
			: Documento(numero, outro)
		{}

		CPF::CPF(const CPF &cpf)
			: Documento(cpf)
		{}

		CPF::CPF(const Pessoa& pessoa, const CPF &cpf)
			: Documento(pessoa, cpf)
		{}

		CPF::~CPF()
		{}

		std::string CPF::str() const
		{
			return Documento::str() + "}";
		}

		std::string CPF::getTipo() const
		{
			return "CPF";
		}

		Documento* CPF::clone() const
		{
			return new CPF(*this);
		}

	}

}
