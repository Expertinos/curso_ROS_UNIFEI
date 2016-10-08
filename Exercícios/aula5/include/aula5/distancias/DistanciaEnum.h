#ifndef DISTANCIA_H
#define DISTANCIA_H

namespace aula5
{

namespace distancias
{

enum DistanciaEnum
{
  MUITO_LONGE,
  LONGE,
  PERTO,
  MUITO_PERTO
};

}

typedef typename distancias::DistanciaEnum Distancia;

}

#endif // DISTANCIA_H
