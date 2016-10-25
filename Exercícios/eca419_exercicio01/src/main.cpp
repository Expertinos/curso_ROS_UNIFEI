#include <stdlib.h>
#include <iostream>
#include "helpers/CSVParser.h"
#include "helpers/PersonFactory.h"
#include "helpers/System.h"
#include "eca419/exercicio01/Headers.h"

#define INT_MAX 1

#define NUMBER_OF_OPTIONS 11
#define NUMBER_OF_ATTEMPTS 3
#define NUMBER_OF_DOCUMENTS 4

using namespace eca419::exercicio01;
using namespace helpers;

/** user interfaces **/
void printMenu();
void printDocumentsMenu();
bool process(System *system, int option);

/** options **/
bool insertPerson(System *system);
bool insertDocument(Pessoa *person);
bool importFromCSV(System *system, std::string file_name);
bool updateDocument(Pessoa *person);
bool updateFromCSV(System *system, std::string file_name);
bool showPerson(const Pessoa &person);
bool showAll(const System& system);
bool showAllByAge(const System& system);
bool exportToCSV(const System& system, std::string file_name);
bool removePerson(System *system, std::string person_name);

/** keyboard helper methods **/
std::string readString();
int readInteger();
std::string askForString(std::string message, int attempts = 0);
int askForInteger(std::string message, int min, int max, int attempts = 0);
std::string askForPersonName(const System& system);
std::string askForFileName();

/** document helper methods **/
std::string getType(int type);

/** printing helper methods**/
void print(const System &system);
void print(const Pessoa& person, std::string indentation = "");
void print(const Pessoa& person, const Documento& document, std::string indentation = "");

int main(int argc, char *argv[])
{
	System system;
	int option;
	while (true)
	{
		printMenu();
		option = askForInteger("Option number", 1, NUMBER_OF_OPTIONS);
		if (option <= 0)
		{
			std::cout << "\nInvalid option: " << option << "!!!";
			std::cout << "\nPlease, enter a valid option number [1, " << NUMBER_OF_OPTIONS << "]!!!";
			continue;
		}
		if (option == NUMBER_OF_OPTIONS)
		{
			break;
		}
		else if (process(&system, option))
		{
			std::cout << "\nDone!!!";
		}
	}
	std::cout << "\nQuitting!!!\n";
	return EXIT_SUCCESS;
}

void printMenu()
{
	std::cout << "\n\n\t********************************************";
	std::cout << "\n\t* Enter the desired option number:         *";
	std::cout << "\n\t* 1) Insert person;                        *";
	std::cout << "\n\t* 2) Insert document;                      *";
	std::cout << "\n\t* 3) Import data from a .CSV file;         *";
	std::cout << "\n\t* 4) Update document;                      *";
	std::cout << "\n\t* 5) Updade data according to a .CSV file; *";
	std::cout << "\n\t* 6) Show person;                          *";
	std::cout << "\n\t* 7) Show all people;                      *";
	std::cout << "\n\t* 8) Show all people filterring their age; *";
	std::cout << "\n\t* 9) Export data to a .CSV file;           *";
	std::cout << "\n\t* 10) Remove person;                       *";
	std::cout << "\n\t* 11) Quit.                                *";
	std::cout << "\n\t********************************************";
}

void printDocumentsMenu()
{
	std::cout << "\n\n\t********************************************";
	std::cout << "\n\t* Considering that:                        *";
	std::cout << "\n\t* 1) RG;                                   *";
	std::cout << "\n\t* 2) CPF;                                  *";
	std::cout << "\n\t* 3) CNH;                                  *";
	std::cout << "\n\t* 4) Titulo de Eleitor;                    *";
	std::cout << "\n\t********************************************";
}

bool process(System *system, int option)
{
	std::string str("");
	if (option == 2 || option == 4 || option == 6 || option == 10)
	{
		str = askForPersonName(*system);
		if (str.empty())
		{
			return false;
		}
	}
	else if (option == 3 || option == 5 || option == 9)
	{
		str = askForFileName();
		if (str.empty())
		{
			return false;
		}
	}
	switch (option)
	{
		case 1:
			return insertPerson(system);
		case 2:
			return insertDocument(system->getPerson(str));
		case 3:
			return importFromCSV(system, str);
		case 4:
			return updateDocument(system->getPerson(str));
		case 5:
			return updateFromCSV(system, str);
		case 6:
			return showPerson(*system->getPerson(str));
		case 7:
			return showAll(*system);
		case 8:
			return showAllByAge(*system);
		case 9:
			return exportToCSV(*system, str);
		case 10:
			return removePerson(system, str);
	}
	std::cout << "\nInvalid option!!!";
	return false;
}

bool insertPerson(System *system)
{
	std::string name("");
	int attempts(0);
	while (true)
	{
		name = askForString("Enter the person's name", attempts++);
		if (name.empty())
		{
			std::cout << "\nAborting!!!";
			return false;
		}
		if (system->contains(name))
		{
			std::cout << "\nThis person is already registered!!!";
		}
		else
		{
			break;
		}
	}
	int age(askForInteger("Enter the person's age", 1, MAX_AGE));
	if (age <= 0)
	{
		std::cout << "\nAborting!!!";
		return false;
	}
	int gender_code(askForInteger("Enter the person's gender (0 for FEMALE and 1 for MALE)", SexoConversor::getMinimum(), SexoConversor::getMaximum()));
	if (gender_code != sexos::FEMININO && gender_code != sexos::MASCULINO)
	{
		std::cout << "\nAborting!!!";
		return false;
	}
	return system->addPerson(new Pessoa(name, age, SexoConversor::toEnumerated(gender_code)));
}

bool insertDocument(Pessoa* person)
{
	printDocumentsMenu();
	std::string type("");
	int attempts(0);
	while (true)
	{
		type = getType(askForInteger("Enter the document type", 1, NUMBER_OF_DOCUMENTS, attempts++));
		if (type.empty())
		{
			std::cout << "\nAborting!!!";
			return false;
		}
		if (person->hasDocumento(type))
		{
			std::cout << "\nThis person already has this type of document!!!";
		}
		else
		{
			break;
		}
	}
	std::string number("");
	attempts = 0;
	while (true)
	{
		number = askForString("Enter the document number", attempts++);
		if (number.empty())
		{
			std::cout << "\nAborting!!!";
			return false;
		}
		if (person->hasDocumento(type, number))
		{
			std::cout << "\nThis person already has this document!!!";
		}
		else
		{
			break;
		}
	}
	std::string mother_name("");
	if (!person->hasDocumento())
	{
		mother_name = askForString("Enter the person's name");
		if (mother_name.empty())
		{
			std::cout << "\nAborting!!!";
			return false;
		}
	}
	else
	{
		mother_name = person->getDocumentos()[0]->getNomeMae();
	}
	Documento* document = NULL;
	if (type == "CPF")
	{
		document = new CPF(number, mother_name);
	}
	else if (type == "Titulo de Eleitor")
	{
		if (person->getIdade() < 16)
		{
			std::cout << "\nThis person must have age greater than or equal to 16 years-old!!!";
			std::cout << "\nAborting!!!";
			return false;
		}
		std::string zone(askForString("Enter the votation zone"));
		if (zone.empty())
		{
			std::cout << "\nAborting!!!";
			return false;
		}
		std::string section(askForString("Enter the votation section"));
		if (section.empty())
		{
			std::cout << "\nAborting!!!";
			return false;
		}
		document = new TituloDeEleitor(number, mother_name, zone, section);
	}
	else // is a DocumentoIdentificador
	{
		std::string emission(askForString("Enter the document emission date"));
		if (type == "RG")
		{
			std::string dob(askForString("Enter the person's day of birth"));
			if (dob.empty())
			{
				std::cout << "\nAborting!!!";
				return false;
			}
			std::string father_name(askForString("Enter the person's father's name"));
			std::string issuing(askForString("Enter the document issuing"));
			document = new RG(number, mother_name, dob, father_name, emission, issuing);
		}
		else if (type == "CNH")
		{
			if (person->getIdade() < 18)
			{
				std::cout << "\nThis person must have age greater than or equal to 18 years-old!!!";
				std::cout << "\nAborting!!!";
				return false;
			}
			if (!person->hasDocumento("RG"))
			{
				std::cout << "\nThis person must have RG!!!";
				std::cout << "\nAborting!!!";
				return false;
			}
			if (!person->hasDocumento("CPF"))
			{
				std::cout << "\nThis person must have CPF!!!";
				std::cout << "\nAborting!!!";
				return false;
			}
			std::string category(askForString("Enter the CNH category"));
			if (category.empty())
			{
				std::cout << "\nAborting!!!";
				return false;
			}
			std::string deadline(askForString("Enter the CNH deadline"));
			document = new CNH(number, (RG*) person->getDocumento("RG"),
												 (CPF*) person->getDocumento("CPF"),
												 category, deadline, emission);
		}
	}
	return document && person->addDocumento(document);
}

bool importFromCSV(System *system, std::string file_name)
{
	CSVParser parser(file_name);
	return parser.importFrom(system);
}

bool updateDocument(Pessoa* person)
{
	printDocumentsMenu();
	std::string type("");
	int attempts(0);
	while (true)
	{
		type = getType(askForInteger("Enter the document type", 1, NUMBER_OF_DOCUMENTS, attempts++));
		if (type.empty())
		{
			std::cout << "\nAborting!!!";
			return false;
		}
		if (!person->hasDocumento(type))
		{
			std::cout << "\nThis person does not have this type of document!!!";
		}
		else if (type == "CPF")
		{
			std::cout << "\nThere is nothing you can update in a CPF!!!";
		}
		else
		{
			break;
		}
	}
	if (type == "Titulo de Eleitor")
	{
		TituloDeEleitor *te = (TituloDeEleitor*) person->getDocumento(type);
		std::string zone(askForString("Enter the votation zone"));
		if (!zone.empty())
		{
			te->setZonaEleitoral(zone);
		}
		std::string section(askForString("Enter the votation section"));
		if (!section.empty())
		{
			te->setSessao(section);
		}
	}
	else
	{
		DocumentoIdentificador* document = (DocumentoIdentificador*) person->getDocumento(type);
		std::string emission(askForString("Enter the document emission date"));
		if (!emission.empty())
		{
			document->setEmissao(emission);
		}
		if (type == "RG")
		{
			RG *rg = (RG*) document;
			std::string issuing(askForString("Enter the document issuing"));
			if (!issuing.empty())
			{
				rg->setEmissor(issuing);
			}
		}
		else if (type == "CNH")
		{
			CNH *cnh = (CNH*) document;
			std::string category(askForString("Enter the CNH category"));
			if (!category.empty())
			{
				cnh->setCategoria(category);
			}
			std::string deadline(askForString("Enter the CNH deadline"));
			if (!deadline.empty())
			{
				cnh->setValidade(deadline);
			}
		}
	}
	return true;
}

bool updateFromCSV(System *system, std::string file_name)
{
	CSVParser parser(file_name);
	return parser.updateFrom(system);
}

bool showPerson(const Pessoa& person)
{
	print(person);
	return true;
}

bool showAll(const System& system)
{
	if (system.empty())
	{
		std::cout << "\nThere is no person registered yet!!!";
		return false;
	}
	print(system);
	return true;
}

bool showAllByAge(const System& system)
{
	if (system.empty())
	{
		std::cout << "\nThere is not any person registered yet!!!";
		return false;
	}
	int lower_age(askForInteger("Enter the lower age", 1, MAX_AGE));
	if (lower_age <= 0)
	{
		return false;
	}
	int upper_age(askForInteger("Enter the upper age", lower_age, MAX_AGE));
	if (upper_age < lower_age || upper_age > MAX_AGE)
	{
		return false;
	}
	std::vector<Pessoa*> people(system.getPeople(lower_age, upper_age));
	if (people.empty())
	{
		std::cout << "\nThere is not any person whose age is in between of " << lower_age << " and " << upper_age << " registered yet!!!";
		return false;
	}
	std::cout << "\nPeople whose age is in between of " << lower_age << " and " << upper_age << ":";
	for (int i = 0; i < people.size(); i++)
	{
		std::cout << "\nPerson " << i++ << ":";
		print(*people[i], "\t");
	}
	return true;
}

bool exportToCSV(const System& system, std::string file_name)
{
	CSVParser parser(file_name);
	return parser.exportTo(system);
}

bool removePerson(System *system, std::string person_name)
{
	return system->removePerson(person_name);;
}

std::string readString()
{
	std::string answer("");
	std::cin.clear();
	std::cin.ignore(INT_MAX);
	std::getline(std::cin, answer);
	if (std::cin.fail())
	{
		return "";
	}
	return answer;
}

int readInteger()
{
	int number(-1);
	std::cin >> number;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(INT_MAX);
		return -1;
	}
	return number;
}

std::string askForString(std::string message, int attempts)
{
	std::string answer("");
	for (int i = attempts; answer.empty(); i++)
	{
		if (i > NUMBER_OF_ATTEMPTS)
		{
			std::cout << "\nMaximum number of attempts exceeded!!!";
			return "";
		}
		std::cout << "\n" << message << ": ";
		answer = readString();
		if (answer == "q" || answer == "quit")
		{
			return "";
		}
	}
	return answer;
}

int askForInteger(std::string message, int min, int max, int attempts)
{
	int number(min - 1);
	for (int i = attempts; number < min || number > max; i++)
	{
		if (i > NUMBER_OF_ATTEMPTS)
		{
			std::cout << "\nMaximum number of attempts exceeded!!!";
			return min - 1;
		}
		std::cout << "\n" << message << ": ";
		number = readInteger();
	}
	return number;
}

std::string askForPersonName(const System& system)
{
	std::string person_name("");
	int attempts(0);
	while (true)
	{
		person_name = askForString("Enter the name of the desired person", attempts++);
		if (person_name.empty())
		{
			return "";
		}
		if (!system.contains(person_name))
		{
			std::cout << "\nThere is no person registered whose name is " + person_name + "!!!";
		}
		else
		{
			break;
		}
	}
	return person_name;
}

std::string askForFileName()
{
	std::string file_name("");
	int attempts(0);
	while (true)
	{
		file_name = askForString("Enter the name of the .CSV file", attempts++);
		if (file_name.empty())
		{
			return "";
		}
		if (!CSVParser::isValid(file_name))
		{
			std::cout << "\nInvalid (or inexistent) extension!!!";
		}
		else
		{
			break;
		}
	}
	return file_name;
}

std::string getType(int type)
{
	switch (type)
	{
		case 1:
			return "RG";
		case 2:
			return "CPF";
		case 3:
			return "CNH";
		case 4:
			return "Titulo de Eleitor";
	}
	return "";
}

void print(const System& system)
{
	std::vector<Pessoa*> people(system.getPeople());
	for (int i(0); i < people.size(); i++)
	{
		std::cout << "\nPerson " << i << ":";
		print(*people[i], "\t");
	}
	std::cout << "\nTotal of " << people.size() << (people.size() > 1 ? " people are" : " person is") << " registered!!!";
}

void print(const Pessoa& person, std::string identation)
{
	std::cout << "\n" + identation + "Name: " + person.getNome().c_str();
	std::cout << "\n" + identation + "Age: " << person.getIdade();
	std::cout << "\n" + identation + "Gender: " << SexoConversor::toString(person.getSexo());
	std::vector<Documento*> documents(person.getDocumentos());
	for (int i = 0; i < documents.size(); i++)
	{
		std::cout << "\n\tDocument " << i << ":";
		std::cout << "\n\t" + identation + documents[i]->str();
	}
}

void print(const Pessoa& person, const Documento& document, std::string identation)
{
	std::cout << "\n" + identation + "Name: " + person.getNome();
	std::cout << "\n" + identation + document.str();
}
