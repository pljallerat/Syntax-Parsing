#include "State.h"
#include <iostream> // pour std::cout 


State::~State() {}

void State::Transition(Automate & automate, Symbole* s){}

void E0::Transition(Automate & automate, Symbole* s) {
  switch (*s) {
    case OPENPAR:
      automate.Decalage(s, new E2());
      break;
    case INT:
      automate.Decalage(s, new E3());
      //cout<<"int0 ";
      break;
    case EXPR:
      // cout<<"expr0 ";
      automate.TransitionNonTerm(new E1());
      break;
    default:
      //cout<<"erreur0 ";
      automate.Erreur();
      break;
  }
}

void E0::Affiche() {
  cout<<"E0 ";
}

void E1::Transition(Automate & automate, Symbole* s) {
  switch (*s) {
    case MULT:
      automate.Decalage(s, new E5());
      break;
    case PLUS:
      //cout<<"plus1 ";
      automate.Decalage(s, new E4());
      break;
    case FIN:
      automate.Fin();
      break;
    default:
      //cout<<"erreur1 ";
      automate.Erreur();
      break;
  }
}

void E1::Affiche() {
  cout<<"E1 ";
}

void E2::Transition(Automate & automate, Symbole* s) {
  switch (*s) {
    case INT:
      automate.Decalage(s, new E3());
      break;
    case OPENPAR:
      automate.Decalage(s, new E2());
      break;
    case EXPR:
      automate.TransitionNonTerm(new E6());
      break;
    default:
      //cout<<"erreur2 ";
      automate.Erreur();
      break;
  }
}

void E2::Affiche() {
  cout<<"E2 ";
}

void E3::Transition(Automate & automate, Symbole* s) {
  switch (*s) {
    case MULT:
      automate.Reduction(5, s);
      break;
    case PLUS:
      //cout<<"plus3 ";
      automate.Reduction(5, s);
      break;
    case CLOSEPAR:
      automate.Reduction(5, s);
      break;
    case FIN:
      automate.Reduction(5, s);
      break;
    default:
      //cout<<"erreur3 ";
      automate.Erreur();
      break;
  }
}

void E3::Affiche() {
  cout<<"E3 ";
}

void E4::Transition(Automate & automate, Symbole* s) {
  switch (*s) {
    case INT:
      automate.Decalage(s, new E3());
      break;
    case OPENPAR:
      automate.Decalage(s, new E2());
      break;
    case EXPR:
      automate.TransitionNonTerm(new E7());
      break;
    default:
      //cout<<"erreur4 ";
      automate.Erreur();
  break;
  }
}

void E4::Affiche() {
  cout<<"E4 ";
}

void E5::Transition(Automate & automate, Symbole* s) {
  switch (*s) {
    case INT:
      automate.Decalage(s, new E3());
      break;
    case OPENPAR:
      automate.Decalage(s, new E2());
      break;
    case EXPR:
      automate.TransitionNonTerm(new E8());
      break;
    default:
      //cout<<"erreur5 ";
      automate.Erreur();
  break;
  }
}

void E5::Affiche() {
  cout<<"E5 ";
}

void E6::Transition(Automate & automate, Symbole* s) {
  switch (*s) {
    case PLUS:
      automate.Decalage(s, new E4());
      break;
    case MULT:
      automate.Decalage(s, new E5());
      break;
    case CLOSEPAR:
      automate.Decalage(s, new E9());
      break;
    default:
      //cout<<"erreur6 ";
      automate.Erreur();
  break;
  }
}

void E6::Affiche() {
  cout<<"E6 ";
}

void E7::Transition(Automate & automate, Symbole* s) {
  switch (*s) {
    case PLUS:
      automate.Reduction(2, s);
      break;
    case MULT:
      automate.Decalage(s, new E5());
      break;
    case CLOSEPAR:
      automate.Reduction(2, s);
      break;
    case FIN:
      automate.Reduction(2, s);
      break;
    default:
      //cout<<"erreur7 ";
      automate.Erreur();
  break;
  }
}

void E7::Affiche() {
  cout<<"E7 ";
}

void E8::Transition(Automate & automate, Symbole* s) {
  switch (*s) {
    case PLUS:
      automate.Reduction(3, s);
      break;
    case MULT:
      automate.Reduction(3, s);
      break;
    case CLOSEPAR:
      automate.Reduction(3, s);
      break;
    case FIN:
      automate.Reduction(3, s);
      break;
    default:
      //cout<<"erreur8 ";
      automate.Erreur();
  break;
  }
}

void E8::Affiche() {
  cout<<"E8 ";
}

void E9::Transition(Automate & automate, Symbole* s) {
  switch (*s) {
    case PLUS:
      automate.Reduction(4, s);
      break;
    case MULT:
      automate.Reduction(4, s);
      break;
    case CLOSEPAR:
      automate.Reduction(4, s);
      break;
    case FIN:
      automate.Reduction(4, s);
      break;
    default:
      //cout<<"erreur9 ";
      automate.Erreur();
  break;
  }
}

void E9::Affiche() {
  cout<<"E9 ";
}
