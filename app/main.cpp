#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "../tests/doctest/doctest.h"
#endif

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <string>

#include "exampleConfig.h"
#include "example.h"
#include "Vector.hh"
#include "Matrix.hh"
#include "Cuboid.hh"
#include "prism6.hh"
#include "../inc/lacze_do_gnuplota.hh"

/*! \brief tu sie dzieje program*/


int main() {
  Vector3D wektor;
  Prism6 granek(wektor);


  PzG::LaczeDoGNUPlota Lacze;
  Lacze.DodajNazwePliku("../datas/graniastoslup6.dat", PzG::RR_Ciagly, 2);

  Lacze.ZmienTrybRys(PzG::TR_3D);

  Lacze.UstawZakresX(-155,155);
  Lacze.UstawZakresY(-155,155);
  Lacze.UstawZakresZ(-155,155);
  granek.zapisz_do_pliku();
  Lacze.Rysuj();

  while(1)
  {

  }
}