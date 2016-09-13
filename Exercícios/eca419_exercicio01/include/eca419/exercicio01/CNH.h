#ifndef CNH_H
#define CNH_H

#include "eca419/exercicio01/CPF.h"
#include "eca419/exercicio01/DocumentoIdentificador.h"
#include "eca419/exercicio01/RG.h"

namespace eca419
{

	namespace exercicio01
	{

		class CNH : public DocumentoIdentificador
		{
		public:
			CNH(std::string numero, const RG& rg, const CPF& cpf,
					std::string emissao = "");
			CNH(std::string numero, std::string nome_mae,
					std::string nascimento, std::string cpf_numero,
					std::string rg_numero, std::string rg_emissao = "",
					std::string rg_emissor = "", std::string nome_pai = "",
					std::string emissao = "");
			CNH(const CNH& cnh);
			virtual ~CNH();
			virtual void operator =(const CNH& cnh);
			virtual std::string str();
			RG getRG();
			void setRG(const RG& rg);
			CPF getCPF();

		private:
			RG *rg_;
			CPF *cpf_;

		};

	}

}

#endif // CNH_H
