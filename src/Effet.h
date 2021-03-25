/**
 @brief Effet.h contient les entêtes et les fonctions des données Effet.
 @author YIK
 @version 1.0
 @date 2021/03/17
*/

/* Directives pour éviter les inclusions multiples */
#ifndef EFFET_H_INCLUDED
#define EFFET_H_INCLUDED

/* Inclusions des entêtes utilisées */
#include <string.h>
#include "Plateau.h"

/* Définitions de la classes */
class Effet{

/* Données privés */
private :

    string nomE;
    string description;
    bool special;

/* Donnée et fonctions publique */
public :

    /**
    @brief Constructeur par défaut de la classe Effet.
    */
    Effet();

    /**
    @brief Destructeur de la classe Case (Met les valeurs à NULL).
    */
    ~Effet();

    /**
    @brief Accesseur : Récupère le nom de l'effet.
    */
    unsigned char & getNomE() const;

    /**
    @brief Mutateur : Modifie le nom de l'effet.
    @param nouvNomE Le nouveau nom de l'effet.
    */
    void setNomE(char & nouvNomE);

    /**
    @brief Accesseur : Récupère la description de l'effet.
    */
    unsigned char & getDescription() const;

    /**
    @brief Mutateur : Modifie la description de l'effet.
    @param nouvDescription La nouvelle description de l'effet.
    */
    void setDescription(string & nouvDescription);

    /**
    @brief Accesseur : Récupère la valeur booléenne "special" de l'effet.
    */
    unsigned char & getSpecial() const;

    /**
    @brief Mutateur : Modifie la valeur special de l'effet.
    @param nouvSpecial La nouvelle valeur booléenne spécial de l'effet.
    */
    void setSpecial(bool & nouvSpecial);
};

/* Définitions des classes qui heritent de la classe effet*/

class HautGauche : public Effet
{
    /**
    @brief Constructeur par défaut de la classe HautGauche.
    */
    HautGauche();
    /**
    @brief Procédure permettant de gerer le comportement de l'effet HautGauche.
    @param x Coordonnées ou l'effet prendra action sur l'axe x.
    @param y Coordonnées ou l'effet prendra action sur l'axe y.
    */
    void comportementHG(int x,int y);
};

class HautDroite : public Effet
{
    /**
    @brief Constructeur par défaut de la classe HautDroite.
    */    
    HautDroite();
    /**
    @brief Procédure permettant de gerer le comportement de l'effet HautDroite.
    @param x Coordonnées ou l'effet prendra action sur l'axe x.
    @param y Coordonnées ou l'effet prendra action sur l'axe y.
    */
    void comportementHD(int x,int y);
};

class BasGauche : public Effet
{
    /**
    @brief Constructeur par défaut de la classe BasGauche.
    */  
    BasGauche();
    /**
    @brief Procédure permettant de gerer le comportement de l'effet BasGauche.
    @param x Coordonnées ou l'effet prendra action sur l'axe x.
    @param y Coordonnées ou l'effet prendra action sur l'axe y.
    */
    void comportementBG(int x,int y);
};

class BasDroite : public Effet
{
    /**
    @brief Constructeur par défaut de la classe BasDroite.
    */  
    BasDroite();
    /**
    @brief Procédure permettant de gerer le comportement de l'effet BasDroite.
    @param x Coordonnées ou l'effet prendra action sur l'axe x.
    @param y Coordonnées ou l'effet prendra action sur l'axe y.
    */
    void comportementBD(int x,int y);
};



class Haut : public Effet
{
    /**
    @brief Constructeur par défaut de la classe Haut.
    */  
    Haut();
    /**
    @brief Procédure permettant de gerer le comportement de l'effet Haut.
    @param y Coordonnées ou l'effet prendra action sur l'axe y.
    */
    void comportementH(int y);
};

class Droite : public Effet
{
    /**
    @brief Constructeur par défaut de la classe Droite.
    */  
    Droite();
    /**
    @brief Procédure permettant de gerer le comportement de l'effet Droite.
    @param x Coordonnées ou l'effet prendra action sur l'axe x.
    */
    void comportementD(int x);
};

class Gauche : public Effet
{
    /**
    @brief Constructeur par défaut de la classe Gauche.
    */  
    Gauche();
    /**
    @brief Procédure permettant de gerer le comportement de l'effet Gauche.
    @param x Coordonnées ou l'effet prendra action sur l'axe x.
    */
    void comportementG(int x);
};

class Bas : public Effet
{
    /**
    @brief Constructeur par défaut de la classe Bas.
    */    
    Bas();
    /**
    @brief Procédure permettant de gerer le comportement de l'effet Bas.
    @param y Coordonnées ou l'effet prendra action sur l'axe y.
    */
    void comportementB(int y);
};

#endif // EFFET_H_INCLUDED
