/* Inclusion de l'entète du module */
#include "Jeton.h"

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

  // Dessine un jeton de la couleur du joueur.
   void Jeton::DessinerJeton (unsigned int Xmin, unsigned int Ymin, unsigned int Xmax, unsigned int Ymax) {
      for(unsigned int i = Ymin; i<Ymax+1; i++)
       {
           for(unsigned int j= Xmin; j<Xmax+1; j++)
           {

           }
       }
   }

   // Efface un jeton.
   void Jeton::EffacerJeton () {

   }
