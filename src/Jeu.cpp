/* Inclusions des entêtes utilisées */
#include "Jeu.h"

    // Constructeur par défaut de la classe Jeu.
    Jeu::Jeu(){
        pla = Plateau();
        j1 = Joueur();
        j2 = Joueur();
        score = Score();
    }


    // Constructeur de la classe Jeu.
    Jeu::Jeu(Plateau p, Joueur joueur1, Joueur joueur2){
        pla = p;
        j1 = joueur1;
        j2 = joueur2;
        score = Score();
    }

    // Destructeur de la classe Joueur.
    Jeu::~Jeu(){
        pla = Plateau();
        j1 = NULL;
        j2 = NULL;
        score = Score();
    }


    // Accesseur : Récupère le plateau de jeu.
    char & Jeu::getPlateau() const{
        return pla;
    }

    // Accesseur : Récupère le joueur1 de la partie en cours.
    char & Jeu::getJoueur1() const{
        return j1;
    }

    // Accesseur : Récupère le joueur2 de la partie en cours.
    char & Jeu::getJoueur2() const{
        return j2;
    }

    // Accesseur : Récupère le score de la partie.
    unsigned int & Jeu::getScore() const{
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
    void Jeu::setScore(Score & nvScore){
        score = nvScore;
    }

    // Défini les options du jeu.
    void Jeu::menuJeu(int choix){
        switch (choix)
        {
        case 0:
            modeVsJoueur();
            break;
        case 1:
            modeVsIA();
            break;
        case 2:
            quitJeu();
            break;
        }
    }

    // Met à jour la partie de jeu avec les dernières informations.
    void Jeu::majJeu(){

    }

    // Met fin à la partie.
    void Jeu::finDePartie(){
        Score * scof = new Score(j1.getNombreCase,j2.getNombreCase, pla.getClassique,pla);
        scof.CalculateurScore();
        sco.setScore(scof);
        //A COMPLETER//
    }

    // Définie aléatoirement l'ordre dans lequelle les joueurs vont jouer.
    void Jeu::ordreJeu(){
        int choix = rand() % 2 + 1; 
        switch (choix)
        {
        case 1:
            joueurTour(j1);
            break;
        case 2:
            joueurTour(j2);
            break;
    }


    // Définie l'ordre dans lequelle les joueurs vont jouer.
    void Jeu::ordreJeu(Joueur j){
        joueurTour(j);
    }

    // Permet de déterminer le tour des joueurs.
    void Jeu::joueurTour(Joueur j){
        
    }

    // Permet au joueur de jouer son tour.
    void Jeu::actionJoueur(Joueur j){

    }

    // Permet de fermer le jeu.
    void Jeu::quitJeu(){
        exit(0);
    }

    // Permet de rejouer une partie.
    void Jeu::rejouerPartie(){
        ~Jeu();
        quitJeu();
        //A COMPLETER//
    }

    // Lance le mode Joueur vs Joueur.
    void Jeu::modeVsJoueur(){
        ordreJeu();
        finDePartie();
    }

    // Lance le mode vs IA.
    void Jeu::modeVsIA(){
        ordreJeu();
        finDePartie();
    }