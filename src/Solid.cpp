#include "Solid.hh"

/*!
    \file
        \brief  metody klasy Solid
*/


/*! \brief ustawia wierzcholki srodka bryly*/
void Solid::wstaw_srodek(Vector3D srodek_bryly)
{
    this->srodek_bryly = srodek_bryly; //aby zapobiec przykrywaniu się zmiennych uzywam this*/
}


/*! \brief zczytuje wierzcholki srodka bryly*/
Vector3D Solid::zczytaj_srodek() const
{
    return srodek_bryly;
}


/*! \brief zczytuje nazwe pliku do ktorego zapisywane beda wierzcholki*/
std::string Solid::jaka_nazwa() const
{
    return nazwa_pliku_bryly;
}


/*! \brief przesuwa bryle o zadany wektor*/
void Solid::przesun_o_wektor(Vector3D wektor_przesuniecia)
{
    for(int i=0; i < (int)wierzcholki.size() ; i++)
    {
        wierzcholki[i] =  wierzcholki[i] + wektor_przesuniecia;
    }
}


/*! \brief obraca bryle o zadany kat*/
void Solid::obrot(Matrix3x3 macierz_obrotu)
{
    for(int i=0; i < (int)wierzcholki.size() ; i++)
    {
        wierzcholki[i] =  macierz_obrotu * wierzcholki[i];
    }
} 


/*! \brief zapisuje wspolrzedne bryly do pliku*/
void Solid::zapisz_do_pliku()
{
    std::fstream plik;
    double tab[]={0,0,(*wymiary)[2]/2};
    Vector3D wysokosc(tab);
    plik.open(nazwa_pliku_bryly, std::ios::out);
    for(int i=0; i<(int)wierzcholki.size() ; i+=2)
    {
      plik << srodek_bryly+wysokosc << std::endl;;  
        for(int j=0; j<2 ; j++)
        {
            plik << wierzcholki[j+i] << std::endl;
        }
      plik << srodek_bryly-wysokosc << std::endl << std::endl;
    }
    
      plik << srodek_bryly+wysokosc << std::endl;;  
        for(int j=0; j<2 ; j++)
        {
            plik << wierzcholki[j] << std::endl;
        }
      plik << srodek_bryly-wysokosc << std::endl << std::endl;
    plik.close();
}