#include "eca419/exercicio01/Pessoa.h"

namespace eca419
{

	namespace exercicio01
	{

		Pessoa::Pessoa(std::string nome, int idade, const Sexo& sexo,
					 const std::vector<Documento*>& documentos)
			: nome_(nome),
				idade_(idade),
				sexo_(sexo)
		{
			for (int i(0); i < documentos.size(); i++)
			{
				documentos_[documentos[i]->getTipo()] = documentos[i];
			}
		}

		Pessoa::Pessoa(const Pessoa& pessoa)
			: nome_(pessoa.nome_),
				idade_(pessoa.idade_),
				sexo_(pessoa.sexo_)
		{
			for (std::map<std::string, Documento*>::const_iterator it(pessoa.documentos_.begin()); it != pessoa.documentos_.end(); it++)
			{
				documentos_[it->first] = it->second->clone();
			}
		}

		Pessoa::~Pessoa()
		{
			if (!documentos_.empty())
			{
				for (std::map<std::string, Documento*>::iterator it(documentos_.begin()); it != documentos_.end(); it++)
				{
					delete it->second;
					it->second = NULL;
				}
			}
		}

		std::string Pessoa::str() const
		{
			std::stringstream ss;
			ss << nome_ + " {idade: " << idade_;
			ss << ", sexo: " + SexoConversor::toString(sexo_);
			if (!documentos_.empty())
			{
				std::map<std::string, Documento*>::const_iterator it(documentos_.begin());
				ss << ", documentos: [" + it->second->str();
				while (++it != documentos_.end())
				{
					ss << "; " + it->second->str();
				}
			}
			ss << "]}";
			return ss.str();
		}

		const char* Pessoa::c_str() const
		{
			return str().c_str();
		}

		Pessoa* Pessoa::clone()
		{
			return new Pessoa(*this);
		}

		bool Pessoa::operator ==(const Pessoa& pessoa)
		{
			return nome_ == pessoa.nome_;
		}

		bool Pessoa::operator !=(const Pessoa& pessoa)
		{
			return !operator ==(pessoa);
		}

		void Pessoa::operator =(const Pessoa& pessoa)
		{
			nome_ = pessoa.nome_;
			idade_ = pessoa.idade_;
			sexo_ = pessoa.sexo_;
			for (std::map<std::string, Documento*>::iterator it(documentos_.begin()); it != documentos_.end(); it++)
			{
				delete it->second;
				it->second = NULL;
			}
			documentos_.clear();
			documentos_ = pessoa.documentos_;
		}

		std::string Pessoa::getNome() const
		{
			return nome_;
		}

		int Pessoa::getIdade() const
		{
			return idade_;
		}

		void Pessoa::setIdade(int idade)
		{
			if (idade > idade_)
			{
				idade_ = idade;
			}
		}

		void Pessoa::aniversariou()
		{
			idade_++;
		}

		Sexo Pessoa::getSexo() const
		{
			return sexo_;
		}

		std::string Pessoa::getNomeMae() const
		{
			return hasDocumento() ? documentos_.begin()->second->getNomeMae() : "";
		}

		bool Pessoa::hasDocumento() const
		{
			return !documentos_.empty();
		}

		bool Pessoa::hasDocumento(std::string tipo) const
		{
			return documentos_.find(tipo) != documentos_.end();
		}


		bool Pessoa::hasDocumento(std::string tipo, std::string numero) const
		{
			std::map<std::string, Documento*>::const_iterator it(documentos_.find(tipo));
			return it != documentos_.end() && it->second->getNumero() == numero;
		}

		std::vector<Documento*> Pessoa::getDocumentos() const
		{
			std::vector<Documento*> documentos;
			for (std::map<std::string, Documento*>::const_iterator it(documentos_.begin()); it != documentos_.end(); it++)
			{
				documentos.push_back(it->second);
			}
			return documentos;
		}

		Documento* Pessoa::getDocumento(std::string tipo) const
		{
			std::map<std::string, Documento*>::const_iterator it(documentos_.find(tipo));
			return it != documentos_.end() ? it->second : NULL;
		}

		Documento* Pessoa::getDocumento(std::string tipo, std::string numero) const
		{
			Documento* documento = getDocumento(tipo);
			return documento && documento->getNumero() == numero ? documento : NULL;
		}

		bool Pessoa::addDocumento(Documento *documento)
		{
			if (!documento || documento->getTipo().empty())
			{
				return false;
			}
			std::pair<std::map<std::string, Documento*>::iterator, bool> ret;
			ret = documentos_.insert(std::pair<std::string, Documento*>(documento->getTipo(), documento));
			return ret.second;
		}

		bool Pessoa::updateDocumento(Documento* documento)
		{
			return documento && removeDocumento(*documento) && addDocumento(documento);
		}

		bool Pessoa::removeDocumento(const Documento& documento)
		{
			std::map<std::string, Documento*>::iterator it(documentos_.find(documento.getTipo()));
			if (it == documentos_.end() || *it->second != documento)
			{
				return false;
			}
			delete it->second;
			it->second = NULL;
			documentos_.erase(it);
			return true;
		}

	}

}
