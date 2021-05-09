/* Inclusions des entêtes utilisées */
#include "JeuTest.h"
#include <iostream>

    //Constructeur par défaut de la classe.
    JeuTest::JeuTest(){

    }

    JeuTest::JeuTest(Jeu j){
        jeu = j;
    }

    JeuTest::~JeuTest(){

    }
    

    // Menu de test de Régression
    void JeuTest::menuTestRegression(){
        Jeu jeu;
        jeu.initJeu();
        unsigned int x;
        unsigned int xFin;
        std::cout << "Test de regression de Régression" << std::endl;
        std::cout << "Voici la liste des classes pouvant être testé" << std::endl;
        std::cout << "1 : Classe Case." << std::endl;
        std::cout << "2 : Classe Effet." << std::endl;
        std::cout << "3 : Classe Jeton." << std::endl;
        std::cout << "4 : Classe Jeu." << std::endl;
        std::cout << "5 : Classe Joueur." << std::endl;
        std::cout << "6 : Classe Plateau." << std::endl;
        std::cout << "7 : Classe Score." << std::endl;
        std::cout << std::endl;

        do{
            std::cout << "Quel classe voulez vous testez ? " << std::endl;
            std::cin >> x;
        }while(x<0 || x>7);

        switch (x)
        {
            case 1:
            {
                jeu.getPlateau().getCase(1,1).testRCase();
                break;
            }

            case 2:
            {
                jeu.getJoueur1().getJeton("Pion").getEffet()->testREffet();
                break;
            }

            case 3:
            {
                Jeton pion = jeu.getJoueur1().getJeton("Pion");
                pion.testRJeton();
                break;
            }

            case 4:
            {
                jeu.testRJeu();
                break;
            }

            case 5:
            {
                jeu.getJoueur1().testRJoueur();
                break;
            }

            case 6:
            {
                Plateau plateau = jeu.getPlateau();
                plateau.testRPlateau();
                break;
            }

            case 7:
            {
                jeu.getScore()->testRScore();
                break;
            }

        }

        std::cout << std::endl;
        std::cout << "1: Retour au menu principale." << std::endl;
        std::cout << "2: Quitter les tests de régression." << std::endl;

        do{
            std::cout << "Que voulez vous faire ? " << std::endl;
            std::cin >> xFin;
        }while(x<0 || x>2);
        
        switch (xFin)
        {
        case 1:
            menuTestRegression();
            break;
        
        case 2:
            exit(0);
            break;
        }
    }