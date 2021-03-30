/* Inclusion de l'entète du module */
#include "Jeton.h"

// Constructeur par défaut de la classe Jeton.
    Jeton::Jeton() {
       NomJeton = "Pion";
       EffetJeton = NULL;
       Utilise = false;
   }

// Constructeur de la classe Jeton.
   Jeton::Jeton(std::string nom) {
      NomJeton = nom;

      int effetRand = rand() % 8 + 1; 
      switch(effetRand)
      {
         case 1:
               EffetJeton = new HautGauche;
               break;
         case 2:
               EffetJeton = new HautDroite;
               break;
         case 3:
               EffetJeton = new BasGauche;
               break;
         case 4:
               EffetJeton = new BasDroite;
               break;
         case 5:
               EffetJeton = new Haut;
               break;
         case 6:
               EffetJeton = new Droite;
               break;
         case 7:
               EffetJeton = new Gauche;
               break;
         case 8:
               EffetJeton = new Bas;
               break;
      }

   }
// Destructeur de la classe Jeton.
   Jeton::~Jeton()
   {
     /*  NomJeton = "Pion";
       EffetJeton = new Effet();
       Utilise = false;*/
       if(EffetJeton != NULL)
       {
          delete EffetJeton;
       }
   }

// Accesseur : Récupère la valeur NomJeton du Jeton.
   std::string Jeton::getNomJeton () const {
      return NomJeton;
   }

// Accesseur : Récupère la valeur EffetJeton du Jeton.
   Effet * Jeton::getEffet () const {
      return EffetJeton;
   }

// Accesseur : Récupère la valeur Utilisé du Jeton.
   bool Jeton::getUtilisation () const {
      return Utilise;
   }

// Mutateur : Modifie la valeur NomJeton du Jeton.
   void Jeton::setNomJeton (std::string & nvNom) {
      NomJeton = nvNom;
   }

// Mutateur : Modifie l'effet du Jeton.
   void Jeton::setEffet(Effet * nvEffet) {
      EffetJeton = nvEffet;
   }

// Mutateur : Modifie la valeur Utilisé du Jeton.
   void Jeton::setUtilisation (bool & nvBool) {
      Utilise = nvBool;
   }

