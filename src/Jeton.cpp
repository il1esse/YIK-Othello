/* Inclusion de l'entète du module */
#include "Jeton.h"

/* Définitions des fonctions membres publiques et privées */
// Constructeur par défaut de la classe: initialise dimx et dimy à 0



// Constructeur par défaut de la classe Jeton.
    Jeton::Jeton() {
       NomJeton = "Pion";
       EffetJeton = NULL;
       Utilise = false;
   }

// Constructeur de la classe Jeton.
    Jeton::Jeton(char nom, bool utilisation) {
      NomJeton = nom;
      Utilise = utilisation;

      int effetRand = rand() % 8 + 1; 
      switch(effetRand)
      {
         case 1:
               EffetJeton = HautGauche();
               break;
         case 2:
               EffetJeton = HautDroite();
               break;
         case 3:
               EffetJeton = BasGauche();
               break;
         case 4:
               EffetJeton = BasDroite();
               break;
         case 5:
               EffetJeton = Haut();
               break;
         case 6:
               EffetJeton = Droite();
               break;
         case 7:
               EffetJeton = Gauche();
               break;
         case 8:
               EffetJeton = Bas();
               break;
      }

// Destructeur de la classe Jeton.
   Jeton::~Jeton () {
       NomJeton = "Pion";
       EffetJeton = NULL;
       Utilise = false;
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

