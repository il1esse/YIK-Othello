/**
 @brief JeuTest contient les test de régression du projet.
 @author YIK
 @version 1.0
 @date 2021/03/17
*/

/* Directives pour éviter les inclusions multiples */
#ifndef JEUTEST_H
#define JEUTEST_H

/* Inclusions des entêtes utilisées */
#include "Jeu.h"

/* Définitions de la classes */
class JeuTest {
    /* Données privés */
    private:
    Jeu jeu;


    /* Donnée et fonctions publique */
    public: 

    /**
    @brief Constructeur par défaut de la classe JeuTest.
    */
    JeuTest();

    /**
    @brief Constructeur de la classe JeuTest.
    @param j Jeu.
    */
    JeuTest(Jeu j);

    /**
    @brief Destructeur de la classe JeuTest.
    */
    ~JeuTest();

    /**
    @brief Menu de test de régression
    */
    void menuTestRegression();

};
#endif /* Termine le #ifndef JEUTEST_H */