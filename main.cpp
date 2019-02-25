
/*
-----------------------------------------------------------------------------------
Laboratoire : Labo01
Fichier     : main.cpp
Auteur(s)   : Loic Dessaules, Doran Kayoumi
Date        : 25.02.2019
But         : Le but de ce laboratoire est de créer une classe Date en utilisant la compilation séparée. Nous devons mettre
              en place de la surcharge de constructeur, d'opérateur et des fonctions friends.
Remarque(s) : L'opérateur "=" c'a pas eu besoin d'etre surchargé, car de base ce la fonctionne. Le comportement
              de base de l'opérateur "=" fonctionne pour notre classe Date.
Compilateur : g++ <8.2.1>
-----------------------------------------------------------------------------------
 */

#include "Date.h"
#include <iostream>


using namespace std;

int main() {

    // Test data

    Date date1(04, 07, 1993);
    Date date2(28, 02, 2019);
    Date date3;

    cout << (date2 == date1) << endl;

    cout << date2 << endl;

    date3 = date2;

    date1 = {1, 2, 1995};

    cout << date1 << endl;
    cout << date3 << endl;

    return 0;
}