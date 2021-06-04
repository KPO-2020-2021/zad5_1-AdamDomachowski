#pragma once

#include "Vector3D.hh"
#include <fstream>
#include <vector>
#include <matrix3x3.hh>

class Solid
{
protected:

Vector3D *wymiary; /*! \brief wymiary bryly*/

std::vector<Vector3D> wierzcholki; /*! \brief wierzcholki bryly*/

Vector3D srodek_bryly; /*! \brief przechowuje wspolrzedne srodka bryly*/ 

std::string nazwa_pliku_bryly;  /*! \brief przechowuje nazwe pliku do którego zapisywane beda wierzcholki*/

public:
void wstaw_srodek(Vector3D srodek_bryly); /*! \brief ustawia wierzcholki srodka bryly*/

Vector3D zczytaj_srodek() const; /*! \brief zczytuje wierzcholki srodka bryly*/

std::string jaka_nazwa() const; /*! \brief zczytuje nazwe pliku do ktorego zapisywane beda wierzcholki*/

void przesun_o_wektor(Vector3D wektor_przesuniecia); /*! \brief przesuwa bryle o zadany wektor*/

void obrot(Matrix3x3 macierz_obrotu); /*! \brief obraca bryle o zadany kat*/

void zapisz_do_pliku(); /*! \brief zapisuje wspolrzedne bryly do pliku*/

};