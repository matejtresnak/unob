#include <iostream>
#include <chrono>
using namespace std;

struct Matice {
    int **matice; // ukazatel na ukazatel reprezentujici matici
    int radky;
    int sloupce;
};

Matice* vytvor_matici(int radky, int sloupce) {
    Matice *matice = new Matice;
    matice->radky = radky;
    matice->sloupce = sloupce;
    matice->matice = new int*[radky];
    for (int i = 0; i < radky; i++) {
        matice->matice[i] = new int[sloupce];  // Alokace pro sloupce
    }
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    srand(seed);
    for (int i = 0; i < radky; i++) {
        for (int j = 0; j < sloupce; j++) {
            matice->matice[i][j] = rand() % 10;
        }
    }
    return matice;
}

void vypis_matici(Matice *matice) {
    if (!matice) {  // Ověření, zda matice není nullptr
        cout << "Matice neexistuje nebo nelze zobrazit.\n" << endl;
        return;
    }
    
    for (int i = 0; i < matice->radky; i++) {
        for (int j = 0; j < matice->sloupce; j++) {
            cout << matice->matice[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void smaz_matici(Matice *matice) {
    for (int i = 0; i < matice->radky; i++) {
        delete[] matice->matice[i];  // Uvolnění paměti každého řádku
    }
    delete[] matice->matice;  // Uvolnění ukazatele na řádky
    delete matice;  // Uvolnění samotné struktury Matice
}

Matice* secti_matice(Matice *matice1, Matice *matice2){
    if (matice1->radky == matice2->radky && matice1->sloupce == matice2->sloupce){
        Matice *vysledek = vytvor_matici(matice1->radky,matice1->sloupce);
        for (int i = 0; i < vysledek->radky; i++) {
            for (int j = 0; j < vysledek->sloupce; j++) {
                vysledek->matice[i][j] = (matice1->matice[i][j]) + (matice2->matice[i][j]);
            }
        }
        return vysledek;
    }

    else {
        return nullptr;
    }
}

Matice* nasob_matice(Matice *matice1, Matice *matice2) {
    if (matice1->sloupce == matice2->radky) {
        Matice* vysledek = vytvor_matici(matice1->radky, matice2->sloupce);

        // Násobení matic
        for (int i = 0; i < matice1->radky; i++) {
            for (int j = 0; j < matice2->sloupce; j++) {
                vysledek->matice[i][j] = 0;  // Inicializace prvku výsledné matice
                for (int k = 0; k < matice1->sloupce; k++) {
                    vysledek->matice[i][j] += matice1->matice[i][k] * matice2->matice[k][j];
                }
            }
        }

        return vysledek;
    }

    else {
        return nullptr;
    }

}
int main(){
    Matice *matice1 = vytvor_matici(2,3);
    vypis_matici(matice1);

    Matice *matice2 = vytvor_matici(3,4);
    vypis_matici(matice2);

    cout << "Soucet matic"<<endl;
    vypis_matici(secti_matice(matice1,matice2));

    cout << "Soucin matic"<<endl;
    vypis_matici(nasob_matice(matice1,matice2));


    smaz_matici(matice1);
    smaz_matici(matice2);
}