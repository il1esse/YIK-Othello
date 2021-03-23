#include <case.h>

case::case()
{
    couleurC = "neutre";
    etat = 0;
}

case::~case()
{
    couleurC = NULL;
    etat = NULL;
}

unsigned char & case::getCouleurC() const;
{
    return couleurC;
}

unsigned char case::setCouleurC(char & nouvCouleur);
{
    couleurC = nouvCouleur;
}

unsigned char & case::getEtat() const;
{
    return etat;
}

unsigned char & case::setEtat(bool & nouvEtat);
{
    etat = nouvEtat;
}
