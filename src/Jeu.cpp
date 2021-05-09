/* Inclusions des entêtes utilisées */
#include "Jeu.h"
#include <iostream>

    // Constructeur par défaut de la classe Jeu.
    Jeu::Jeu(){

    }


    // Constructeur de la classe Jeu.
    Jeu::Jeu(Plateau p, Joueur joueur1, Joueur joueur2){
        pla = p;
        j1 = joueur1;
        j2 = joueur2;
    }

    // Destructeur de la classe Jeu.
    Jeu::~Jeu(){

    }


    // Accesseur : Récupère le plateau de jeu.
    const Plateau & Jeu::getPlateau() const{
        return pla;
    }

    // Accesseur : Récupère le joueur1 de la partie en cours.
    const Joueur & Jeu::getJoueur1() const{
        return j1;
    }

    
    //Accesseur : Récupère le joueur1 de la partie en cours.
    Joueur & Jeu::getJoueur1(){
        return j1;
    }

    // Accesseur : Récupère le joueur2 de la partie en cours.
    const Joueur & Jeu::getJoueur2() const{
        return j2;
    }

    //Accesseur : Récupère le joueur2 de la partie en cours.
    Joueur & Jeu::getJoueur2(){
        return j2;
    }

    // Accesseur : Récupère le score de la partie.
    const Score * Jeu::getScore() const{
        return score;
    }

    // Accesseur : Récupère le score de la partie.
    Score * Jeu::getScore(){
        return score;
    }


    // Mutateur : Modifie le plateau de jeu.
    void Jeu::setPlateau(Plateau & nvPlateau){
        pla = nvPlateau;
    }

    // Mutateur : Modifie le Joueur1.
    void Jeu::setJoueur1(Joueur & nvJoueur1){
        j1 = nvJoueur1;
    }


    // Mutateur : Modifie le Joueur2.
    void Jeu::setJoueur2(Joueur & nvJoueur2){
        j2 = nvJoueur2;
    }


    // Mutateur : Modifie le nombre de case possédé par le joueur.
    void Jeu::setScore(Score * nvScore){
        score = nvScore;
    }

    // Donne la couleur du joueur1 et du joueur2
    void Jeu::donneCouleur(){
        std::string couleur_j1 = "Bleu";
        std::string couleur_j2 = "Rouge";
        j1.setCouleur(couleur_j1);
        j2.setCouleur(couleur_j2);
    }

    // Donne un pseudo à un joueur.
    void Jeu::pseudoJoueur(Joueur j, std::string pseudo){
        j.setPseudo(pseudo);
    }

    // Permet au jeu de poser un jeton d'un joueur sur le plateau.
    void Jeu::poseJeton(Joueur & j, unsigned int x, unsigned int y, std::string nomJeton){
        if(j.getJeton(nomJeton).getUtilisation() == false){
            j.setUtilisationJeton(nomJeton);
            int nbJ = j.getNombreJeton();
            j.setNombreJeton(nbJ-1);
            std::string couleur = j.getCouleur();
            pla.majPlateau(x,y,couleur);
            j.getJeton(nomJeton).getEffet()->comportement(x,y,pla,couleur);
            j.majCaseJoueur(pla);
        } 
    }

    // Initialise le jeu avec deux joueurs et leurs couleurs + initialisation du plateau.
    void Jeu::initJeu(){
        j1.initJoueur();
        j2.initJoueur();
        donneCouleur();
        pla.initPlateau();
        pla.dessinePlateau();
    }

    // Permet de fermer le jeu.
    void Jeu::quitJeu(){
        exit(0);
    }
    
    // Permet de rejouer une partie.
    void Jeu::rejouerPartie(){
        Joueur nouveauJ1;
        Joueur nouveauJ2;
        Plateau nouveauPla;
        setJoueur1(nouveauJ1);
        setJoueur2(nouveauJ2);
        setPlateau(nouveauPla);
        delete score;
        score = new Score();
    }

    // Test de regression : Lance les test de régressions de Jeu.
    void Jeu::testRJeu(){
        unsigned int x;
        unsigned int xFin;
        std::cout << "Test de regression de la classe Jeu." << std::endl;
        std::cout << "1: Test fonction getPlateau." << std::endl;
        std::cout << "2: Test fonction getJoueur1." << std::endl;
        std::cout << "3: Test fonction getJoueur2." << std::endl;
        std::cout << "4: Test fonction getScore." << std::endl;
        std::cout << "5: Test fonction setPlateau" << std::endl;
        std::cout << "6: Test fonction setJoueur1." << std::endl;
        std::cout << "7: Test fonction setJoueur2." << std::endl;
        std::cout << "8: Test fonction setScore." << std::endl;
        std::cout << "9: Test fonction donneCouleur." << std::endl;
        std::cout << "10: Test fonction pseudoJoueur." << std::endl;
        std::cout << "11: Test fonction poseJeton." << std::endl;
        std::cout << "12: Test initJeu" << std::endl;
        std::cout << "13: Test rejouerPartie" << std::endl;
        std::cout << std::endl;

        do{
            std::cout << "Quel test voulez vous lancez ? " << std::endl;
            std::cin >> x;
        }while(x<0 || x>13);

        switch (x)
        {
            case 1:
            {
                break;
            }

            case 2:
            {
                break;
            }

            case 3:
            {
                break;
            }

            case 4:
            {
                break;
            }

            case 5:
            {
                break;
            }

            case 6:
            {
                break;
            }

            case 7:
            {
                break;
            }

            case 8:
            {
                break;
            }

            case 9:
            {
                break;
            }

            case 10:
            {
                break;
            }

            case 11:
            {
                break;
            }

            case 12:
            {
                break;
            }

            case 13:
            {
                break;
            }
        }

        std::cout << std::endl;
        std::cout << "1: Retour aux tests de régression de Jeu" << std::endl;
        std::cout << "2: Quitter les tests de régression de Jeu" << std::endl;

        do{
            std::cout << "Que voulez vous faire ? " << std::endl;
            std::cin >> xFin;
        }while(x<0 || x>2);
        
        switch (xFin)
        {
        case 1:
            testRJeu();
            break;
        
        case 2:
            exit(0);
            break;
        }
    }
