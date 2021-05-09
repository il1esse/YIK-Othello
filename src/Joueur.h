/**
 @brief Joueur.h contient les entêtes et les fonctions des données joueur.
 @author YIK
 @version 1.0
 @date 2021/03/17
*/

/* Directives pour éviter les inclusions multiples */
#ifndef JOUEUR_H
#define JOUEUR_H

/* Inclusions des entêtes utilisées */
#include "Jeton.h"
#include "Plateau.h"
#include <iostream>

/* Définitions de la classes */
class Joueur {

/* Données privés */
 private :
    std::string pseudo;
    std::string couleur;
    unsigned int nbrJ;
    unsigned int nbrC;
    Jeton * tabJeton;

/* Donnée et fonctions publique */
 public :
    
    /**
    @brief Constructeur par défaut de la classe Joueur.
    */
    Joueur();

    /**
    @brief Constructeur de la classe Joueur.
    @param nomJoueur Pseudo du joueur.
    */
    Joueur(char nomJoueur);

    /**
    @brief Destructeur de la classe Joueur.
    */
    ~Joueur();

    /**
    @brief Accesseur : Récupère le pseudo du joueur.
    */
    const std::string & getPseudo() const;
    
    /**
    @brief Accesseur : Récupère le Jeton du joueur qui porte le nomJeton.
    */
    const Jeton & getJeton (std::string nomJeton) const;

    /**
    @brief Initialise les infos du Joueur.
    */
    void initJoueur();

    /**
    @brief Accesseur : Récupère la couleur associé au joueur.
    */
    const std::string & getCouleur() const;

    /**
    @brief Accesseur : Récupère le nombre de jeton possédé par le joueur.
    */
    const unsigned int & getNombreJeton() const;

    /**
    @brief Accesseur : Récupère le nombre de case possédé par le joueur.
    */
    const unsigned int & getNombreCase() const;

    /**
    @brief Mutateur : Modifie le nom du joueur.
    @param nvPseudo Le nouveau pseudo du joueur.
    */
    void setPseudo(std::string & nvPseudo);

    /**
    @brief Mutateur : Modifie la couleur du joueur..
    @param nvCouleur La nouvelle couleur du joueur.
    */
    void setCouleur(std::string & nvCouleur);

    /**
    @brief Mutateur : Modifie le nombre de jeton du joueur.
    @param nvNbJeton Le nouveau nombre de jeton du joueur.
    */
    void setNombreJeton(unsigned int nvNbJeton);

    /**
    @brief Mutateur : Modifie le nombre de case possédé par le joueur.
    @param nvNbCase Le nouveau nombre de case possédé par joueur.
    */
    void setNombreCase(unsigned int nvNbCase);

    /**
    @brief Crée les 7 jetons.
    */
    void creerJeton();

    /**
    @brief Met à jour l'information du nombre de case possédé par le joueur.
    @param p Plateau de jeu.
    */
    void majCaseJoueur(const Plateau & p);

    /**
    @brief Retourne un booléen disant si le nom du jeton est un jeton du jeu.
    @param nomJeton nom du Jeton dont on doit vérifier l'existence
    */
    bool existeJeton(std::string nomJeton);

    /**
    @brief Change la valeur utilisation du jeton utilisé
    @param nomJeton nom du Jeton dont on doit mettre là valeur d'utilisation à vrai
    */
    void setUtilisationJeton(std::string nomJeton);

    /**
    @brief Affiche les informations du joueur graphiquement.
    */
    void afficheJoueurGraph();

    /**
    @brief Affiche les informations du joueur textuellement.
    */
    void afficheJoueurTxt();

    /**
    @brief Dessine les Jetons du tableaux de jeton possédé par le joueur.
    */
    void dessineJeton();

    /**
    @brief Test de regression : Lance les test de régressions de Joueur.
    */
    void testRJoueur();

};
#endif /* Termine le #ifndef JOUEUR_H */