#ifndef PESSOA_H
#define PESSOA_H

#include <string>
#include <sstream>
#include <vector>
#include "eca419/exercicio01/Documento.h"
#include "eca419/exercicio01/sexos/SexoConversor.h"

namespace eca419
{

	namespace exercicio01
	{

		class Pessoa
		{
		public:
			Pessoa(std::string nome, int idade, const Sexo& sexo = SexoConversor::getDefault(),
						 const std::vector<Documento*>& documentos = std::vector<Documento*>());
			Pessoa(const Pessoa& pessoa);
			virtual ~Pessoa();
			virtual std::string str();
			const char* c_str();
			virtual bool operator ==(const Pessoa& pessoa);
			bool operator !=(const Pessoa& pessoa);
			virtual void operator =(const Pessoa& pessoa);
			std::string getNome();
			int getIdade();
			void setIdade(int idade);
			void aniversariou();
			Sexo getSexo();
			std::vector<Documento*> getDocumentos();
			bool removeDocumento(const Documento& documento);

			/** templates **/
			template<typename D>
			bool addDocumento(const D& documento);
			template<typename D>
			bool updateDocumento(const D& documento);

		private:
			std::string nome_;
			int idade_;
			Sexo sexo_;
			std::vector<Documento*> documentos_;

		};

		template<typename D>
		bool Pessoa::addDocumento(const D& documento)
		{
			std::vector<Documento*>::iterator it = documentos_.begin();
			while (it != documentos_.end())
			{
				if (**it == documento)
				{
					return false;
				}
				++it;
			}
			documentos_.push_back(new D(documento));
			return true;
		}

		template<typename D>
		bool Pessoa::updateDocumento(const D& documento)
		{
			std::vector<Documento*>::iterator it = documentos_.begin();
			while (it != documentos_.end())
			{
				if (**it == documento)
				{
					delete *it;
					*it = NULL;
					it = documentos_.erase(it);
					documentos_.push_back(new D(documento));
					return true;
				}
				++it;
			}
			return false;
		}

	}

}

#endif // PESSOA_H
