#include "eca419/exercicio01/Documento.h"
#include "eca419/exercicio01/Pessoa.h"

namespace eca419
{

	namespace exercicio01
	{

		Documento::Documento(std::string numero, std::string nome_mae)
			: numero_(numero),
				nome_mae_(nome_mae)
		{}

		Documento::Documento(std::string numero, const Documento& outro)
			: numero_(numero),
				nome_mae_(outro.nome_mae_)
		{}

		Documento::Documento(const Pessoa& pessoa, const Documento &documento)
			: numero_(documento.numero_),
				nome_mae_(documento.nome_mae_)
		{}

		Documento::Documento(const Documento &documento)
			: numero_(documento.numero_),
				nome_mae_(documento.nome_mae_)
		{}

		Documento::~Documento()
		{}

		std::string Documento::str() const
		{
			return getTipo() + ": {numero: " + numero_ + ", mae: " + nome_mae_;
		}

		const char* Documento::c_str() const
		{
			return str().c_str();
		}

		bool Documento::operator ==(const Documento& documento)
		{
			return isInstanceOf(documento) && numero_ == documento.numero_;
		}

		bool Documento::operator !=(const Documento& documento)
		{
			return !operator ==(documento);
		}

		void Documento::operator =(const Documento& documento)
		{
			numero_ = documento.numero_;
			nome_mae_ = documento.nome_mae_;
		}

		bool Documento::isInstanceOf(std::string tipo) const
		{
			return getTipo() == tipo;
		}

		bool Documento::isInstanceOf(const Documento& documento) const
		{
			return isInstanceOf(documento.getTipo());
		}

		std::string Documento::getNumero() const
		{
			return numero_;
		}

		std::string Documento::getNomeMae() const
		{
			return nome_mae_;
		}

	}

}
