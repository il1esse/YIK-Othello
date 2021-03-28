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
std::string Effet::getNomE() const
{
    return nomE;
}

//Mutateur : Modifie le nom de l'effet.
void Effet::setNomE(std::string & nouvNomE)
{
    nomE = nouvNomE;
}

//Accesseur : Récupère la description de l'effet.
std::string Effet::getDescription() const
{
    return description;
}

//Mutateur : Modifie la description de l'effet.
void Effet::setDescription(std::string & nouvDescription)
{
    description = nouvDescription;
}

//Accesseur : Récupère la valeur permettant de savoir si l'effet est special.
bool Effet::getSpecial() const
{
    return special;
}

//Mutateur : Modifie la valeur special de l'effet.
void Effet::setSpecial(bool & nouvSpecial)
{
    special = nouvSpecial;
}



//Constructeur par défaut de la classe HautGauche.
HautGauche::HautGauche() : Effet()
{
    std::string nomTMP = "Haut Gauche";
    std::string descriptionTMP = "Acquiert la case à la diagonale haute gauche de l'endroit ou a été posé le jeton, si elle est neutre.";
    bool specialTMP = false;

    setNomE(nomTMP);
    setDescription(descriptionTMP);
    setSpecial(specialTMP);
}
//Procédure permettant de gerer le comportement de l'effet HautGauche.
 void HautGauche::comportementHG(int & x,int & y, Plateau & p,std::string couleur)
{
    int nvX = x-1;
    int nvY = y+1;
    p.Plateau::majPlateau(nvX,nvY,couleur);
}

//Constructeur par défaut de la classe HautDroite.
HautDroite::HautDroite() : Effet()
{
    std::string nomTMP = "Haut Droite";
    std::string descriptionTMP = "Acquiert la case à la diagonale haute droite de l'endroit ou a été posé le jeton, si elle est neutre";
    bool specialTMP = false;

    setNomE(nomTMP);
    setDescription(descriptionTMP);
    setSpecial(specialTMP);
}
//Procédure permettant de gerer le comportement de l'effet HautDroite.
void HautDroite::comportementHD(int & x,int & y, Plateau & p,std::string couleur)
{
    int nvX = x+1;
    int nvY = y+1;
    p.Plateau::majPlateau(nvX,nvY,couleur);
}

//Constructeur par défaut de la classe BasGauche.
BasGauche::BasGauche() : Effet()
{
    std::string nomTMP = "BasGauche";
    std::string descriptionTMP = "Acquiert la case à la diagonale basse gauche de l'endroit ou a été posé le jeton, si elle est neutre";
    bool specialTMP = false;

    setNomE(nomTMP);
    setDescription(descriptionTMP);
    setSpecial(specialTMP);
}
//Procédure permettant de gerer le comportement de l'effet BasGauche.
void BasGauche::comportementBG(int & x,int & y, Plateau & p,std::string couleur)
{
    int nvX = x-1;
    int nvY = y-1;
    p.Plateau::majPlateau(nvX,nvY,couleur);
}

//Constructeur par défaut de la classe BasDroite.
BasDroite::BasDroite() : Effet()
{
    std::string nomTMP = "BasDroite";
    std::string descriptionTMP = "Acquiert la case à la diagonale basse droite de l'endroit ou a été posé le jeton, si elle est neutre";
    bool specialTMP = false;

    setNomE(nomTMP);
    setDescription(descriptionTMP);
    setSpecial(specialTMP);
}
//Procédure permettant de gerer le comportement de l'effet BasDroite.
void BasDroite::comportementBD(int & x,int & y, Plateau & p,std::string couleur)
{
    int nvX = x+1;
    int nvY = y-1;
    p.Plateau::majPlateau(nvX,nvY,couleur);
}

//Constructeur par défaut de la classe Haut.
Haut::Haut() : Effet()
{
    std::string nomTMP = "Haut";
    std::string descriptionTMP = "Acquiert la case au dessus du l'endroit ou le jeton a été posé, si elle est neutre";
    bool specialTMP = false;

    setNomE(nomTMP);
    setDescription(descriptionTMP);
    setSpecial(specialTMP);
}
//Procédure permettant de gerer le comportement de l'effet Haut.
void Haut::comportementH(int & x,int & y, Plateau & p,std::string couleur)
{
    int nvY = y+1;
    p.Plateau::majPlateau(x,nvY,couleur);
}

//Constructeur par défaut de la classe Droite.
Droite::Droite() : Effet()
{
    std::string nomTMP = "Droite";
    std::string descriptionTMP = "Acquiert la case à droite l'endroit ou le jeton a été posé, si elle est neutre";
    bool specialTMP = false;

    setNomE(nomTMP);
    setDescription(descriptionTMP);
    setSpecial(specialTMP);
}
//Procédure permettant de gerer le comportement de l'effet Droite.
void Droite::comportementD(int & x,int & y, Plateau & p,std::string couleur)
{
    int nvX = x+1;
    p.Plateau::majPlateau(nvX,y,couleur);
}

//Constructeur par défaut de la classe Gauche.
Gauche::Gauche() : Effet()
{
    std::string nomTMP = "Gauche";
    std::string descriptionTMP = "Acquiert la case a gauche l'endroit ou le jeton a été posé, si elle est neutre";
    bool specialTMP = false;

    setNomE(nomTMP);
    setDescription(descriptionTMP);
    setSpecial(specialTMP);
}
//Procédure permettant de gerer le comportement de l'effet Gauche.
void Gauche::comportementG(int & x,int & y, Plateau & p,std::string couleur)
{
    int nvX = x-1;
    p.Plateau::majPlateau(nvX,y,couleur);
}

//Constructeur par défaut de la classe Bas.
Bas::Bas() : Effet()
{
    std::string nomTMP = "Bas";
    std::string descriptionTMP = "Acquiert la case en dessous de l'endroit ou le jeton a été posé, si elle est neutre";
    bool specialTMP = false;

    setNomE(nomTMP);
    setDescription(descriptionTMP);
    setSpecial(specialTMP);
}
//Procédure permettant de gerer le comportement de l'effet Bas.
void Bas::comportementB(int & x,int & y, Plateau & p,std::string couleur)
{
    int nvY = y-1;
    p.Plateau::majPlateau(x,nvY,couleur);
}
