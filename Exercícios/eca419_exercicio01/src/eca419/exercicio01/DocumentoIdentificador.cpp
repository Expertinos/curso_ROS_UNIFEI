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

		DocumentoIdentificador::DocumentoIdentificador(const Pessoa& pessoa, const DocumentoIdentificador &documento)
			: Documento(pessoa, documento),
				nascimento_(documento.nascimento_),
				nome_pai_(documento.nome_pai_),
				emissao_(documento.emissao_)
		{}

		DocumentoIdentificador::DocumentoIdentificador(const DocumentoIdentificador &documento)
			: Documento(documento),
				nascimento_(documento.nascimento_),
				nome_pai_(documento.nome_pai_),
				emissao_(documento.emissao_)
		{}

		DocumentoIdentificador::~DocumentoIdentificador()
		{}

		std::string DocumentoIdentificador::str() const
		{
			return Documento::str() +
					(nome_pai_.empty() ? "" : ", pai: ") + nome_pai_ +
					", nascimento: " + nascimento_ +
					(emissao_.empty() ? "" : ", emissao: ") + emissao_;
		}

		void DocumentoIdentificador::operator =(const DocumentoIdentificador& documento)
		{
			Documento::operator =(documento);
			nascimento_ = documento.nascimento_;
			nome_pai_ = documento.nome_pai_;
			emissao_ = documento.emissao_;
		}

		std::string DocumentoIdentificador::getNascimento() const
		{
			return nascimento_;
		}

		std::string DocumentoIdentificador::getNomePai() const
		{
			return nome_pai_;
		}

		std::string DocumentoIdentificador::getEmissao() const
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
