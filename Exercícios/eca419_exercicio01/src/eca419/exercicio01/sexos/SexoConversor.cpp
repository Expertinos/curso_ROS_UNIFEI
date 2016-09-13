#include "eca419/exercicio01/sexos/SexoConversor.h"

namespace eca419
{

	namespace exercicio01
	{

		namespace sexos
		{

			SexoConversor::SexoConversor(int id)
				: EnumConversor(getEnumerated(id))
			{}

			SexoConversor::SexoConversor(std::string nome)
				: EnumConversor(getEnumerated(nome))
			{}

			SexoConversor::SexoConversor(Sexo sexo)
				: EnumConversor(sexo)
			{}

			SexoConversor::~SexoConversor()
			{}

			Sexo SexoConversor::getEnumerated(int id)
			{
				switch (id)
				{
					case 0:
						return FEMININO;
					case 1:
						return MASCULINO;
				}
				return SexoConversor::getDefault();
			}

			Sexo SexoConversor::getEnumerated(std::string nome)
			{
				if (nome == "FEMININO" || nome == "F" || nome == "feminino" || nome == "Feminino")
				{
					return FEMININO;
				}
				else if (nome == "MASCULINO" || nome == "M" || nome == "masculino" || nome == "Masculino")
				{
					return MASCULINO;
				}
				return getDefault();
			}

			std::string SexoConversor::str(Sexo sexo)
			{
				switch (sexo)
				{
					case FEMININO:
						return "FEMININO";
					case MASCULINO:
						return "MASCULINO";
				}
				return "";
			}

			const char* SexoConversor::c_str(Sexo sexo)
			{
				return str(sexo).c_str();
			}

			Sexo SexoConversor::toEnumerated(int id)
			{
				SexoConversor conversor(id);
				return conversor.getEnumerated();
			}

			Sexo SexoConversor::toEnumerated(std::string nome)
			{
				SexoConversor conversor(nome);
				return conversor.getEnumerated();
			}

			std::string SexoConversor::toString(Sexo sexo)
			{
				SexoConversor conversor(sexo);
				return conversor.str();
			}

			const char* SexoConversor::toCString(Sexo sexo)
			{
				SexoConversor conversor(sexo);
				return conversor.c_str();
			}

			Sexo SexoConversor::getDefault()
			{
				return MASCULINO;
			}

			std::vector<Sexo> SexoConversor::getAll()
			{
				std::vector<Sexo> sexos;
				sexos.push_back(MASCULINO);
				sexos.push_back(FEMININO);
				return sexos;
			}

		}

	}

}
