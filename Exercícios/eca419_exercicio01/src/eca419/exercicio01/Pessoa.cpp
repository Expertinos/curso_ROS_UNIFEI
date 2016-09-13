#include "eca419/exercicio01/Pessoa.h"

namespace eca419
{

	namespace exercicio01
	{

		Pessoa::Pessoa(std::string nome, int idade, const Sexo& sexo,
					 const std::vector<Documento*>& documentos)
			: nome_(nome),
				idade_(idade),
				sexo_(sexo),
				documentos_(documentos)
		{}

		Pessoa::Pessoa(const Pessoa& pessoa)
			: nome_(pessoa.nome_),
				idade_(pessoa.idade_),
				sexo_(pessoa.sexo_),
				documentos_(pessoa.documentos_)
		{}

		Pessoa::~Pessoa()
		{
			if (!documentos_.empty())
			{
				for (int i = 0; i < documentos_.size(); i++)
				{
					delete documentos_[i];
					documentos_[i] = NULL;
				}
			}
		}

		std::string Pessoa::str()
		{
			std::stringstream ss;
			ss << nome_ + " {idade: " << idade_;
			ss << ", sexo: " + SexoConversor::toString(sexo_);
			if (!documentos_.empty())
			{
				ss << ", documentos: [" + documentos_[0]->str();
				for (int i = 1; i < documentos_.size(); i++)
				{
					ss << "; " + documentos_[i]->str();
				}
			}
			ss << "]}";
			return ss.str();
		}

		const char* Pessoa::c_str()
		{
			return str().c_str();
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
			documentos_.clear();
			documentos_ = pessoa.documentos_;
		}

		std::string Pessoa::getNome()
		{
			return nome_;
		}

		int Pessoa::getIdade()
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

		Sexo Pessoa::getSexo()
		{
			return sexo_;
		}

		std::vector<Documento*> Pessoa::getDocumentos()
		{
			return documentos_;
		}

		bool Pessoa::removeDocumento(const Documento& documento)
		{
			std::vector<Documento*>::iterator it = documentos_.begin();
			while (it != documentos_.end())
			{
				if (**it == documento)
				{
					delete *it;
					*it = NULL;
					it = documentos_.erase(it);
					return true;
				}
				++it;
			}
			return false;
		}

	}

}
