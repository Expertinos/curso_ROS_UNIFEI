#include "eca419/exercicio01/RG.h"

namespace eca419
{

	namespace exercicio01
	{

		RG::RG(std::string numero, std::string nome_mae,
					 std::string nascimento, std::string nome_pai,
					 std::string emissao, std::string emissor)
			: DocumentoIdentificador(numero, nome_mae, nascimento, nome_pai, emissao),
				emissor_(emissor)
		{}

		RG::RG(std::string numero, const DocumentoIdentificador& outro,
					 std::string emissao, std::string emissor)
			: DocumentoIdentificador(numero, outro, emissao),
				emissor_(emissor)
		{}

		RG::RG(const Pessoa& pessoa, const RG &rg)
			: DocumentoIdentificador(pessoa, rg),
				emissor_(rg.emissor_)
		{}

		RG::RG(const RG &rg)
			: DocumentoIdentificador(rg),
				emissor_(rg.emissor_)
		{}

		RG::~RG()
		{}

		void RG::operator =(const RG& rg)
		{
			DocumentoIdentificador::operator =(rg);
			emissor_ = rg.emissor_;
		}

		std::string RG::str() const
		{
			return DocumentoIdentificador::str() +
					(emissor_.empty() ? "" : ", emissor: ") + emissor_ + "}";
		}

		Documento* RG::clone() const
		{
			return new RG(*this);
		}

		std::string RG::getTipo() const
		{
			return "RG";
		}

		std::string RG::getEmissor() const
		{
			return emissor_;
		}

		void RG::setEmissor(std::string emissor)
		{
			if (emissor != "")
			{
				emissor_ = emissor;
			}
		}

	}

}
