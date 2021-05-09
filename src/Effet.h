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
    virtual ~Effet();

    /**
    @brief Accesseur : Récupère le nom de l'effet.
    */
    const std::string & getNomE() const;

    /**
    @brief Mutateur : Modifie le nom de l'effet.
    @param nouvNomE Le nouveau nom de l'effet.
    */
    void setNomE(std::string & nouvNomE);

    /**
    @brief Accesseur : Récupère la description de l'effet.
    */
    const std::string & getDescription() const;

    /**
    @brief Mutateur : Modifie la description de l'effet.
    @param nouvDescription La nouvelle description de l'effet.
    */
    void setDescription(std::string nouvDescription);

    /**
    @brief Accesseur : Récupère la valeur booléenne "special" de l'effet.
    */
    const bool & getSpecial() const;

    /**
    @brief Mutateur : Modifie la valeur special de l'effet.
    @param nouvSpecial La nouvelle valeur booléenne spécial de l'effet.
    */
    void setSpecial(bool & nouvSpecial);

    /**
    @brief Test de regression : Lance les test de régressions de Effet.
    */
    void testREffet();

    virtual void comportement(unsigned int x,unsigned int y, Plateau & p,std::string couleur) = 0;
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
    virtual void comportement(unsigned int x,unsigned int y, Plateau & p,std::string couleur) override;
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
    virtual void comportement(unsigned int x,unsigned int y, Plateau & p,std::string couleur) override;
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
    virtual void comportement(unsigned int x,unsigned int y, Plateau & p,std::string couleur) override;
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
    virtual void comportement(unsigned int x,unsigned int y, Plateau & p,std::string couleur) override;
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
    virtual void comportement(unsigned int x,unsigned int y, Plateau & p,std::string couleur) override;
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
    virtual void comportement(unsigned int x,unsigned int y, Plateau & p,std::string couleur) override;
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
    virtual void comportement(unsigned int x,unsigned int y, Plateau & p,std::string couleur) override;
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
    virtual void comportement(unsigned int x,unsigned int y, Plateau & p,std::string couleur) override;
};

#endif // EFFET_H_INCLUDED
