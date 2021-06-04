#pragma once  

#include "Solid.hh"

class Cuboid : public Solid
{

public:

/*! \brief konstruktor parametryczny*/
Cuboid(Vector3D srodek, double a=200, double b=200, double c=200, std::string nazwa_pliku_prostopadloscianu = "../datas/cuboid.dat");


};