#include "bottom.hh"

    Bottom::Bottom(Vector3D wymiary, int grubosc_kratki , std::string nazwa_pliku)
    {
    this->nazwa = nazwa_pliku;
    double tab[3];
    proste=0;
    for (int i = -wymiary[0] / 2; i < wymiary[0] / 2; i += grubosc_kratki)
    {
        for (int j = -wymiary[1] / 2; j < wymiary[1] / 2; j += grubosc_kratki)
        {
            tab[0] = i;
            tab[1] = j;

            wierzcholki.push_back(tab);
        }
        proste++;
    }
    }


    Vector3D &Bottom::operator[](int index)
    {
    return wierzcholki[index];
    }


    Vector3D Bottom::operator[](int index)const
    {
    return wierzcholki[index];
    }


    void Bottom::ustaw_nazwe(std::string nazwa)
    {
    this->nazwa = nazwa;
    }
    
    std::string Bottom::czytaj_nazwe() const
    {
    return nazwa;
    }


    void Bottom::zapisz()
    {
    std::fstream plik;
    plik.open(nazwa, std::ios::out);
    for (int i = 0; i < (int)wierzcholki.size(); i ++)
    {  
    if(i%proste==0)
    plik<<std::endl;
     plik<<wierzcholki[i]<<std::endl;
    }  
    plik.close();
    }