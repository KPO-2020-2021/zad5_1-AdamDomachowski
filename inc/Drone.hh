#pragma once
#include <unistd.h>
#include "Cuboid.hh"
#include "prism6.hh"
#include "../inc/lacze_do_gnuplota.hh"

class Drone 
{
    int nr_drona;
    Matrix3x3 macierz_obrotu;
    Vector3D droga;
    double kat;
    Cuboid body_dummy;
    Cuboid body_copy;

public:

    Drone(int nr_drona);
    void obrot(double kat);
    void przesun(double dorga); /*! \brief tutaj podajemy odleglosc o jaka dron ma sie przesunac */
    void zapisz();
    void pilot(PzG::LaczeDoGNUPlota &Lacze);
};