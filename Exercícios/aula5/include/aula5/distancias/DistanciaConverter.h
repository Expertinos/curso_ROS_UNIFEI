#ifndef DISTANCIA_CONVERTER_H
#define DISTANCIA_CONVERTER_H

#include "aula5/distancias/DistanciaEnum.h"
#include "EnumConverter.h"

namespace aula5
{

namespace distancias
{

class DistanciaConverter : public EnumConverter<Distancia>
{
public:
  DistanciaConverter(int id);
  DistanciaConverter(std::string nome);
  DistanciaConverter(Distancia distancia);
  virtual ~DistanciaConverter();
  using EnumConverter::getEnumerated;
  virtual Distancia getEnumerated(int id) const;
  virtual Distancia getEnumerated(std::string nome) const;
  using EnumConverter::getId;
  virtual int getId(std::string nome) const;
  virtual int getId(Distancia distancia) const;
  using EnumConverter::str;
  virtual std::string str(Distancia distancia) const;
  using EnumConverter::c_str;
  virtual const char* c_str(Distancia distancia) const;

  static int toId(Distancia distancia);
  static Distancia toEnumerated(int id);
  static Distancia toEnumerated(std::string nome);
  static bool isValid(std::string nome);
  static std::string toString(Distancia distancia);
  static const char* toCString(Distancia distancia);
  static Distancia getDefault();
  static Distancia getMinimum();
  static Distancia getMaximum();
  static std::vector<Distancia> getAll();

};

}

typedef typename distancias::DistanciaConverter DistanciaConverter;

}


#endif // DISTANCIA_CONVERTER_H
