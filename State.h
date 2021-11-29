#pragma once

#include <string>
#include "Automate.h"
using namespace std;

class Automate;

class State {
    public: 
        State() { }
        virtual ~State();
        virtual void Transition(Automate & automate, Symbole* s) = 0;
        virtual void Affiche() = 0;
};

class E0 : public State {
    public: 
        E0() {}
        ~E0() { }   
        void Transition(Automate & automate, Symbole* s);
        void Affiche();
};

class E1: public State {
    public: 
        E1() { }
        ~E1() { }
        void Transition(Automate & automate, Symbole* s);
        void Affiche();
};

class E2 : public State {
    public: 
        E2() { }
        ~E2() { }     
        void Transition(Automate & automate, Symbole* s);
        void Affiche();
};

class E3 : public State {
    public: 
        E3() { }
        ~E3() { }        
        void Transition(Automate & automate, Symbole* s);
        void Affiche();
};

class E4 : public State {
    public: 
        E4() { }
        ~E4() { }      
        void Transition(Automate & automate, Symbole* s);
        void Affiche();
};

class E5 : public State {
    public: 
        E5() { }
        ~E5() { }        
        void Transition(Automate & automate, Symbole* s);
        void Affiche();
};

class E6 : public State {
    public: 
        E6() { }
        ~E6() { }     
        void Transition(Automate & automate, Symbole* s);
        void Affiche();
};

class E7 : public State {
    public: 
        E7() { }
        ~E7() { }     
        void Transition(Automate & automate, Symbole* s);
        void Affiche();
};

class E8 : public State {
    public: 
        E8() { }
        ~E8() { }     
        void Transition(Automate & automate, Symbole* s);
        void Affiche();
};

class E9 : public State {
    public: 
        E9() { }
        ~E9() { }     
        void Transition(Automate & automate, Symbole* s);
        void Affiche();
};