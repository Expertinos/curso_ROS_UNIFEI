#ifndef CPF_H
#define CPF_H

#include "eca419/exercicio01/Documento.h"

namespace eca419
{

	namespace exercicio01
	{

		class CPF : public Documento
		{
		public:
			CPF(std::string numero, std::string nome_mae);
			CPF(std::string numero, const Documento& outro);
			CPF(const CPF& cpf);
			virtual ~CPF();
			virtual std::string str();

		};

	}

}

#endif // CPF_H
