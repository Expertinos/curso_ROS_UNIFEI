#ifndef RG_H
#define RG_H

#include "eca419/exercicio01/DocumentoIdentificador.h"

namespace eca419
{

	namespace exercicio01
	{

		class RG : public DocumentoIdentificador
		{
		public:
			RG(std::string numero, std::string nome_mae,
				 std::string nascimento, std::string nome_pai = "",
				 std::string emissao = "", std::string emissor = "");
			RG(std::string numero, const DocumentoIdentificador& outro,
				 std::string emissao = "", std::string emissor = "");
			RG(const Pessoa& pessoa, const RG& rg);
			RG(const RG& rg);
			virtual ~RG();
			virtual void operator =(const RG& rg);
			virtual std::string str() const;
			virtual std::string getTipo() const;
			virtual Documento* clone() const;
			std::string getEmissor() const;
			void setEmissor(std::string emissor);

		private:
			std::string emissor_;

		};

	}

}

#endif // RG_H
