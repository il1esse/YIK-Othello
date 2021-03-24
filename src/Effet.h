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
    unsigned char setNomE(char & nouvNomE);

    /**
    @brief Accesseur : Récupère la description de l'effet.
    */
    unsigned char & getDescription() const;

    /**
    @brief Mutateur : Modifie la description de l'effet.
    @param nouvDescription La nouvelle description de l'effet.
    */
    unsigned char setDescription(string & nouvDescription);

    /**
    @brief Accesseur : Récupère la valeur permettant de savoir si l'effet est special.
    */
    unsigned char & getSpecial() const;

    /**
    @brief Mutateur : Modifie la valeur special de l'effet.
    @param nouvSpecial La nouvelle valeur permettant de savoir si l'effet est special.
    */
    unsigned char setSpecial(bool & nouvSpecial);
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
    @param x Coordonées ou est placé le jeton sur l'axe des x.
    @param y Coordonées ou est placé le jeton sur l'axe des y.
    */
    void comportementHG(int J.x,int J.y);
};

class HautDroite : public Effet
{
    /**
    @brief Constructeur par défaut de la classe HautDroite.
    */    
    HautDroite();
    /**
    @brief Procédure permettant de gerer le comportement de l'effet HautDroite.
    @param x Coordonées ou est placé le jeton sur l'axe des x.
    @param y Coordonées ou est placé le jeton sur l'axe des y.
    */
    void comportementHD(int J.x,int J.y);
};

class BasGauche : public Effet
{
    /**
    @brief Constructeur par défaut de la classe BasGauche.
    */  
    BasGauche();
    /**
    @brief Procédure permettant de gerer le comportement de l'effet BasGauche.
    @param x Coordonées ou est placé le jeton sur l'axe des x.
    @param y Coordonées ou est placé le jeton sur l'axe des y.
    */
    void comportementBG(int J.x,int J.y);
};

class BasDroite : public Effet
{
    /**
    @brief Constructeur par défaut de la classe BasDroite.
    */  
    BasDroite();
    /**
    @brief Procédure permettant de gerer le comportement de l'effet BasDroite.
    @param x Coordonées ou est placé le jeton sur l'axe des x.
    @param y Coordonées ou est placé le jeton sur l'axe des y.
    */
    void comportementBD(int J.x,int J.y);
};



class Haut : public Effet
{
    /**
    @brief Constructeur par défaut de la classe Haut.
    */  
    Haut();
    /**
    @brief Procédure permettant de gerer le comportement de l'effet Haut.
    @param y Coordonées ou est placé le jeton sur l'axe des y.
    */
    void comportementH(int J.y);
};

class Droite : public Effet
{
    /**
    @brief Constructeur par défaut de la classe Droite.
    */  
    Droite();
    /**
    @brief Procédure permettant de gerer le comportement de l'effet Droite.
    @param x Coordonées ou est placé le jeton sur l'axe des x.
    */
    void comportementD(int J.x);
};

class Gauche : public Effet
{
    /**
    @brief Constructeur par défaut de la classe Gauche.
    */  
    Gauche();
    /**
    @brief Procédure permettant de gerer le comportement de l'effet Gauche.
    @param x Coordonées ou est placé le jeton sur l'axe des x.
    */
    void comportementG(int J.x);
};

class Bas : public Effet
{
    /**
    @brief Constructeur par défaut de la classe Bas.
    */    
    Bas();
    /**
    @brief Procédure permettant de gerer le comportement de l'effet Bas.
    @param y Coordonées ou est placé le jeton sur l'axe des y.
    */
    void comportementB(int J.y);
};

#endif // EFFET_H_INCLUDED
