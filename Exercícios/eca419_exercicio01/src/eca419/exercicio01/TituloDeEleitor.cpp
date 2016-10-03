#include "eca419/exercicio01/TituloDeEleitor.h"

namespace eca419
{

	namespace exercicio01
	{

		TituloDeEleitor::TituloDeEleitor(std::string numero, std::string nome_mae, std::string zona_eleitoral, std::string sessao)
			: Documento(numero, nome_mae),
				zona_eleitoral_(zona_eleitoral),
				sessao_(sessao)
		{}

		TituloDeEleitor::TituloDeEleitor(std::string numero, const Documento &outro, std::string zona_eleitoral, std::string sessao)
			: Documento(numero, outro),
				zona_eleitoral_(zona_eleitoral),
				sessao_(sessao)
		{}

		TituloDeEleitor::TituloDeEleitor(const TituloDeEleitor& titulo_de_eleitor)
			: Documento(titulo_de_eleitor),
				zona_eleitoral_(titulo_de_eleitor.zona_eleitoral_),
				sessao_(titulo_de_eleitor.sessao_)
		{}

		TituloDeEleitor::~TituloDeEleitor()
		{}

		std::string TituloDeEleitor::str() const
		{
			return Documento::str() +
					", zona eleitoral: " + zona_eleitoral_ +
					", sessao: " + sessao_ + "}";
		}

		Documento* TituloDeEleitor::clone() const
		{
			return new TituloDeEleitor(*this);
		}

		std::string TituloDeEleitor::getTipo() const
		{
			return "Titulo de Eleitor";
		}

		std::string TituloDeEleitor::getZonaEleitoral() const
		{
			return zona_eleitoral_;
		}

		void TituloDeEleitor::setZonaEleitoral(std::string zona_eleitoral)
		{
			zona_eleitoral_ = zona_eleitoral;
		}

		std::string TituloDeEleitor::getSessao() const
		{
			return sessao_;
		}

		void TituloDeEleitor::setSessao(std::string sessao)
		{
			sessao_ = sessao;
		}

	}

}


