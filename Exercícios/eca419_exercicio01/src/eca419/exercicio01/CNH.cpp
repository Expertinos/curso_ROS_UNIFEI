#include "eca419/exercicio01/CNH.h"

namespace eca419
{

	namespace exercicio01
	{

		CNH::CNH(std::string numero, RG *rg, CPF *cpf, std::string categoria,
						 std::string validade, std::string emissao)
			: DocumentoIdentificador(numero, *rg, emissao),
				categoria_(categoria),
				validade_(validade)
		{
			rg_ = rg;
			cpf_ = cpf;
		}

		CNH::CNH(const CNH &cnh)
			: DocumentoIdentificador(cnh),
				categoria_(cnh.categoria_),
				validade_(cnh.validade_)
		{
			rg_ = (RG*) cnh.rg_->clone();
			cpf_ = (CPF*) cnh.cpf_->clone();
		}

		CNH::~CNH()
		{
			rg_ = NULL;
			cpf_ = NULL;
		}

		void CNH::operator =(const CNH& cnh)
		{
			DocumentoIdentificador::operator =(cnh);
			rg_ = (RG*) cnh.rg_->clone();
			cpf_ = (CPF*) cnh.cpf_->clone();
			categoria_ = cnh.categoria_;
			validade_ = cnh.validade_;
		}

		std::string CNH::str() const
		{
			return DocumentoIdentificador::str() +
					", rg: " + rg_->getNumero() +
					", cpf: " + cpf_->getNumero() +
					", categoria: " + categoria_ +
					(validade_.empty() ? "" : ", emissao: ") + validade_ + "}";
		}

		std::string CNH::getTipo() const
		{
			return "CNH";
		}

		Documento* CNH::clone() const
		{
			return new CNH(*this);
		}

		RG CNH::getRG() const
		{
			return *rg_;
		}

		void CNH::setRG(RG *rg)
		{
			if (rg)
			{
				rg_ = rg;
			}
		}

		CPF CNH::getCPF() const
		{
			return *cpf_;
		}

		std::string CNH::getCategoria() const
		{
			return categoria_;
		}

		void CNH::setCategoria(std::string categoria)
		{
			if (!categoria.empty())
			{
				categoria_ = categoria;
			}
		}

		std::string CNH::getValidade() const
		{
			return validade_;
		}

		void CNH::setValidade(std::string validade)
		{
			validade_ = validade;
		}

	}

}
