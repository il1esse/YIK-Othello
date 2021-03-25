/* Inclusion de l'entète du module */
#include "Jeton.h"



/* Inclusion d'entêtes standards */
#include <cassert>
#include <iostream>
#include <fstream>
using namespace std;







/* Définitions des fonctions membres publiques et privées */
// Constructeur par défaut de la classe: initialise dimx et dimy à 0



// Constructeur par défaut de la classe Jeton.
    Jeton::Jeton() {
       NomJeton = "Pion";
       EffetJeton = NULL;
       Utilisé = false;
   }



// Constructeur de la classe Jeton.
    Jeton::Jeton(char nom, Effet effet, bool utilisation) {
       NomJeton = nom;
       EffetJeton = effet;
       Utilisé = utilisation;
   }



// Destructeur de la classe Jeton.
   Jeton::~Jeton () {
       NomJeton = "Pion";
       EffetJeton = NULL;
       Utilisé = false;
   }



// Accesseur : Récupère la valeur NomJeton du Jeton.
   char & Jeton::getNomJeton () const {
      return NomJeton;
   }



// Accesseur : Récupère la valeur EffetJeton du Jeton.
   Effet & Jeton::getEffet () const {
      return EffetJeton;
   }



// Accesseur : Récupère la valeur Utilisé du Jeton.
   bool & Jeton::getUtilisation () const {
      return Utilisé;
   }



// Mutateur : Modifie la valeur NomJeton du Jeton.
   void Jeton::setNomJeton (char & nvNom) {
      NomJeton = nvNom;
   }



// Mutateur : Modifie l'effet du Jeton.
   void Jeton::setEffet(Effet & nvEffet) {
      EffetJeton = nvEffet;
   }



// Mutateur : Modifie la valeur Utilisé du Jeton.
   void Jeton::setUtilisation (bool & nvBool) {
      Utilisé = nvBool;
   }

