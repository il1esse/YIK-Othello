/* Inclusion de l'entète du module */
#include "Image.h"

/* Inclusion d'entêtes standards */
#include <cassert>
#include <iostream>
#include <fstream>
using namespace std;

/* Définitions des fonctions membres publiques et privées */

// Constructeur par défaut de la classe: initialise dimx et dimy à 0
   // ce constructeur n'alloue pas de pixel
    Jeton::Jeton() {
       NomJeton = 0;
       EffetJeton = ;
       Utilisé = ;
   }

// Destructeur de la classe: déallocation de la mémoire du tableau de pixels
   // et mise à jour des champs dimx et dimy à 0
   Jeton::~Jeton () {
       NomJeton = 0;
       EffetJeton = 0;
       Utilisé = 0;
   }

// Accesseur : récupère le pixel original de coordonnées (x,y) en vérifiant leur validité
   // la formule pour passer d'un tab 2D à un tab 1D est tab[y*dimx+x]
   Jeton & Jeton::getJeton () const {
   }

// Mutateur : modifie le pixel de coordonnées (x,y)
   void Jeton::setJeton () {
   }

  // Dessine un rectangle plein de la couleur dans l'image (en utilisant setPix, indices en paramètre compris)
   void Jeton::DessinerJeton () {
   }

   // Efface l'image en la remplissant de la couleur en paramètre
   // (en appelant dessinerRectangle avec le bon rectangle)
   void Jeton::EffacerJeton () {
   }