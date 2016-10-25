#ifndef PERSONFACTORY_H
#define PERSONFACTORY_H

#include "helpers/System.h"
#include "eca419/exercicio01/Headers.h"

namespace helpers
{

	class PersonFactory
	{
	public:
		static bool createPerson(System *system);
		static bool createDocument(System *system, std::string person_name);
		static bool updateDocument(System *system, std::string person_name);

	};

}

#endif // PERSONFACTORY_H
