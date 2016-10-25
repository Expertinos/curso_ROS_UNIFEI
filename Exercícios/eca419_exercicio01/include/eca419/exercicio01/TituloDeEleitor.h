#ifndef TITULO_DE_ELEITOR_H
#define TITULO_DE_ELEITOR_H

#include "eca419/exercicio01/Pessoa.h"

namespace eca419
{

	namespace exercicio01
	{

		class TituloDeEleitor : public Documento
		{
		public:
			TituloDeEleitor(std::string numero, std::string nome_mae, std::string zona_eleitoral = "", std::string sessao = "");
			TituloDeEleitor(std::string numero, const Documento& outro, std::string zona_eleitoral = "", std::string sessao = "");
			TituloDeEleitor(const Pessoa& pessoa, const TituloDeEleitor& titulo_de_eleitor);
			TituloDeEleitor(const TituloDeEleitor& titulo_de_eleitor);
			virtual ~TituloDeEleitor();
			virtual std::string str() const;
			virtual std::string getTipo() const;
			virtual Documento* clone() const;
			std::string getZonaEleitoral() const;
			void setZonaEleitoral(std::string zona_eleitoral);
			std::string getSessao() const;
			void setSessao(std::string sessao);

		private:
			std::string zona_eleitoral_, sessao_;
		};

	}

}



#endif // TITULO_DE_ELEITOR_H
