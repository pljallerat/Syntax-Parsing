#include "Automate.h"
#include "State.h"
#include "Symbole.h"
#include <deque>
#include <iostream>

using namespace std;

Automate::Automate() {
  fini = false;
  erreur = false;
  states.push_front(new E0());
}

void Automate::Avancer(Symbole* symbole) {
    //symbole->Affiche();
    //cout<<"Avancer"<<endl;
    states.front()->Transition(*this, symbole);
}

void Automate::TransitionNonTerm(State* state) {
    states.push_front(state);
}

void Automate::Decalage(Symbole* s, State* state){
  //cout<<"decalage"<<endl;
  //empiler symbole
  symboles.push_front(s);
  //empiler l'état
  states.push_front(state);
}

void Automate::Fin() {
  fini = true;
}

bool Automate::GetFini() {
  return fini;
}

void Automate::Erreur() {
  erreur = true;
}

bool Automate::GetErreur() {
  return erreur;
}

void Automate::GetSymboles() {
  cout<<"Symboles: ";
  for (int i = 0; i < symboles.size(); i++) {
    symboles[i]->Affiche();
  }
  cout<<endl;
}

void Automate::GetStates() {
  for (int i = 0; i < states.size(); i++) {
    states[i]->Affiche();
    cout<<" ";
  }
  cout<<endl;
}

int Automate::GetResultat()
{
    return ((Expression*)symboles.front())->GetVal();
}

void Automate::Reduction(int r, Symbole* s){

  Symbole* symbole = new Symbole(OPENPAR);
  Expression* s1 = new Expression(0);
  Expression* s3 = new Expression(0);
  Entier* entier = new Entier(0);
  Expression* expr = new Expression(0);
  
  switch (r){
    case 1:

      break;
      
    case 2:
      // E+E

      //dépiler 3 symboles et remplacer par la nouvelle expression
      s1 = (Expression*)symboles.front();
      symboles.pop_front();
      symboles.pop_front();
      s3 = (Expression*)symboles.front();
      symboles.pop_front();

      expr = new Expression(s1->GetVal()+s3->GetVal());
      symboles.push_front(expr);

      //dépiler 3 états
      states.pop_front();
      states.pop_front();
      states.pop_front();
    
      Avancer(expr);
      Avancer(s);

      break;

    case 3:
      // E * E
      //dépiler 3 symboles et remplacer par la nouvelle expression
      s1 = (Expression*)symboles.front();
      symboles.pop_front();
  
      symboles.pop_front();
      s3 = (Expression*)symboles.front();
      symboles.pop_front();

      expr = new Expression (s1->GetVal() * s3->GetVal());
      symboles.push_front(expr);

      //dépiler 3 états
      states.pop_front();
      states.pop_front();
      states.pop_front();

      Avancer((Expression*)s1);
      Avancer(s);
    
      break;

    case (4):
      // (E)
      symboles.pop_front();
      s1 = (Expression*)symboles.front(); 
      symboles.pop_front();
      symboles.pop_front();

      symboles.push_front((Expression*)s1);

      //depiler 3 état
      states.pop_front();
      states.pop_front();
      states.pop_front();

      Avancer((Expression*)s1);
      Avancer(s);
      break;

    case (5):
      // E -> val
      symbole = symboles.front();
      symboles.pop_front();

      expr = new Expression(((Entier*)symbole)->GetVal());
      symboles.push_front(expr);

      states.pop_front();
      Avancer(expr);
      Avancer(s);
      break;

    default:
      cout<<"erreur de réduction";
      break;
  }
}