/* Inclusions des entêtes utilisées */
#include "JeuModeTexte.h"
#include <iostream>
    
    // Constructeur par défaut de la classe JeuModeTexte.
    JeuModeTexte::JeuModeTexte(){
        jeu = Jeu();
    }

    // Constructeur de la classe JeuModeTexte.
    JeuModeTexte::JeuModeTexte(Jeu j){
        jeu = j;
    }

    // Destructeur de la classe JeuModeTexte.
    JeuModeTexte::~JeuModeTexte(){
        jeu = Jeu();
    }

    // Accesseur : Récupère le jeu.
    const Jeu & JeuModeTexte::getJeu() const{
        return jeu;
    }

    
    // Mutateur: Change le jeu.
    void JeuModeTexte::setJeu(Jeu nvJeu){
        jeu = nvJeu;
    }

    // Défini les options du jeu.
    void JeuModeTexte::menuJeu(){
        unsigned int x;
        std::cout << "Que voulez vous faire ? " << std::endl;
        std::cout << "1: Mode VS IA " << std::endl;
        std::cout << "2: Mode VS Joueur " << std::endl;
        std::cout << "3: Quitter le jeu " << std::endl;

        do{

            std::cout << "Entrez votre choix : " ;
            std::cin >> x;
            std::cout << std::endl;

        }while(x < 0 || x>3);

        switch (x)
        {
        case 1: modeVsIA(); break;

        case 2: modeVsJoueur(); break;

        case 3: jeu.quitJeu(); break;
        
        }

    }

    //Défini les options de choix de départ.
    void JeuModeTexte::menuChoix(){
        unsigned int x;
        std::cout << "Dans quelle ordre voulez vous commencez ? " << std::endl;
        std::cout << "1: Choix aléatoire " << std::endl;
        std::cout << "2: Choix joueur" << std::endl;

        do{

            std::cout << "Entrez votre choix : " ;
            std::cin >> x;
            std::cout << std::endl;

        }while(x < 0 || x>2);

        switch (x)
        {
        case 1: ordreJeu(); break;

        case 2:  
                std::cout << "Quelle joueur commencera en premier ? Joueur 1 ou 2 ?" ;
                std::cin >> x;
                std::cout << std::endl;
                if(x == 1){
                    ordreJeu(jeu.getJoueur1());
                }
                else ordreJeu(jeu.getJoueur2());
                break;
        
        }
    }

    // Met fin à la partie.
    void JeuModeTexte::finDePartie(){
        Score victoire = jeu.getScore();
        if(jeu.getJoueur1().getNombreCase() > jeu.getJoueur2().getNombreCase())
        {
            victoire.setVictoire(true);
            victoire.AfficherScoreTxt(jeu.getJoueur1(),jeu.getJoueur2(),jeu.getPlateau());
        }
        else if(jeu.getJoueur2().getNombreCase() > jeu.getJoueur1().getNombreCase())
        {
            victoire.setVictoire(false);
            victoire.AfficherScoreTxt(jeu.getJoueur1(),jeu.getJoueur2(),jeu.getPlateau());
        }
        else
        {
            std::cout << "Egalité !" << std::endl;
        }

        std::cout << "1 : Pour rejouer." << std::endl;
        std::cout << "2 : Pour quitter." << std::endl;
        
        unsigned int x;

        do{
            std::cout << "Entrez votre choix" << std::endl;
            std::cin >> x;
        }while(x<0 || x>2);
        
        switch (x)
        {
        case 1 :
            jeu.rejouerPartie();
            menuJeu();
            break;
        
        case 2 :
            jeu.quitJeu();
            break;
        }


    }

    // Définie aléatoirement l'ordre dans lequelle les joueurs vont jouer.
    void JeuModeTexte::ordreJeu(){
        int joueurRand = rand() % 2 + 1; 
        switch (joueurRand)
        {
        case 1:
            std::cout << "C'est au tour de " << jeu.getJoueur1().getPseudo() << " de commencer." << std::endl;
            joueurTour(jeu.getJoueur1());
            break;
        case 2:
            std::cout << "C'est au tour de " << jeu.getJoueur2().getPseudo() << " de commencer." << std::endl;
            joueurTour(jeu.getJoueur2());
            break;
        }
    }

    // Définie l'ordre dans lequelle les joueurs vont jouer.
    void JeuModeTexte::ordreJeu(Joueur joueur)
    {
        std::cout << "C'est au tour de " << joueur.getPseudo() << " de commencer." << std::endl;
        joueurTour(joueur);
    }  

    // Permet de déterminer le tour des joueurs.
    void JeuModeTexte::joueurTour(Joueur j){
        for(int i=0; i<7; i++)
        {
            std::cout << "Tour " << i+1 << std::endl;
            if(j.getPseudo() == jeu.getJoueur1().getPseudo())
            {
                actionJoueur(jeu.getJoueur1());
                actionJoueur(jeu.getJoueur2());
            }
            else 
            {
                actionJoueur(jeu.getJoueur2());
                actionJoueur(jeu.getJoueur1());
            }
        }
        finDePartie();
    }

    // Permet au joueur de jouer son tour.
    void JeuModeTexte::actionJoueur(Joueur j){
        std::cout << "A toi de jouer "<<j.getPseudo() << std::endl;
        std::cout << "Voici tes informations. " << std::endl;
        j.afficheJoueurTxt();
        Plateau plateau = jeu.getPlateau();
        std::cout << "Plateau de jeu : " << std::endl;
        plateau.dessinePlateau(); 
        std::cout << "Rappel : Pour choisir une case donnée sa coordonnée x(min = 1) et y(min = 1)" << std::endl;
        std::cout << "Sur quelle case veux-tu poser un jeton ? " << std::endl;
        unsigned int x;
        unsigned int y;
        std::string nomJeton;

            do{
                std::cout << "Coordonnée x de la case." ;
                std::cin >> x;
                std::cout << std::endl;
            }while(x<0 || x>(plateau.getDimensionX()-2));
            
            do{
                std::cout << "Coordonnée y de la case." ;
                std::cin >> y;
                std::cout << std::endl;
            }while(y<0 || y>(plateau.getDimensionY()-2));

            do{
                std::cout << "Nom du jeton à jouer." ;
                std::cin >> nomJeton;
                std::cout << std::endl;
            }while(j.getJeton(nomJeton).getNomJeton() != nomJeton);

        std::cout << "Vous jouer le jeton " << nomJeton << "sur la case [" << x << "," << y <<"] "<<std::endl;
        j.poseJeton(x,y,plateau,nomJeton);
        plateau.dessinePlateau();
        std::cout << j.getPseudo() << " possède " <<j.getNombreCase() << " case(s)";
    }

    // Lance le mode Joueur vs Joueur.
    void JeuModeTexte::modeVsJoueur(){
        std::string pseudo_j1;
        std::string pseudo_j2;
        std::cout << "Entrez le pseudo du joueur 1 : ";
        std::cin >> pseudo_j1;
        do{
            std::cout << "Entrez le pseudo du joueur 2 : ";
            std::cin >> pseudo_j2;
        }while(pseudo_j1 == pseudo_j2);

        Joueur joueur1 = jeu.getJoueur1();
        Joueur joueur2 = jeu.getJoueur2();
        joueur1.setPseudo(pseudo_j1);
        joueur2.setPseudo(pseudo_j2);
        
        menuChoix();
    }

    // Lance le mode vs IA.
    void JeuModeTexte::modeVsIA(){
        std::string pseudo_j1;
        std::cout << "Entrez le pseudo du joueur 1 : ";
        std::cin >> pseudo_j1;
        Joueur joueur1 = jeu.getJoueur1();
        joueur1.setPseudo(pseudo_j1);
        menuChoix();
    }
