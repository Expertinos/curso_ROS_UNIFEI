#include "eca419/exercicio01/DocumentoIdentificador.h"

namespace eca419
{

	namespace exercicio01
	{

		DocumentoIdentificador::DocumentoIdentificador(std::string numero, std::string nome_mae,
																									 std::string nascimento, std::string nome_pai,
																									 std::string emissao)
			: Documento(numero, nome_mae),
				nascimento_(nascimento),
				nome_pai_(nome_pai),
				emissao_(emissao)
		{}

		DocumentoIdentificador::DocumentoIdentificador(std::string numero,
																									 const DocumentoIdentificador& outro,
																									 std::string emissao)
			: Documento(numero, outro),
				nascimento_(outro.nascimento_),
				nome_pai_(outro.nome_pai_),
				emissao_(emissao)
		{}

		DocumentoIdentificador::DocumentoIdentificador(const DocumentoIdentificador &documento)
			: Documento(documento),
				nascimento_(documento.nascimento_),
				nome_pai_(documento.nome_pai_),
				emissao_(documento.emissao_)
		{}

		DocumentoIdentificador::~DocumentoIdentificador()
		{}

		std::string DocumentoIdentificador::str()
		{
			return Documento::str() +
					(nome_pai_ != "" ? ", pai: " : "") + nome_pai_ +
					", nascimento: " + nascimento_ +
					(emissao_ != "" ? ", emissao: " : "") + emissao_;
		}

		void DocumentoIdentificador::operator =(const DocumentoIdentificador& documento)
		{
			Documento::operator =(documento);
			nascimento_ = documento.nascimento_;
			nome_pai_ = documento.nome_pai_;
			emissao_ = documento.emissao_;
		}

		std::string DocumentoIdentificador::getNascimento()
		{
			return nascimento_;
		}

		std::string DocumentoIdentificador::getNomePai()
		{
			return nome_pai_;
		}

		std::string DocumentoIdentificador::getEmissao()
		{
			return emissao_;
		}

		void DocumentoIdentificador::setEmissao(std::string emissao)
		{
			if (emissao != "")
			{
				emissao_ = emissao;
			}
		}

	}

}
