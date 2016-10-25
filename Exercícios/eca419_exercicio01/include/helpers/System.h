#ifndef SYSTEM_H
#define SYSTEM_H

#include "eca419/exercicio01/Pessoa.h"

namespace helpers
{

	class System
	{
	public:
		System();
		virtual ~System();

		bool empty() const;
		bool contains(std::string person_name) const;
		bool contains(const eca419::exercicio01::Pessoa& person) const;
		eca419::exercicio01::Pessoa* getPerson(std::string person_name) const;
		std::vector<eca419::exercicio01::Pessoa*> getPeople() const;
		std::vector<eca419::exercicio01::Pessoa*> getPeople(int lower_age, int upper_age) const;
		bool addPerson(eca419::exercicio01::Pessoa *person);
		bool addPeople(std::map<std::string, eca419::exercicio01::Pessoa*> people);
		bool updatePerson(eca419::exercicio01::Pessoa *person);
		bool updatePeople(std::map<std::string, eca419::exercicio01::Pessoa*> people);
		bool removePerson(std::string person_name);
		bool removePerson(const eca419::exercicio01::Pessoa& person);

	private:
		std::map<std::string, eca419::exercicio01::Pessoa*> people_;

	};

}

#endif // SYSTEM_H
