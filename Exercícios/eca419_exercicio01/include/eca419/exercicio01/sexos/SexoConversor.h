#ifndef SEXO_CONVERSOR_H
#define SEXO_CONVERSOR_H

#include "eca419/exercicio01/sexos/SexoEnum.h"
#include "eca419/exercicio01/EnumConversor.h"

namespace eca419
{

	namespace exercicio01
	{

		namespace sexos
		{

			class SexoConversor : public EnumConversor<Sexo>
			{
			public:
				SexoConversor(int id);
				SexoConversor(std::string nome);
				SexoConversor(Sexo sexo);
				virtual ~SexoConversor();
				using EnumConversor::getEnumerated;
				virtual Sexo getEnumerated(int id);
				virtual Sexo getEnumerated(std::string nome);
				using EnumConversor::str;
				virtual std::string str(Sexo sexo);
				using EnumConversor::c_str;
				virtual const char* c_str(Sexo sexo);

				static Sexo toEnumerated(int id);
				static Sexo toEnumerated(std::string nome);
				static std::string toString(Sexo sexo);
				static const char* toCString(Sexo sexo);
				static Sexo getDefault();
				static std::vector<Sexo> getAll();

			};

		}

		typedef typename sexos::SexoConversor SexoConversor;

	}

}


#endif // SEXO_CONVERSOR_H
