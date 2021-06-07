#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
#include "prism6.hh"
#include "lacze_do_gnuplota.hh"
#include "Drone.hh"
#include "bottom.hh"
#define ilosc_dronow_na_scenie 4


class Scena
{
PzG::LaczeDoGNUPlota Lacze;
Drone *tab[ilosc_dronow_na_scenie]; /*! \brief tablica dronów*/
Bottom *podloze; /*! \brief wskaźnik na przygotowaną podloge*/
public:
Scena(); /*! \brief przygotowuje scene*/
void rysuj(); /*! \brief rysuje sytuacje*/
bool menu(); /*! \brief wyswietla menu i odpowiada za wybor drona*/
};
