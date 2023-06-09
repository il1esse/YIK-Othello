/**
 @brief Plateau.h contient les entêtes et les fonctions des données plateau.
 @author YIK
 @version 1.0
 @date 2021/03/17
*/

/* Directives pour éviter les inclusions multiples */
#ifndef PLATEAU_H
#define PLATEAU_H

/* Inclusions des entêtes utilisées */
#include "Case.h"
#include <iostream>
#include <cassert>

/* Définitions de la classes */
class Plateau {

/* Données privés */
 private :
    unsigned int dimx;
    unsigned int dimy;
    bool classique;
    Case * tabCase;

/* Donnée et fonctions publique */
 public :
    
    /**
    @brief Constructeur par défaut de la classe Plateau.
    */
    Plateau();

    /**
    @brief Constructeur de la classe Plateau.
    @param x dimension en x
    @param y dimension en y
    @param type type du plateau : vrai pour un plateau classique.
    */
    Plateau(unsigned int x, unsigned int y, bool type);

    /**
    @brief Destructeur de la classe plateau.
    */
    ~Plateau();

    /**
    @brief Accesseur : Récupère la case de coordonnées (x,y) en vérifiant leur 
    validité la formule pour passer d'un tab 2D à un tab 1D est tab[y*dimx+x].
    @param x coordonnée en X
    @param y coordonnée en Y
    */
    Case & getCase(unsigned int x, unsigned int y) const;

    /**
    @brief Accesseur : Récupère la dimension x du plateau
    */
    unsigned int getDimensionX() const;

    /**
    @brief Accesseur : Récupère la dimension y du plateau
    */
    unsigned int getDimensionY() const;

    /**
    @brief Accesseur : Récupère le type du plateau.
    */
    bool getType() const;

    /**
    @brief Mutateur : Modifie l'état & la couleur de la case de coordonnées (x,y).
    @param x La valeur de la case en X.
    @param y La valeur de la case en Y.
    @param etat La nouvelle valeur état de la case.
    */
    void setCase(unsigned int x, unsigned int y,std::string couleur);

    /**
    @brief Initialise les cases du plateau.
    */
    void initPlateau();

    /**
    @brief Affiche les bordures du plateau.
    @param taille taille du plateau en X
    */
    void afficheBordureHorizontale(int taille) const;
    
    /**
    @brief Affiche le contenu des cases du plateau.
    @param taille_x taille du plateau en X
    @param val_y coordonnée en y des contenus à afficher
    */
    void afficheContenu(int taille_x,int val_y) const;
    
    /**
    @brief Dessine le plateau.
    */
    void dessinePlateau() const;

    /**
    @brief Met à jour le plateau par rapport à l'état d'une case.
    @param x coordonnée en X
    @param y coordonnée en Y
    @param couleur couleur à donnée à la case.
    */
    void majPlateau(unsigned int x, unsigned int y,std::string couleur);

    /**
    @brief Applique la règle horizontale.
    @param x coordonnée en X
    @param y coordonnée en Y
    */
    void appliRegleHori(unsigned int x, unsigned int y);

    /**
    @brief Applique la règle verticale.
    @param x coordonnée en X
    @param y coordonnée en Y
    */
    void appliRegleVerti(unsigned int x, unsigned int y);

    /**
    @brief Applique la règle diagonale
    @param x coordonnée en X
    @param y coordonnée en Y
    */
    void appliRegleDiag(unsigned int x, unsigned int y);

    /**
    @brief Test de regression : Lance les test de régressions de Plateau.
    */
    void testRPlateau();

};
#endif /* Termine le #ifndef PLATEAU_H */
