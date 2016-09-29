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
				virtual Sexo getEnumerated(int id) const;
				virtual Sexo getEnumerated(std::string nome) const;
				using EnumConversor::getId;
				virtual int getId(std::string nome) const;
				virtual int getId(Sexo sexo) const;
				using EnumConversor::str;
				virtual std::string str(Sexo sexo) const;
				using EnumConversor::c_str;
				virtual const char* c_str(Sexo sexo) const;

				static int toId(Sexo sexo);
				static Sexo toEnumerated(int id);
				static Sexo toEnumerated(std::string nome);
				static bool isValid(std::string nome);
				static std::string toString(Sexo sexo);
				static const char* toCString(Sexo sexo);
				static Sexo getDefault();
				static Sexo getMinimum();
				static Sexo getMaximum();
				static std::vector<Sexo> getAll();

			};

		}

		typedef typename sexos::SexoConversor SexoConversor;

	}

}


#endif // SEXO_CONVERSOR_H
