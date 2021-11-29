#include <iostream>
#include "Lexer.h"
#include "Symbole.h"
#include "Automate.h"

using namespace std;


int main(int argc, char *argv[]) {

   string chaine;

    if (argc < 2) {
        cout << "Utilisation de la chaine de caratère par défaut" << endl;
        cout << "(Vous pouvez entrer votre propre chaine de caratère en paramètre de l'excutable main)"<<endl;
        chaine = *(new string("1*(1+1)*3*5+4*3"));
    } else {
        chaine = *(new string(argv[1]));
    }

    cout<<chaine<<endl;
    cout<<endl;

    Lexer l(chaine);
    Symbole* s;
    Automate* automate = new Automate();

    do {
        s = l.Consulter();
        automate->Avancer(s);
        l.Avancer();
        if (automate->GetFini() == true) {
            cout<<"Resultat: "<<automate->GetResultat()<<endl;
        }
        if (automate->GetErreur() == true) {
            cout<<"Erreur dans l'experession arithmétique"<<endl;
            break;
        }
    } while(*s!=FIN);
    
   return 0;
}