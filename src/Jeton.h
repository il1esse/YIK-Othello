/**
 @brief Jeton contient les données & les entêtes des fonctions jeton.
 @author YIK
 @version 1.0
 @date 2021/03/17
*/

/* Directives pour éviter les inclusions multiples */
#ifndef JETON_H
#define JETON_H
/* Inclusions des entêtes utilisées */


/* Définitions de la classes */
class Jeton {

/* Données privés */
 private :
    char NomJeton;
    Effet EffetJeton;
    bool Utilisé;

/* Donnée et fonctions publique */
 public :
    
    /**
    @brief Constructeur par défaut de la classe Jeton.
    */
    Jeton();

    /**
    @brief Constructeur de la classe Jeton.
    @param nom Nom du jeton.
    @param effet Effet du jeton.
    @param utilisation Utilisation du jeton par un booléen.
    */
    Jeton(char nom, Effet effet, bool utilisation);

    /**
    @brief Destructeur de la classe Jeton.
    */
    ~Jeton();

    /**
    @brief Accesseur : Récupère la valeur NomJeton du Jeton.
    */
    char & getNomJeton() const;

    /**
    @brief Accesseur : Récupère la valeur EffetJeton du Jeton.
    */
    Effet & getEffet() const;

    /**
    @brief Accesseur : Récupère la valeur Utilisé du Jeton.
    */
    bool & getUtilisation() const;

    /**
    @brief Mutateur : Modifie l'effet du Jeton.
    @param nvEffet Le nouvelle effet du Jeton.
    */
    void setEffet(Effet & nvEffet);

    /**
    @brief Mutateur : Modifie la valeur Utilisé du Jeton.
    @param nvBool Le nouvelle valeur booléenne d'utilisation Jeton.
    */
    void setUtilisation(bool & nvBool);

    /**
    @brief Mutateur : Modifie la valeur NomJeton du Jeton.
    @param nvNom Le nouvelle valeur NomJeton du Jeton.
    */
    void setNomJeton(char & nvNom);

    /**
    @brief Dessine un jeton.
    */
    void dessineJeton();

    /**
    @brief Efface un jeton.
    */
    void effaceJeton();

};
#endif /* Termine le #ifndef JETON_H */
