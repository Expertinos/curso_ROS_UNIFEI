#ifndef DOCUMENTO_H
#define DOCUMENTO_H

#include <string>

namespace eca419
{

	namespace exercicio01
	{

		class Pessoa;

		class Documento
		{
		public:
			Documento(const Pessoa& pessoa, const Documento& documento);
			Documento(const Documento& documento);
			virtual ~Documento();
			virtual std::string str() const;
			const char* c_str() const;
			virtual Documento* clone() const = 0;
			virtual bool operator ==(const Documento& documento);
			bool operator !=(const Documento& documento);
			virtual void operator =(const Documento& documento);
			virtual std::string getTipo() const = 0;
			bool isInstanceOf(std::string type) const;
			bool isInstanceOf(const Documento& documento) const;
			std::string getNumero() const;
			std::string getNomeMae() const;

		protected:
			Documento(std::string numero, std::string nome_mae);
			Documento(std::string numero, const Documento& outro);

		private:
			std::string numero_;
			std::string nome_mae_;

		};

	}

}

#endif // DOCUMENTO_H
