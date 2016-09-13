#include "eca419/exercicio01/Documento.h"

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

		Documento::Documento(const Documento &documento)
			: numero_(documento.numero_),
				nome_mae_(documento.nome_mae_)
		{}

		Documento::~Documento()
		{}

		std::string Documento::str()
		{
			return "numero: " + numero_ + ", mae: " + nome_mae_;
		}

		const char* Documento::c_str()
		{
			return str().c_str();
		}

		bool Documento::operator ==(const Documento& documento)
		{
			return numero_ == documento.numero_;
		}

		bool Documento::operator !=(const Documento& documento)
		{
			return !operator !=(documento);
		}

		void Documento::operator =(const Documento& documento)
		{
			numero_ = documento.numero_;
			nome_mae_ = documento.nome_mae_;
		}

		std::string Documento::getNumero()
		{
			return numero_;
		}

		std::string Documento::getNomeMae()
		{
			return nome_mae_;
		}

	}

}
