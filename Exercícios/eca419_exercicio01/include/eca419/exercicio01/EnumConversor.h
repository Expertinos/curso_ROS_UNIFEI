#ifndef ENUM_CONVERSOR_H
#define ENUM_CONVERSOR_H

#include <string>
#include <vector>

namespace eca419
{

	namespace exercicio01
	{

		template<typename E>
		class EnumConversor
		{
		public:
			virtual ~EnumConversor();
			E getEnumerated() const;
			virtual E getEnumerated(int id) const = 0;
			virtual E getEnumerated(std::string nome) const = 0;
			int getId() const;
			virtual int getId(std::string nome) const = 0;
			virtual int getId(E enumerated) const = 0;
			std::string str() const;
			virtual std::string str(E enumerated) const = 0;
			const char* c_str() const;
			virtual const char* c_str(E enumerated) const = 0;
			void operator =(int id);
			void operator =(std::string nome);
			void operator =(E enumerated);

		protected:
			EnumConversor(E enumerated);

		private:
			E enumerated_;

		};

		/**
		 * The implementation is used inside the header file because of
		 * the use of templates. This is the most recomended usage.
		 * Benefits: General usage.
		 */

		template<typename E>
		EnumConversor<E>::EnumConversor(E enumerated)
			: enumerated_(enumerated)
		{}

		template<typename E>
		EnumConversor<E>::~EnumConversor()
		{}

		template<typename E>
		E EnumConversor<E>::getEnumerated() const
		{
			return enumerated_;
		}

		template<typename E>
		int EnumConversor<E>::getId() const
		{
			return getId(enumerated_);
		}

		template<typename E>
		std::string EnumConversor<E>::str() const
		{
			return str(enumerated_);
		}

		template<typename E>
		const char* EnumConversor<E>::c_str() const
		{
			return str().c_str();
		}

		template<typename E>
		void EnumConversor<E>::operator =(int id)
		{
			enumerated_ = getEnumerated(id);
		}

		template<typename E>
		void EnumConversor<E>::operator =(std::string nome)
		{
			enumerated_ = getEnumerated(nome);
		}

		template<typename E>
		void EnumConversor<E>::operator =(E enumerated)
		{
			enumerated_ = enumerated;
		}

	}

}

#endif // ENUM_CONVERSOR_H
