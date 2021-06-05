#include "Drone.hh"


    Drone::Drone(int nr_drona)
    {
        this->nr_drona = nr_drona;
    }


    void Drone::obrot(double kat)
    {
        this->kat += kat;
        Matrix3x3 jedynkowa;
        macierz_obrotu = jedynkowa * obrot_Z(this->kat);
        body_copy.obrot(macierz_obrotu);
        body_copy.przesun_o_wektor(this->droga);

    }


    void Drone::przesun(double droga)
    {
        Vector3D droga_1;
        droga_1[0] = droga * cos(kat*M_PI/180);
        droga_1[1] = droga * sin(kat*M_PI/180);
        droga_1[2] = 0;

        this->droga = this->droga + droga_1;
        body_copy.obrot(macierz_obrotu); 
        body_copy.przesun_o_wektor(this->droga);
    }


    void Drone::zapisz()
    {
        body_copy.zapisz_do_pliku();

    }


    void Drone::pilot(PzG::LaczeDoGNUPlota &Lacze)
    {
        double droga;
        double kat;
        char wybor;
        std::cout << "m - menu:";
        std::cin >> wybor;
        switch (wybor)
        {
        case 'p':
            std::cout << "podaj droge: ";
            std::cin >> droga;
            for (int i=0;i<droga; i++)
            {
            body_copy = body_dummy;    
            przesun(1);
            zapisz();
            Lacze.Rysuj();
            usleep(10000);
            }
            break;

        case 'o':
            std::cout << "podaj kat (w stopniach) obrotu: ";
            std::cin >> kat;
            if (kat >=0){
                for (int i=0;i<kat; i++)
                {
                body_copy = body_dummy;   
                obrot(1);
                zapisz();
                Lacze.Rysuj();
                usleep(10000);
                }
            }
            else
            {
                for (int i=0;i>kat; i--)
                {
                body_copy = body_dummy;   
                obrot(-1);
                zapisz();
                Lacze.Rysuj();
                usleep(10000);
                }
            }
            break;

        case 'k':
            return exit(0);
        
        default:
            break;
        }
    }