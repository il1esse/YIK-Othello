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
#include <strings.h>
#include <stdlib.h>
#include "Plateau.h"

/* Définitions de la classes */
class Effet{

/* Données privés */
private :

    std::string nomE;
    std::string description;
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
    std::string getNomE() const;

    /**
    @brief Mutateur : Modifie le nom de l'effet.
    @param nouvNomE Le nouveau nom de l'effet.
    */
    void setNomE(std::string & nouvNomE);

    /**
    @brief Accesseur : Récupère la description de l'effet.
    */
    std::string getDescription() const;

    /**
    @brief Mutateur : Modifie la description de l'effet.
    @param nouvDescription La nouvelle description de l'effet.
    */
    void setDescription(std::string & nouvDescription);

    /**
    @brief Accesseur : Récupère la valeur booléenne "special" de l'effet.
    */
    bool getSpecial() const;

    /**
    @brief Mutateur : Modifie la valeur special de l'effet.
    @param nouvSpecial La nouvelle valeur booléenne spécial de l'effet.
    */
    void setSpecial(bool & nouvSpecial);
};

/* Définitions des classes qui heritent de la classe effet*/

class HautGauche : public Effet
{
    public: 

    /**
    @brief Constructeur par défaut de la classe HautGauche.
    */
    HautGauche();
    /**
    @brief Procédure permettant de gerer le comportement de l'effet HautGauche.
    @param x Coordonnées ou l'effet prendra action sur l'axe x.
    @param y Coordonnées ou l'effet prendra action sur l'axe y.
    */
    void comportementHG(int & x,int & y, Plateau & p,std::string couleur);
};

class HautDroite : public Effet
{
    public:

    /**
    @brief Constructeur par défaut de la classe HautDroite.
    */    
    HautDroite();
    /**
    @brief Procédure permettant de gerer le comportement de l'effet HautDroite.
    @param x Coordonnées ou l'effet prendra action sur l'axe x.
    @param y Coordonnées ou l'effet prendra action sur l'axe y.
    @param p Plateau de jeu.
    @param couleur Couleur du jeton.
    */
    void comportementHD(int & x,int & y, Plateau & p,std::string couleur);
};

class BasGauche : public Effet
{
    public:

    /**
    @brief Constructeur par défaut de la classe BasGauche.
    */  
    BasGauche();
    /**
    @brief Procédure permettant de gerer le comportement de l'effet HautDroite.
    @param x Coordonnées ou l'effet prendra action sur l'axe x.
    @param y Coordonnées ou l'effet prendra action sur l'axe y.
    @param p Plateau de jeu.
    @param couleur Couleur du jeton.
    */
    void comportementBG(int & x,int & y, Plateau & p,std::string couleur);
};

class BasDroite : public Effet
{
    public:

    /**
    @brief Constructeur par défaut de la classe BasDroite.
    */  
    BasDroite();
    /**
    @brief Procédure permettant de gerer le comportement de l'effet HautDroite.
    @param x Coordonnées ou l'effet prendra action sur l'axe x.
    @param y Coordonnées ou l'effet prendra action sur l'axe y.
    @param p Plateau de jeu.
    @param couleur Couleur du jeton.
    */
    void comportementBD(int & x,int & y, Plateau & p,std::string couleur);
};



class Haut : public Effet
{
    public:

    /**
    @brief Constructeur par défaut de la classe Haut.
    */  
    Haut();
    /**
    @brief Procédure permettant de gerer le comportement de l'effet HautDroite.
    @param x Coordonnées ou l'effet prendra action sur l'axe x.
    @param y Coordonnées ou l'effet prendra action sur l'axe y.
    @param p Plateau de jeu.
    @param couleur Couleur du jeton.
    */
    void comportementH(int & x,int & y, Plateau & p,std::string couleur);
};

class Droite : public Effet
{
    public:

    /**
    @brief Constructeur par défaut de la classe Droite.
    */  
    Droite();
    /**
    @brief Procédure permettant de gerer le comportement de l'effet HautDroite.
    @param x Coordonnées ou l'effet prendra action sur l'axe x.
    @param y Coordonnées ou l'effet prendra action sur l'axe y.
    @param p Plateau de jeu.
    @param couleur Couleur du jeton.
    */
    void comportementD(int & x,int & y, Plateau & p,std::string couleur);
};

class Gauche : public Effet
{
    public:

    /**
    @brief Constructeur par défaut de la classe Gauche.
    */  
    Gauche();
    /**
    @brief Procédure permettant de gerer le comportement de l'effet HautDroite.
    @param x Coordonnées ou l'effet prendra action sur l'axe x.
    @param y Coordonnées ou l'effet prendra action sur l'axe y.
    @param p Plateau de jeu.
    @param couleur Couleur du jeton.
    */
    void comportementG(int & x,int & y, Plateau & p,std::string couleur);
};

class Bas : public Effet
{
    public:
    
    /**
    @brief Constructeur par défaut de la classe Bas.
    */    
    Bas();
    /**
    @brief Procédure permettant de gerer le comportement de l'effet HautDroite.
    @param x Coordonnées ou l'effet prendra action sur l'axe x.
    @param y Coordonnées ou l'effet prendra action sur l'axe y.
    @param p Plateau de jeu.
    @param couleur Couleur du jeton.
    */
    void comportementB(int & x,int & y, Plateau & p,std::string couleur);
};

#endif // EFFET_H_INCLUDED
