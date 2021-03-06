#include "Cuboid.hh"

/*!
    \file
    \brief metody klasy Cuboid
*/


/*!
    konstruktor prostopadloscianu                                                                                                                      
    \param [in] srodek - wspolrzedne srodka prostopadloscianu.      
    \param [in] a - dlugosc  
    \param [in] b - szerokosc  
    \param [in] c - wysokosc  
    \param [in] nazwa_pliku_prostopadloscianu - nazwa pliku do zapisu wierzcholkow                                                                                                            
    \return prostopadloscian z okreslonymi chechami.                           
 */
Cuboid::Cuboid(Vector3D srodek, double a, double b, double c, std::string nazwa_pliku_prostopadloscianu)
{
    double tab[]={a,b,c};
    wymiary = new Vector3D(tab);
    this->srodek_bryly=srodek;
    this->nazwa_pliku_bryly = nazwa_pliku_prostopadloscianu;
 
    Vector3D punkt;

    punkt[0] = srodek[0]-(a/2);
    punkt[1] = srodek[1]+(b/2);
    punkt[2] = srodek[2]+(c/2);
    wierzcholki.push_back(punkt);

    punkt[0] = srodek[0]-(a/2);
    punkt[1] = srodek[1]+(b/2);
    punkt[2] = srodek[2]-(c/2);
    wierzcholki.push_back(punkt);

    punkt[0] = srodek[0]+(a/2);
    punkt[1] = srodek[1]+(b/2);
    punkt[2] = srodek[2]+(c/2);
    wierzcholki.push_back(punkt);

    punkt[0] = srodek[0]+(a/2);
    punkt[1] = srodek[1]+(b/2);
    punkt[2] = srodek[2]-(c/2);
    wierzcholki.push_back(punkt);

    punkt[0] = srodek[0]+(a/2);
    punkt[1] = srodek[1]-(b/2);
    punkt[2] = srodek[2]+(c/2);
    wierzcholki.push_back(punkt);

    punkt[0] = srodek[0]+(a/2);
    punkt[1] = srodek[1]-(b/2);
    punkt[2] = srodek[2]-(c/2);
    wierzcholki.push_back(punkt);

    punkt[0] = srodek[0]-(a/2);
    punkt[1] = srodek[1]-(b/2);
    punkt[2] = srodek[2]+(c/2);
    wierzcholki.push_back(punkt);

    punkt[0] = srodek[0]-(a/2);
    punkt[1] = srodek[1]-(b/2);
    punkt[2] = srodek[2]-(c/2);
    wierzcholki.push_back(punkt);

    
    
}
 