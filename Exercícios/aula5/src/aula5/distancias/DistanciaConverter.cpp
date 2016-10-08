#include "aula5/distancias/DistanciaConverter.h"

namespace aula5
{

namespace distancias
{

DistanciaConverter::DistanciaConverter(int id)
  : EnumConverter(getEnumerated(id))
{}

DistanciaConverter::DistanciaConverter(std::string nome)
  : EnumConverter(getEnumerated(nome))
{}

DistanciaConverter::DistanciaConverter(Distancia distancia)
  : EnumConverter(distancia)
{}

DistanciaConverter::~DistanciaConverter()
{}

Distancia DistanciaConverter::getEnumerated(int id) const
{
  switch (id)
  {
  case 0:
    return MUITO_LONGE;
  case 1:
    return LONGE;
  case 2:
    return PERTO;
  case 3:
    return MUITO_PERTO;
  }
  return DistanciaConverter::getDefault();
}

Distancia DistanciaConverter::getEnumerated(std::string nome) const
{
  if (nome == "MUITO_LONGE" || nome == "muito longe" || nome == "Muito Longe")
  {
    return MUITO_LONGE;
  }
  else if (nome == "LONGE" || nome == "longe" || nome == "Longe")
  {
    return LONGE;
  }
  else if (nome == "PERTO" || nome == "perto" || nome == "Perto")
  {
    return PERTO;
  }
  else if (nome == "MUITO_PERTO" || nome == "muito perto" || nome == "Muito Perto")
  {
    return MUITO_PERTO;
  }
  return getDefault();
}

int DistanciaConverter::getId(std::string nome) const
{
  if (nome == "MUITO_LONGE" || nome == "muito longe" || nome == "Muito Longe")
  {
    return 0;
  }
  else if (nome == "LONGE" || nome == "longe" || nome == "Longe")
  {
    return 1;
  }
  else if (nome == "PERTO" || nome == "perto" || nome == "Perto")
  {
    return 2;
  }
  else if (nome == "MUITO_PERTO" || nome == "muito perto" || nome == "Muito Perto")
  {
    return 3;
  }
  return -1;
}

int DistanciaConverter::getId(Distancia distancia) const
{
  switch (distancia)
  {
  case MUITO_LONGE:
    return 0;
  case LONGE:
    return 1;
  case PERTO:
    return 2;
  case MUITO_PERTO:
    return 3;
  }
  return -1;
}

std::string DistanciaConverter::str(Distancia distancia) const
{
  switch (distancia)
  {
  case MUITO_LONGE:
    return "MUITO_LONGE";
  case LONGE:
    return "LONGE";
  case PERTO:
    return "PERTO";
  case MUITO_PERTO:
    return "MUITO_PERTO";
  }
  return "";
}

const char* DistanciaConverter::c_str(Distancia distancia) const
{
  return str(distancia).c_str();
}

int DistanciaConverter::toId(Distancia distancia)
{
  DistanciaConverter converter(distancia);
  return converter.getId();
}

Distancia DistanciaConverter::toEnumerated(int id)
{
  DistanciaConverter converter(id);
  return converter.getEnumerated();
}

Distancia DistanciaConverter::toEnumerated(std::string nome)
{
  DistanciaConverter converter(nome);
  return converter.getEnumerated();
}

bool DistanciaConverter::isValid(std::string nome)
{
  return nome == "MUITO_LONGE" || nome == "muito longe" || nome == "Muito Longe" ||
         nome == "LONGE" || nome == "longe" || nome == "Longe" ||
         nome == "PERTO" || nome == "perto" || nome == "Perto" ||
         nome == "MUITO_PERTO" || nome == "muito perto" || nome == "Muito Perto";
}

std::string DistanciaConverter::toString(Distancia distancia)
{
  DistanciaConverter converter(distancia);
  return converter.str();
}

const char* DistanciaConverter::toCString(Distancia distancia)
{
  DistanciaConverter converter(distancia);
  return converter.c_str();
}

Distancia DistanciaConverter::getDefault()
{
  return MUITO_PERTO;
}

std::vector<Distancia> DistanciaConverter::getAll()
{
  std::vector<Distancia> distancias;
  distancias.push_back(MUITO_LONGE);
  distancias.push_back(LONGE);
  distancias.push_back(PERTO);
  distancias.push_back(MUITO_PERTO);
  return distancias;
}

Distancia DistanciaConverter::getMinimum()
{
  return MUITO_PERTO;
}

Distancia DistanciaConverter::getMaximum()
{
  return MUITO_LONGE;
}

}

}
