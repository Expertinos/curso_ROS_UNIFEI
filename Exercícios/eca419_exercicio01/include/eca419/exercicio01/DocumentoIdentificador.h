#ifndef DOCUMENTO_IDENTIFICADOR_H
#define DOCUMENTO_IDENTIFICADOR_H

#include "eca419/exercicio01/Documento.h"

namespace eca419
{

	namespace exercicio01
	{

		class DocumentoIdentificador : public Documento
		{
		public:
			DocumentoIdentificador(const DocumentoIdentificador& documento);
			virtual ~DocumentoIdentificador();
			virtual std::string str();
			virtual void operator =(const DocumentoIdentificador& documento);
			std::string getNascimento();
			std::string getNomePai();
			std::string getEmissao();
			void setEmissao(std::string emissao);

		protected:
			DocumentoIdentificador(std::string numero, std::string nome_mae,
														 std::string nascimento, std::string nome_pai = "",
														 std::string emissao = "");
			DocumentoIdentificador(std::string numero,
														 const DocumentoIdentificador& outro,
														 std::string emissao = "");

		private:
			std::string nascimento_;
			std::string nome_pai_;
			std::string emissao_;

		};

	}

}

#endif // DOCUMENTO_IDENTIFICADOR_H
