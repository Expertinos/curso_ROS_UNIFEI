#include "helpers/System.h"

using namespace eca419::exercicio01;

namespace helpers
{

	System::System()
	{

	}

	System::~System()
	{
		for (std::map<std::string, Pessoa*>::iterator it(people_.begin()); it != people_.end(); it++)
		{
			if (it->second)
			{
				delete it->second;
				it->second = NULL;
			}
		}
	}

	bool System::empty() const
	{
		return people_.empty();
	}

	bool System::contains(std::string person_name) const
	{
		return people_.find(person_name) != people_.end();
	}

	bool System::contains(const Pessoa &person) const
	{
		return contains(person.getNome());
	}

	Pessoa* System::getPerson(std::string person_name) const
	{
		std::map<std::string, Pessoa*>::const_iterator it(people_.find(person_name));
		return it != people_.end() ? it->second : NULL;
	}

	std::vector<Pessoa*> System::getPeople() const
	{
		std::vector<Pessoa*> people;
		for (std::map<std::string, Pessoa*>::const_iterator it(people_.begin()); it != people_.end(); it++)
		{
			people.push_back(it->second);
		}
		return people;
	}

	std::vector<Pessoa*> System::getPeople(int lower_age, int upper_age) const
	{
		std::vector<Pessoa*> people;
		for (std::map<std::string, Pessoa*>::const_iterator it(people_.begin()); it != people_.end(); it++)
		{
			int person_age = it->second->getIdade();
			if (person_age >= lower_age && person_age <= upper_age)
			{
				people.push_back(it->second);
			}
		}
		return people;
	}

	bool System::addPerson(Pessoa *person)
	{
		if (!person || person->getNome().empty())
		{
			return false;
		}
		std::pair<std::map<std::string, Pessoa*>::iterator, bool> ret;
		ret = people_.insert(std::pair<std::string, Pessoa*>(person->getNome(), person));
		return ret.second;
	}

	bool System::addPeople(std::map<std::string, eca419::exercicio01::Pessoa*> people)
	{
		if (people.empty())
		{
			return false;
		}
		people_.insert(people.begin(), people.end());
		return true;
	}

	bool System::updatePerson(Pessoa *person)
	{
		std::map<std::string, Pessoa*>::iterator it(people_.find(person->getNome()));
		if (it == people_.end())
		{
			return false;
		}
		*it->second = *person;
		return true;
	}

	bool System::updatePeople(std::map<std::string, eca419::exercicio01::Pessoa*> people)
	{
		if (people.empty())
		{
			return false;
		}
		bool success(true);
		for (std::map<std::string, eca419::exercicio01::Pessoa*>::iterator it(people.begin()); it != people.end(); it++)
		{
			if (!updatePerson(it->second))
			{
				success = false;
			}
		}
		return success;
	}

	bool System::removePerson(std::string person_name)
	{
		std::map<std::string, Pessoa*>::iterator it(people_.find(person_name));
		if (it == people_.end())
		{
			return false;
		}
		delete it->second;
		it->second = NULL;
		people_.erase(it);
		return true;
	}

	bool System::removePerson(const Pessoa &person)
	{
		return removePerson(person.getNome());
	}

}

