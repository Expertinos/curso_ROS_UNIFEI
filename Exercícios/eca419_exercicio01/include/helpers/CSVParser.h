#ifndef CSV_PARSER_H
#define CSV_PARSER_H

#define ERROR_LABEL "ERROR"
#define WARN_LABEL "WARN"
#define MAX_AGE 150

#include "helpers/System.h"
#include "eca419/exercicio01/Headers.h"

namespace helpers
{

	class CSVParser
	{
	public:
		CSVParser(std::string file_name);
		virtual ~CSVParser();
		bool importFrom(System *system);
		bool importFrom(std::string file_name, System *system);
		bool updateFrom(System *system);
		bool updateFrom(std::string file_name, System *system);
		bool exportTo(const System& system) const;
		bool exportTo(std::string file_name, const System& system);

		static bool isValid(std::string file_name);

	private:
		bool setFileName(std::string file_name);
		bool isKnown(std::string title) const;
		std::map<int, std::string> associateIndexesToColumnTitles(std::string titles_line) const;
		std::pair<std::string, eca419::exercicio01::Pessoa*> importPersonFrom(std::map<std::string, std::pair<int, std::string> > columns, int line);
		std::pair<std::string, eca419::exercicio01::Pessoa*> updatePersonFrom(System *system, std::map<std::string, std::pair<int, std::string> > columns, int line);
		std::string exportColumnTitles() const;
		std::string exportPerson(std::map<std::string, std::pair<int, std::string> > titles, const eca419::exercicio01::Pessoa &person) const;
		std::map<std::string, std::pair<int, std::string> > getColumns(std::map<int, std::string> titles, std::string line) const;
		std::pair<int, std::string> getColumn(std::map<std::string, std::pair<int, std::string> > columns, std::string title) const;
		std::string readColumn(std::map<std::string, std::pair<int, std::string> > columns, std::string title, int line = -1, std::string label = "") const;

		std::string file_name_;
		std::vector<const char*> known_titles_;

		static const char *COLUMN_TITLE_NAME;
		static const char *COLUMN_TITLE_AGE;
		static const char *COLUMN_TITLE_GENDER;
		static const char *COLUMN_TITLE_MOTHER_NAME;
		static const char *COLUMN_TITLE_DOB;
		static const char *COLUMN_TITLE_FATHER_NAME;
		static const char *COLUMN_TITLE_RG_NUMBER;
		static const char *COLUMN_TITLE_RG_EMISSION;
		static const char *COLUMN_TITLE_RG_ISSUING;
		static const char *COLUMN_TITLE_CPF_NUMBER;
		static const char *COLUMN_TITLE_CNH_NUMBER;
		static const char *COLUMN_TITLE_CNH_CATEGORY;
		static const char *COLUMN_TITLE_CNH_DEADLINE;
		static const char *COLUMN_TITLE_CNH_EMISSION;
		static const char *COLUMN_TITLE_TITULO_NUMBER;
		static const char *COLUMN_TITLE_TITULO_ZONE;
		static const char *COLUMN_TITLE_TITULO_SECTION;
	};

}

#endif // CSV_PARSER_H
