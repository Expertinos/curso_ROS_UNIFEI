#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "helpers/CSVParser.h"

using namespace eca419::exercicio01;

namespace helpers
{

	const char *CSVParser::COLUMN_TITLE_NAME = "Nome";
	const char *CSVParser::COLUMN_TITLE_AGE = "Idade";
	const char *CSVParser::COLUMN_TITLE_GENDER = "Sexo";
	const char *CSVParser::COLUMN_TITLE_MOTHER_NAME = "Nome Mae";
	const char *CSVParser::COLUMN_TITLE_DOB = "Nascimento";
	const char *CSVParser::COLUMN_TITLE_FATHER_NAME = "Nome Pai";
	const char *CSVParser::COLUMN_TITLE_RG_NUMBER = "Numero RG";
	const char *CSVParser::COLUMN_TITLE_RG_EMISSION = "Emissao RG";
	const char *CSVParser::COLUMN_TITLE_RG_ISSUING = "Emissor RG";
	const char *CSVParser::COLUMN_TITLE_CPF_NUMBER = "Numero CPF";
	const char *CSVParser::COLUMN_TITLE_CNH_NUMBER = "Numero CNH";
	const char *CSVParser::COLUMN_TITLE_CNH_CATEGORY = "Categoria CNH";
	const char *CSVParser::COLUMN_TITLE_CNH_DEADLINE = "Validade CNH";
	const char *CSVParser::COLUMN_TITLE_CNH_EMISSION = "Emissao CNH";
	const char *CSVParser::COLUMN_TITLE_TITULO_NUMBER = "Numero Titulo";
	const char *CSVParser::COLUMN_TITLE_TITULO_ZONE = "Zona Eleitoral";
	const char *CSVParser::COLUMN_TITLE_TITULO_SECTION = "Sessao";

	CSVParser::CSVParser(std::string file_name)
		: file_name_(file_name)
	{
		known_titles_.clear();
		known_titles_.push_back(COLUMN_TITLE_NAME);
		known_titles_.push_back(COLUMN_TITLE_AGE);
		known_titles_.push_back(COLUMN_TITLE_GENDER);
		known_titles_.push_back(COLUMN_TITLE_MOTHER_NAME);
		known_titles_.push_back(COLUMN_TITLE_DOB);
		known_titles_.push_back(COLUMN_TITLE_FATHER_NAME);
		known_titles_.push_back(COLUMN_TITLE_RG_NUMBER);
		known_titles_.push_back(COLUMN_TITLE_RG_EMISSION);
		known_titles_.push_back(COLUMN_TITLE_RG_ISSUING);
		known_titles_.push_back(COLUMN_TITLE_CPF_NUMBER);
		known_titles_.push_back(COLUMN_TITLE_CNH_NUMBER);
		known_titles_.push_back(COLUMN_TITLE_CNH_CATEGORY);
		known_titles_.push_back(COLUMN_TITLE_CNH_DEADLINE);
		known_titles_.push_back(COLUMN_TITLE_CNH_EMISSION);
		known_titles_.push_back(COLUMN_TITLE_TITULO_NUMBER);
		known_titles_.push_back(COLUMN_TITLE_TITULO_ZONE);
		known_titles_.push_back(COLUMN_TITLE_TITULO_SECTION);
	}

	CSVParser::~CSVParser()
	{}

	bool CSVParser::importFrom(System *system)
	{
		if (!system)
		{
			return false;
		}
		std::ifstream csv_file;
		csv_file.open(file_name_.c_str(), std::ifstream::in);
		if (!csv_file.is_open())
		{
			std::cout << "\nInexistent file path!!!";
			csv_file.close();
			return false;
		}
		int line(0);
		std::string str_line("");
		while (str_line.empty() && csv_file.good())
		{
			std::getline(csv_file, str_line);
			line++;
		}
		if (str_line.empty())
		{
			std::cout << "\nEmpty file!!!";
			std::cout << "\nAborting!!!";
			csv_file.close();
			return false;
		}
		std::map<int, std::string> titles(associateIndexesToColumnTitles(str_line));
		if (titles.empty())
		{
			std::cout << "\nUnknown column titles!!!";
			std::cout << "\nAborting!!!";
			csv_file.close();
			return false;
		}
		int imports(0);
		std::map<std::string, Pessoa*> people;
		while (csv_file.good())
		{
			std::getline(csv_file, str_line);
			if (str_line.empty())
			{
				continue;
			}
			std::map<std::string, std::pair<int, std::string> > columns(getColumns(titles, str_line));
			if (columns.size() != titles.size())
			{
				std::cout << "\n[" << ERROR_LABEL << "] @ line: " << line << ": ";
				std::cout << "The number of columns in a line (" << columns.size()
									<< ") must be equals to the number of title columns ("
									<< titles.size() << ") at the first line!!!";
				continue;
			}
			std::pair<std::string, Pessoa*> person(importPersonFrom(columns, ++line));
			if (!person.first.empty())
			{
				imports++;
				people.insert(person);
			}
		}
		int failures(line - imports);
		if (failures > 0)
		{
			std::cout << "\nFailed " << failures << " time" << (failures > 1 ? "s" : "") << "!!!";
		}
		if (imports > 0)
		{
			std::cout << "\nImported " << imports << (imports > 1 ? " people" : " person") << "!!!";
		}
		else
		{
			std::cout << "\nNone person has been imported!!!";
		}
		csv_file.close();
		return system->addPeople(people) && !csv_file.is_open();
	}

	bool CSVParser::importFrom(std::string file_name, System *system)
	{
		return setFileName(file_name) && importFrom(system);
	}

	bool CSVParser::updateFrom(System *system)
	{
		if (!system)
		{
			return false;
		}
		std::ifstream csv_file;
		csv_file.open(file_name_.c_str(), std::ifstream::in);
		if (!csv_file.is_open())
		{
			std::cout << "\nInexistent file path!!!";
			csv_file.close();
			return false;
		}
		int line(0);
		std::string str_line("");
		while (str_line.empty() && csv_file.good())
		{
			std::getline(csv_file, str_line);
			line++;
		}
		if (str_line.empty())
		{
			std::cout << "\nEmpty file!!!";
			std::cout << "\nAborting!!!";
			csv_file.close();
			return false;
		}
		std::map<int, std::string> titles(associateIndexesToColumnTitles(str_line));
		if (titles.empty())
		{
			std::cout << "\nUnknown column titles!!!";
			std::cout << "\nAborting!!!";
			csv_file.close();
			return false;
		}
		int updates(0);
		std::map<std::string, Pessoa*> people;
		while (csv_file.good())
		{
			std::getline(csv_file, str_line);
			if (str_line.empty())
			{
				continue;
			}
			std::map<std::string, std::pair<int, std::string> > columns(getColumns(titles, str_line));
			if (columns.size() != titles.size())
			{
				std::cout << "\n[" << ERROR_LABEL << "] @ line: " << line << ": ";
				std::cout << "The number of columns in a line (" << columns.size()
									<< ") must be equals to the number of title columns ("
									<< titles.size() << ") at the first line!!!";
				continue;
			}
			std::pair<std::string, Pessoa*> person(updatePersonFrom(system, columns, ++line));
			if (!person.first.empty())
			{
				updates++;
				people.insert(person);
			}
		}
		int failures(line - updates);
		if (failures > 0)
		{
			std::cout << "\nFailed " << failures << " time" << (failures > 1 ? "s" : "") << "!!!";
		}
		if (updates > 0)
		{
			std::cout << "\nUpdated " << updates << (updates > 1 ? " people" : " person") << "!!!";
		}
		else
		{
			std::cout << "\nNone person has been updated!!!";
		}
		csv_file.close();
		return system->updatePeople(people) && !csv_file.is_open();
	}

	bool CSVParser::updateFrom(std::string file_name, System *system)
	{
		return setFileName(file_name) && updateFrom(system);
	}

	bool CSVParser::exportTo(const System& system) const
	{
		if (system.empty())
		{
			std::cout << "\nThere is no person registered yet!!!";
			return false;
		}
		std::vector<Pessoa*> people(system.getPeople());
		std::ofstream csv_file;
		csv_file.open(file_name_.c_str());
		if (!csv_file.is_open())
		{
			std::cout << "\nInexistent file path!!!";
			csv_file.close();
			return false;
		}
		std::string titles_line(exportColumnTitles());
		csv_file << titles_line;
		std::map<std::string, std::pair<int, std::string> > titles(getColumns(associateIndexesToColumnTitles(titles_line), titles_line));
		for (std::vector<Pessoa*>::const_iterator it(people.begin()); it != people.end(); it++)
		{
			csv_file << "\n" << exportPerson(titles, **it);
		}
		csv_file.close();
		return !csv_file.is_open();
	}

	bool CSVParser::exportTo(std::string file_name, const System& system)
	{
		return setFileName(file_name) && exportTo(system);
	}

	bool CSVParser::setFileName(std::string file_name)
	{
		std::string extension(".csv");
		if (file_name.size() <= extension.size() || file_name.find(extension) + extension.size() != file_name.size())
		{
			file_name_ = "";
			return false;
		}
		file_name_ = file_name;
		return true;
	}

	bool CSVParser::isValid(std::string file_name)
	{
		std::string extension(".csv");
		return file_name.size() > extension.size() && file_name.find(extension) + extension.size() == file_name.size();
	}

	std::map<int, std::string> CSVParser::associateIndexesToColumnTitles(std::string titles_line) const
	{
		std::map<int, std::string> titles;
		if (!titles_line.empty())
		{
			std::size_t index(0), next_index;
			next_index = titles_line.find(',', index);
			int counter(0);
			while (index < titles_line.size())
			{
				std::string title(titles_line.substr(index, next_index - index));
				if (!title.empty() && isKnown(title))
				{
					titles[counter++] = title;
				}
				index = next_index != std::string::npos ? next_index + 1 : titles_line.size();
				next_index = titles_line.find(',', index);
			}
		}
		return titles;
	}

	bool CSVParser::isKnown(std::string title) const
	{
		for (int i(0); i < known_titles_.size(); i++)
		{
			if (known_titles_[i] == title)
			{
				return true;
			}
		}
		return false;
	}

	std::pair<std::string, Pessoa*> CSVParser::importPersonFrom(std::map<std::string, std::pair<int, std::string> > columns, int line)
	{
		std::pair<std::string, Pessoa*> pair("", NULL);
		std::string name(readColumn(columns, COLUMN_TITLE_NAME, line, ERROR_LABEL));
		if (name.empty())
		{
			std::cout << "Person's name must NOT be empty!!!";
			return pair;
		}
		std::pair<int, std::string> column(getColumn(columns, COLUMN_TITLE_AGE));
		int age(atoi(readColumn(columns, COLUMN_TITLE_AGE).c_str()));
		if (age <= 0 || age > MAX_AGE)
		{
			std::cout << "\n[" << ERROR_LABEL << "] @ line: " << line << ", column: " << column.first << ": ";
			std::cout << "Person's age must be a positive number (0, " << MAX_AGE << "]!!!";
			return pair;
		}
		column = getColumn(columns, COLUMN_TITLE_GENDER);
		std::string gender(readColumn(columns, COLUMN_TITLE_GENDER));
		if (!SexoConversor::isValid(gender))
		{
			std::cout << "\n[" << ERROR_LABEL << "] @ line: " << line << ", column: " << column.first << ": ";
			std::cout << "Person's gender must be valid (M or F)!!!";
			return pair;
		}
		Pessoa *person = new Pessoa(name, age, SexoConversor::toEnumerated(gender));
		pair = std::pair<std::string, Pessoa*>(name, person);
		std::string mother(readColumn(columns, COLUMN_TITLE_MOTHER_NAME, line, WARN_LABEL));
		if (mother.empty())
		{
			std::cout << "Person's mother's name must be known to have any document!!!";
			return pair;
		}
		CPF *cpf = NULL;
		std::string cpf_number(readColumn(columns, COLUMN_TITLE_CPF_NUMBER));
		if (!cpf_number.empty())
		{
			cpf = new CPF(cpf_number, mother);
			person->addDocumento(cpf);
		}
		column = getColumn(columns, COLUMN_TITLE_TITULO_NUMBER);
		std::string te_number(readColumn(columns, COLUMN_TITLE_TITULO_NUMBER));
		if (!te_number.empty())
		{
			if (person->getIdade() >= 16)
			{
				std::string te_zone(readColumn(columns, COLUMN_TITLE_TITULO_ZONE));
				std::string te_section(readColumn(columns, COLUMN_TITLE_TITULO_SECTION));
				person->addDocumento(new TituloDeEleitor(te_number, mother, te_zone, te_section));
			}
			else
			{
				std::cout << "\n[" << WARN_LABEL << "] @ line: " << line << ", column: " << column.first << ": ";
				std::cout << "Person must be at least 16 years-old to have a Titulo de Eleitor!!!";
			}
		}
		std::string father(readColumn(columns, COLUMN_TITLE_FATHER_NAME));
		std::string dob(readColumn(columns, COLUMN_TITLE_DOB, line, WARN_LABEL));
		if (dob.empty())
		{
			std::cout << "Person's day-of-birth must be known to have any identification document!!!";
			return pair;
		}
		std::string rg_number(readColumn(columns, COLUMN_TITLE_RG_NUMBER));
		RG *rg = NULL;
		if (!rg_number.empty())
		{
			std::string rg_emission(readColumn(columns, COLUMN_TITLE_RG_EMISSION));
			std::string rg_issuing(readColumn(columns, COLUMN_TITLE_RG_ISSUING));
			rg = new RG(rg_number, mother, dob, father, rg_emission, rg_issuing);
			person->addDocumento(rg);
		}
		column = getColumn(columns, COLUMN_TITLE_CNH_NUMBER);
		std::string cnh_number(readColumn(columns, COLUMN_TITLE_CNH_NUMBER));
		if (!cnh_number.empty())
		{
			if (person->getIdade() >= 18)
			{
				if (rg)
				{
					if (cpf)
					{
						std::string cnh_category(readColumn(columns, COLUMN_TITLE_CNH_CATEGORY, line, WARN_LABEL));
						if (cnh_category.empty())
						{
							std::cout << "Person's CNH must have a category!!!";
						}
						else
						{
							std::string cnh_deadline(readColumn(columns, COLUMN_TITLE_CNH_DEADLINE));
							std::string cnh_emission(readColumn(columns, COLUMN_TITLE_CNH_EMISSION));
							person->addDocumento(new CNH(cnh_number, rg, cpf, cnh_category, cnh_deadline, cnh_emission));
						}
					}
					else
					{
						std::cout << "\n[" << WARN_LABEL << "] @ line: " << line << ", column: " << column.first << ": ";
						std::cout << "Person must have CPF to have a CNH!!!";
					}
				}
				else
				{
					std::cout << "\n[" << WARN_LABEL << "] @ line: " << line << ", column: " << column.first << ": ";
					std::cout << "Person must have RG to have a CNH!!!";
				}
			}
			else
			{
				std::cout << "\n[" << WARN_LABEL << "] @ line: " << line << ", column: " << column.first << ": ";
				std::cout << "Person must be at least 18 years-old to have a CNH!!!";
			}
		}
		return pair;
	}

	std::pair<std::string, Pessoa*> CSVParser::updatePersonFrom(System *system, std::map<std::string, std::pair<int, std::string> > columns, int line)
	{
		std::pair<std::string, Pessoa*> pair("", NULL);
		std::string name(readColumn(columns, COLUMN_TITLE_NAME, line, ERROR_LABEL));
		if (name.empty())
		{
			std::cout << "Person's name must NOT be empty!!!";
			return pair;
		}
		if (!system->contains(name))
		{
			return importPersonFrom(columns, line);
		}
		Pessoa *person = system->getPerson(name)->clone();
		pair = std::pair<std::string, Pessoa*>(person->getNome(), person);
		std::pair<int, std::string> column(getColumn(columns, COLUMN_TITLE_AGE));
		std::string age_str(readColumn(columns, COLUMN_TITLE_AGE));
		int age(person->getIdade());
		if (!age_str.empty())
		{
			age = atoi(age_str.c_str());
			if (age > 0 && age <= person->getIdade())
			{
				std::cout << "\n[" << WARN_LABEL << "] @ line: " << line << ", column: " << column.first << ": ";
				std::cout << "Person's age must be greater than his registered age (" << person->getIdade() << ")!!!";
				age = person->getIdade();
			}
			else if (age > person->getIdade() && age <= MAX_AGE)
			{
				person->setIdade(age);
			}
		}
		std::string cpf_number(readColumn(columns, COLUMN_TITLE_CPF_NUMBER));
		std::string te_number(readColumn(columns, COLUMN_TITLE_TITULO_NUMBER));
		std::string rg_number(readColumn(columns, COLUMN_TITLE_RG_NUMBER));
		std::string cnh_number(readColumn(columns, COLUMN_TITLE_CNH_NUMBER));
		if (cpf_number.empty() && te_number.empty() && rg_number.empty() && cnh_number.empty())
		{
			return pair;
		}
		std::string mother(person->getNomeMae());
		if (mother.empty())
		{
			mother = readColumn(columns, COLUMN_TITLE_MOTHER_NAME, line, WARN_LABEL);
			if (mother.empty())
			{
				std::cout << "Person's mother's name must be known to have any document!!!";
				return pair;
			}
		}
		if (!cpf_number.empty())
		{
			CPF *cpf = NULL;
			if (!person->hasDocumento("CPF", cpf_number))
			{
				cpf = new CPF(cpf_number, mother);
				if (person->hasDocumento("CPF"))
				{
					person->updateDocumento(cpf);
				}
				else
				{
					person->addDocumento(cpf);
				}
			}
		}
		if (!te_number.empty())
		{
			if (person->getIdade() >= 16)
			{
				std::string te_zone(readColumn(columns, COLUMN_TITLE_TITULO_ZONE));
				std::string te_section(readColumn(columns, COLUMN_TITLE_TITULO_SECTION));
				TituloDeEleitor *te = NULL;
				if (person->hasDocumento("Titulo de Eleitor"))
				{
					te = (TituloDeEleitor*) person->getDocumento("Titulo de Eleitor");
					if (person->hasDocumento("Titulo de Eleitor", te_number))
					{
						te = (TituloDeEleitor*) te->clone();
						te->setZonaEleitoral(te_zone);
						te->setSessao(te_section);
					}
					else
					{
						te = new TituloDeEleitor(te_number, mother, te_zone, te_section);
					}
					person->updateDocumento(te);
				}
				else
				{
					te = new TituloDeEleitor(te_number, mother, te_zone, te_section);
					person->addDocumento(te);
				}
			}
			else
			{
				std::cout << "\n[" << WARN_LABEL << "] @ line: " << line << ", column: " << column.first << ": ";
				std::cout << "Person must be at least 16 years-old to have a Titulo de Eleitor!!!";
			}
		}
		if (rg_number.empty() && cnh_number.empty())
		{
			return pair;
		}
		std::string dob, father;
		dob = readColumn(columns, COLUMN_TITLE_DOB, line, WARN_LABEL);
		father = readColumn(columns, COLUMN_TITLE_FATHER_NAME);
		if (!rg_number.empty())
		{
			std::string rg_emission(readColumn(columns, COLUMN_TITLE_RG_EMISSION));
			std::string rg_issuing(readColumn(columns, COLUMN_TITLE_RG_ISSUING));
			RG *rg = NULL;
			if (person->hasDocumento("RG"))
			{
				rg = (RG*) person->getDocumento("RG");
				if (rg->getNumero() == rg_number)
				{
					rg = (RG*) rg->clone();
					rg->setEmissao(rg_emission);
					rg->setEmissor(rg_issuing);
				}
				else
				{
					rg = new RG(rg_number, *rg, rg_emission, rg_issuing);
				}
				person->updateDocumento(rg);
			}
			else
			{
				if (dob.empty())
				{
					std::cout << "Person's day-of-birth must be known to have any identification document!!!";
					return pair;
				}
				rg = new RG(rg_number, mother, dob, father, rg_emission, rg_issuing);
				person->addDocumento(rg);
			}
		}
		if (!cnh_number.empty())
		{
			if (person->getIdade() >= 18)
			{
				if (person->hasDocumento("RG"))
				{
					RG *rg = (RG*) person->getDocumento("RG");
					if (person->hasDocumento("CPF"))
					{
						CPF *cpf = (CPF*) person->getDocumento("CPF");
						std::string cnh_category(readColumn(columns, COLUMN_TITLE_CNH_CATEGORY, line, WARN_LABEL));
						std::string cnh_deadline(readColumn(columns, COLUMN_TITLE_CNH_DEADLINE));
						std::string cnh_emission(readColumn(columns, COLUMN_TITLE_CNH_EMISSION));
						CNH *cnh = NULL;
						if (person->hasDocumento("CNH"))
						{
							cnh = (CNH*) person->getDocumento("CNH");
							if (person->hasDocumento("CNH", cnh_number))
							{
								cnh = (CNH*) cnh->clone();
								cnh->setCategoria(cnh_category);
								cnh->setEmissao(cnh_emission);
								cnh->setValidade(cnh_deadline);
							}
							else
							{
								cnh = new CNH(cnh_number, rg, cpf, cnh_category, cnh_deadline, cnh_emission);
							}
							person->updateDocumento(cnh);
						}
						else
						{
							if (cnh_category.empty())
							{
								std::cout << "Person's CNH must have a category!!!";
								return pair;
							}
							cnh = new CNH(cnh_number, rg, cpf, cnh_category, cnh_deadline, cnh_emission);
							person->addDocumento(cnh);
						}
					}
					else
					{
						std::cout << "\n[" << WARN_LABEL << "] @ line: " << line << ", column: " << column.first << ": ";
						std::cout << "Person must have CPF to have a CNH!!!";
					}
				}
				else
				{
					std::cout << "\n[" << WARN_LABEL << "] @ line: " << line << ", column: " << column.first << ": ";
					std::cout << "Person must have RG to have a CNH!!!";
				}
			}
			else
			{
				std::cout << "\n[" << WARN_LABEL << "] @ line: " << line << ", column: " << column.first << ": ";
				std::cout << "Person must be at least 18 years-old to have a CNH!!!";
			}
		}
		return pair;
	}

	std::string CSVParser::exportColumnTitles() const
	{
		std::stringstream ss;
		if (known_titles_.empty())
		{
			return "";
		}
		ss << known_titles_[0];
		for (int i(1); i < known_titles_.size(); i++)
		{
			ss << "," << known_titles_[i];
		}
		return ss.str();
	}

	std::string CSVParser::exportPerson(std::map<std::string, std::pair<int, std::string> > titles, const Pessoa& person) const
	{
		std::vector<std::string> columns(known_titles_.size());
		columns[getColumn(titles, COLUMN_TITLE_NAME).first] = person.getNome();
		std::stringstream aux;
		aux << person.getIdade();
		columns[getColumn(titles, COLUMN_TITLE_AGE).first] = aux.str();
		columns[getColumn(titles, COLUMN_TITLE_GENDER).first] = SexoConversor::toString(person.getSexo());
		columns[getColumn(titles, COLUMN_TITLE_MOTHER_NAME).first] = person.getNomeMae();
		if (person.hasDocumento())
		{
			if (person.hasDocumento("CPF"))
			{
				CPF *cpf = (CPF*) person.getDocumento("CPF");
				columns[getColumn(titles, COLUMN_TITLE_CPF_NUMBER).first] = cpf->getNumero();
			}
			if (person.hasDocumento("Titulo de Eleitor"))
			{
				TituloDeEleitor *te = (TituloDeEleitor*) person.getDocumento("Titulo de Eleitor");
				columns[getColumn(titles, COLUMN_TITLE_TITULO_NUMBER).first] = te->getNumero();
				columns[getColumn(titles, COLUMN_TITLE_TITULO_ZONE).first] = te->getZonaEleitoral();
				columns[getColumn(titles, COLUMN_TITLE_TITULO_SECTION).first] = te->getSessao();
			}
			if (person.hasDocumento("RG"))
			{
				RG *rg = (RG*) person.getDocumento("RG");
				columns[getColumn(titles, COLUMN_TITLE_DOB).first] = rg->getNascimento();
				columns[getColumn(titles, COLUMN_TITLE_FATHER_NAME).first] = rg->getNomePai();
				columns[getColumn(titles, COLUMN_TITLE_RG_NUMBER).first] = rg->getNumero();
				columns[getColumn(titles, COLUMN_TITLE_RG_EMISSION).first] = rg->getEmissao();
				columns[getColumn(titles, COLUMN_TITLE_RG_ISSUING).first] = rg->getEmissor();
			}
			if (person.hasDocumento("CNH"))
			{
				CNH *cnh = (CNH*) person.getDocumento("CNH");
				columns[getColumn(titles, COLUMN_TITLE_CNH_NUMBER).first] = cnh->getNumero();
				columns[getColumn(titles, COLUMN_TITLE_CNH_CATEGORY).first] = cnh->getCategoria();
				columns[getColumn(titles, COLUMN_TITLE_CNH_DEADLINE).first] = cnh->getValidade();
				columns[getColumn(titles, COLUMN_TITLE_CNH_EMISSION).first] = cnh->getEmissao();
			}
		}
		if (columns.size() != titles.size())
		{
			return "";
		}
		std::stringstream ss;
		ss << columns[0];
		for (int i(1); i < columns.size(); i++)
		{
			ss << "," << columns[i];
		}
		return ss.str();
	}

	std::map<std::string, std::pair<int, std::string> > CSVParser::getColumns(std::map<int, std::string> titles, std::string line) const
	{
		std::map<std::string, std::pair<int, std::string> > columns;
		int counter(0);
		std::size_t index(0), next_index;
		next_index = line.find(',', index);
		while (index < line.size())
		{
			std::string column(line.substr(index, next_index - index));
			columns.insert(std::pair<std::string, std::pair<int, std::string> >(titles[counter++], std::pair<int, std::string>(counter, column)));
			index = next_index != std::string::npos ? next_index + 1 : line.size();
			next_index = line.find(',', index);
		}
		if (!line.empty() && line[line.size() - 1] == ',')
		{
			columns.insert(std::pair<std::string, std::pair<int, std::string> >(titles[counter], std::pair<int, std::string>(-1, "")));
		}
		if (columns.size() != titles.size())
		{
			columns.empty();
		}
		return columns;
	}

	std::pair<int, std::string> CSVParser::getColumn(std::map<std::string, std::pair<int, std::string> > columns, std::string title) const
	{
		std::map<std::string, std::pair<int, std::string> >::iterator it(columns.find(title));
		return it != columns.end() ? it->second : std::pair<int, std::string>(-1, "");
	}

	std::string CSVParser::readColumn(std::map<std::string, std::pair<int, std::string> > columns, std::string title, int line, std::string label) const
	{
		std::map<std::string, std::pair<int, std::string> >::iterator it(columns.find(title));
		if (it == columns.end())
		{
			return "";
		}
		std::pair<int, std::string> column(it->second);
		if (!label.empty() && column.second.empty())
		{
			std::cout << "\n[" << label << "] @ line: " << line << ", column: " << column.first << ": ";
		}
		return column.second;
	}

}
