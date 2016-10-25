#ifndef CNH_H
#define CNH_H

#include "eca419/exercicio01/CPF.h"
#include "eca419/exercicio01/RG.h"

namespace eca419
{

	namespace exercicio01
	{

		class CNH : public DocumentoIdentificador
		{
		public:
			CNH(std::string numero, RG *rg, CPF* cpf, std::string categoria,
					std::string validade = "", std::string emissao = "");
			CNH(const Pessoa& pessoa, const CNH& cnh);
			CNH(const CNH& cnh);
			virtual ~CNH();
			virtual void operator =(const CNH& cnh);
			virtual std::string str() const;
			virtual std::string getTipo() const;
			virtual Documento* clone() const;
			RG getRG() const;
			void setRG(RG *rg);
			CPF getCPF() const;
			std::string getCategoria() const;
			void setCategoria(std::string categoria);
			std::string getValidade() const;
			void setValidade(std::string validade);

		private:
			RG *rg_;
			CPF *cpf_;
			std::string categoria_, validade_;

		};

	}

}

#endif // CNH_H
