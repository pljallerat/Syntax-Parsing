#pragma once

#include <deque>
#include "Symbole.h"
#include "State.h"
using namespace std;

class State;

class Automate {
    
    public:
        Automate();
        ~Automate() { }

        void TransitionNonTerm(State* state);
        void Avancer(Symbole* symbole);
        void Decalage(Symbole* s, State* state);
        void Reduction(int r, Symbole* s);
        void Fin();
        bool GetFini(); //renvoit un booléen qui est vrai si la lecture est fini
        void Erreur();
        bool GetErreur(); //renvoit un booléen qui est vrai si une erreur a été rencontré pendant la lecture
        int GetResultat();
        void GetSymboles(); //renvoit la pile de symbole pour le débugage
        void GetStates();  //renvoit la pile de d'état pour le débugage

    protected:
        deque <State*> states;
        deque <Symbole*> symboles;
        bool fini;
        bool erreur;
};

// Une pile d'état
