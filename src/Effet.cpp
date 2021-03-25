/* Inclusions de l'entête du module */
#include <Effet.h>

// Constructeur par défaut de la classe Effet.
Effet::Effet()
{
    nomE = "pas attribu�";
    description = "Rien";
    special = NULL;
}

// Desctructeur par défaut de la classe Effet.
Effet::~Effet()
{
    nomE = NULL;
    description = NULL;
    special = NULL;
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
    return description
}

//Mutateur : Modifie la description de l'effet.
void Effet::setDescription(string & nouvDescription)
{
    description = nouvDescription;
}

//Accesseur : Récupère la valeur permettant de savoir si l'effet est special.
unsigned char & Effet::getSpecial() const
{
    return special
}

//Mutateur : Modifie la valeur special de l'effet.
void Effet::setSpecial(bool & nouvSpecial)
{
    special = nouvDescription
}



//Constructeur par défaut de la classe HautGauche.
HautGauche::HautGauche()
{
    nomE = "Haut Gauche";
    description = "Change l�etat de la case Haut Gauche";
    special = 0;
}
//Procédure permettant de gerer le comportement de l'effet HautGauche.
HautGauche::comportementHG(int & x,int & y)
{
    x = x-1;
    y = y+1;
}

//Constructeur par défaut de la classe HautDroite.
HautDroite::HautDroite()
{
    nomE = "Haut Droite";
    description = "Change l�etat de la case Haut Droite";
    special = 0;
}
//Procédure permettant de gerer le comportement de l'effet HautDroite.
HautDroite::comportementHD(int & x,int & y)
{
    x = x+1;
    y = y+1;
}

//Constructeur par défaut de la classe BasGauche.
BasGauche::BasGauche()
{
    nomE = "BasGauche";
    description = "Change l�etat de la case BasGauche";
    special = 0;
}
//Procédure permettant de gerer le comportement de l'effet BasGauche.
BasGauche::comportementBG(int & x,int & y)
{
    x = x-1;
    y = y-1;
}

//Constructeur par défaut de la classe BasDroite.
BasDroite::BasDroite()
{
    nomE = "BasDroite";
    description = "Change l�etat de la case BasDroite";
    special = 0;
}
//Procédure permettant de gerer le comportement de l'effet BasDroite.
BasDroite::comportementBD(int & x,int & y)
{
    x = x+1;
    y = y-1;
}

//Constructeur par défaut de la classe Haut.
Haut::Haut()
{
    nomE = "Haut";
    description = "Change l�etat de la case Haut";
    special = 0;
}
//Procédure permettant de gerer le comportement de l'effet Haut.
Haut::comportementH(int & y)
{
    y = y+1;
}

//Constructeur par défaut de la classe Droite.
Droite::Droite()
{
    nomE = "Droite";
    description = "Change l�etat de la case Droite";
    special = 0;
}
//Procédure permettant de gerer le comportement de l'effet Droite.
Droite::comportementD(int & x)
{
    x = x+1
}

//Constructeur par défaut de la classe Gauche.
Gauche::Gauche()
{
    nomE = "Gauche";
    description = "Change l�etat de la case Gauche";
    special = 0;
}
//Procédure permettant de gerer le comportement de l'effet Gauche.
Gauche::comportementG(int & x)
{
    x = x-1
}

//Constructeur par défaut de la classe Bas.
Bas::Bas()
{
    nomE = "Bas";
    description = "Change l�etat de la case Bas";
    special = 0;
}
//Procédure permettant de gerer le comportement de l'effet Bas.
Bas::comportementB(int & y)
{
    y = y-1;
}
