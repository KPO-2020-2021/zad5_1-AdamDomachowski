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
#include "Drone.hh"
#include "../inc/lacze_do_gnuplota.hh"

/*! \brief tu sie dzieje program*/


int main() {
Drone d(0);


  PzG::LaczeDoGNUPlota Lacze;
  Lacze.DodajNazwePliku("../datas/cuboid.dat", PzG::RR_Ciagly, 2);

  Lacze.ZmienTrybRys(PzG::TR_3D);

  Lacze.UstawZakresX(-300,300);
  Lacze.UstawZakresY(-300,300);
  Lacze.UstawZakresZ(-300,300);
  d.zapisz();
  Lacze.Rysuj();
  while(1)
  {
  d.pilot(Lacze);
  }
}