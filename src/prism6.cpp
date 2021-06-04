#include "prism6.hh"

Prism6::Prism6(Vector3D centrum,double R , double dlugosc_graniastoslupa, std::string nazwa_pliku_graniastoslupa6 )
{
    double tab[]={0,0,dlugosc_graniastoslupa};
    wymiary = new Vector3D(tab);
    this->srodek_bryly=centrum;
    this->nazwa_pliku_bryly = nazwa_pliku_graniastoslupa6;
    Vector3D punkt;

    for(int i=0; i<360; i+=60)
    {
       punkt[0] = R*cos(i*M_PI/180);
       punkt[1] = R*sin(i*M_PI/180);
       punkt[2] = centrum[2] + (dlugosc_graniastoslupa/2);
       wierzcholki.push_back(punkt);

       punkt[0] = R*cos(i*M_PI/180);
       punkt[1] = R*sin(i*M_PI/180);
       punkt[2] = centrum[2] - (dlugosc_graniastoslupa/2);
       wierzcholki.push_back(punkt);
    }
}