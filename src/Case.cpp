/* Inclusions de l'entête du module */
#include "Case.h"

/* Constructeur par défaut de la classe Case, met les valeurs à la case Neutre */
Case::Case()
{
    couleurC = "Neutre";
    etat = 2;
}

/* Constructeur de la classe Case */
Case::Case(std::string c, unsigned int e)
{
    couleurC = c;
    etat = e;
}

/* Destructeur de la classe Case */
Case::~Case()
{
    //couleurC = "Neutre";
    //etat = 2;
}

/* Accesseur : Récupère la valeur de couleur de la case. */
std::string Case::getCouleurC() const
{
    return couleurC;
}

/* Mutateur : Modifie la couleur de la case. */
void Case::setCouleurC(std::string nvCouleur)
{
    couleurC = nvCouleur;
}

/* Accesseur : Récupère la valeur d'état de la case. */
unsigned int Case::getEtat() const
{
    return etat;
}

/* Mutateur : Modifie l'état de la case. */
void Case::setEtat(unsigned int nvEtat)
{
    etat = nvEtat;
}
