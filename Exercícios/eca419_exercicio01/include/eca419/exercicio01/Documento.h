#ifndef DOCUMENTO_H
#define DOCUMENTO_H

#include <string>

namespace eca419
{

	namespace exercicio01
	{

		class Documento
		{
		public:
			Documento(const Documento& documento);
			virtual ~Documento();
			virtual std::string str();
			const char* c_str();
			virtual bool operator ==(const Documento& documento);
			bool operator !=(const Documento& documento);
			virtual void operator =(const Documento& documento);
			std::string getNumero();
			std::string getNomeMae();

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
