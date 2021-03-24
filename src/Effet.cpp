#include <effet.h>

effet::effet()
{
    nomE = "pas attribu�";
    description = "Rien";
    special = NULL;
}

effet::~effet()
{

}

unsigned char & effet::getNomE() const
{
    return nomE;
}

unsigned char effet::setNomE(char & nouvNomE)
{
    nomE = nouvNomE;
}

unsigned char &  effet::getDescription() const
{
    return description
}

unsigned char effet::setDescription(string & nouvDescription)
{
    description = nouvDescription;
}

unsigned char & effet::getSpecial() const
{
    return special
}

unsigned char effet::setSpecial(bool & nouvSpecial)
{
    special = nouvDescription
}




HautGauche::HautGauche()
{
    nomE = "Haut Gauche";
    description = "Change l�etat de la case Haut Gauche";
    special = 0;
}
HautGauche::comportementHG(int J.x,int J.y)
{
    x = x-1;
    y = y+1;
}


HautDroite::HautDroite()
{
    nomE = "Haut Droite";
    description = "Change l�etat de la case Haut Droite";
    special = 0;
}
HautDroite::comportementHD(int J.x,int J.y)
{
    x = x+1;
    y = y+1;
}

BasGauche::BasGauche()
{
    nomE = "BasGauche";
    description = "Change l�etat de la case BasGauche";
    special = 0;
}
BasGauche::comportementBG(int J.x,int J.y)
{
    x = x-1;
    y = y-1;
}

BasDroite::BasDroite()
{
    nomE = "BasDroite";
    description = "Change l�etat de la case BasDroite";
    special = 0;
}
BasDroite::comportementBD(int J.x,int J.y)
{
    x = x+1;
    y = y-1;
}


Haut::Haut()
{
    nomE = "Haut";
    description = "Change l�etat de la case Haut";
    special = 0;
}
Haut::comportementH(int J.y)
{
    y = y+1;
}

Droite::Droite()
{
    nomE = "Droite";
    description = "Change l�etat de la case Droite";
    special = 0;
}
Droite::comportementD(int J.x)
{
    x = x+1
}

Gauche::Gauche()
{
    nomE = "Gauche";
    description = "Change l�etat de la case Gauche";
    special = 0;
}
Gauche::comportementG(int J.x)
{
    x = x-1
}

Bas::Bas()
{
    nomE = "Bas";
    description = "Change l�etat de la case Bas";
    special = 0;
}
Bas::comportementB(int J.y)
{
    y = y-1;
}
