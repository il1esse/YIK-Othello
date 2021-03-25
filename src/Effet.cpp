/* Inclusions de l'entête du module */
#include "Effet.h"

// Constructeur par défaut de la classe Effet.
Effet::Effet()
{
    nomE = "Vide";
    description = "Vide";
    special = false;
}

// Desctructeur par défaut de la classe Effet.
Effet::~Effet()
{
    nomE = "Vide";
    description = "Vide";
    special = false;
}

//Accesseur : Récupère le nom de l'effet.
unsigned char & Effet::getNomE() const
{
    return nomE;
}

//Mutateur : Modifie le nom de l'effet.
void Effet::setNomE(char & nouvNomE)
{
    nomE = nouvNomE;
}

//Accesseur : Récupère la description de l'effet.
unsigned char &  Effet::getDescription() const
{
    return description;
}

//Mutateur : Modifie la description de l'effet.
void Effet::setDescription(string & nouvDescription)
{
    description = nouvDescription;
}

//Accesseur : Récupère la valeur permettant de savoir si l'effet est special.
unsigned char & Effet::getSpecial() const
{
    return special;
}

//Mutateur : Modifie la valeur special de l'effet.
void Effet::setSpecial(bool & nouvSpecial)
{
    special = nouvSpecial;
}



//Constructeur par défaut de la classe HautGauche.
HautGauche::HautGauche()
{
    nomE = "Haut Gauche";
    description = "Acquiert la case à la diagonale haute gauche de l'endroit ou a été posé le jeton, si elle est neutre";
    special = 0;
}
//Procédure permettant de gerer le comportement de l'effet HautGauche.
HautGauche::comportementHG(int & x,int & y, Plateau & p,char couleur)
{
    nvX = x-1;
    nvY = y+1;
    Plateau::majPlateau(nvX,nvY,couleur);
}

//Constructeur par défaut de la classe HautDroite.
HautDroite::HautDroite()
{
    nomE = "Haut Droite";
    description = "Acquiert la case à la diagonale haute droite de l'endroit ou a été posé le jeton, si elle est neutre";
    special = 0;
}
//Procédure permettant de gerer le comportement de l'effet HautDroite.
HautDroite::comportementHD(int & x,int & y, Plateau & p,char couleur)
{
    nvX = x+1;
    nvY = y+1;
    Plateau::majPlateau(nvX,nvY,couleur);
}

//Constructeur par défaut de la classe BasGauche.
BasGauche::BasGauche()
{
    nomE = "BasGauche";
    description = "Acquiert la case à la diagonale basse gauche de l'endroit ou a été posé le jeton, si elle est neutre";
    special = 0;
}
//Procédure permettant de gerer le comportement de l'effet BasGauche.
BasGauche::comportementBG(int & x,int & y, Plateau & p,char couleur)
{
    nvX = x-1;
    nvY = y-1;
    Plateau::majPlateau(nvX,nvY,couleur);
}

//Constructeur par défaut de la classe BasDroite.
BasDroite::BasDroite()
{
    nomE = "BasDroite";
    description = "Acquiert la case à la diagonale basse droite de l'endroit ou a été posé le jeton, si elle est neutre";
    special = 0;
}
//Procédure permettant de gerer le comportement de l'effet BasDroite.
BasDroite::comportementBD(int & x,int & y, Plateau & p,char couleur)
{
    nvX = x+1;
    nvY = y-1;
    Plateau::majPlateau(nvX,nvY,couleur);
}

//Constructeur par défaut de la classe Haut.
Haut::Haut()
{
    nomE = "Haut";
    description = "Acquiert la case au dessus du l'endroit ou le jeton a été posé, si elle est neutre";
    special = 0;
}
//Procédure permettant de gerer le comportement de l'effet Haut.
Haut::comportementH(int & x,int & y, Plateau & p,char couleur)
{
    nvY = y+1;
    Plateau::majPlateau(x,nvY,couleur);
}

//Constructeur par défaut de la classe Droite.
Droite::Droite()
{
    nomE = "Droite";
    description = "Acquiert la case à droite l'endroit ou le jeton a été posé, si elle est neutre";
    special = 0;
}
//Procédure permettant de gerer le comportement de l'effet Droite.
Droite::comportementD(int & x,int & y, Plateau & p,char couleur)
{
    nvX = x+1
    Plateau::majPlateau(nvX,y,couleur);
}

//Constructeur par défaut de la classe Gauche.
Gauche::Gauche()
{
    nomE = "Gauche";
    description = "Acquiert la case a gauche l'endroit ou le jeton a été posé, si elle est neutre";
    special = 0;
}
//Procédure permettant de gerer le comportement de l'effet Gauche.
Gauche::comportementG(int & x,int & y, Plateau & p,char couleur)
{
    nvX = x-1
    Plateau::majPlateau(nvX,y,couleur);
}

//Constructeur par défaut de la classe Bas.
Bas::Bas()
{
    nomE = "Bas";
    description = "Acquiert la case en dessous de l'endroit ou le jeton a été posé, si elle est neutre";
    special = 0;
}
//Procédure permettant de gerer le comportement de l'effet Bas.
Bas::comportementB(int & x,int & y, Plateau & p,char couleur)
{
    nvY = y-1;
    Plateau::majPlateau(x,nvY,couleur);
}
