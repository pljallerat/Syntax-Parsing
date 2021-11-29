#include "Symbole.h"
#include <iostream>

Symbole::~Symbole() {}

void Symbole::Affiche() {
   cout<<Etiquettes[ident]<<" ";
}

void Entier::Affiche() {
  cout<<"int:"<<valeur<<" ";
}

void Expression::Affiche() {
  cout<<"eprx:"<<valeur<<" ";
}

int Entier::GetVal() {
  return valeur;
}

int Expression::GetVal() {
  return valeur;
}
