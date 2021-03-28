/**
 @brief Case.h contient les entêtes et les fonctions des données Case.
 @author YIK
 @version 1.0
 @date 2021/03/17
*/

/* Directives pour éviter les inclusions multiples */
#ifndef CASE_H_INCLUDED
#define CASE_H_INCLUDED

/* Inclusions des entêtes utilisées */

#include <iostream>

/* Définitions de la classes */
class Case{

/* Données privés */
private :

    std::string couleurC;
    unsigned int etat;

/* Donnée et fonctions publique */
public :

    /**
    @brief Constructeur par défaut de la classe Case.
    */
    Case();

    /**
    @brief Constructeur de la classe Plateau.
    @param c Représente la couleur de la case.
    @param e Représente l'état de la case (0=Joueur, 1=Adversaire, 2=Neutre, 3=Bord).
    */
    Case(std::string c,unsigned int e);

    /**
    @brief Destructeur de la classe Case (Met les valeurs à neutre).
    */
    ~Case();

    /**
    @brief Accesseur : Récupère la valeur de couleur de la case.
    */
    std::string getCouleurC() const;

    /**
    @brief Mutateur : Modifie la couleur de la case.
    @param nvCouleur La nouvelle valeur couleur de la case.
    */
    void setCouleurC(std::string & nvCouleur);

    /**
    @brief Accesseur : Récupère la valeur d'état de la case.
    */
    unsigned int getEtat() const;

    /**
    @brief Mutateur : Modifie l'état de la case.
    @param nvEtat La nouvelle valeur d'état de la case.
    */
    void setEtat(unsigned int & nvEtat);

};

#endif // CASE_H_INCLUDED
