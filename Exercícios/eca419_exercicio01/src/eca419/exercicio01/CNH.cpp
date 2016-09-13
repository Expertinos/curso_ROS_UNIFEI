#include "eca419/exercicio01/CNH.h"

namespace eca419
{

	namespace exercicio01
	{

		CNH::CNH(std::string numero, const RG& rg, const CPF& cpf, std::string emissao)
			: DocumentoIdentificador(numero, rg, emissao),
				rg_(new RG(rg)),
				cpf_(new CPF(cpf))
		{}

		CNH::CNH(std::string numero, std::string nome_mae,
						 std::string nascimento, std::string cpf_numero,
						 std::string rg_numero, std::string rg_emissao,
						 std::string rg_emissor, std::string nome_pai,
						 std::string emissao)
			: DocumentoIdentificador(numero, nome_mae, nascimento, nome_pai, emissao),
				rg_(new RG(rg_numero, nome_mae, nascimento, nome_pai, rg_emissao, rg_emissor)),
				cpf_(new CPF(cpf_numero, nome_mae))
		{}

		CNH::CNH(const CNH &cnh)
			: DocumentoIdentificador(cnh),
				rg_(new RG(*cnh.rg_)),
				cpf_(new CPF(*cnh.cpf_))
		{}

		CNH::~CNH()
		{
			if (rg_)
			{
				delete rg_;
			}
			if (cpf_)
			{
				delete cpf_;
			}
		}

		void CNH::operator =(const CNH& cnh)
		{
			DocumentoIdentificador::operator =(cnh);
			if (cnh.rg_)
			{
				delete rg_;
			}
			rg_ = new RG(*cnh.rg_);
			if (cnh.cpf_)
			{
				delete cpf_;
			}
			cpf_ = new CPF(*cnh.cpf_);
		}

		std::string CNH::str()
		{
			return "CNH: {" + DocumentoIdentificador::str() +
					", rg: " + rg_->getNumero() +
					", cpf: " + cpf_->getNumero() + "}";
		}

		RG CNH::getRG()
		{
			return *rg_;
		}

		void CNH::setRG(const RG& rg)
		{
			if (rg_)
			{
				delete rg_;
			}
			rg_ = new RG(rg);
		}

		CPF CNH::getCPF()
		{
			return *cpf_;
		}

	}

}
