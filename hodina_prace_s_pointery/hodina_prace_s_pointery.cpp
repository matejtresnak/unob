#include <iostream>
using namespace std;

struct Pole {
    int* radek;
    int delka;
};

void VytiskniPole(Pole pole) {
    for (int i = 0; i < pole.delka; i++) {
        cout << pole.radek[i] << ", ";
    }

}

Pole* vytvoreniPole(int delka) {
    Pole* p = new Pole();
    p->delka = delka;
    p->radek = new int[delka];
    srand(time(NULL));
    for (int i = 0; i < p->delka; i++) {
        p->radek[i] = rand() % 10;
    }

    return p;
}

Pole *SectiPole(Pole *pole1, Pole *pole2) {
    if (pole1->delka != pole2->delka) {
        return nullptr;
    }
    else {
        Pole *vysledek = vytvoreniPole(pole1->delka);
        for (int i = 0; i < pole1->delka; i++) {
            vysledek->radek[i] = pole1->radek[i] + pole2->radek[i];
        }
        return vysledek;
    }
}



//Pole vytvoreniPole(int delka) {
//    Pole p = Pole();
//    p.delka = delka;
//    p.radek = new int[delka];
//    srand(time(NULL));
//    for (int i = 0; i < p.delka; i++) {
//        p.radek[i] = rand() % 10;
//    }
//
//    return p;
//}

void odstraneniPole(Pole pole) {

}



int main()
{
    Pole *pole = vytvoreniPole(5);
    Pole *pole2 = vytvoreniPole(5);
    VytiskniPole(*pole);
    cout << endl;
    VytiskniPole(*pole2);
    cout << endl;
    Pole *soucet = SectiPole(pole, pole2);
    VytiskniPole(*soucet);
    

    return 0;
}
