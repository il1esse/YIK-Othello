/* Inclusion de l'entète du module */
#include "Jeton.h"

/* Inclusion d'entêtes standards */
#include <cassert>
#include <iostream>
#include <fstream>
using namespace std;

/* Définitions des fonctions membres publiques et privées */

// Constructeur par défaut de la classe: initialise dimx et dimy à 0
    Jeton::Jeton() {
       NomJeton = "Jeton";
       EffetJeton = NULL;
       Utilisé = false;
   }

// Destructeur de la classe: déallocation de la mémoire du tableau de pixels
   // et mise à jour des champs dimx et dimy à 0
   Jeton::~Jeton () {
       NomJeton = NULL;
       EffetJeton = NULL;
       Utilisé = false;
   }

// Accesseur :
   Jeton & Jeton::getNomJeton () const {
      return NomJeton;
   }

// Accesseur :
   Jeton & Jeton::getEffetJeton () const {
      return EffetJeton;
   }

// Accesseur :
   Jeton & Jeton::getUtiliseJeton () const {
      return Utilisé;
   }


// Mutateur :
   void Jeton::setNomJeton () {
      NomJeton = NomJet;
   }

// Mutateur :
   void Jeton::setEffetJeton () {
      EffetJeton = EffetJet;
   }

// Mutateur :
   void Jeton::setUtiliseJeton () {
      Utilisé = UtiliseJet;
   }

  // Dessine un rectangle plein de la couleur du joueur
   void Jeton::DessinerJeton (unsigned int Xmin, unsigned int Ymin, unsigned int Xmax, unsigned int Ymax) {
      for(unsigned int i = Ymin; i<Ymax+1; i++)
       {
           for(unsigned int j= Xmin; j<Xmax+1; j++)
           {
               setPix(j,i); 
           }
       }
   }

   // Efface l'image en la remplissant de la couleur en paramètre
   // (en appelant dessinerRectangle avec le bon rectangle)
   void Jeton::EffacerJeton () {
   }
