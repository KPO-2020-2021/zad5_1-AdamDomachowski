#pragma once

#include "Vector3D.hh"
#include "matrix3x3.hh"
#include <fstream>
#include <vector>

class Bottom
{
protected:
    std::vector<Vector3D> wierzcholki;
    std::string nazwa;
    int proste;
public:
    Bottom(Vector3D wymiary=Vector3D(), int grubosc_kratki = 5, std::string nazwa_pliku = "../datas/Bottom.dat");
    Vector3D &operator[](int index);
    Vector3D operator[](int index)const;
    void ustaw_nazwe(std::string nazwa);
    std::string czytaj_nazwe() const;
    void zapisz();
};