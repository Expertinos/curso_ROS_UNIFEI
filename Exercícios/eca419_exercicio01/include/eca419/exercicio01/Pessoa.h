#ifndef PESSOA_H
#define PESSOA_H

#include <string>
#include <sstream>
#include <vector>
#include <map>
#include "eca419/exercicio01/Documento.h"
#include "eca419/exercicio01/sexos/SexoConversor.h"

namespace eca419
{

	namespace exercicio01
	{

		class Pessoa
		{
		public:
			Pessoa(std::string nome, int idade, const Sexo& sexo,
						 const std::vector<Documento*>& documentos = std::vector<Documento*>());
			Pessoa(const Pessoa& pessoa);
			virtual ~Pessoa();
			virtual std::string str() const;
			const char* c_str() const;
			virtual Pessoa* clone();
			virtual bool operator ==(const Pessoa& pessoa);
			bool operator !=(const Pessoa& pessoa);
			virtual void operator =(const Pessoa& pessoa);
			std::string getNome() const;
			int getIdade() const;
			void setIdade(int idade);
			void aniversariou();
			Sexo getSexo() const;
			std::string getNomeMae() const;
			bool hasDocumento() const;
			bool hasDocumento(std::string tipo) const;
			bool hasDocumento(std::string tipo, std::string numero) const;
			Documento* getDocumento(std::string tipo) const;
			Documento* getDocumento(std::string tipo, std::string numero) const;
			std::vector<Documento*> getDocumentos() const;
			bool addDocumento(Documento* documento);
			bool updateDocumento(Documento* documento);
			bool removeDocumento(const Documento& documento);

		private:
			std::string nome_;
			int idade_;
			Sexo sexo_;
			std::map<std::string, Documento*> documentos_;

		};

	}

}

#endif // PESSOA_H
