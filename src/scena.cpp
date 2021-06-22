#include "scena.hh"

/*!
    \file
        \brief przygotowuje scene, rysuje podloze, tworzy drony, ustawia gnuplota
*/

Scena::Scena()
{
Lacze.ZmienTrybRys(PzG::TR_3D);
Lacze.UstawZakresY(-300, 300);
Lacze.UstawZakresX(-300, 300);
Lacze.UstawZakresZ(-300, 300);
double wymiary[3]={600,600,0};

Vector3D wymiary_podloza(wymiary);

podloze=new Bottom(wymiary_podloza,20);

Lacze.DodajNazwePliku(podloze->czytaj_nazwe().c_str(), PzG::RR_Ciagly, 2);
podloze->zapisz();

for(int i=0;i<ilosc_dronow_na_scenie; i++)
{
double pozycja[3]={(double)(rand()%440-220),(double)(rand()%440-220),15};
tab[i]=new Drone(i,Lacze,Vector3D(pozycja));
tab[i]->zapisz();
}
Lacze.Rysuj();
}

/*! \brief rysuje*/
void Scena::rysuj()
{
    Lacze.Rysuj();
}

/*! \brief wyswietla menu oraz odpowiada za wybor konkretnego drona */
bool Scena::menu()
{
    int numer_drona = 0;
    while(numer_drona == 0){
    std::cout<<"podaj nr drona 1 - 4 ";
    
    std::cin>>numer_drona;
    switch (numer_drona)
    {
    case 1:
        numer_drona = 1;
        break;

    case 2:
        numer_drona = 2;
        break;
            
    case 3:
        numer_drona = 3;
        break;

    case 4:
        numer_drona = 4;
        break;      

    default:
        std::cout << "podano niespodziewana wartosc" << std::endl;
        exit(1);
        break;
    }
    }
    
    if(numer_drona-1<ilosc_dronow_na_scenie)
    {
        tab[numer_drona]->pilot();
    }
    else
    {
        return false;
    }
  return true;
}


